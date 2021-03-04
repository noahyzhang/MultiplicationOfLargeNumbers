#ifndef STUDY_LIST_H
#define STUDY_LIST_H

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

extern int errno;

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

typedef struct List{
    int size;
    Node* head;
    Node* tail;
}List;

List* createList();
List* InsertBefore(List** list,int data);
List* InsertAfter(List** list, int data);
void ShowListPositive(List* list);
void ShowListReverse(List* list);
List* NumAdd(List* list, List* list2);
List* NumMulti(List* list1, List* list2);

#endif //STUDY_LIST_H
