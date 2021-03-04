#include "list.h"

List* createList()
{
    List* list = (List*)malloc(sizeof(List));
    if (list == NULL)
    {
        printf("malloc failed");
        return NULL;
    }
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}


List* InsertBefore(List** list,int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("malloc failed");
        return *list;
    }
    node->data = data;
    node->prev = NULL;
    node->next = NULL;

    if ((*list)->size == 0)
    {
        (*list)->head = node;
        (*list)->tail = node;
        (*list)->size ++;
    }else {
        (*list)->head->prev = node;
        node->next = (*list)->head;
        (*list)->head = node;
        ((*list)->size) ++;
    }
    return *list;
}


List* InsertAfter(List** list, int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("malloc failed");
        return *list;
    }
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    if ((*list)->size == 0)
    {
        (*list)->tail = node;
        (*list)->head = node;
        (*list)->size ++;
    }else {
        (*list)->tail->next = node;
        node->prev = (*list)->tail;
        (*list)->tail = node;
        ((*list)->size) ++;
    }
    return *list;
}

List* RemoveDataAfter(List** list)
{
    if ((*list)->size == 0 )
    {
        return *list;
    }
    if ((*list)->size == 1)
    {
        (*list)->size = 0;
        (*list)->head = (*list)->tail = NULL;
        return *list;
    }
    Node* tail = (*list)->tail;
    Node* tmp = (*list)->tail->prev;
    (*list)->tail = tmp;
    tail->prev = tail->next = NULL;
    (*list)->tail->next = NULL;
    (*list)->size--;
    return *list;
}

void ShowListPositive(List* list)
{
    Node* tmp = list->head;
    while (tmp != NULL)
    {
        printf("%d",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

void ShowListReverse(List* list)
{
    Node* tmp = list->tail;
    while(tmp != NULL)
    {
        printf("%d",tmp->data);
        tmp = tmp->prev;
    }
    printf("\n");
}

List* NumAdd(List* list1,List* list2)
{
    List* newList = createList();
    if (newList == NULL)
    {
        printf("malloc failed");
        return NULL ;
    }
    int carry = 0;
    int data = 0;
    Node* tmp1 = list1->tail;
    Node* tmp2 = list2->tail;
    while(tmp1 != NULL || tmp2 != NULL)
    {
        int data1 = 0;
        int data2 = 0;
        if (tmp1 != NULL)
        {
            data1 = tmp1->data;
        }
        if (tmp2 != NULL)
        {
            data2 = tmp2->data;
        }
        data = data1 + data2 + carry;
        if (data > 9)
        {
            carry = 1;
            data = data % 10;
        }else {
            carry = 0;
        }
        newList = InsertBefore(&newList,data);
        if (tmp1 != NULL )
            tmp1 = tmp1->prev;
        if (tmp2 != NULL)
            tmp2 = tmp2->prev;
    }
    if (carry == 1)
    {
        newList = InsertBefore(&newList,carry);
    }
    return newList;
}

List* ListIntMulti(List* list, int value)
{
    List* newList = createList();
    if (newList == NULL)
    {
        printf("malloc failed");
        return NULL ;
    }
    int carry = 0;
    int data = 0;
    Node* tmp = list->tail;
    while(tmp != NULL)
    {
        int bits = 0;
        data = (tmp->data) * value + carry;
        if (data > 9)
        {
            carry = data / 10;
            bits = data % 10;
        }else{
            bits = data;
            carry = 0;
        }
        newList = InsertBefore(&newList,bits);
        tmp = tmp->prev;
    }
    if (carry == 1)
    {
        newList = InsertBefore(&newList,carry);
    }
    return newList;
}

List* ListAndListMulti(List* lowlist, List* highlist, int num)
{
//    ShowListPositive(lowlist);
//    ShowListPositive(highlist);
//    printf("\n");
    if(lowlist->size == 0)
    {
        return highlist;
    }
    List* newList = createList();
    List* tmp = createList();
    for (int i = 0;i < num;i++)
    {
        int data = lowlist->tail->data;
        lowlist = RemoveDataAfter(&lowlist);
        tmp = InsertBefore(&tmp,data);
    }
//    ShowListPositive(tmp);
//    ShowListPositive(lowlist);
//    printf("\n");
    newList = NumAdd(lowlist,highlist);
    Node* node = tmp->head;
    while (node != NULL)
    {
        newList = InsertAfter(&newList,node->data);
        node = node->next;
    }
//    ShowListPositive(newList);
//    printf("\n");
    return newList;
}

List* NumMulti(List* list1, List* list2)
{
    List* newList = createList();
    Node* tmp = list2->tail;
    int num = 0;
    while(tmp != NULL)
    {
        List* node = ListIntMulti(list1,tmp->data);
        newList = ListAndListMulti(newList,node,num);
        num ++;
        tmp = tmp->prev;
    }
    return newList;
}