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

	// ...
	PSG_LINKED_LIST_OPAQUE_NAME(int_p) list = PSG_LINKED_LIST_NEW_FUNCTION_NAME(int_p)();
	int* i = malloc(sizeof(int));
	if (i) *i = 1;
	int* ii = malloc(sizeof(int));
	if (ii) *ii = 2;
	int* iii = malloc(sizeof(int));
	if (iii) *iii = 3;
	int* iv = (int*)malloc(sizeof(int));
	if (iv) *iv = 4;
	PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, iv);
	PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, iii);
	PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, ii);
	PSG_LINKED_LIST_PUSH_FIRST_FUNCTION_NAME(int_p)(list, i);

	PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(int_p) it0 = PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(int_p)(list);
	PSG_LINKED_LIST_ITERATOR_OPAQUE_NAME(int_p) it1 = PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(int_p)(list);

	/*while (!PSG_LINKED_LIST_ITERATOR_IS_LAST_FUNCTION_NAME(int_p)(it0))
	{
		printf("%d\n", *PSG_LINKED_LIST_ITERATOR_GET_ITEM_FUNCTION_NAME(int_p)(it0));
		PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	}*/

	PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it0);
	PSG_LINKED_LIST_ITERATOR_NEXT_FUNCTION_NAME(int_p)(it1);

	if (PSG_LINKED_LIST_ITERATOR_EQUALS_FUNCTION_NAME(int_p)(it0, it1))
	{
		printf("the iterators are equal.\n");
	}
	else
	{
		printf("the iterators are not equal.\n");
	}

	PSG_LINKED_LIST_ITERATOR_FREE_FUNCTION_NAME(int_p)(it0);
	PSG_LINKED_LIST_ITERATOR_FREE_FUNCTION_NAME(int_p)(it1);

	free(i);
	free(ii);
	free(iii);
	free(iv);
	PSG_LINKED_LIST_FREE_FUNCTION_NAME(int_p)(list);

	return 0;
}
