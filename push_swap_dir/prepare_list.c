#include "push_swap.h"


t_list*     append()
{
    t_list  *new;
    new = malloc(sizeof(t_list));
    return (new);
}

t_list* prepare_a_list(int argc, char **argv, t_list *a_head)
{
    int count;
    t_list *a_ori;

    a_head = append();
    count = argc;
    a_head->is_dummy = TRUE_A;
    a_ori = a_head;
    while(argc-- - 1)
    {
        a_head->next = malloc(sizeof(t_list));
        (a_head->next)->prev = a_head;
        (a_head->next)->is_dummy = FALSE;
        (a_head->next)->value = ft_atoi(argv[count - argc]);
        a_head = a_head->next;
    }
    a_head->next = a_ori;
    a_ori->prev = a_head;

    return (a_ori);
}

t_list* prepare_b_list(t_list *b_head)
{
    b_head = append();

    b_head->next = b_head;
    b_head->prev = b_head;
    b_head->is_dummy = TRUE_B;

    return (b_head);
}


int arena(t_list *list, int warrior)
{
    int win;

    win = 1;
    list = list->next;
    while(list->is_dummy == FALSE)
    {
        if(warrior > list->value)
            win++;
        list = list->next;
    }
    return (win);
}

void    tend_values(int len, t_list* list_head, t_list *src_head)
{
    t_list *list;
    t_list *src;

    list = list_head->next;
    src = src_head->next;
    while(list -> is_dummy == FALSE)
    {
        list->value = arena(src_head, src->value);
        list = list->next;
        src = src->next;
    }
}