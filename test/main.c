#include "int_p_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

//
int main(void)
{

	// OK
	// int *i = malloc(sizeof(int));
	// struct psg_int_p_node_t *test = psg_int_p_node_new(i, 0, 0);
	// psg_int_p_node_free(test, free_int);

	// OK
	// struct psg_int_p_linked_list_t *list = psg_int_p_linked_list_new();
	// psg_int_p_linked_list_free(list, free_int);

	// OK
	// struct psg_int_p_linked_list_t *list = psg_int_p_linked_list_new();
	// int *i = malloc(sizeof(int));
	// psg_int_p_linked_list_push_first(list, i);
	// psg_int_p_linked_list_push_first(list, i);
	// psg_int_p_linked_list_free(list);
	// free(i);

	// OK
	// struct psg_int_p_linked_list_t *list = psg_int_p_linked_list_new();
	// int *i = malloc(sizeof(int));
	// psg_int_p_linked_list_push_first(list, i);
	// psg_int_p_linked_list_push_first(list, i);
	// printf("size: %zu\n", psg_int_p_linked_list_get_size(list));
	// psg_int_p_linked_list_pop_last(list);
	// psg_int_p_linked_list_pop_last(list);
	// printf("size: %zu\n", psg_int_p_linked_list_get_size(list));
	// psg_int_p_linked_list_free(list);
	// free(i);

	// OK
	// PSG_LINKED_LIST_OPAQUE_NAME(int_p) list = PSG_LINKED_LIST_NEW_FUNCTION_NAME(int_p)();
	// int *i = malloc(sizeof(int));
	// *i = 1;
	// int *ii = malloc(sizeof(int));
	// *ii = 2;
	// int *iii = malloc(sizeof(int));
	// *iii = 3;
	// int *iv = malloc(sizeof(int));
	// *iv = 4;
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, iv);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, iii);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, ii);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, i);
	// printf("size: %zu\n", PSG_LINKED_LIST_GET_SIZE_FUNCTION_NAME(int_p)(list));
	// printf("%d\n", *PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(int_p)(list));
	// printf("%d\n", *PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(int_p)(list));
	// printf("%d\n", *PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(int_p)(list));
	// printf("%d\n", *PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(int_p)(list));
	// printf("size: %zu\n", PSG_LINKED_LIST_GET_SIZE_FUNCTION_NAME(int_p)(list));
	// PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(int_p)(list);
	// PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(int_p)(list);
	// PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(int_p)(list);
	// PSG_LINKED_LIST_FREE_FUNCTION_NAME(int_p)(list);
	// free(i);
	// free(ii);
	// free(iii);
	// free(iv);

	// OK
	// struct psg_int_p_linked_list_t *list = psg_int_p_linked_list_new();
	// int *i = malloc(sizeof(int));
	// printf("size: %zu\n", psg_int_p_linked_list_get_size(list));
	// psg_int_p_linked_list_pop_last(list);
	// psg_int_p_linked_list_pop_last(list);
	// printf("size: %zu\n", psg_int_p_linked_list_get_size(list));
	// psg_int_p_linked_list_push_first(list, i);
	// psg_int_p_linked_list_push_first(list, i);
	// printf("size: %zu\n", psg_int_p_linked_list_get_size(list));
	// psg_int_p_linked_list_free(list);
	// free(i);

	// OK
	// PSG_LINKED_LIST_OPAQUE_NAME(int_p) list = PSG_LINKED_LIST_NEW_FUNCTION_NAME(int_p)();
	// int *i = malloc(sizeof(int));
	// *i = 1;
	// int *ii = malloc(sizeof(int));
	// *ii = 2;
	// int *iii = malloc(sizeof(int));
	// *iii = 3;
	// int *iv = malloc(sizeof(int));
	// *iv = 4;

	// //PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, iv);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, iii);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, ii);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, i);

	// printf("%d\n", *PSG_LINKED_LIST_LAST_FUNCTION_NAME(int_p)(list));

	// printf("size: %zu\n", PSG_LINKED_LIST_GET_SIZE_FUNCTION_NAME(int_p)(list));

	// PSG_LINKED_LIST_FREE_FUNCTION_NAME(int_p)(list);
	// free(i);
	// free(ii);
	// free(iii);
	// free(iv);

	// iterator allocation and deallocation test passed for the following cases: empty list, list with items and list equals to null.
	// PSG_LINKED_LIST_OPAQUE_NAME(int_p) list = PSG_LINKED_LIST_NEW_FUNCTION_NAME(int_p)();
	// int *i = malloc(sizeof(int));
	// *i = 1;
	// int *ii = malloc(sizeof(int));
	// *ii = 2;
	// int *iii = malloc(sizeof(int));
	// *iii = 3;
	// int *iv = malloc(sizeof(int));
	// *iv = 4;

	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, iv);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, iii);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, ii);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, i);

	// PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(int_p) it0 = PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(int_p)(0);
	// PSG_LINKED_LIST_ITERATOR_FREE_FUNCTION_NAME(int_p)(it0);

	// PSG_LINKED_LIST_FREE_FUNCTION_NAME(int_p)(list);
	// free(i);
	// free(ii);
	// free(iii);
	// free(iv);

	// flow:
	// iterator is first initialized with a non-empty list: V (returns 1)
	// iterator is last initialized with a non-empty list: V (returns 0)
	// iterator is last initialized with an empty list: V (returns 0)
	// iterator is first initialized with an empty list: V (returns 0)
	// iterator is first initialized with a null list: V (returns 0)
	// iterator is last initialized with a null list: V (returns 0)
	// PSG_LINKED_LIST_OPAQUE_NAME(int_p) list = PSG_LINKED_LIST_NEW_FUNCTION_NAME(int_p)();
	// int *i = malloc(sizeof(int));
	// *i = 1;
	// int *ii = malloc(sizeof(int));
	// *ii = 2;
	// int *iii = malloc(sizeof(int));
	// *iii = 3;
	// int *iv = malloc(sizeof(int));
	// *iv = 4;

	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, iv);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, iii);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, ii);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, i);

	// PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(int_p) it0 = PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(int_p)(list);
	// printf("%d\n", PSG_LINKED_LIST_ITERATOR_IS_FIRST_FUNCTION_NAME(int_p)(it0));
	// printf("%d\n", PSG_LINKED_LIST_ITERATOR_IS_LAST_FUNCTION_NAME(int_p)(it0));
	// printf("%d\n", PSG_LINKED_LIST_ITERATOR_IS_LAST_FUNCTION_NAME(int_p)(PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(int_p)(list)));
	// printf("%d\n", PSG_LINKED_LIST_ITERATOR_IS_FIRST_FUNCTION_NAME(int_p)(PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(int_p)(list)));
	// printf("%d\n", PSG_LINKED_LIST_ITERATOR_IS_FIRST_FUNCTION_NAME(int_p)(0));
	// printf("%d\n", PSG_LINKED_LIST_ITERATOR_IS_LAST_FUNCTION_NAME(int_p)(0));
	// PSG_LINKED_LIST_ITERATOR_FREE_FUNCTION_NAME(int_p)(it0);

	// PSG_LINKED_LIST_FREE_FUNCTION_NAME(int_p)(list);
	// free(i);
	// free(ii);
	// free(iii);
	// free(iv);

	// use cases:
	// iterator next on an empty list: V (do nothing)
	// iterator next on a non-empty list: V (go ahead if the next node is not null or is not the last node)
	// iterator next on a null list: V (do nothing)
	// iterator prev on an empty list: V (do nothing)
	// iterator prev on a non-empty list: V (go behind if the prev node is not null or is not the first node)
	// iterator prev on a null list: V (do nothing)
	// PSG_LINKED_LIST_OPAQUE_NAME(int_p) list = PSG_LINKED_LIST_NEW_FUNCTION_NAME(int_p)();
	// int *i = malloc(sizeof(int));
	// *i = 1;
	// int *ii = malloc(sizeof(int));
	// *ii = 2;
	// int *iii = malloc(sizeof(int));
	// *iii = 3;
	// int *iv = malloc(sizeof(int));
	// *iv = 4;

	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, iv);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, iii);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, ii);
	// PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, i);

	// PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(int_p) it0 = PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(int_p)(list);
	// // PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(0);
	// // PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION_NAME(int_p)(0);
	// // PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	// // PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	// // PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION_NAME(int_p)(it0);
	// // PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION_NAME(int_p)(it0);
	// //PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	// //PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	// //PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	// //PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	// //PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	// //PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	// PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	// PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	// PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	// PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION_NAME(int_p)(it0);
	// PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION_NAME(int_p)(it0);
	// PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION_NAME(int_p)(it0);
	// PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION_NAME(int_p)(it0);
	// PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION_NAME(int_p)(it0);
	// printf("%d\n", *PSG_LINKED_LIST_ITERATOR_GET_ITEM_FUNCTION_NAME(int_p)(it0));
	// PSG_LINKED_LIST_ITERATOR_FREE_FUNCTION_NAME(int_p)(it0);

	// PSG_LINKED_LIST_FREE_FUNCTION_NAME(int_p)(list);
	// free(i);
	// free(ii);
	// free(iii);
	// free(iv);

	//
	PSG_LINKED_LIST_OPAQUE_NAME(int_p) list = PSG_LINKED_LIST_NEW_FUNCTION_NAME(int_p)();
	int *i = malloc(sizeof(int));
	*i = 1;
	int *ii = malloc(sizeof(int));
	*ii = 2;
	int *iii = malloc(sizeof(int));
	*iii = 3;
	int *iv = malloc(sizeof(int));
	*iv = 4;

	PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, iv);
	PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, iii);
	PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, ii);
	PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, i);

	PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(int_p) it0 = PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(int_p)(list);
	PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	while (!PSG_LINKED_LIST_ITERATOR_IS_FIRST_FUNCTION_NAME(int_p)(it0))
	{
		printf("%d\n", PSG_LINKED_LIST_ITERATOR_GET_ITEM_FUNCTION_NAME(int_p)(it0) ? *PSG_LINKED_LIST_ITERATOR_GET_ITEM_FUNCTION_NAME(int_p)(it0) : 0);
		PSG_LINKED_LIST_ITERATOR_PREV_FUNCTION_NAME(int_p)(it0);
	}
	PSG_LINKED_LIST_ITERATOR_FREE_FUNCTION_NAME(int_p)(it0);

	PSG_LINKED_LIST_FREE_FUNCTION_NAME(int_p)(list);
	free(i);
	free(ii);
	free(iii);
	free(iv);

	return 0;
}
