#include "push_swap.h"

void    init_import_a(t_list *a_head, t_list *b_head)
{
    int pivot;
    int len;

    pivot = (find_min(a_head))->value + len_list(a_head) / 2;
    printf("pivot is %d\n", pivot);
    len = len_list(a_head);
    while(len--)
    {
        if((a_head->next)->value < pivot)
        {
            push(a_head, b_head);
            if((b_head->next)->value > pivot / 2)
                rotate(b_head);
        }
        else
            rotate(a_head);
    }
}

void    clean_up(t_list *a_head, t_list *b_head)
{
    while(len_list(b_head) != 0)
    {
        push_min(b_head, a_head);
        rotate(a_head);
    }
    if((a_head->next)->value != 1)
        import_a(a_head, b_head);
}

void    import_a(t_list *a_head, t_list *b_head)
{
    int pivot;

    while((a_head->next)->value != 1)
    {
        push(a_head, b_head);
        if((b_head->next)->value > pivot / 2)
            rotate(b_head);
    }
    clean_up(a_head, b_head);
}

void    quick_sort(t_list *a_head, t_list *b_head)
{
    init_import_a(a_head, b_head);
    printf("import done\n");
    // check_stacks(a_head, b_head);
    clean_up(a_head, b_head);
    printf("cleaned\n");
    // check_stacks(a_head, b_head);
}
