/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 00:28:43 by ybel-hac          #+#    #+#             */
/*   Updated: 2022/11/26 21:46:08 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	close_message(void)
{
	ft_putstr("Error\n");
	ft_putstr("\033[0;32m\
\t████████╗██╗░░██╗███████╗  ░██████╗░░█████╗░███╗░░░███╗███████╗  ██╗░░██╗░█████╗░░██████╗\n\
\t╚══██╔══╝██║░░██║██╔════╝  ██╔════╝░██╔══██╗████╗░████║██╔════╝  ██║░░██║██╔══██╗██╔════╝\n\
\t░░░██║░░░███████║█████╗░░  ██║░░██╗░███████║██╔████╔██║█████╗░░  ███████║███████║╚█████╗░\n\
\t░░░██║░░░██╔══██║██╔══╝░░  ██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░  ██╔══██║██╔══██║░╚═══██╗\n\
\t░░░██║░░░██║░░██║███████╗  ╚██████╔╝██║░░██║██║░╚═╝░██║███████╗  ██║░░██║██║░░██║██████╔╝\n\
\t░░░╚═╝░░░╚═╝░░╚═╝╚══════╝  ░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝  ╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░\n\
\n\
\t░█████╗░██╗░░░░░░█████╗░░██████╗███████╗██████╗░  ██████╗░██╗░░░██╗  ████████╗██╗░░██╗███████╗\n\
\t██╔══██╗██║░░░░░██╔══██╗██╔════╝██╔════╝██╔══██╗  ██╔══██╗╚██╗░██╔╝  ╚══██╔══╝██║░░██║██╔════╝\n\
\t██║░░╚═╝██║░░░░░██║░░██║╚█████╗░█████╗░░██║░░██║  ██████╦╝░╚████╔╝░  ░░░██║░░░███████║█████╗░░\n\
\t██║░░██╗██║░░░░░██║░░██║░╚═══██╗██╔══╝░░██║░░██║  ██╔══██╗░░╚██╔╝░░  ░░░██║░░░██╔══██║██╔══╝░░\n\
\t╚█████╔╝███████╗╚█████╔╝██████╔╝███████╗██████╔╝  ██████╦╝░░░██║░░░  ░░░██║░░░██║░░██║███████╗\n\
\t░╚════╝░╚══════╝░╚════╝░╚═════╝░╚══════╝╚═════╝░  ╚═════╝░░░░╚═╝░░░  ░░░╚═╝░░░╚═╝░░╚═╝╚══════╝\n\
\n\
\t\t\t\t\t██╗░░░██╗░██████╗███████╗██████╗░\n\
\t\t\t\t\t██║░░░██║██╔════╝██╔════╝██╔══██╗\n\
\t\t\t\t\t██║░░░██║╚█████╗░█████╗░░██████╔╝\n\
\t\t\t\t\t██║░░░██║░╚═══██╗██╔══╝░░██╔══██╗\n\
\t\t\t\t\t╚██████╔╝██████╔╝███████╗██║░░██║\n\
\t\t\t\t\t░╚═════╝░╚═════╝░╚══════╝╚═╝░░╚═╝\n");
}

int	invalid_message(void)
{
	ft_putstr("Error\n");
	ft_putstr("\033[0;31m\
██╗███╗░░██╗██╗░░░██╗░█████╗░██╗\
░░░░░██╗██████╗░  ███╗░░░███╗░█████╗░██████╗░\n\
██║████╗░██║██║░░░██║██╔══██╗██║\
░░░░░██║██╔══██╗  ████╗░████║██╔══██╗██╔══██╗\n\
██║██╔██╗██║╚██╗░██╔╝███████║██║\
░░░░░██║██║░░██║  ██╔████╔██║███████║██████╔╝\n\
██║██║╚████║░╚████╔╝░██╔══██║██║\
░░░░░██║██║░░██║  ██║╚██╔╝██║██╔══██║██╔═══╝░\n\
██║██║░╚███║░░╚██╔╝░░██║░░██║███\
████╗██║██████╔╝  ██║░╚═╝░██║██║░░██║██║░░░░░\n\
╚═╝╚═╝░░╚══╝░░░╚═╝░░░╚═╝░░╚═╝╚══\
════╝╚═╝╚═════╝░  ╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░░░░\n");
	ft_putstr("\033[0;32mThe map must contain 1 exit, \
at least 1 collectible, and 1 starting position to be valid.");
	ft_putstr("otherwise check this pointes: \n- extension of file is\
 .ber\n- the map closed/surrounded by walls\n- (exit/player) not duplicated.\n");
	return (0);
}

void	succes_message(void)
{
	ft_putstr("\033[0;32m\n\
░██████╗░██████╗░███████╗░█████╗░████████╗ \
░██╗░░░░░░░██╗░█████╗░██████╗░██╗░░██╗\n\
██╔════╝░██╔══██╗██╔════╝██╔══██╗╚══██╔══╝ \
░██║░░██╗░░██║██╔══██╗██╔══██╗██║░██╔╝\n\
██║░░██╗░██████╔╝█████╗░░███████║░░░██║░░░ \
░╚██╗████╗██╔╝██║░░██║██████╔╝█████═╝░\n\
██║░░╚██╗██╔══██╗██╔══╝░░██╔══██║░░░██║░░░ \
░░████╔═████║░██║░░██║██╔══██╗██╔═██╗░\n\
╚██████╔╝██║░░██║███████╗██║░░██║░░░██║░░░ \
░░╚██╔╝░╚██╔╝░╚█████╔╝██║░░██║██║░╚██╗\n\
░╚═════╝░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝░░░╚═╝░░░ \
░░░╚═╝░░░╚═╝░░░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝\n");
}

int	ft_error(char *txt)
{
	ft_putstr("Error\n");
	ft_putstr("\033[0;31m");
	ft_putstr(txt);
	return (0);
}

void	over_message(void)
{
	ft_putstr("\033[0;31m\
░██████╗░░█████╗░███╗░░░███╗███████╗  ░█████╗░██╗░░░██╗███████╗██████╗░\n\
██╔════╝░██╔══██╗████╗░████║██╔════╝  ██╔══██╗██║░░░██║██╔════╝██╔══██╗\n\
██║░░██╗░███████║██╔████╔██║█████╗░░  ██║░░██║╚██╗░██╔╝█████╗░░██████╔╝\n\
██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░  ██║░░██║░╚████╔╝░██╔══╝░░██╔══██╗\n\
╚██████╔╝██║░░██║██║░╚═╝░██║███████╗  ╚█████╔╝░░╚██╔╝░░███████╗██║░░██║\n\
░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝  ░╚════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝\n");
}
