#include "pseudo_generic_linked_list_declaration.h"
#include <stdlib.h>

//
#define PSG_NODE_STRUCT_T(user_type) \
    struct psg_##user_type##_node_t

//
#define PSG_NODE_STRUCT(user_type, item_type)       \
    PSG_NODE_STRUCT_T(user_type)                    \
    {                                               \
        item_type item;                             \
        PSG_NODE_STRUCT_T(user_type) * prev, *next; \
    }

//
#define PSG_NODE_NEW(user_type) \
    psg_##user_type##_node_new

//
#define PSG_NODE_NEW_F(user_type, item_type)                                                                                                    \
    void PSG_NODE_NEW(user_type)(PSG_NODE_STRUCT_T(user_type) * prev, PSG_NODE_STRUCT_T(user_type) * next, PSG_NODE_STRUCT_T(user_type) * *out) \
    {                                                                                                                                           \
        PSG_NODE_STRUCT_T(user_type) *self = (PSG_NODE_STRUCT_T(user_type) *)malloc(sizeof(PSG_NODE_STRUCT_T(user_type)));                      \
        if (self)                                                                                                                               \
        {                                                                                                                                       \
            self->prev = prev;                                                                                                                  \
            self->next = next;                                                                                                                  \
            *out = self;                                                                                                                        \
        }                                                                                                                                       \
    }

// @todo define a node_set_item method to avoid item initialization (actually it is a problem in case of item_type defined as struct)
//
#define PSG_NODE_SET_ITEM(user_type) \
    psg_##user_type##_node_set_item

//
#define PSG_NODE_SET_ITEM_F(user_type, item_type)                                          \
    void PSG_NODE_SET_ITEM(user_type)(PSG_NODE_STRUCT_T(user_type) * self, item_type item) \
    {                                                                                      \
        if (self)                                                                          \
        {                                                                                  \
            self->item = item;                                                             \
        }                                                                                  \
    }

//
#define PSG_NODE_FREE(user_type) \
    psg_##user_type##_node_free

//
#define PSG_NODE_FREE_F(user_type, item_type)                          \
    void PSG_NODE_FREE(user_type)(PSG_NODE_STRUCT_T(user_type) * self) \
    {                                                                  \
        if (self)                                                      \
        {                                                              \
            free(self);                                                \
        }                                                              \
    }

//
#define PSG_LL_STRUCT(user_type, item_type)          \
    PSG_LL_STRUCT_T(user_type)                       \
    {                                                \
        PSG_NODE_STRUCT_T(user_type) * first, *last; \
        size_t size;                                 \
    }

//
#define PSG_LL_NEW_F(user_type, item_type)                                                                           \
    PSG_LL_NEW_PROTO(user_type, item_type)                                                                           \
    {                                                                                                                \
        PSG_LL_STRUCT_T(user_type) *self = (PSG_LL_STRUCT_T(user_type) *)malloc(sizeof(PSG_LL_STRUCT_T(user_type))); \
        if (self)                                                                                                    \
        {                                                                                                            \
            PSG_NODE_NEW(user_type)(0, 0, &self->first);                                                             \
            PSG_NODE_NEW(user_type)(0, 0, &self->last);                                                              \
            self->first->next = self->last;                                                                          \
            self->last->prev = self->first;                                                                          \
            self->last->next = self->last;                                                                           \
            self->first->prev = self->first;                                                                         \
            self->size = 0;                                                                                          \
            *out = self;                                                                                             \
        }                                                                                                            \
    }

//
#define PSG_LL_FREE_F(user_type, item_type)                         \
    PSG_LL_FREE_PROTO(user_type, item_type)                         \
    {                                                               \
        if (self)                                                   \
        {                                                           \
            PSG_NODE_STRUCT_T(user_type) *node = self->first->next; \
            PSG_NODE_STRUCT_T(user_type) *tmp = 0;                  \
            while (node && node != self->last)                      \
            {                                                       \
                tmp = node;                                         \
                node = node->next;                                  \
                PSG_NODE_FREE(user_type)(tmp);                      \
            }                                                       \
            PSG_NODE_FREE(user_type)(self->first);                  \
            PSG_NODE_FREE(user_type)(self->last);                   \
            free(self);                                             \
        }                                                           \
    }

#define PSG_LL_GET_SIZE_F(user_type, item_type) \
    PSG_LL_GET_SIZE_PROTO(user_type, item_type) \
    {                                           \
        if (self)                               \
        {                                       \
            *out = self->size;                  \
        }                                       \
    }

//
#define PSG_LL_INSERT_FIRST_F(user_type, item_type)                         \
    PSG_LL_INSERT_FIRST_PROTO(user_type, item_type)                         \
    {                                                                       \
        if (self)                                                           \
        {                                                                   \
            PSG_NODE_STRUCT_T(user_type) * node;                            \
            PSG_NODE_NEW(user_type)(self->first, self->first->next, &node); \
            PSG_NODE_SET_ITEM(user_type)(node, item);                       \
            self->first->next->prev = node;                                 \
            self->first->next = node;                                       \
            self->size++;                                                   \
        }                                                                   \
    }

//
#define PSG_LL_REMOVE_LAST_F(user_type, item_type)                \
    PSG_LL_REMOVE_LAST_PROTO(user_type, item_type)                \
    {                                                             \
        if (self && self->size)                                   \
        {                                                         \
            PSG_NODE_STRUCT_T(user_type) *tmp = self->last->prev; \
            *out = tmp->item;                                     \
            self->last->prev = tmp->prev;                         \
            tmp->prev->next = self->last;                         \
            PSG_NODE_FREE(user_type)(tmp);                        \
            self->size--;                                         \
        }                                                         \
    }

//
#define PSG_LL_ITERATOR_STRUCT(user_type)    \
    PSG_LL_ITERATOR_STRUCT_T(user_type)      \
    {                                        \
        PSG_LL_STRUCT_T(user_type)           \
        const *iterable;                     \
        PSG_NODE_STRUCT_T(user_type) * curr; \
    };

//
#define PSG_LL_ITERATOR_NEW_F(user_type)                                                                                               \
    PSG_LL_ITERATOR_NEW_PROTO(user_type)                                                                                               \
    {                                                                                                                                  \
        if (iterable)                                                                                                                  \
        {                                                                                                                              \
            PSG_LL_ITERATOR_STRUCT_T(user_type) *it = 0;                                                                               \
            if ((it = malloc(sizeof(PSG_LL_ITERATOR_STRUCT_T(user_type)))))                                                            \
            {                                                                                                                          \
                *it = (PSG_LL_ITERATOR_STRUCT_T(user_type)){.iterable = iterable, .curr = iterable->size ? iterable->first->next : 0}; \
                *out = it;                                                                                                             \
            }                                                                                                                          \
        }                                                                                                                              \
    }

//
#define PSG_LL_ITERATOR_FREE_F(user_type) \
    PSG_LL_ITERATOR_FREE_PROTO(user_type) \
    {                                     \
        if (self)                         \
        {                                 \
            free(self);                   \
        }                                 \
    }

//
#define PSG_LL_ITERATOR_IS_EQUAL_F(user_type)                     \
    PSG_LL_ITERATOR_IS_EQUAL_PROTO(user_type)                     \
    {                                                             \
        if (self && self->curr && to_compare && to_compare->curr) \
        {                                                         \
            if (self->curr == to_compare->curr)                   \
            {                                                     \
                return 1;                                         \
            }                                                     \
            else                                                  \
            {                                                     \
                return 0;                                         \
            }                                                     \
        }                                                         \
        return 0;                                                 \
    }

//
#define PSG_LL_ITERATOR_IS_FIRST_F(user_type)                                            \
    PSG_LL_ITERATOR_IS_FIRST_PROTO(user_type)                                            \
    {                                                                                    \
        if (self && self->curr && self->iterable && self->iterable->first == self->curr) \
        {                                                                                \
            return 1;                                                                    \
        }                                                                                \
        else                                                                             \
        {                                                                                \
            return 0;                                                                    \
        }                                                                                \
    }

//
#define PSG_LL_ITERATOR_IS_LAST_F(user_type)                                            \
    PSG_LL_ITERATOR_IS_LAST_PROTO(user_type)                                            \
    {                                                                                   \
        if (self && self->curr && self->iterable && self->iterable->last == self->curr) \
        {                                                                               \
            return 1;                                                                   \
        }                                                                               \
        else                                                                            \
        {                                                                               \
            return 0;                                                                   \
        }                                                                               \
    }

//
#define PSG_LL_ITERATOR_NEXT_F(user_type)           \
    PSG_LL_ITERATOR_NEXT_PROTO(user_type)           \
    {                                               \
        if (self && self->curr && self->curr->next) \
        {                                           \
            self->curr = self->curr->next;          \
        }                                           \
    }

//
#define PSG_LL_ITERATOR_PREV_F(user_type)           \
    PSG_LL_ITERATOR_PREV_PROTO(user_type)           \
    {                                               \
        if (self && self->curr && self->curr->prev) \
        {                                           \
            self->curr = self->curr->prev;          \
        }                                           \
    }

//
#define PSG_LL_ITERATOR_GET_ITEM_F(user_type, item_type)                                                     \
    PSG_LL_ITERATOR_GET_ITEM_PROTO(user_type, item_type)                                                     \
    {                                                                                                        \
        if (self && self->curr && self->curr != self->iterable->first && self->curr != self->iterable->last) \
        {                                                                                                    \
            *out = self->curr->item;                                                                         \
        }                                                                                                    \
    }

//
#define PSG_LL_ITERATOR_SET_ITEM_F(user_type, item_type)                                                     \
    PSG_LL_ITERATOR_SET_ITEM_PROTO(user_type, item_type)                                                     \
    {                                                                                                        \
        if (self && self->curr && self->curr != self->iterable->first && self->curr != self->iterable->last) \
        {                                                                                                    \
            self->curr->item = item;                                                                         \
        }                                                                                                    \
    }

//
#define PSG_LINKED_LIST_DEFINITION_MOD(user_type, item_type) \
    PSG_NODE_STRUCT(user_type, item_type);                   \
    PSG_NODE_NEW_F(user_type, item_type)                     \
    PSG_NODE_SET_ITEM_F(user_type, item_type)                \
    PSG_NODE_FREE_F(user_type, item_type)                    \
    PSG_LL_STRUCT(user_type, item_type);                     \
    PSG_LL_NEW_F(user_type, item_type)                       \
    PSG_LL_FREE_F(user_type, item_type)                      \
    PSG_LL_GET_SIZE_F(user_type, item_type)                  \
    PSG_LL_INSERT_FIRST_F(user_type, item_type)              \
    PSG_LL_REMOVE_LAST_F(user_type, item_type)               \
    PSG_LL_ITERATOR_STRUCT(user_type)                        \
    PSG_LL_ITERATOR_NEW_F(user_type)                         \
    PSG_LL_ITERATOR_FREE_F(user_type)                        \
    PSG_LL_ITERATOR_IS_EQUAL_F(user_type)                    \
    PSG_LL_ITERATOR_IS_FIRST_F(user_type)                    \
    PSG_LL_ITERATOR_IS_LAST_F(user_type)                     \
    PSG_LL_ITERATOR_NEXT_F(user_type)                        \
    PSG_LL_ITERATOR_PREV_F(user_type)                        \
    PSG_LL_ITERATOR_GET_ITEM_F(user_type, item_type)         \
    PSG_LL_ITERATOR_SET_ITEM_F(user_type, item_type)
