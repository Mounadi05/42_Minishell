#ifndef BUILT_IN_H
#define BUILT_IN_H

int     blt_cd(char *path);
int     blt_echo(char **cmd);
int     blt_pwd();
int     blt_env();
int     blt_exit(char **cmd);
int     blt_unset(char **cmd);
int     blt_export(char **cmd);

#endif