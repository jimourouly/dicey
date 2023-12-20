#include "libft/libft.h"
#include <sys/time.h>

void ft_node_move_to_front(t_node **head, t_node *node_to_move) {
    if (*head == NULL || node_to_move == NULL || *head == node_to_move) return;

    // Trouver et détacher le nœud
    t_node *current = *head;
    t_node *prev = NULL;
    while (current != NULL && current != node_to_move) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return; // Nœud non trouvé

    if (prev != NULL) prev->next = current->next;

    // Ajouter au début
    current->next = *head;
    *head = current;
}

void ft_node_move_to_end(t_node **head, t_node *node_to_move) {
    if (*head == NULL || node_to_move == NULL || node_to_move->next == NULL) return;

    // Trouver et détacher le nœud
    t_node *current = *head;
    t_node *prev = NULL;
    while (current != NULL && current != node_to_move) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) return; // Nœud non trouvé

    if (prev != NULL) prev->next = current->next;

    // Si le nœud était déjà le dernier, pas besoin de le déplacer
    if (current->next == NULL) return;

    // Ajouter à la fin
    t_node *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = current;
    current->next = NULL;
}

void ft_node_sort(t_node **head) {
    int swapped;
    int temp;

    t_node *current;
    t_node *last = NULL;
    if (*head == NULL) return;
    swapped = 1;
    while (swapped == 1) {
        swapped = 0;
        current = *head;

        while (current->next != last) {
            if (current->value > current->next->value) {
                temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;

                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    }
}

int get_rdm(int i)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    int lower = 1;
    int upper = i;
//Func to randomize between 2 nbr
    
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
            //create new node head
            node = ft_node_create_new(get_rdm(value));
        }
        else 
        {
            //append node with rdm
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
