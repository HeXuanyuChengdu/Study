#include "sqlist.h"

/**功能：在控制台输出一个线性表list的所有元素
 * 参数：list：要被输出的线性表
 * 返回值：无
 */
void prtintList(sqList list)
{
    //printf("测试打印函数/n");
    if(ListEmpty(list) == true)
    {
        printf("列表为空\n");
      //  printf("测试打印函数中是否正确判断线性表为空/n");
    }
    else
    {
        printf("该线性表的元素有:");
        for (int i = 0; i < list.listlength; i++)
        {
            printf("%d ",list.data[i]);
        }
        printf("\n");
        
    }
}


int main()
{
    sqList * list = NULL;
    printf("===========测试创建线性表表======\n");
    int testdata[] = {1,2,3,4,5,6,7,8,9,10};
    int result = 0;
    int searchLocaltionInput = 0;
    int insertLocaltionInput = 0;
    int deletalLocaltionInput = 0;
    ElemType insertInput = 0;
    ElemType e = 0;

    //printf("test before InitList\n");

    if(InitList(&list))
    {
        printf("创建线性表成功!\n");
       // printf("test in Init if\n");mak
        prtintList(*list);
    }
    
    if (ListEmpty(*list))
    {
        printf("创建线性表成功后表为空\n");
    }
    
    

    for (int i = 0; i < 10; i++)
    {
       result =  ListInsert(list,i+1,testdata[i]);
       if (result==ERROR)
       {
            printf("在插入第%d个元素过程中失败\n",i+1);
            break;
       }  
    }
    

    if(!ListEmpty(*list))
    {
        printf("初始化完成\n");
        prtintList(*list);
    }

    printf("请输入一个要查找的位置：");
    scanf("%d",&searchLocaltionInput);
    printf("\n");
    
    if(GetElem(*list,searchLocaltionInput,&e))
    {
        printf("您查找的第%d个数为%d\n",searchLocaltionInput,e);
    }  

    printf("请输入一个要插入的数：");
    scanf("%d",&insertInput);
    printf("\n");

    printf("请输入要插入的位置:");
    scanf("%d",&insertLocaltionInput);

    if(ListInsert(list,insertLocaltionInput,insertInput))
    {
        printf("插入成功\n");
        prtintList(*list);
    }

    

    printf("请输入要删除的位置:");
    scanf("%d",&deletalLocaltionInput);
    printf("\n");

    if(ListDelete(list,deletalLocaltionInput,&e))
    {
        printf("您成功删除了第%d位置的%d元素\n",deletalLocaltionInput,e);
        prtintList(*list);
    }

    if (ClearList(list))
    {
        list = NULL;
        printf("线性表成功释放\n");
        //prtintList(*list);
    }

    return 0;
    
    
}