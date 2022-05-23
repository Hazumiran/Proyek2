#include <stdlib.h>
#include <stdio.h>

#ifndef linkedlist.H
#define linkedlist.H

typedef struct node_s
{
    char data;
    struct node_s *next;
    struct node_s *prev;
}Node;

typedef struct list_s
{
    Node *head;
}List;

List *CreateHead();
Node *CreateNode(int value);
void DeAlokasi (Node *node);
int insertNode(List *list, Node *node, int index);
int removeNode(List *list, Node *node);
int removeNodeByIndex(List *list, int index);
int listLength(List *list);
Node * getNode(List *list, int index);
void printList(List *list);
int deleteList(List * list);

#endif