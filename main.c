#include "libft/libft.h"
#include <sys/time.h>

int get_rdm(int i)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    int lower = 1;
    int upper = i;
    srand((unsigned int)(time.tv_usec));
    int rdm = (rand() % (upper - lower + 1 )) + lower;
    return (rdm);
}

int main (int ac, char **av)
{
    int nbrdice;
    int i;
    int value;
    t_node *node;

    if (ac != 3)
    {
        nbrdice = 10;
        value = 6;
    }
    else 
    {
        nbrdice = atoi(av[1]);
        value = atoi(av[2]);
    }
    i = nbrdice;
    while (nbrdice > 0)
    {
        if (nbrdice == i)
        {
        node = ft_node_create_new(get_rdm(value));
        }
        else 
        {
            ft_node_append(node, get_rdm(value));
        }
        nbrdice --; 
    }
    ft_node_print_list(node);
    ft_node_sort(&node);
    ft_node_print_list(node);
    ft_node_del(node);
    return (0);
}
