#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

#define FALSE 0
#define TRUE 1
#define TRUE_A 3
#define TRUE_B 4
#define CLEANING_VOL 15

typedef struct t_list
{
    struct t_list *next;
    struct t_list *prev;
    long value;
    int is_dummy;
    int sort_status;
} t_list;


//pre_error_check
void    error_case();
void    pre_error_check(int argc, char **argv);
long    custom_atoi(const char *str);

//preparetions
t_list* append();
t_list* prepare_a_list(int argc, char ** argv, t_list *a_head);
t_list* prepare_b_list(t_list *b_head);
void    tend_values(int len, t_list* list, t_list *ranking);

//post_process
void    check_duplicates(t_list *list);


//controls
void    swap(t_list* head);
void    push(t_list* a_head, t_list* b_head);
void    rotate(t_list *head);
void    r_rotate(t_list *head);

//sort
void    two_sort(t_list *dum);
int     is_sorted(t_list *a_head);
void    push_min(t_list    *a_head, t_list *b_head);
t_list* find_min(t_list *list);
t_list* find_min_ranged(int range, t_list *list);
int     len_list(t_list*    head);
void    three_sort(t_list *dum);
void    five_sort(t_list    *a_head, t_list *b_head);

// 2
void    quick_sort_2(t_list *a_head, t_list *b_head);
void    process_b(t_list *a_head, t_list *b_head);
void    ruminant(int ruminant_count, t_list *a_head, t_list *b_head);

// check_funcs
void    check_stacks(t_list *a_dummy, t_list *b_dummy);
void    check_stack(t_list *a_head);
void    check_stack_r(t_list *a_head);
void    check_link(t_list *a_head);

#endif