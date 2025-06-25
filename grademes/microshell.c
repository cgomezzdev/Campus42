/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:25:14 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/06/26 01:24:08 by cgomez-z         ###   ########.fr       */
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
                write(2, s++, 1);  // Escribe el mensaje principal a stderr
        if (arg)
        {
                write(2, " ", 1);  // Escribe un espacio entre el mensaje y el argumento (si existe)
                while (*arg)
                        write(2, arg++, 1);  // Escribe el argumento a stderr
        }
        write(2, "\n", 1);  // Añade un salto de línea al final del mensaje
        return (1);  // Devuelve 1 para indicar un error
}

// ----------------------------------------------------------
// Implementación del built-in 'cd'
// Solo acepta exactamente un argumento (la ruta)
// Si no se cumplen las condiciones, imprime error adecuado
// ----------------------------------------------------------
static int ft_cd(char **av, int i)
{
        if (i != 2)  // Comprobamos que 'cd' tenga exactamente un argumento
                return msg("error: cd: bad arguments", NULL);  // Error si hay más o menos de un argumento
        else if (chdir(av[1]) == -1)  // Si falla la llamada a chdir (para cambiar directorio)
                return msg("error: cd: cannot change directory to", av[1]);  // Error con la ruta
        return (0);  // Devuelve 0 si todo fue correcto
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
        int pipes = (av[i] && !strcmp(av[i], "|"));  // Comprobamos si hay un pipe ('|') después del comando

        // Si hay un pipe, creamos el pipe y comprobamos errores
        if (pipes && pipe(fd) == -1)
                return msg("error: fatal", NULL);  // Error al crear el pipe

        int pid = fork();  // Creamos un proceso hijo
        if (!pid)  // Si estamos en el proceso hijo
        {
                av[i] = 0;  // Separamos el comando donde estaba el pipe o ';' (cortamos los argumentos)
                // Si hay un pipe, redirigimos stdout al extremo de escritura del pipe
                if (pipes && (dup2(fd[1], 1) == -1 || close(fd[1]) == -1 || close(fd[0]) == -1))
                        return msg("error: fatal", NULL);  // Error al redirigir el pipe

                // Ejecutamos el comando usando execve (que reemplaza el proceso actual)
                execve(*av, av, env);
                // Si execve falla, mostramos un mensaje de error y terminamos
                return msg("error: cannot execute", *av);
        }
        // En el proceso padre, esperamos a que el hijo termine
        waitpid(pid, &status, 0);
        // Si hay un pipe, redirigimos stdin al extremo de lectura del pipe
        if (pipes && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
                return msg("error: fatal", NULL);  // Error al redirigir el pipe

        // Devolvemos el código de salida del hijo si terminó normalmente
        return WIFEXITED(status) && WEXITSTATUS(status);
}

// ----------------------------------------------------------
// Función principal que itera sobre los argumentos
// Divide los comandos usando ';' y '|' como separadores
// ----------------------------------------------------------
int main(int ac, char **av, char **env)
{
        int status;
        int i;

        status = 0;  // Variable para guardar el estado de la ejecución
        i = 0;
        if (ac > 1)  // Comprobamos que haya argumentos (comandos) para ejecutar
        {
                while (av[i] && av[++i])  // Iteramos sobre los argumentos
                {
                        av += i;  // Saltamos el comando ejecutado
                        i = 0;  // Reiniciamos el índice de los argumentos
                        while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))  // Buscamos un '|' o ';' como separador de comandos
                                i++;
                        if (!strcmp(*av, "cd"))  // Si el comando es 'cd', ejecutamos ft_cd
                                status = ft_cd(av, i);
                        else if (i)  // Si hay más de un argumento, ejecutamos el comando normalmente
                                status = ft_exec(av, env, i);
                }
        }
        return status;  // Retornamos el estado de la última ejecución (código de salida)
}
