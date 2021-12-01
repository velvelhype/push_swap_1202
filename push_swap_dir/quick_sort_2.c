#include "push_swap.h"

int     ship_amount(int pivot, t_list *head)
{
    int ship_count;

    ship_count = 0;
    head = head->next;
    while(head->is_dummy == FALSE)
    {
        if(head->value > pivot)
            ship_count++;
        head = head->next;
    }
    return (ship_count);
}

void    init(t_list *a_head, t_list *b_head)
{
    int pivot;
    int len;
    int ruminant_count;
    int shipment;

    pivot = (find_min(a_head))->value + len_list(a_head) / 2;
    len = len_list(a_head);
    shipment = len / 2;
    ruminant_count = len - shipment;

    while(shipment)
    {
        if((a_head->next)->value < pivot)
        {
            push(a_head, b_head);
            shipment--;
        }
        else
            rotate(a_head);
        
        check_stacks(a_head, b_head);
    }
    process_b(a_head, b_head);
    ruminant(ruminant_count, a_head, b_head);
}

void     cut_half(t_list *a_head, t_list *b_head)
{
    int pivot;
    int ruminant_count;
    int shipment;

    pivot = (find_min(b_head))->value + len_list(b_head) / 2;
    shipment = ship_amount(pivot, b_head);
    ruminant_count = shipment;

    // printf("cut! %d\n", pivot);
    // check_stacks(b_head);

    while(shipment)
    {
        if ((b_head->next)->value > pivot)
        {
            push(b_head, a_head);
            shipment--;
            
        }
        else if(b_head->next == find_min(b_head))
        {
            push(b_head, a_head);
            rotate(a_head);
        }
        else
            rotate(b_head);

        check_stacks(a_head, b_head);
        
    }
    process_b(a_head, b_head);
    ruminant(ruminant_count, a_head, b_head);
}

int     next_pivot(int range, t_list* head)
{
    int pivot;

    pivot = (find_min_ranged(range, head))->value + range / 2;
    return (pivot);
}

void    ruminant(int ruminant_count, t_list *a_head, t_list *b_head)
{
    int is_cleanable;
    int pivot;


    while(ruminant_count--)
    {
        if (a_head->prev->value + 1 == a_head->next->value)
            rotate(a_head);
        else
            push(a_head, b_head);
    }
    // printf("ruminanted\n");

    check_stacks(a_head, b_head);

    process_b(a_head, b_head);
}

void    clean_up(t_list *a_head, t_list *b_head)
{
    while(len_list(b_head) != 0)
    {
        push_min(b_head, a_head);
        rotate(a_head);
    }
}

void    process_b(t_list *a_head, t_list *b_head)
{
    if (len_list(b_head) < CLEANING_VOL)
        clean_up(a_head, b_head);
    else
        cut_half(a_head, b_head);
}

void    quick_sort_2(t_list *a_head, t_list *b_head)
{
    init(a_head, b_head);
}
