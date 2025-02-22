/**
 * 文件名：sqlist.h
 * 描述：对顺序线性表的抽象数据类型的实现
 */

#ifndef SQLIST_H
#define SQLIST_H

#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0           
#define MAXSIZE 20
#define true 1
#define false 0

typedef int Status;  /*表示状态*/
typedef int ElemType; /*代表数据元素的具体值*/

typedef struct sqList
{
    int data[MAXSIZE];
    int listlength;
}sqList;

Status InitList (sqList** list);                       /*初始化操作，建立一个空的线性表 */
int ListEmpty(sqList list);                         /*若线性表为空，返回true,否则返回false */
Status ClearList(sqList* list);                         /*清空线性表 */
Status GetElem(sqList list,int localtion,ElemType* e);  /*将线性表List中第localtion个元素值返回给e*/
int LocateElem(sqList list,ElemType e);                  /*查找List线性表中是否有e元素，如果成功返回e元素的位置，如果失败返回0*/
Status ListInsert(sqList* list,int localtion,ElemType e);/*在线性表List中的localtion位置插入元素e*/
Status ListDelete(sqList* list,int localtion,ElemType* e);/*删除线性表list中的第localtion个元素，并将值返回给e*/
int ListLength(sqList list);                              /*返回线性表L的元素个数*/


#endif