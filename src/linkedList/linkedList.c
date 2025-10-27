//
// Created by Dhia Neifar on 10/26/25.
//

// filename: linkedList.c


#include "linkedList.h"

#include <stdio.h>
#include <stdlib.h>


typedef struct node Node;

struct node {
    int value;
    Node *next;
};

Node *initLinkedList(Node* next, const int value) {
    Node *head = malloc(sizeof(Node));
    if (head == NULL) {printf("Failed to allocate memory.\n"); return NULL;}
    head->value = value;
    head->next = next;
    return head;
}

Node *delLinkedList(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    while (current != NULL) {
        prev = current;
        current = current->next;
        free(prev);
    }
    prev = NULL;
    return current;
}

Node *createLinkedList(const int *array, const int n) {
    if (n == 0) {return NULL;}
    Node *head = initLinkedList(NULL, array[0]);
    Node *current = head;
    for (int i = 1; i < n; i++) {
        Node *new = initLinkedList(NULL, array[i]);
        current->next = new;
        current = current->next;
    }
    return head;
}

void iterateLinkedList(const Node *head) {
    const Node *prov = head;
    while (prov != NULL) {
        printf("%d\t", prov->value);
        prov = prov->next;
    }
    printf("\n");
}

Node *getTail(Node *head) {
    Node *tail = head;
    while (tail->next != NULL) tail = tail->next;
    return tail;
}

Node *append(Node *head, const int value) {
    Node *newTail = initLinkedList(NULL, value);
    Node *tail = getTail(head);
    tail->next = newTail;
    return head;
}

Node *removeNode(Node* head, const int value) {
    Node *curr = head;
    Node *prev = NULL;
    while (curr->value != value) {
        prev = curr;
        curr = curr->next;
    }
    if (prev == NULL) head = head->next;
    if (prev != NULL) prev->next = curr->next;
    free(curr);
    return head;
}

Node *pop(Node *head) {
    Node *tail = head;
    Node *prev = NULL;
    while (tail->next != NULL) {
        prev = tail;
        tail = tail->next;
    }
    if (prev != NULL) prev->next = NULL;
    return tail;
}

Node *removeByIndex(Node* head, const int index) {
    Node *curr = head;
    Node *prev = NULL;
    int i = 0;
    while (curr != NULL && i++ < index) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {printf("Error! index exceeds length of List!\n"); return head;}
    if (prev == NULL) head = head->next;
    if (prev != NULL) prev->next = curr->next;
    free(curr);
    return head;
}

size_t getLength(const Node *head) {
    size_t length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

int getMax(const Node *head) {
    int result = head->value;
    while (head->next != NULL) {
        head = head->next;
        if (result < head->value) result = head->value;
    }
    return result;
}

int getMin(const Node *head) {
    int result = head->value;
    while (head->next != NULL) {
        head = head->next;
        if (result > head->value) result = head->value;
    }
    return result;
}

double getAverage(const Node *head) {
    size_t length = 1;
    int result = head->value;
    while (head->next != NULL) {
        head = head->next;
        result += head->value;
        length++;
    }
    return (double)result / length;
}

Node *join(Node *head1, Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    Node *tail = getTail(head1);
    tail->next = head2;
    head2 = NULL;
    return head1;
}

int *toArray(const Node *head) {
    if (head == NULL) return NULL;
    const size_t length = getLength(head);
    int *array = malloc(length * sizeof(int));
    int *ptr = array;
    while (head != NULL) {
        *array = head->value;
        array++;
        head = head->next;
    }
    return ptr;
}