#include "int_p_linked_list.h"
#include "struct_test_ll.h"
#include <stdlib.h>
#include <stdio.h>

void struct_t_test(void)
{

	PSG_LL_T(test_t)
	struct_ll;
	PSG_LL_NEW(test_t)(&struct_ll);

	struct test_t x = {.x = 0, .y = 0};
	PSG_LL_INSERT_FIRST(test_t)(struct_ll, x);

	PSG_LL_FREE(test_t)(struct_ll);
}

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

	iterator_test();
	struct_t_test();

	return 0;
}
