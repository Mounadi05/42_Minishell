#include "../inc/minishell.h"

int    errors_return(char *s)
{
    char *er;
    
    er = strerror(errno);
    glob.exit_code = errno;
    ft_putstr_fd("\033[4;31m", 2);
    ft_putstr_fd(&glob.av[0][2], 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(s, 2);
    ft_putstr_fd(": ", 2);
    ft_putstr_fd(er, 2);
    ft_putstr_fd("\033[0m\n", 2);
    return (glob.exit_code);
}

int    errors_print(char *s)
{
    if (s)
    {
        ft_putstr_fd("minishell: parse error near `", 2);
        ft_putstr_fd(s, 2);
        ft_putstr_fd("'\n", 2);
    }
    else
        ft_putstr_fd("minishell: parse error near `newline'\n", 2);
    return (1);
}

int    pars_error(char **s)
{
    int i;

    i = -1;
    while (s[++i])
    {
        if (!s[i + 1] && (s[i][0] == '>' || s[i][0] == '<'))
            return (errors_print(s[i + 1]));
        else if ((s[i][0] == '>' || s[i][0] == '<') && (s[i + 1][0] == '>' || s[i + 1][0] == '<'))
            return (errors_print(s[i + 1]));
    }
    return (0);
}