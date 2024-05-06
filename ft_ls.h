#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_arguements
{
    int l;
    int a;
    int r;
    int R;
    int t;
    int num_files;
} t_arguements;

typedef struct s_directory
{
    char   *name;
    struct stat *stats;
    struct s_directory *next;
} t_directory;


#endif