//
// Created by Dhia Neifar on 10/26/25.
//

// filename: linkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <stdio.h>

typedef struct node Node;

Node *initLinkedList(Node* next, int value);
Node *createLinkedList(const int *array, int n);
Node *delLinkedList(Node *head);
void iterateLinkedList(const Node *head);
Node *getTail(Node *head);
Node *append(Node *head, int value);
Node *removeNode(Node* head, int value);
Node *pop(Node *head);
Node *removeByIndex(Node* head, int index);
size_t getLength(const Node *head);
int getMax(const Node *head);
int getMin(const Node *head);
double getAverage(const Node *head);
Node *join(Node *head1, Node *head2);
int *toArray(const Node *head);
Node *insertNode(Node *head, size_t index, int value);

#endif // LINKEDLIST_H