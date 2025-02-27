#include "linklist.h"


/**
 * 功能：初始化链式存储线性表，创建一个头节点
 * 参数：doubleListPtr:指向线性表指针的指针，用来对主函数传入的Linklist变量进行初始化
 * 返回值：成功返回OK，失败返回ERROR
 */
Status InitList (LinkList* doubleListPtr){
    *doubleListPtr = (LinkList)malloc(sizeof(Node));
    if (*doubleListPtr == NULL)
    {
        printf("分配内存失败\n");
        return ERROR;
    }

    (*doubleListPtr) ->data = HEAD_NUMBER; //代表是头节点
    (*doubleListPtr) -> next = NULL;
    return OK;    
}             

/**
 * 功能：判断链表是否为空
 * 参数：listPtr:指向线性表的指针
 * 返回：为空返回true,否则返回false
 */
int ListEmpty(LinkList listPtr){
    
    if (listPtr == NULL)
    {
        printf("错误，传入了空指针\n");
        return ERROR;
    }
    
    
    LinkList ptr = listPtr->next;   //让ptr指向头节点
    if (ptr->next==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

/**
 * 功能：清空线性表
 * 参数：dobulelistPtr:指向要清空的线性表的指针的指针变量
 * 返回：成功返回OK，否则返回ERROR
 */
Status ClearList(LinkList* doubleListPtr){
    if (doubleListPtr==NULL)
    {
        printf("错误，传入了空指针\n");
        return ERROR;
    }
    
    LinkList deletePtr,nextPtr;
    LinkList listPtr = *doubleListPtr;
    deletePtr = listPtr->next->next;   //指向头节点的下一个节点，即真正的第一个节点
    
    while (deletePtr != NULL)
    {
        nextPtr = deletePtr->next;
        free(deletePtr);
        deletePtr = nextPtr;     //让deletePtr指针移动到下一个元素
    }

    return OK;
}

/**
 * 功能：获取第localtion个元素，并将其指传递给e
 * 参数：listPtr:要查询的线性表
 *      localtion:要查询的元素的位置 从1开始
 *      e:接收查到的结果
 * 返回值：成功返回OK，失败返回ERROR
 */
Status GetElem(LinkList listPtr,int localtion,ElemType* e){
    if (ListEmpty(listPtr)==true)
    {
        printf("错误：线性表为空\n");
        return ERROR;
    }

    LinkList workPtr = listPtr->next->next;   //指向第一个节点
    
    for (int  i = 0; i < localtion; i++)
    {
        workPtr = workPtr->next;           //移动工作指针
    }
    
    *e = workPtr->data;
    return OK;
}

/**
 * 功能：查找线性表中是否有值为e的元素，若有，返回元素的位置，否则返回ERROR
 * 参数：listPtr:要查找的线性表
 *      e:要查找的值
 * 返回值：如果有值为e的元素，则返回元素的位置，否则返回ERROR
 */
int LocateElem(LinkList listPtr,ElemType e){
    
    if (listPtr == NULL)
    {
        printf("错误:传递了空指针\n");
        return ERROR;
    }
    
    
    if (ListEmpty(listPtr)==true)
    {
        printf("错误：线性表为空\n");
        return ERROR;
    }

    int localtion = 1;   //因为求得是位置，所以从1开始
    LinkList workPtr = listPtr->next->next;//  指向第一个节点
    while (workPtr != NULL)
    {
        if (workPtr->data == e)
        {
            return localtion;
        }
        workPtr = workPtr->next; //依次移动指针
        localtion++;
    }

    if (workPtr == NULL)
    {
        return ERROR;
    }   
}

/**
 * 功能：在线性表的第localtion位置插入元素e
 * 参数：dobuleListPtr:指向要插入的线性表指针的指针
 *      localtion:要插入的元素的位置，从1开始
 *      e：要插入的元素
 * 返回：成功返回OK，否则返回ERROR
 */
Status ListInsert(LinkList* dobuleListPtr,int localtion,ElemType e){
    if (dobuleListPtr == NULL)
    {
        printf("错误:传递了空指针\n");
        return ERROR;
    }
    
    LinkList listPtr = *dobuleListPtr;

    if (ListEmpty(listPtr)==true)
    {
        printf("错误：线性表为空\n");
        return ERROR;
    }

    LinkList newNode = (LinkList)malloc(sizeof(Node));//创建一个新节点
    newNode->data = e;
    newNode->next = NULL;    //先让新节点指针域为空，避免使用野指针
    int i = 1;
    LinkList workPtr,nextPtr;
    workPtr = listPtr->next->next;

    //实际上如果正常退出循环，workPtr应该是指向要插入位置的前一个元素
    while (workPtr != NULL && i<localtion )
    {
        workPtr = workPtr->next;
        i++;
    }
    
    if (workPtr == NULL || i>localtion)
    {
        printf("要插入的位置超出长度");
        return ERROR;
    }
    
    newNode->next = workPtr->next;   //把新节点插入原来的位置
    workPtr->next = newNode;

    return OK;
}

/**
 * 功能：删除第location个位置的元素
 * 参数：doubleListPtr:指向要删除元素的线性表的指针
 *      localtion:要删除的元素的位置
 *      e:用来接收要删除的元素
 * 返回值：成功返回OK，失败返回ERROR
 */
Status ListDelete(LinkList* doubleListPtr,int localtion,ElemType* e){
    if (doubleListPtr == NULL)
    {
        printf("错误，传入了空指针\n");
        return ERROR;
    }
    
    
    int i = 0;
    LinkList listPtr = *doubleListPtr;
    LinkList deletePtr = listPtr->next->next;   //
}