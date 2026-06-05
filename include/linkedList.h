//
// Created by Dhia Neifar on 10/26/25.
//

// filename: linkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <stddef.h>
#include <node.h>

/*
 * LListStatus
 *
 * Return codes used by linked-list functions. Public functions return one of
 * these values instead of printing errors or terminating the program.
 */
typedef enum {
    /* Operation completed successfully. */
    LLIST_OK = 0,

    /* A required pointer argument was NULL. */
    LLIST_ERROR_NULL_ARGUMENT,

    /* The operation requires a non-empty list, but the list is empty. */
    LLIST_ERROR_EMPTY,

    /* An index was outside the valid range for the list. */
    LLIST_ERROR_OUT_OF_BOUNDS,

    /* Memory allocation failed. */
    LLIST_ERROR_ALLOCATION,

    /* A lower-level node operation failed. */
    LLIST_NODE_ERROR,

    /* A requested value was not found in the list. */
    LLIST_VALUE_DOESNT_EXIST,
} LListStatus;

/*
 * fromArray
 *
 * Builds a linked list from an integer array.
 *
 * Arguments:
 * - array: input array containing n integers.
 * - n: number of values in array. Must be greater than zero.
 * - head: output parameter. Pass the address of a node* variable.
 *         On success, *head points to the first node. On failure, *head is
 *         set to NULL when head itself is not NULL.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if array or head is NULL.
 * - LLIST_ERROR_EMPTY if n <= 0.
 * - LLIST_NODE_ERROR if a node allocation fails.
 *
 * Ownership:
 * - The caller owns the created list and must free it with deleteLinkedList().
 */
LListStatus fromArray(const int array[], int n, node** head);

/*
 * deleteLinkedList
 *
 * Frees every node in a linked list.
 *
 * Arguments:
 * - head: first node of the list to free. Must not be NULL.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if head is NULL.
 *
 * Note:
 * - This function receives head by value, so it cannot set the caller's head
 *   variable to NULL. The caller should do that after successful deletion.
 */
LListStatus deleteLinkedList(node* head);

/*
 * iterateLinkedList
 *
 * Prints every value in the list to stdout, separated by tabs.
 *
 * Arguments:
 * - head: first node of the list to print. Must not be NULL.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if head is NULL.
 */
LListStatus iterateLinkedList(const node* head);

/*
 * getTail
 *
 * Finds the last node in a non-empty list.
 *
 * Arguments:
 * - head: first node of the list. Must not be NULL.
 * - tail: output parameter. Pass the address of a node* variable.
 *         On success, *tail points to the last node.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if head or tail is NULL.
 */
LListStatus getTail(node* head, node** tail);

/*
 * append
 *
 * Adds a new value after the current tail.
 *
 * Arguments:
 * - head: first node of a non-empty list. Must not be NULL.
 * - value: integer value to append.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if head is NULL.
 * - LLIST_NODE_ERROR if node allocation fails.
 *
 * Note:
 * - This function does not create a list from an empty NULL head.
 */
LListStatus append(node* head, int value);

/*
 * removeNode
 *
 * Removes the first node whose value equals value.
 *
 * Arguments:
 * - head: address of the caller's node* head variable. Must not be NULL and
 *         *head must not be NULL. node** is required because removing the
 *         first node changes the caller's head pointer.
 * - value: value to remove.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if head or *head is NULL.
 * - LLIST_VALUE_DOESNT_EXIST if value is not found.
 */
LListStatus removeNode(node** head, int value);

/*
 * pop
 *
 * Removes the tail node and returns its value.
 *
 * Arguments:
 * - head: address of the caller's node* head variable. Must not be NULL and
 *         *head must not be NULL. node** is required because popping a
 *         single-node list changes the caller's head pointer to NULL.
 * - value: output parameter. On success, *value receives the removed value.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if head, *head, or value is NULL.
 */
LListStatus pop(node** head, int* value);

/*
 * removeByIndex
 *
 * Removes the node at a zero-based index.
 *
 * Arguments:
 * - head: address of the caller's node* head variable. Must not be NULL and
 *         *head must not be NULL. node** is required because removing index 0
 *         changes the caller's head pointer.
 * - index: zero-based index of the node to remove.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if head or *head is NULL.
 * - LLIST_ERROR_OUT_OF_BOUNDS if index is greater than the last valid index.
 */
LListStatus removeByIndex(node** head, size_t index);

/*
 * getLength
 *
 * Counts the number of nodes in a non-empty list.
 *
 * Arguments:
 * - head: first node of the list. Must not be NULL.
 * - length: output parameter. On success, *length receives the node count.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if head or length is NULL.
 */
LListStatus getLength(const node* head, size_t* length);

/*
 * getMax
 *
 * Finds the largest value in a non-empty list.
 *
 * Arguments:
 * - head: first node of the list. Must not be NULL.
 * - max: output parameter. On success, *max receives the largest value.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if head or max is NULL.
 */
LListStatus getMax(const node* head, int* max);

/*
 * getMin
 *
 * Finds the smallest value in a non-empty list.
 *
 * Arguments:
 * - head: first node of the list. Must not be NULL.
 * - min: output parameter. On success, *min receives the smallest value.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if head or min is NULL.
 */
LListStatus getMin(const node* head, int* min);

/*
 * getAverage
 *
 * Calculates the arithmetic mean of all values in a non-empty list.
 *
 * Arguments:
 * - head: first node of the list. Must not be NULL.
 * - average: output parameter. On success, *average receives the average.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if head or average is NULL.
 */
LListStatus getAverage(const node* head, double* average);

/*
 * join
 *
 * Links the tail of head1 to head2 and returns the resulting list head.
 *
 * Arguments:
 * - head1: first list. May be NULL.
 * - head2: second list. May be NULL.
 * - result: output parameter. On success, *result receives the first node of
 *           the joined list.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if result is NULL.
 *
 * Ownership:
 * - This function does not allocate or copy nodes. It re-links existing lists.
 *   After joining, free the combined list once.
 */
LListStatus join(node* head1, node* head2, node** result);

/*
 * toArray
 *
 * Copies list values into a newly allocated int array.
 *
 * Arguments:
 * - head: first node of the list. Must not be NULL.
 * - array: output parameter. Pass the address of an int* variable.
 *          On success, *array points to a malloc-allocated array.
 * - n: output parameter. On success, *n receives the number of elements.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if head, array, or n is NULL.
 * - LLIST_ERROR_ALLOCATION if array allocation fails.
 *
 * Ownership:
 * - The caller owns *array on success and must free it with free().
 */
LListStatus toArray(const node* head, int** array, size_t* n);

/*
 * insertNode
 *
 * Inserts a new value at a zero-based index.
 *
 * Arguments:
 * - head: address of the caller's node* head variable. Must not be NULL and
 *         *head must not be NULL. node** is required because inserting at
 *         index 0 changes the caller's head pointer.
 * - index: zero-based insertion index. index 0 inserts before the current
 *          head. index equal to the list length appends at the end.
 * - value: integer value to insert.
 *
 * Returns:
 * - LLIST_OK on success.
 * - LLIST_ERROR_NULL_ARGUMENT if head or *head is NULL.
 * - LLIST_ERROR_OUT_OF_BOUNDS if index is greater than the list length.
 * - LLIST_NODE_ERROR if node allocation fails.
 */
LListStatus insertNode(node** head, size_t index, int value);

#endif // LINKEDLIST_H
