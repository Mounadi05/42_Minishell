#include "../inc/minishell.h"

char *handl_unclosed(char *inp)
{
    int i;

    glob.p = -1;
    if (!check_pipe(inp) ||  check_quote(inp))
    {
        glob.p = dup(0);
        inp = check_full(inp);
        dup(glob.p);
        close(glob.p);
    }
    glob.p = -1;
    return (inp);
}