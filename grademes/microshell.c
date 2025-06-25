/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:25:14 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/06/25 01:53:24 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>     // para funciones como write, fork, pipe, dup2, execve, chdir, etc.
#include <string.h>     // para funciones como strcmp
#include <sys/wait.h>   // para usar waitpid y macros como WIFEXITED

// ----------------------------------------------------------
// Función auxiliar para imprimir errores por STDERR (fd 2)
// Si se pasa un segundo argumento, se imprime también
// Retorna siempre 1 para usarlo como valor de error
// ----------------------------------------------------------
static int msg(char *s, char *arg)
{
	while (*s)
		write(2, s++, 1);  // escribe mensaje principal
	if (arg)
	{
		write(2, " ", 1);  // espacio separador
		while (*arg)
			write(2, arg++, 1);  // escribe argumento
	}
	write(2, "\n", 1);  // salto de línea final
	return (1);
}

// ----------------------------------------------------------
// Implementación del built-in 'cd'
// Solo acepta exactamente un argumento (la ruta)
// Si no se cumplen las condiciones, imprime error adecuado
// ----------------------------------------------------------
static int ft_cd(char **av, int i)
{
	if (i != 2)
		return msg("error: cd: bad arguments", NULL);  // más o menos de un argumento
	else if (chdir(av[1]) == -1)  // si chdir falla
		return msg("error: cd: cannot change directory to", av[1]);
	return (0);  // éxito
}

// ----------------------------------------------------------
// Ejecuta un comando que no sea 'cd'
// Soporta 'pipes' entre comandos, si detecta el símbolo '|'
// i es el índice donde termina el comando actual
// ----------------------------------------------------------
static int ft_exec(char **av, char **env, int i)
{
	int status;
	int fd[2];
	int pipes = (av[i] && !strcmp(av[i], "|"));  // comprobamos si hay pipe después del comando
	// Si hay pipe, creamos el pipe y comprobamos errores
	if (pipes && pipe(fd) == -1)
		return msg("error: fatal", NULL);
	int pid = fork();  // bifurcamos proceso
	if (!pid) // Proceso hijo
	{
		av[i] = 0;  // Separamos el comando cortando donde estaba el pipe o ';'
		// Si hay pipe, redirigimos stdout al extremo de escritura del pipe
		if (pipes && (dup2(fd[1], 1) == -1 || close(fd[1]) == -1 || close(fd[0]) == -1))
			return msg("error: fatal", NULL);
		// Ejecutamos el comando, pasándole los argumentos y el entorno
		execve(*av, av, env);
		// Si execve falla, mostramos mensaje de error y terminamos
		return msg("error: cannot execute", *av);
	}
	// Proceso padre: espera al hijo
	waitpid(pid, &status, 0);
	// Si hay pipe, redirigimos stdin al extremo de lectura del pipe
	if (pipes && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return msg("error: fatal", NULL);
	// Retornamos el código de salida del hijo si ha terminado normalmente
	return WIFEXITED(status) && WEXITSTATUS(status);
}

// ----------------------------------------------------------
// Función principal que itera sobre los argumentos
// Divide los comandos usando ';' y '|' como separadores
// ----------------------------------------------------------
int main(int ac, char **av, char **env)
{
	(void)ac;  // se ignora ac porque no se usa directamente
	int status = 0;

	while (*av && *(av + 1))  // nos aseguramos de que hay argumentos después del nombre del programa
	{
		av++;  // saltamos el nombre del programa
		int i = 0;
		// Buscamos el índice del próximo separador ('|' o ';')
		while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
			i++;
		// Si el comando es 'cd', lo manejamos directamente
		if (strcmp(*av, "cd") == 0)
			status = ft_cd(av, i);
		// Si no, lo tratamos como un comando externo
		else if (i)
			status = ft_exec(av, env, i);
		// Nos saltamos el bloque que ya procesamos
		av += i;
	}
	return status;
}
