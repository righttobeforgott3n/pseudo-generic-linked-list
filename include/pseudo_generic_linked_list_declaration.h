#ifndef PSEUDO_GENERIC_LINKED_LIST_H
#define PSEUDO_GENERIC_LINKED_LIST_H

#include <stddef.h>

//
#define PSG_LL_STRUCT_T(user_type) \
    struct psg_##user_type##_linked_list_t

//
#define PSG_LL_T(user_type) \
    psg_##user_type##_linked_list

//
#define PSG_LL_TYPEDEF(user_type) \
    typedef PSG_LL_STRUCT_T(user_type) * PSG_LL_T(user_type);

//
#define PSG_LL_NEW(user_type) \
    psg_##user_type##_linked_list_new

//
#define PSG_LL_NEW_PROTO(user_type, item_type) \
    PSG_LL_T(user_type)                        \
    PSG_LL_NEW(user_type)(void)

//
#define PSG_LL_FREE(user_type) \
    psg_##user_type##_linked_list_free

//
#define PSG_LL_FREE_PROTO(user_type, item_type) \
    void PSG_LL_FREE(user_type)(PSG_LL_T(user_type) self)

//
#define PSG_LL_GET_SIZE(user_type) \
    psg_##user_type##_linked_list_get_size

//
#define PSG_LL_GET_SIZE_PROTO(user_type, item_type) \
    size_t PSG_LL_GET_SIZE(user_type)(PSG_LL_T(user_type) self)

//
#define PSG_LL_INSERT_FIRST(user_type) \
    psg_##user_type##_linked_list_insert_first

//
#define PSG_LL_INSERT_FIRST_PROTO(user_type, item_type) \
    void PSG_LL_INSERT_FIRST(user_type)(PSG_LL_T(user_type) self, item_type item)

//
#define PSG_LL_REMOVE_LAST(user_type) \
    psg_##user_type##_linked_list_remove_last

//
#define PSG_LL_REMOVE_LAST_PROTO(user_type, item_type) \
    item_type PSG_LL_REMOVE_LAST(user_type)(PSG_LL_T(user_type) self)

//
#define PSG_LL_ITERATOR_STRUCT_T(user_type) \
    struct psg_##user_type##_linked_list_iterator_t

//
#define PSG_LL_ITERATOR_T(user_type) \
    psg_##user_type##_linked_list_iterator

//
#define PSG_LL_ITERATOR_TYPEDEF(user_type) \
    typedef PSG_LL_ITERATOR_STRUCT_T(user_type) * PSG_LL_ITERATOR_T(user_type);

//
#define PSG_LL_ITERATOR_NEW(user_type) \
    psg_##user_type##_linked_list_iterator_new

//
#define PSG_LL_ITERATOR_NEW_PROTO(user_type) \
    PSG_LL_ITERATOR_T(user_type)             \
    PSG_LL_ITERATOR_NEW(user_type)(PSG_LL_T(user_type) iterable)

//
#define PSG_LL_ITERATOR_FREE(user_type) \
    psg_##user_type##_linked_list_iterator_free

//
#define PSG_LL_ITERATOR_FREE_PROTO(user_type) \
    void PSG_LL_ITERATOR_FREE(user_type)(PSG_LL_ITERATOR_T(user_type) self)

//
#define PSG_LL_ITERATOR_IS_FIRST(user_type) \
    psg_##user_type##_linked_list_iterator_is_first

//
#define PSG_LL_ITERATOR_IS_FIRST_PROTO(user_type) \
    int PSG_LL_ITERATOR_IS_FIRST(user_type)(PSG_LL_ITERATOR_T(user_type) self)

//
#define PSG_LL_ITERATOR_IS_EQUAL(user_type) \
    psg_##user_type##_linked_list_iterator_is_equal

//
#define PSG_LL_ITERATOR_IS_EQUAL_PROTO(user_type) \
    int PSG_LL_ITERATOR_IS_EQUAL(user_type)(PSG_LL_ITERATOR_T(user_type) self, PSG_LL_ITERATOR_T(user_type) to_compare)

//
#define PSG_LL_ITERATOR_IS_LAST(user_type) \
    psg_##user_type##_linked_list_iterator_is_last

//
#define PSG_LL_ITERATOR_IS_LAST_PROTO(user_type) \
    int PSG_LL_ITERATOR_IS_LAST(user_type)(PSG_LL_ITERATOR_T(user_type) self)

//
#define PSG_LL_ITERATOR_NEXT(user_type) \
    psg_##user_type##_linked_list_iterator_next

//
#define PSG_LL_ITERATOR_NEXT_PROTO(user_type) \
    void PSG_LL_ITERATOR_NEXT(user_type)(PSG_LL_ITERATOR_T(user_type) self)

//
#define PSG_LL_ITERATOR_PREV(user_type) \
    psg_##user_type##_linked_list_iterator_prev

//
#define PSG_LL_ITERATOR_PREV_PROTO(user_type) \
    void PSG_LL_ITERATOR_PREV(user_type)(PSG_LL_ITERATOR_T(user_type) self)

//
#define PSG_LL_ITERATOR_GET_ITEM(user_type) \
    psg_##user_type##_linked_list_iterator_get_item

//
#define PSG_LL_ITERATOR_GET_ITEM_PROTO(user_type, item_type) \
    item_type PSG_LL_ITERATOR_GET_ITEM(user_type)(PSG_LL_ITERATOR_T(user_type) self)

//
#define PSG_LL_ITERATOR_SET_ITEM(user_type) \
    psg_##user_type##_linked_list_iterator_set_item

//
#define PSG_LL_ITERATOR_SET_ITEM_PROTO(user_type, item_type) \
    void PSG_LL_ITERATOR_SET_ITEM(user_type)(PSG_LL_ITERATOR_T(user_type) self, item_type item)

#define PSG_LINKED_LIST_DECLARATION_MOD(user_type, item_type) \
    PSG_LL_TYPEDEF(user_type)                                 \
    PSG_LL_NEW_PROTO(user_type, item_type);                   \
    PSG_LL_FREE_PROTO(user_type, item_type);                  \
    PSG_LL_GET_SIZE_PROTO(user_type, item_type);              \
    PSG_LL_INSERT_FIRST_PROTO(user_type, item_type);          \
    PSG_LL_REMOVE_LAST_PROTO(user_type, item_type);           \
    PSG_LL_ITERATOR_TYPEDEF(user_type)                        \
    PSG_LL_ITERATOR_NEW_PROTO(user_type);                     \
    PSG_LL_ITERATOR_FREE_PROTO(user_type);                    \
    PSG_LL_ITERATOR_IS_EQUAL_PROTO(user_type);                \
    PSG_LL_ITERATOR_IS_FIRST_PROTO(user_type);                \
    PSG_LL_ITERATOR_IS_LAST_PROTO(user_type);                 \
    PSG_LL_ITERATOR_NEXT_PROTO(user_type);                    \
    PSG_LL_ITERATOR_PREV_PROTO(user_type);                    \
    PSG_LL_ITERATOR_GET_ITEM_PROTO(user_type, item_type);     \
    PSG_LL_ITERATOR_SET_ITEM_PROTO(user_type, item_type);

#endif
