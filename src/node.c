//
// Created by Dhia Neifar on 6/2/26.
//


#include "../include/node.h"

#include <stdlib.h>

NodeStatus initNode(const int value, node** head) {
    if (head == NULL) return NODE_ERROR_NULL_ARGUMENT;
    *head = NULL;
    node* placeholder = malloc(sizeof(node));
    if (placeholder == NULL) return NODE_ERROR_ALLOCATION;
    placeholder->value = value;
    placeholder->next = NULL;
    *head = placeholder;
    return NODE_OK;
}
