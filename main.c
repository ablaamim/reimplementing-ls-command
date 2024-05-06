#include "ft_ls.h"

void   print_args(t_arguements *args)
{
    printf("l:         %d\n", args->l);
    printf("a:         %d\n", args->a);
    printf("r:         %d\n", args->r);
    printf("R:         %d\n", args->R);
    printf("t:         %d\n", args->t);
    printf("num_files: %d\n", args->num_files);
}

void print_list(t_directory *dir)
{
    t_directory *tmp = dir;

    if (tmp == NULL)
    {
        printf("No files\n");
        return ;
    }

    while (tmp != NULL)
    {
        printf("name: %s\n", tmp->name);
        tmp = tmp->next;
    }
}

int parser(int argc, char *argv[], t_arguements args, t_directory *dir)
{
    // printf("argc: %d\n", argc);
    // while (argc--)
    // {
    //     printf("argv: %s\n", *argv++);
    // }
    int i = 1;
    while (i < argc)
    {
        if (argv[i][0] == '-')
        {
            int j = 1;
            while (argv[i][j] != '\0')
            {
                if (argv[i][j] == 'l')
                    args.l = 1;
                else if (argv[i][j] == 'a')
                    args.a = 1;
                else if (argv[i][j] == 'r')
                    args.r = 1;
                else if (argv[i][j] == 'R')
                    args.R = 1;
                else if (argv[i][j] == 't')
                    args.t = 1;
                else
                {
                    printf("ft_ls: illegal option -- %c\n", argv[i][j]);
                    printf("usage: ft_ls [-lartR] [file ...]\n");
                    return (1);
                }
                j++;
            }
        }
        else
        {
            //printf("argv[i]: %s\n", argv[i]);
            // Add the file to the linked list
            t_directory *new_dir = (t_directory *)malloc(sizeof(t_directory));
            if (new_dir == NULL)
            {
                perror("malloc failed\n");
                return (1);
            }
            new_dir->name = argv[i];
            new_dir->next = dir;
            dir = new_dir;
            args.num_files++;
        }
        i++;
    }
    print_args(&args);
    print_list(dir);
    return (0);
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;
    t_arguements *args;
    t_directory *dir = NULL;
    int         return_args = 0;
    args = (t_arguements *)malloc(sizeof(t_arguements));
    if (args == NULL)
    {
        perror("malloc failed\n");
        return (EXIT_FAILURE);
    }
    // Initialize the arguments
    args->l = 0;
    args->a = 0;
    args->r = 0;
    args->R = 0;
    args->t = 0;
    args->num_files = 0;
    //print_args(args);
    return_args = parser(argc, argv, *args, dir);
    //print_list(dir);
    return (EXIT_SUCCESS);
}