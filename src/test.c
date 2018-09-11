#include "../includes/minishell.h"

int    main(void)
{
    char        ***test;
    char        **array;

    if (!(array = malloc(sizeof(char *) * 3)))
        return (-1);
    array[0] = ft_strdup("YL");
    array[1] = ft_strdup("HELLK");
    array[2] = NULL;
    test = &array;
    printf("=========BEFORE=========\n");
    ft_print_array(*test);
    printf("=========AFTER=========\n");
    printf("TEST + 1 => %s\n", *(*test + 1));
    //    **test => array[0]    (**test) + 1 => array[1]   *test => array
    ft_strdel((*test + 1));
    *(*test + 1) = ft_strdup("NEW STR");
    ft_print_array(*test);
    ft_free_array(array);
    while (1);
    return (0);
}