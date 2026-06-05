//
// Created by Dhia Neifar on 10/26/25.
//

// filename: linkedList.c


#include "../include/linkedList.h"

#include <stdio.h>
#include <stdlib.h>


LListStatus fromArray(const int array[], const int n, node** head) {
    if (head == NULL || array == NULL) return LLIST_ERROR_NULL_ARGUMENT;
    *head = NULL;
    if (n <= 0) return LLIST_ERROR_EMPTY;
    node* placeholder = NULL;
    NodeStatus ns = initNode(array[0], &placeholder);
    if (ns != NODE_OK) return LLIST_NODE_ERROR;
    node* current = placeholder;
    for (int i = 1; i < n; i++) {
        node* new = NULL;
        ns = initNode(array[i], &new);
        if (ns != NODE_OK) {
            deleteLinkedList(placeholder);
            return LLIST_NODE_ERROR;
        }
        current->next = new;
        current = new;
    }
    *head = placeholder;
    return LLIST_OK;
}

LListStatus deleteLinkedList(node* head) {
    if (head == NULL) return LLIST_ERROR_NULL_ARGUMENT;
    node* current = head;
    while (current != NULL) {
        node* next = current->next;
        free(current);
        current = next;
    }
    return LLIST_OK;
}

LListStatus iterateLinkedList(const node* head) {
    if (head == NULL) return LLIST_ERROR_NULL_ARGUMENT;
    const node* prov = head;
    while (prov != NULL) {
        printf("%d\t", prov->value);
        prov = prov->next;
    }
    printf("\n");
    return LLIST_OK;
}

LListStatus getTail(node* head, node** tail) {
    if (head == NULL || tail == NULL) return LLIST_ERROR_NULL_ARGUMENT;
    node* placeholder = head;
    while (placeholder->next != NULL) placeholder = placeholder->next;
    *tail = placeholder;
    return LLIST_OK;
}

LListStatus append(node* head, const int value) {
    node* tail = NULL;
    const LListStatus ls = getTail(head, &tail);
    if (ls != LLIST_OK) return ls;

    node* newTail = NULL;
    const NodeStatus ns = initNode(value, &newTail);
    if (ns != NODE_OK) return LLIST_NODE_ERROR;

    tail->next = newTail;
    return LLIST_OK;
}

LListStatus removeNode(node** head, const int value) {
    if (head == NULL || *head == NULL) return LLIST_ERROR_NULL_ARGUMENT;

    node* curr = *head;
    node* prev = NULL;
    while (curr != NULL && curr->value != value) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) return LLIST_VALUE_DOESNT_EXIST;
    if (prev == NULL) *head = curr->next;
    if (prev != NULL) prev->next = curr->next;
    free(curr);
    return LLIST_OK;
}

LListStatus pop(node** head, int* value) {
    if (head == NULL || *head == NULL || value == NULL) return LLIST_ERROR_NULL_ARGUMENT;
    node* tail = *head;
    node* prev = NULL;
    while (tail->next != NULL) {
        prev = tail;
        tail = tail->next;
    }
    if (prev != NULL) prev->next = NULL;
    *value = tail->value;
    if (tail == *head) *head = NULL;
    free(tail);
    return LLIST_OK;
}

LListStatus removeByIndex(node** head, const size_t index) {
    if (head == NULL || *head == NULL) return LLIST_ERROR_NULL_ARGUMENT;
    node* curr = *head;
    node* prev = NULL;
    int i = 0;
    while (curr != NULL && i++ < index) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) return LLIST_ERROR_OUT_OF_BOUNDS;
    if (prev == NULL) *head = curr->next;
    if (prev != NULL) prev->next = curr->next;
    free(curr);
    return LLIST_OK;
}

LListStatus getLength(const node* head, size_t* length) {
    if (head == NULL || length == NULL) return LLIST_ERROR_NULL_ARGUMENT;
    size_t len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    *length = len;
    return LLIST_OK;
}

LListStatus getMax(const node* head, int* max) {
    if (head == NULL || max == NULL) return LLIST_ERROR_NULL_ARGUMENT;
    int result = head->value;
    while (head->next != NULL) {
        head = head->next;
        if (result < head->value) result = head->value;
    }
    *max = result;
    return LLIST_OK;
}

LListStatus getMin(const node* head, int* min) {
    if (head == NULL || min == NULL) return LLIST_ERROR_NULL_ARGUMENT;
    int result = head->value;
    while (head->next != NULL) {
        head = head->next;
        if (result > head->value) result = head->value;
    }
    *min = result;
    return LLIST_OK;
}

LListStatus getAverage(const node* head, double* average) {
    if (head == NULL || average == NULL) return LLIST_ERROR_NULL_ARGUMENT;
    size_t length = 1;
    int result = head->value;
    while (head->next != NULL) {
        head = head->next;
        result += head->value;
        length++;
    }
    *average = (double)result / (double)length;
    return LLIST_OK;
}

LListStatus join(node* head1, node* head2, node** result) {
    if (result == NULL) return LLIST_ERROR_NULL_ARGUMENT;
    if (head1 == NULL) {
        *result = head2;
        return LLIST_OK;
    }
    if (head2 == NULL) {
        *result = head1;
        return LLIST_OK;
    }

    node* tail = NULL;
    const LListStatus status = getTail(head1, &tail);
    if (status != LLIST_OK) return status;

    tail->next = head2;
    *result = head1;
    return LLIST_OK;
}

LListStatus toArray(const node* head, int** array, size_t* n) {
    if (head == NULL || array == NULL || n == NULL) return LLIST_ERROR_NULL_ARGUMENT;
    *array = NULL;
    *n = 0;
    const LListStatus lls = getLength(head, n);
    if (lls != LLIST_OK) return lls;

    int* arr = malloc(*n * sizeof(int));
    if (arr == NULL) return LLIST_ERROR_ALLOCATION;
    *array = arr;
    while (head != NULL) {
        *arr = head->value;
        arr++;
        head = head->next;
    }
    return LLIST_OK;
}

LListStatus insertNode(node** head, const size_t index, const int value) {
    if (head == NULL || *head == NULL) return LLIST_ERROR_NULL_ARGUMENT;
    if (index == 0) {
        node* new_node = NULL;
        const NodeStatus ns = initNode(value, &new_node);
        if (ns != NODE_OK) return LLIST_NODE_ERROR;
        new_node->next = *head;
        *head = new_node;
        return LLIST_OK;
    }

    int i = 0;
    node* curr = *head;
    while (curr != NULL && i++ < index - 1) {
        curr = curr->next;
    }
    if (curr == NULL) return LLIST_ERROR_OUT_OF_BOUNDS;
    node* new_node = NULL;
    const NodeStatus ns = initNode(value, &new_node);
    if (ns != NODE_OK) return LLIST_NODE_ERROR;
    new_node->next = curr->next;
    curr->next = new_node;
    return LLIST_OK;
}
