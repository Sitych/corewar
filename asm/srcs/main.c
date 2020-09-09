#include "../includes/asm.h"
#include "../libft/includes/libftprintf.h"
#include <stdlib.h>

void    ft_exit(char *str)
{
    ft_putstr(str);
    exit(1);
}

void ft_check_filename(char *name)
{
    if (ft_strlen(ft_strstr(name, ".s")) != 2 && ft_strlen(name) < 3)
    {
        ft_exit("Bad file name\n");
    }
    else
    {
        ft_printf("File: %s\n", name);
    }
}

void    ft_check_header()
{
    if (COMMENT_CHAR == '\n' || LABEL_CHAR == '\n')
    {
        ft_exit("Wrong chars in header\n");
    }
}


int main(int ac, char **av)
{
//	We have one important question: how much champs we want to process. If only 1:
    if (ac != 2)
        ft_exit("Usage: bla-bla-bla\n");

    ft_check_header();
    ft_check_filename(av[1]);

    ft_printf("HI!!!\n");
	return (0);
}
