/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 02:58:21 by cgomez-z          #+#    #+#             */
/*   Updated: 2025/02/06 02:58:37 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

// Imprime una cadena y actualiza la longitud total escrita
void put_str(char *s, int *len)
{
    if (!s)
        s = "(null)"; // Si la cadena es NULL, imprime "(null)"
    while (*s)
        *len += write(1, s++, 1); // Escribe carácter por carácter y actualiza len correctamente
}

// Imprime un número en una base dada (decimal o hexadecimal) y actualiza la longitud
void put_dig(int n, int base, int *len)
{
    char *hexa = "0123456789abcdef";
    unsigned int num;

    if (n < 0 && base == 10) // Manejo de números negativos en base 10
    {
        *len += write(1, "-", 1);
        num = -n; // Convierte a positivo para evitar problemas con UINT_MAX
    }
    else
        num = (unsigned int)n;
    
    if (num >= (unsigned int)base)
        put_dig(num / base, base, len); // Llamada recursiva para imprimir los dígitos previos
    
    *len += write(1, &hexa[num % base], 1); // Imprime el dígito actual
}

// Implementación de ft_printf con soporte para %s, %d y %x
int ft_printf(char *f, ...)
{
    int len = 0;
    va_list args;

    va_start(args, f);
    while (*f)
    {
        if (*f == '%' && *(f + 1)) // Verifica que haya un especificador válido
        {
            f++;
            if (*f == 's')
                put_str(va_arg(args, char *), &len);
            else if (*f == 'd')
                put_dig(va_arg(args, int), 10, &len);
            else if (*f == 'x')
                put_dig(va_arg(args, unsigned int), 16, &len);
            else
                len += write(1, f, 1); // Imprime el carácter literal si no es un especificador válido
        }
        else
            len += write(1, f, 1); // Imprime el carácter directamente si no es '%'
        f++;
    }
    va_end(args);
    return len;
}

