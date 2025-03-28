#include "int_p_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

void iterator_test(void)
{

	int b;
	size_t s;
	char *smesg = NULL;

	// TEST 0
	PSG_LL_T(int_p)
	list;
	PSG_LL_NEW(int_p)(&list);
	PSG_LL_GET_SIZE(int_p)(list, &s);
	b = 0 == s;
	printf("size: %zu -> TEST 0 %s \n", s, b ? "PASSED" : "FAILED"); // @todo make it reusable
	if (!b)
	{
		PSG_LL_FREE(int_p)(list);
		return;
	}

	// TEST 1
	int *i = malloc(sizeof(int));
	*i = 1;
	int *ii = malloc(sizeof(int));
	*ii = 2;
	int *iii = malloc(sizeof(int));
	*iii = 3;
	int *iv = malloc(sizeof(int));
	*iv = 4;
	PSG_LL_INSERT_FIRST(int_p)(list, iv);
	PSG_LL_INSERT_FIRST(int_p)(list, iii);
	PSG_LL_INSERT_FIRST(int_p)(list, ii);
	PSG_LL_INSERT_FIRST(int_p)(list, i);
	PSG_LL_GET_SIZE(int_p)(list, &s);
	b = 4 == s;
	printf("size: %zu -> TEST 1 %s\n", s, b ? "PASSED" : "FAILED");
	if (!b)
	{
		PSG_LL_FREE(int_p)(list);
		free(i);
		free(ii);
		free(iii);
		free(iv);
		return;
	}

	// TEST 2
	size_t index = 0;
	int values[s];
	PSG_LL_ITERATOR_T(int_p)
	it0;
	PSG_LL_ITERATOR_NEW(int_p)(list, &it0);
	while (!PSG_LL_ITERATOR_IS_LAST(int_p)(it0))
	{
		// printf("index: %zu, value: %d\n", index, *PSG_LL_ITERATOR_GET_ITEM(int_p)(it0));
		int *t;
		PSG_LL_ITERATOR_GET_ITEM(int_p)(it0, &t);
		*(values + index++) = *t;
		PSG_LL_ITERATOR_NEXT(int_p)(it0);
	}
	if (*(values + --index) == 4 && *(values + --index) == 3 && *(values + --index) == 2 && *(values + --index) == 1)
	{
		smesg = "PASSED";
	}
	else
	{
		smesg = "FAILED";
		b = 0;
	}
	printf("values: [%d, %d, %d, %d] -> TEST %s %s\n", *(values), *(values + 1), *(values + 2), *(values + 3), "2", smesg);
	if (!b)
	{
		PSG_LL_ITERATOR_FREE(int_p)(it0);
		PSG_LL_FREE(int_p)(list);
		free(i);
		free(ii);
		free(iii);
		free(iv);
		return;
	}

	// TEST 3
	PSG_LL_ITERATOR_NEXT(int_p)(it0);
	int *v = NULL;
	PSG_LL_ITERATOR_GET_ITEM(int_p)(it0, &v);
	b = PSG_LL_ITERATOR_IS_LAST(int_p)(it0);
	printf("value: %d, index: %s -> TEST %s %s\n", v ? *v : 0, b ? "LAST" : "NOT_LAST", "3", b ? "PASSED" : "FAILED");
	if (!b)
	{
		PSG_LL_ITERATOR_FREE(int_p)(it0);
		PSG_LL_FREE(int_p)(list);
		free(i);
		free(ii);
		free(iii);
		free(iv);
		return;
	}

	// TEST 4
	index = s;
	PSG_LL_ITERATOR_PREV(int_p)(it0);
	while (!PSG_LL_ITERATOR_IS_FIRST(int_p)(it0))
	{
		// printf("index: %zu, value: %d\n", index, *PSG_LL_ITERATOR_GET_ITEM(int_p)(it0));
		int *t;
		PSG_LL_ITERATOR_GET_ITEM(int_p)(it0, &t);
		*(values + --index) = *t;
		PSG_LL_ITERATOR_PREV(int_p)(it0);
	}
	index = s;
	if (*(values + --index) == 4 && *(values + --index) == 3 && *(values + --index) == 2 && *(values + --index) == 1)
	{
		smesg = "PASSED";
	}
	else
	{
		smesg = "FAILED";
		b = 0;
	}
	printf("values: [%d, %d, %d, %d] -> TEST %s %s\n", *(values), *(values + 1), *(values + 2), *(values + 3), "4", smesg);
	if (!b)
	{
		PSG_LL_ITERATOR_FREE(int_p)(it0);
		PSG_LL_FREE(int_p)(list);
		free(i);
		free(ii);
		free(iii);
		free(iv);
		return;
	}

	// TEST 5
	PSG_LL_ITERATOR_PREV(int_p)(it0);
	PSG_LL_ITERATOR_GET_ITEM(int_p)(it0, &v);
	b = PSG_LL_ITERATOR_IS_FIRST(int_p)(it0);
	printf("value: %d, index: %s -> TEST %s %s\n", v ? *v : 0, b ? "FIRST" : "NOT_FIRST", "5", b ? "PASSED" : "FAILED");
	if (!b)
	{
		PSG_LL_ITERATOR_FREE(int_p)(it0);
		PSG_LL_FREE(int_p)(list);
		free(i);
		free(ii);
		free(iii);
		free(iv);
		return;
	}

	// TEST 6
	PSG_LL_ITERATOR_NEXT(int_p)(it0);
	int sixtynine = 69;
	PSG_LL_ITERATOR_SET_ITEM(int_p)(it0, &sixtynine);
	PSG_LL_ITERATOR_GET_ITEM(int_p)(it0, &v);
	printf("value: %d, index: %d -> TEST %s %s\n", *v, 0, "6", (b = (*v == sixtynine)) ? "PASSED" : "FAILED");
	if (!b)
	{
		PSG_LL_ITERATOR_FREE(int_p)(it0);
		PSG_LL_FREE(int_p)(list);
		free(i);
		free(ii);
		free(iii);
		free(iv);
		return;
	}

	PSG_LL_ITERATOR_FREE(int_p)(it0);
	PSG_LL_FREE(int_p)(list);
	free(i);
	free(ii);
	free(iii);
	free(iv);
}

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
	// PSG_LL_T(int_p) list = PSG_LL_NEW(int_p)();
	// int *i = malloc(sizeof(int));
	// *i = 1;
	// int *ii = malloc(sizeof(int));
	// *ii = 2;
	// int *iii = malloc(sizeof(int));
	// *iii = 3;
	// int *iv = malloc(sizeof(int));
	// *iv = 4;
	// PSG_LL_INSERT_FIRST(int_p)(list, iv);
	// PSG_LL_INSERT_FIRST(int_p)(list, iii);
	// PSG_LL_INSERT_FIRST(int_p)(list, ii);
	// PSG_LL_INSERT_FIRST(int_p)(list, i);
	// printf("size: %zu\n", PSG_LINKED_LIST_GET_SIZE_FUNCTION_NAME(int_p)(list));
	// printf("%d\n", *PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(int_p)(list));
	// printf("%d\n", *PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(int_p)(list));
	// printf("%d\n", *PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(int_p)(list));
	// printf("%d\n", *PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(int_p)(list));
	// printf("size: %zu\n", PSG_LINKED_LIST_GET_SIZE_FUNCTION_NAME(int_p)(list));
	// PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(int_p)(list);
	// PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(int_p)(list);
	// PSG_LINKED_LIST_POP_LAST_FUNCTION_NAME(int_p)(list);
	// PSG_LL_FREE(int_p)(list);
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
	// PSG_LINKED_LIST_OPAQUE_NAME(int_p) list = PSG_LL_NEW(int_p)();
	// int *i = malloc(sizeof(int));
	// *i = 1;
	// int *ii = malloc(sizeof(int));
	// *ii = 2;
	// int *iii = malloc(sizeof(int));
	// *iii = 3;
	// int *iv = malloc(sizeof(int));
	// *iv = 4;

	// //PSG_LL_INSERT_FIRST(int_p)(list, iv);
	// PSG_LL_INSERT_FIRST(int_p)(list, iii);
	// PSG_LL_INSERT_FIRST(int_p)(list, ii);
	// PSG_LL_INSERT_FIRST(int_p)(list, i);

	// printf("%d\n", *PSG_LINKED_LIST_LAST_FUNCTION_NAME(int_p)(list));

	// printf("size: %zu\n", PSG_LINKED_LIST_GET_SIZE_FUNCTION_NAME(int_p)(list));

	// PSG_LL_FREE(int_p)(list);
	// free(i);
	// free(ii);
	// free(iii);
	// free(iv);

	// iterator allocation and deallocation test passed for the following cases: empty list, list with items and list equals to null.
	// PSG_LINKED_LIST_OPAQUE_NAME(int_p) list = PSG_LL_NEW(int_p)();
	// int *i = malloc(sizeof(int));
	// *i = 1;
	// int *ii = malloc(sizeof(int));
	// *ii = 2;
	// int *iii = malloc(sizeof(int));
	// *iii = 3;
	// int *iv = malloc(sizeof(int));
	// *iv = 4;

	// PSG_LL_INSERT_FIRST(int_p)(list, iv);
	// PSG_LL_INSERT_FIRST(int_p)(list, iii);
	// PSG_LL_INSERT_FIRST(int_p)(list, ii);
	// PSG_LL_INSERT_FIRST(int_p)(list, i);

	// PSG_LL_ITERATOR_T(int_p) it0 = PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(int_p)(0);
	// PSG_LL_ITERATOR_FREE(int_p)(it0);

	// LEE(int_p)(list);
	// free(ii);
	// free(iii);
	// free(iv);

	//
	// iterator is firstith a non-empty list: V (returns 1)
	// itera t initialized ty list: V (returns 0)
	// iterator is last initialized with an empty list: V (returns 0)
	// iterator is first initialized with an empty list: V (returns 0)
	// iterator is first initialized with a null list: V (returns 0)
	// iterator is last initialized with a null list: V (returns 0)
	// PSG_LINKED_LIST_OPAQUE_NAME(int_p) list = PSG_LL_NEW(int_p)();
	// int *i = malloc(sizeof(int));
	// *i = 1;
	// int *ii = malloc(sizeof(int));
	// *ii = 2;
	// int *iii = malloc(sizeof(int));
	// *iii = 3;
	// int *iv = malloc(sizeof(int));
	// *iv = 4;

	// PSG_LL_INSERT_FIRST(int_p)(list, iv);
	// PSG_LL_INSERT_FIRST(int_p)(list, iii);
	// PSG_LL_INSERT_FIRST(int_p)(list, ii);
	// PSG_LL_INSERT_FIRST(int_p)(list, i);

	// PSG_LL_ITERATOR_T(int_p) it0 = PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(int_p)(list);
	// printf("%d\n", PSG_LL_ITERATOR_IS__NAME(int_p)(it0));
	// printf("%d\n", PSG_LL_ITERATOR_IS_LAST(int_p)(it0));
	// printf("%d\n", PSG_LL_ITERATOR_IS_LAST(int_p)(PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(int_p)(list)));
	// printf("%d\n", PSG_LL_ITERATOR_IS_FIRST(int_p)(PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(int_p)(list)));
	// printf("%d\n", PSG_LL_ITERATOR_IS_FIRST(int_p)(0));
	// printf("%d\n", PSG_LL_ITERATOR_IS_LAME(int_p)(0));
	// PSG_LL_ITERATOR_FREE(int_p)(it0);

	// PSG_LL_FREE(int_p)(list);
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
	// PSG_LINKED_LIST_OPAQUE_NAME(int_p) list = PSG_LL_NEW(int_p)();
	// int *i = malloc(sizeof(int));
	// *i = 1;
	// int *ii = malloc(sizeof(int));
	// *ii = 2;
	// int *iii = malloc(sizeof(int));
	// *iii = 3;
	// int *iv = malloc(sizeof(int));
	// *iv = 4;

	// PSG_LL_INSERT_FIRST(int_p)(list, iv);
	// PSG_LL_INSERT_FIRST(int_p)(list, iii);
	// PSG_LL_INSERT_FIRST(int_p)(list, ii);
	// PSG_LL_INSERT_FIRST(int_p)(list, i);

	// PSG_LL_ITERATOR_T(int_p) it0 = PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(int_p)(list);
	// // PSG_LL_ITERATOR_NEXE(int_p)(0);
	// // PSG_LL_ITERATOR_PREV_FUt_p)(0);
	// // PSG_LL_ITERATOR_NEXT(int_p)(it0);
	// // PSG_LL_ITERATOR_NEXT(int_p)(it0);
	// // PSG_LL_ITERATOR_PREV_FUN_p)(it0);
	// // PSG_LL_ITERATOR_PREV(int_p)(it0);
	// //PSG_LL_ITERATOR_NEXT(int_p)(it0);
	// //PSG_LL_ITERATOR_NEXT(int_p)(it0);
	// //PSG_LL_ITERATOR_NEXT(int_p)(it0);
	// //PSG_LL_ITERATOR_NEXT(int_p)(it0);
	// //PSG_LL_ITERATOR_NEXT(int_p)(it0);
	// //PSG_LL_ITERATOR_NEXT(int_p)(it0);
	// PSG_LL_ITERATOR_NEXT(int_p)(it0);
	// PSG_LL_ITERATOR_NEXT(int_p)(it0);
	// PSG_LL_ITERATOR_NEXT(int_p)(it0);
	// PSG_LL_ITERATOR_PREV(int_p)(it0);
	// PSG_LL_ITERATOR_PREV(int_p)(it0);
	// PSG_LL_ITERATOR_PREV(int_p)(it0);
	// PSG_LL_ITERATOR_PREV(int_p)(it0);
	// PSG_LL_ITERATOR_PREV(int_p)(it0);
	// printf("%d\n", *PSG_LL_ITERATOR_GET_ITEM(int_p)(it0));
	// PSG_LL_ITERATOR_FREE(int_p)(it0);

	// PSG_LL_FREE(int_p)(list);
	// free(i);
	// free(ii);
	// free(iii);
	// free(iv);

	//
	/*
	PSG_LINKED_LIST_OPAQUE_NAME(int_p) list = PSG_LL_NEW(int_p)();
	int *i = malloc(sizeof(int));
	*i = 1;
	int *ii = malloc(sizeof(int));
	*ii = 2;
	int *iii = malloc(sizeof(int));
	*iii = 3;
	int *iv = malloc(sizeof(int));
	*iv = 4;

	PSG_LL_INSERT_FIRST(int_p)(list, iv);
	PSG_LL_INSERT_FIRST(int_p)(list, iii);
	PSG_LL_INSERT_FIRST(int_p)(list, ii);
	PSG_LL_INSERT_FIRST(int_p)(list, i);

	PSG_LL_ITERATOR_T(int_p) it0 = PSG_LINKED_LIST_ITERATOR_NEW_FUNCTION_NAME(int_p)(list);
	PSG_LL_ITERATOR_T(int_p=G_LINKED_LISTFUNCTION_NAME(int_p)(list);
	//PSG_LL_ITERATOR_NEXE(int_p)(it0);
	//L_ITERATOR_NEXT_FUt_p)(it1);
	printf("%d\n", PSG_LINKED_LIST_ITERATOR_IS_EQUAL_FUNCTION_NAME(int_p)(it0, it1));
	PSG_LL_ITERATOR_FREE(int_p)(it0);
	PSG_LL_ITERATOR_FREE_FUN_p)(it1);_FREE(int_p)(li
	free(ii);
	free(iii);
	free(iv);
	*/

	iterator_test();

	return 0;
}
