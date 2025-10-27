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
size_t getLength(Node *head);
int getMax(Node *head);
int getMin(Node *head);
double getAverage(Node *head);
Node *join(Node *head1, Node *head2);
int *toArray(Node *head);

#endif // LINKEDLIST_H