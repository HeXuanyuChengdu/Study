#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define HEAD_NUMBER -1
#define true 1
#define false 0
typedef int ElemType;
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node* next;
}Node;

typedef struct Node* LinkList;

Status InitList (LinkList* doubleListPtr);                       /*初始化操作，建立一个空的线性表 */
int ListEmpty(LinkList listPtr);                         /*若线性表为空，返回true,否则返回false */
Status ClearList(LinkList* doubleListPtr);                         /*清空线性表 */
Status GetElem(LinkList listPtr,int localtion,ElemType* e);  /*将线性表List中第localtion个元素值返回给e*/
int LocateElem(LinkList listPtr,ElemType e);                  /*查找List线性表中是否有e元素，如果成功返回e元素的位置，如果失败返回0*/
Status ListInsert(LinkList* doubleListPtr,int localtion,ElemType e);/*在线性表List中的localtion位置插入元素e*/
Status ListDelete(LinkList* doubleListPtr,int localtion,ElemType* e);/*删除线性表list中的第localtion个元素，并将值返回给e*/
int ListLength(LinkList list);                              /*返回线性表L的元素个数*/

#endif