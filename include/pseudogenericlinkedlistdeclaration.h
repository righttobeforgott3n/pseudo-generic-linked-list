#ifndef PSEUDOGENERICLINKEDLISTDECLARATION_H
#define PSEUDOGENERICLINKEDLISTDECLARATION_H

/*
 * Placeholder for the new linked list user type name.
 */
#define LINKEDLIST_STRUCT_NAME(user_type) \
    struct linked_list_##user_type##_t

/*
 * Placeholder for linked list opaque type.
 */
#define LINKEDLIST_OPAQUE_NAME(user_type) \
    linked_list_##user_type

/*
 * Opaque type declaration.
 */
#define DECLARE_LINKEDLIST_OPAQUE(userType) \
    typedef LINKEDLIST_STRUCT_NAME(userType) * LINKEDLIST_OPAQUE_NAME(userType);

/*
 * Placeholder for linked list new function.
 */
#define NEW_LINKEDLIST_FUNCTION_NAME(user_type) \
    linked_list_##user_type##_new

/*
 * Prototype for the linked list new function.
 */
#define NEW_LINKEDLIST_FUNCTION_PROTO(user_type) \
    LINKEDLIST_OPAQUE_NAME(user_type)            \
    NEW_LINKEDLIST_FUNCTION_NAME(user_type)(void)

/*
 * Placeholder for linked list free function.
 */
#define FREE_LINKEDLIST_FUNCTION_NAME(user_type) \
    linked_list_##user_type##_free

/*
 * Prototype for the linked list free function.
 */
#define FREE_LINKEDLIST_FUNCTION_PROTO(user_type) \
    void FREE_LINKEDLIST_FUNCTION_NAME(user_type)(LINKEDLIST_OPAQUE_NAME(user_type) self)

/*
 * Placeholder for linked list get size function.
 */
#define LINKEDLIST_SIZE_FUNCTION_NAME(user_type) \
    linked_list_##user_type##_get_size

/*
 * Prototype for the linked list get size function.
 */
#define LINKEDLIST_SIZE_FUNCTION_PROTO(user_type) \
    unsigned int LINKEDLIST_SIZE_FUNCTION_NAME(user_type)(LINKEDLIST_OPAQUE_NAME(user_type) self)

/*
 * Placeholder for linked list add first function.
 */
#define ADD_FIRST_LINKEDLIST_FUNCTION_NAME(user_type) \
    linked_list_##user_type##_add_first

/*
 * Prototype for the linked list add first function.
 */
#define ADD_FIRST_LINKEDLIST_FUNCTION_PROTO(user_type, item_type) \
    void ADD_FIRST_LINKEDLIST_FUNCTION_NAME(user_type)(LINKEDLIST_OPAQUE_NAME(user_type) self, item_type item)

/*
 * Placeholder for linked list add function.
 */
#define ADD_LINKEDLIST_FUNCTION_NAME(user_type, item_type) \
    linked_list_##user_type##_add

/*
 * Prototype for the linked list add function.
 */
#define ADD_LINKEDLIST_FUNCTION_PROTO(userType, itemType) \
    void ADD_LINKEDLIST_FUNCTION_NAME(userType, itemType)(LINKEDLIST_OPAQUE_NAME(userType) self, itemType item, unsigned int pos)

/*
 * Placeholder for linked list remove first function.
 */
#define REMOVE_FIRST_LINKEDLIST_FUNCTION_NAME(user_type) \
    linked_list_##user_type##_remove_first

/*
 * Prototype for the linked list remove first function.
 */
#define REMOVE_FIRST_LINKEDLIST_FUNCTION_PROTO(user_type, item_type) \
    item_type REMOVE_FIRST_LINKEDLIST_FUNCTION_NAME(user_type)(LINKEDLIST_OPAQUE_NAME(user_type) self)

/*
 * Placeholder for linked list remove function.
 */
#define REMOVE_LINKEDLIST_FUNCTION_NAME(user_type, item_type) \
    linked_list_##user_type##_remove

/*
 * Prototype for the linked list remove function.
 */
#define REMOVE_LINKEDLIST_FUNCTION_PROTO(user_type, item_type) \
    item_type REMOVE_LINKEDLIST_FUNCTION_NAME(user_type, item_type)(LINKEDLIST_OPAQUE_NAME(user_type) self, unsigned int pos)

/*
 * Placeholder for linked list for-each function.
 */
#define FOREACH_LINKEDLIST_FUNCTION_NAME(user_type) \
    linked_list_##user_type##_for_each

/*
 * Prototype for linked list for-each function.
 */
#define FOREACH_LINKEDLIST_FUNCTION_PROTO(user_type, item_type) \
    void FOREACH_LINKEDLIST_FUNCTION_NAME(user_type)(LINKEDLIST_OPAQUE_NAME(user_type) self, void (*apply)(item_type))

/*
 * Placeholder for linked list get item function.
 */
#define GET_ITEM_LINKEDLIST_FUNCTION_NAME(user_type) \
    linked_list_##user_type##_get_item

/*
 * Prototype for linked list get item function.
 */
#define GET_ITEM_LINKEDLIST_PROTO(user_type, item_type) \
    item_type GET_ITEM_LINKEDLIST_FUNCTION_NAME(user_type)(LINKEDLIST_OPAQUE_NAME(user_type) self, unsigned int index)

/*
 * Declare in one shot all the needed for a user type linked list header.
 */
#define DECLARE_LINKEDLIST(user_type, item_type)                  \
    DECLARE_LINKEDLIST_OPAQUE(user_type)                          \
    NEW_LINKEDLIST_FUNCTION_PROTO(user_type);                     \
    FREE_LINKEDLIST_FUNCTION_PROTO(user_type);                    \
    LINKEDLIST_SIZE_FUNCTION_PROTO(user_type);                    \
    ADD_FIRST_LINKEDLIST_FUNCTION_PROTO(user_type, item_type);    \
    ADD_LINKEDLIST_FUNCTION_PROTO(user_type, item_type);          \
    REMOVE_FIRST_LINKEDLIST_FUNCTION_PROTO(user_type, item_type); \
    REMOVE_LINKEDLIST_FUNCTION_PROTO(user_type, item_type);       \
    FOREACH_LINKEDLIST_FUNCTION_PROTO(user_type, item_type);      \
    GET_ITEM_LINKEDLIST_PROTO(user_type, item_type);

#endif // PSEUDOGENERICLINKEDLISTDECLARATION_H
