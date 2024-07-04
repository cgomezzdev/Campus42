/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgomez-z <cgomez-z@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:13:43 by cgomez-z          #+#    #+#             */
/*   Updated: 2024/07/04 18:24:08 by cgomez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*El cliente tomara como parametros (server PID,la string que deberia mandarse.
El cliente debe comunicar la string pasada como parametro al servidor
Una vez la string se haya recibido, el servidor debe motrala.
Solo puedes utilizar estas dos signals SIGUSR1 y SIGUSR2.
BONUS
El servidor confirma cada signal recibida mandando una singal al cliente.
Soporta los caracteres Unicode.*/

#include "minitalk.h"


