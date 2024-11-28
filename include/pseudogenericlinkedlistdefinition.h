#ifndef PSEUDOGENERICLINKEDLISTDEFINITION_H
#define PSEUDOGENERICLINKEDLISTDEFINITION_H

#include <stdlib.h>
#include "pseudogenericlinkedlistdeclaration.h"

// ******************* start node section (internal/private to this file) *******************

#define NODE_T(user_type) \
    node_##user_type

#define DEFINE_NODE_TYPE(user_type, item_type) \
    struct NODE_T(user_type)                   \
    {                                          \
        item_type item;                        \
        struct NODE_T(user_type) * next;       \
    }

#define CALLOC_NODE_FUNCTION_NAME(user_type) \
    node_##user_type##_allocate

#define DEFINE_CALLOC_NODE(user_type)                                                   \
    struct NODE_T(user_type) * CALLOC_NODE_FUNCTION_NAME(user_type)(void)               \
    {                                                                                   \
        return (struct NODE_T(user_type) *)calloc(1, sizeof(struct NODE_T(user_type))); \
    }

#define FREE_NODE_FUNCTION_NAME(user_type) \
    node_##user_type##_free

#define DEFINE_FREE_NODE(user_type)                                          \
    void FREE_NODE_FUNCTION_NAME(user_type)(struct NODE_T(user_type) * self) \
    {                                                                        \
        if (self)                                                            \
            free(self);                                                      \
    }

#define NEW_NODE_FUNCTION_NAME(user_type) \
    node_##user_type##_new

#define DEFINE_NEW_NODE(user_type, item_type)                                                                     \
    struct NODE_T(user_type) * NEW_NODE_FUNCTION_NAME(user_type)(item_type item, struct NODE_T(user_type) * next) \
    {                                                                                                             \
        struct NODE_T(user_type) *new_node = CALLOC_NODE_FUNCTION_NAME(user_type)();                              \
        if (new_node)                                                                                             \
        {                                                                                                         \
            new_node->item = item;                                                                                \
            new_node->next = next;                                                                                \
        }                                                                                                         \
        return new_node;                                                                                          \
    }

// ******************* end node section *******************

// ******************* start linked list section *******************

#define DEFINE_LINKEDLIST_TYPE(user_type, item_type)   \
    LINKEDLIST_STRUCT_NAME(user_type)                  \
    {                                                  \
        DEFINE_NODE_TYPE(user_type, item_type) * head; \
        unsigned int size;                             \
    }

#define DEFINE_LINKEDLIST_SIZE(user_type, item_type) \
    LINKEDLIST_SIZE_FUNCTION_PROTO(user_type)        \
    {                                                \
        return self ? self->size : 0;                \
    }

#define CALLOC_LINKEDLIST_FUNCTION_NAME(user_type) \
    linked_list_##user_type##_allocate

#define CALLOC_LINKEDLIST_FUNCTION_PROTO(user_type) \
    LINKEDLIST_OPAQUE_NAME(user_type)               \
    CALLOC_LINKEDLIST_FUNCTION_NAME(user_type)      \
    (void)

#define DEFINE_CALLOC_LINKEDLIST(user_type)                                                             \
    CALLOC_LINKEDLIST_FUNCTION_PROTO(user_type)                                                         \
    {                                                                                                   \
        return (LINKEDLIST_OPAQUE_NAME(user_type))calloc(1, sizeof(LINKEDLIST_STRUCT_NAME(user_type))); \
    }

#define DEFINE_FREE_LINKEDLIST(user_type)                                                                \
    FREE_LINKEDLIST_FUNCTION_PROTO(user_type)                                                            \
    {                                                                                                    \
        if (self)                                                                                        \
        {                                                                                                \
            for (struct NODE_T(user_type) *current_node = (void *)0; (current_node = self->head->next);) \
            {                                                                                            \
                self->head->next = current_node->next;                                                   \
                FREE_NODE_FUNCTION_NAME(user_type)                                                       \
                (current_node);                                                                          \
            }                                                                                            \
            FREE_NODE_FUNCTION_NAME(user_type)(self->head);                                                                                \
            free(self);                                                                                  \
        }                                                                                                \
    }

#define DEFINE_NEW_LINKEDLIST(user_type, item_type)                                                        \
    NEW_LINKEDLIST_FUNCTION_PROTO(user_type)                                                               \
    {                                                                                                      \
        LINKEDLIST_STRUCT_NAME(user_type) *new_linked_list = CALLOC_LINKEDLIST_FUNCTION_NAME(user_type)(); \
        if (new_linked_list)                                                                               \
        {                                                                                                  \
            new_linked_list->head = NEW_NODE_FUNCTION_NAME(user_type)(0, 0);                               \
            new_linked_list->size = 0;                                                                     \
        }                                                                                                  \
        return new_linked_list;                                                                            \
    }

#define ADD_FIRST_LINKEDLIST_FUNCTION_NAME(user_type) \
    linked_list_##user_type##_add_first

#define DEFINE_ADD_FIRST_LINKEDLIST(user_type, item_type)                                                   \
    ADD_FIRST_LINKEDLIST_FUNCTION_PROTO(user_type, item_type)                                               \
    {                                                                                                       \
        if (self)                                                                                           \
        {                                                                                                   \
            struct NODE_T(user_type) *new_node = NEW_NODE_FUNCTION_NAME(user_type)(item, self->head->next); \
            if (new_node)                                                                                   \
            {                                                                                               \
                self->head->next = new_node;                                                                \
                self->size++;                                                                               \
            }                                                                                               \
        }                                                                                                   \
    }

#define DEFINE_ADD_LINKEDLIST(user_type, item_type)                                                      \
    ADD_LINKEDLIST_FUNCTION_PROTO(user_type, item_type)                                                  \
    {                                                                                                    \
        if (self)                                                                                        \
        {                                                                                                \
            if (!pos)                                                                                    \
            {                                                                                            \
                ADD_FIRST_LINKEDLIST_FUNCTION_NAME(user_type)                                            \
                (self, item);                                                                            \
            }                                                                                            \
            else if (pos < self->size + 1)                                                               \
            {                                                                                            \
                struct NODE_T(user_type) *current_node = self->head;                                     \
                for (unsigned int i = 0; i < pos; i++)                                                   \
                {                                                                                        \
                    if (current_node->next)                                                              \
                        current_node = current_node->next;                                               \
                    else                                                                                 \
                        break;                                                                           \
                }                                                                                        \
                struct NODE_T(user_type) *new_node = NEW_NODE_FUNCTION_NAME(user_type)(item, (void *)0); \
                if (new_node)                                                                            \
                {                                                                                        \
                    if (current_node->next)                                                              \
                    {                                                                                    \
                        new_node->next = current_node->next;                                             \
                    }                                                                                    \
                    current_node->next = new_node;                                                       \
                    self->size++;                                                                        \
                }                                                                                        \
            }                                                                                            \
        }                                                                                                \
    }

#define DEFINE_REMOVE_FIRST_LINKEDLIST(user_type, item_type)         \
    REMOVE_FIRST_LINKEDLIST_FUNCTION_PROTO(user_type, item_type)     \
    {                                                                \
        item_type removed_item = 0;                                  \
        struct NODE_T(user_type) *node_to_remove = self->head->next; \
        if (self && node_to_remove)                                  \
        {                                                            \
            removed_item = node_to_remove->item;                     \
            self->head->next = node_to_remove->next;                 \
            FREE_NODE_FUNCTION_NAME(user_type)                       \
            (node_to_remove);                                        \
            self->size--;                                            \
        }                                                            \
        return removed_item;                                         \
    }

#define DEFINE_REMOVE_LINKEDLIST(user_type, item_type)                                 \
    REMOVE_LINKEDLIST_FUNCTION_PROTO(user_type, item_type)                             \
    {                                                                                  \
        item_type removed_item = 0;                                                    \
        if (self)                                                                      \
        {                                                                              \
            if (!pos)                                                                  \
            {                                                                          \
                removed_item = REMOVE_FIRST_LINKEDLIST_FUNCTION_NAME(user_type)(self); \
            }                                                                          \
            else if (pos < self->size)                                                 \
            {                                                                          \
                struct NODE_T(user_type) *current_node = self->head;                   \
                for (unsigned int i = 0; i < pos; i++)                                 \
                    if (current_node->next)                                            \
                        current_node = current_node->next;                             \
                    else                                                               \
                        break;                                                         \
                struct NODE_T(user_type) *node_to_remove = current_node->next;         \
                if (node_to_remove)                                                    \
                {                                                                      \
                    removed_item = node_to_remove->item;                               \
                    current_node->next = node_to_remove->next;                         \
                    FREE_NODE_FUNCTION_NAME(user_type)                                 \
                    (node_to_remove);                                                  \
                    self->size--;                                                      \
                }                                                                      \
            }                                                                          \
        }                                                                              \
        return removed_item;                                                           \
    }

#define DEFINE_FOREACH_LINKEDLIST(user_type, item_type)                                                     \
    FOREACH_LINKEDLIST_FUNCTION_PROTO(user_type, item_type)                                                 \
    {                                                                                                       \
        if (self && apply)                                                                                  \
        {                                                                                                   \
            for (struct NODE_T(user_type) *current_node = self->head; (current_node = current_node->next);) \
            {                                                                                               \
                apply(current_node->item);                                                                  \
            }                                                                                               \
        }                                                                                                   \
    }

#define DEFINE_GET_ITEM_LINKEDLIST(user_type, item_type)             \
    GET_ITEM_LINKEDLIST_PROTO(user_type, item_type)                  \
    {                                                                \
        item_type ret = 0;                                           \
        if (self && index < self->size)                              \
        {                                                            \
            if (!index)                                              \
            {                                                        \
                ret = self->head->next->item;                        \
            }                                                        \
            else                                                     \
            {                                                        \
                struct NODE_T(user_type) *current_node = self->head; \
                for (unsigned int i = 0; i < index; i++)             \
                    if (current_node->next)                          \
                        current_node = current_node->next;           \
                    else                                             \
                        break;                                       \
                ret = current_node->next->item;                      \
            }                                                        \
        }                                                            \
        return ret;                                                  \
    }

/*
 * Macro to define a user type generic linked list in one-shot.
 */
#define DEFINE_LINKEDLIST(user_type, item_type)          \
    DEFINE_LINKEDLIST_TYPE(user_type, item_type);        \
    DEFINE_FREE_NODE(user_type)                          \
    DEFINE_CALLOC_NODE(user_type)                        \
    DEFINE_NEW_NODE(user_type, item_type)                \
    DEFINE_CALLOC_LINKEDLIST(user_type)                  \
    DEFINE_FREE_LINKEDLIST(user_type)                    \
    DEFINE_NEW_LINKEDLIST(user_type, item_type)          \
    DEFINE_LINKEDLIST_SIZE(user_type, item_type)         \
    DEFINE_ADD_FIRST_LINKEDLIST(user_type, item_type)    \
    DEFINE_ADD_LINKEDLIST(user_type, item_type)          \
    DEFINE_REMOVE_FIRST_LINKEDLIST(user_type, item_type) \
    DEFINE_REMOVE_LINKEDLIST(user_type, item_type)       \
    DEFINE_FOREACH_LINKEDLIST(user_type, item_type)      \
    DEFINE_GET_ITEM_LINKEDLIST(user_type, item_type)

// ******************* end linked list section *******************

#endif // PSEUDOGENERICLINKEDLISTDEFINITION_H
