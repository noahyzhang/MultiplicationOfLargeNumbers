//#include "list.h"
//
//List* NumAdd(List* list1,List* list2)
//{
//    List* newList = createList();
//    if (newList == NULL)
//    {
//        printf("malloc failed");
//        return NULL ;
//    }
//    int carry = 0;
//    int data = 0;
//    Node* tmp1 = list1->tail;
//    Node* tmp2 = list2->tail;
//    while(tmp1 != NULL || tmp2 != NULL)
//    {
//        int data1 = 0;
//        int data2 = 0;
//        if (tmp1 != NULL)
//        {
//            data1 = tmp1->data;
//        }
//        if (tmp2 != NULL)
//        {
//            data2 = tmp2->data;
//        }
//        data = data1 + data2 + carry;
//        if (data > 9)
//        {
//            carry = 1;
//            data = data % 10;
//        }else {
//            carry = 0;
//        }
//        newList = InsertBefore(&newList,data);
//    }
//    if (carry == 1)
//    {
//        newList = InsertBefore(&newList,carry);
//    }
//    return newList;
//}
