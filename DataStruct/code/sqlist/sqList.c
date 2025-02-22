#include "sqlist.h"

/**功能：创建一个空的顺序线性表，将创建好的线性表用List返回
 * 参数：List:用于接收创建好的线性表
 * 返回值：表示创建是否成功的状态
 */
Status InitList(sqList** list)
{
   // printf("test in InitList Function\n");
    *list = (sqList*)malloc(sizeof(sqList));
   // printf("成功分配内存\n");
    if(*list == NULL)
    {
        printf("内存分配失败");
        return ERROR;
    }
    (*list)->listlength = 0;
    return OK;
}

/**功能：若线性表为空返回true，否则返回false
 * 参数： list：要判断的线性表
 * 返回值： 若list为空返回true，否则返回false
 */
int ListEmpty(sqList list)
{
   
    return list.listlength == 0 ? true:false;

}

/**功能：清空整个线性表
 * 参数：list:要被清空的线性表
 * 返回值：成功返回OK失败返回ERROR
 */
Status ClearList(sqList* list)
{
    if(list == NULL)
    {
        printf("使用了空指针！");
        return ERROR;
    }
    
    free(list);
    //list = NULL;
    return OK;
}

/**功能：将线性表中第localtion个位置的元素返回给e
 * 参数：   list:查找的线性表
 *          localtion:需要返回的元素的位置
 *          e:接收被返回的元素
 * 返回值： 成功返回OK，否则返回false
 */
Status GetElem(sqList list, int localtion, ElemType *e)
{
    if(ListEmpty(list) == true)
    {
        printf("错误：列表为空！\n");
        return ERROR;
    }
    if(localtion<1 || localtion>list.listlength)
    {
        printf("错误：查找的元素超出范围\n");
        return ERROR;
    }

    *e = list.data[localtion-1];
    return OK;
}

/**功能：查找list线性表中是否有e元素，如果有返回e所在的位置，如果没有返回false
 * 参数：list:查找的线性表
 *       e:查找的目标元素
 * 返回值：成功返回e所在位置，失败返回false
 */
int LocateElem(sqList list, ElemType e)
{
    if(ListEmpty(list)==true)
    {
        printf("错误：线性表为空\n");
        return false;
    }

    int length = list.listlength;
    for(int i=0;i<length;i++)
    {
        if (e == list.data[i])
        {
            return i+1;
        }
        
    }

    return false;

}

/**功能：在list线性表的localtion位置插入元素e
 * 参数： list :要插入的线性表
 *        localtion: 要插入的位置，从1开始
 *        e: 要插入的元素
 * 返回值：成功插入返回OK，否则返回ERROR
 */
Status ListInsert(sqList *list, int localtion, ElemType e)
{
    if(list == NULL)
    {
        printf("错误：使用空指针\n");
        return ERROR;
    }
    if(localtion<1 || localtion>list->listlength+1)   //考虑如果插入末尾的情况允许location=listlength+1
    {
        printf("错误：试图在%d位置插入元素\n",localtion);
        return ERROR;
    }
    if (list->listlength==MAXSIZE)
    {
        printf("错误:线性表已满\n");
        return false;
    }
   // printf("location=%d,length=%d\n",localtion,list->listlength);
    //只有不在最后一个位置插入元素时才对前面的元素进行移动,取向等是因为等于时正好插入到最后一个位置，也必须把原来位置的最后一个元素移走
    if(localtion <= list->listlength)
    {
        for(int k =list->listlength-1;k>=localtion-1;k--)    //保证localtion位置上原来的元素也被移动，所以这里是>=
        {
            list->data[k+1] = list->data[k];//向后移动数组
        }
       
    }
    list->data[localtion-1] = e;
    list->listlength++;
   // printf("插入后，length=%d\n",list->listlength);
    // printf("此时线性表长度为：%d,线性表中元素如下：\n",list->listlength);
    // for (int i = 0; i < list->listlength; i++)
    // {
    //     printf("%d ",list->data[i]);
    // }
    // printf("\n");
    return OK;
}

/**功能:删除线性表list中localtion位置的元素
 * 参数：list:要操作的线性表List
 *       localtion:要删除的元素的为hi
 *       e:接收被删除的元素
 * 返回值：成功返回true，失败返回false
 */
Status ListDelete(sqList* list,int localtion,ElemType* e)
{
    if(list == NULL)
    {
        printf("错误：使用空指针\n");
        return ERROR;
    }
    
    if(ListEmpty(*list) == true)
    {
        printf("错误，删除空表\n");
        return false;
    }

    if(localtion<1 || localtion>list->listlength)
    {
        printf("错误：操作位置越界\n");
        return false;
    }

    *e = list->data[localtion-1]; 
    if(localtion<list->listlength) //若不是最后一个元素
    {
        for(int i=localtion-1;i<list->listlength-1;i++)//向前移动数组
        {
            list->data[i] = list->data[i+1];
        }
    }
    list->listlength--;
    // printf("此时线性表长度为：%d,线性表中元素如下：\n",list->listlength);
    // for (int i = 0; i < list->listlength; i++)
    // {
    //     printf("%d ",list->data[i]);
    // }
    // printf("\n");
    
    return OK;
}

/**功能：返回线性表元素的个数
 * 参数；list:要被查询的线性表
 * 返回值：线性表长度
 */
int ListLength(sqList list)
{
    return list.listlength;
}