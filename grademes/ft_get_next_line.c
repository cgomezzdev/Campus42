/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 03:04:02 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/02/06 03:04:57 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>   // Para la función open()
#include <stdio.h>   // Para printf() (usado en el main)
#include <stdlib.h>  // Para malloc() y free()
#include <unistd.h>  // Para read() y close()

// Definimos BUFFER_SIZE en caso de que no esté definido en la compilación
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

// Implementación de get_next_line
char *get_next_line(int fd)
{
        int byte;       // Variable para almacenar el número de bytes leídos
        int i;          // Índice para recorrer la línea
        char c;         // Variable donde se almacena el carácter leído
        char *line;     // Puntero que almacenará la línea leída
        // Verificamos si el BUFFER_SIZE es inválido o si el descriptor de archivo es inválido
        if (BUFFER_SIZE < 1 || fd < 0)
                return (NULL);
        i = 0;
        // Se reserva memoria para almacenar la línea, pero aquí hay un error:
        // - Se asigna un tamaño fijo de 10,000 bytes sin justificación.
        // - `sizeof(char *)` está mal; debería ser `sizeof(char)`, aunque en este caso no afecta.
        line = malloc(10000 * sizeof(char *));
        if (!line) // Si malloc falla, se retorna NULL
                return (NULL);
        // Se lee un solo carácter del archivo
        byte = read(fd, &c, 1);
        while (byte > 0) // Mientras haya caracteres por leer
        {
                line[i] = c; // Se almacena el carácter leído en la línea
                i++;
                // ERROR: `if (c == '\n' || EOF)` siempre se ejecuta porque `EOF` es -1, una constante siempre verdadera
                // Lo correcto sería `if (c == '\n' || byte == 0)`
                if (c == '\n' || EOF) 
                        break;
                byte = read(fd, &c, 1); // Se sigue leyendo carácter por carácter
        }
        // Si no se ha leído nada (`i == 0`), o si hay un error (`byte < 0`), liberamos memoria y retornamos NULL
        if (i == 0 || byte < 0)
        {
                free(line);
                return (NULL);
        }
        // Se agrega el carácter nulo al final de la línea para que sea una cadena válida
        line[i] = '\0';
        return (line);
}

/*
int main(void)
{
        int fd;
        int i;
        char *path;
        char *line;

        i = -1;
        path = "test.txt";
        fd = open(path, O_RDONLY);
        while (++i < 2)
        {
                line = get_next_line(fd);
                printf("line: %s\n", line);
        }
        return (0);
}
*/

