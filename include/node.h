//
// Created by Dhia Neifar on 6/2/26.
//

// filename: node.h

#ifndef UTILITIES_NODE_H
#define UTILITIES_NODE_H

/*
 * node
 *
 * A single element in a singly linked list of integers.
 *
 * Fields:
 * - value: the integer stored in this node.
 * - next: pointer to the next node, or NULL if this is the last node.
 */
typedef struct node node;
struct node {
    int value;
    node* next;
};

/*
 * NodeStatus
 *
 * Return codes used by node-level helper functions.
 */
typedef enum {
    /* Operation completed successfully. */
    NODE_OK = 0,

    /* A required pointer argument was NULL. */
    NODE_ERROR_NULL_ARGUMENT,

    /* malloc failed while creating a node. */
    NODE_ERROR_ALLOCATION
} NodeStatus;

/*
 * initNode
 *
 * Allocates and initializes one standalone node.
 *
 * Arguments:
 * - value: integer value to store in the new node.
 * - head: output parameter. Pass the address of a node* variable.
 *         On success, *head points to the new node. The new node's next
 *         pointer is initialized to NULL. On failure, *head is set to NULL
 *         when head itself is not NULL.
 *
 * Returns:
 * - NODE_OK on success.
 * - NODE_ERROR_NULL_ARGUMENT if head is NULL.
 * - NODE_ERROR_ALLOCATION if memory allocation fails.
 *
 * Example:
 *     node *n = NULL;
 *     NodeStatus status = initNode(10, &n);
 */
NodeStatus initNode(int value, node** head);

#endif //UTILITIES_NODE_H
