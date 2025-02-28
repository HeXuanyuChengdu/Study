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
    // printf("在检查空的函数中\n");
    
    // printf("开始检查---\n");
    if (listPtr->next==NULL)     //头节点的next域为空
    {
       //printf("退出检查空的函数，为空\n");
        return true;
    }
    else
    {
        //printf("退出检查空的函数,不为空\n");
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

    int localtion = 0;   //因为求得是位置，所以从1开始
    LinkList workPtr = listPtr;
    while (workPtr->next != NULL)
    {
        if (workPtr->data == e)
        {
            return localtion;
        }
        workPtr = workPtr->next;
        localtion++;
    }
    return ERROR;
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
    
   // printf("进入插入函数\n");
    LinkList listPtr = *dobuleListPtr;
    LinkList workPtr = listPtr; //从头节点开始遍历
    int pointOfworkPtr = 0;                  //代表了workPtr的位置，由于头结点认为是0位置，所以从0开始

    /*这里workPtr去判断而不是workPtr->判断，实现了允许在已有位置后面一位插入*/
    while (workPtr != NULL && pointOfworkPtr< localtion-1)  //workPtr移动到localtion-1的位置，因为是要在localtion位置插入数据而不是localtion后插入数据
    {
        workPtr = workPtr->next;  //移动workPtr
        pointOfworkPtr++;
    }
    
    if (workPtr == NULL )//由于头结点的存在，所以即使插入第一个位置也不满足条件
    {
        printf("错误，位置超过长度\n");
        return ERROR;
    }

    LinkList newNode = (LinkList)malloc(sizeof(Node));
    newNode->data= e;
    newNode->next= workPtr->next;        //首先让新节点连接上插入位置前一个元素的后继
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
    
    int i = 1;
    LinkList listPtr = *doubleListPtr;
    LinkList deletePtr = listPtr->next->next;   //指向第一个节点

    while ( deletePtr != NULL && i < localtion)
    {
        deletePtr = deletePtr->next;
        i++;
    }

    if (deletePtr->next != NULL)   //如果不是队尾
    {
        
    }
       
}

/**
 * 功能：打印列表
 * 参数：要打印的列表
 * 返回值：无
 */
void printList(LinkList listPre){
    LinkList printPre = listPre;
    int i =0;
    if (printPre->next==NULL)
    {
        printf("此时列表为空\n");
    }else{ 
        while (printPre!= NULL)
        {
            printf("Node%d->data=%d\n",i,printPre->data);
            printPre = printPre->next;
            i++;
        }
    }
}


int main(){
    LinkList list = NULL;
    ElemType e = 3;
    int result=0;
    LinkList printPre;
  
    if (InitList(&list)==OK)
    {
        printf("初始化成功\n");
        printList(list);  
    }
    for(int i =0;i<3;i++)
    {
        ListInsert(&list,i+1,i);
      
    }
    printf("插入3次后,线性表结果:\n");
    printList(list);
    printf("#########\n");
    for (int  i = 0; i < 3; i++)
    {
        ElemType testNumber=i;
        result = LocateElem(list,testNumber);
        printf("%d在第%d个元素\n",testNumber,result);
    }

    
    result=LocateElem(list,4);
    if (result == ERROR)
    {
        printf("4不在链表中");
    }
    

    free(list);
}