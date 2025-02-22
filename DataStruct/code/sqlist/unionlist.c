#include "sqlist.h"
#include <time.h>

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
        //printf("该线性表的元素有:");
        for (int i = 0; i < list.listlength; i++)
        {
            printf("%d ",list.data[i]);
        }
        printf("\n");
        
    }
} 

/**功能：使用0~100随机数给线性表填充数据
 * 参数：list:被填充数据的线性表
 *       lengthUserInput:填充多长的数据
 * 返回值：成功返回OK，失败返回false
 */
Status fillList(sqList* list,int lengthUserInput)
{
    if (lengthUserInput>MAXSIZE)
    {
        printf("错误：生成数据长度超出最大值\n");
        return false;
    }
    
    for (int i = 0; i < lengthUserInput; i++)
    {
        ListInsert(list,i+1,(rand()%100));
        //printf("i=%d,test.length=%d,,number=%d\n",i,list->listlength,rand()%100);
    }
    return OK;
    
}

/**功能：求两个线性表的并集，并将并集结果返回
 * 参数：listFirst:求并集的第一个线性表
 *       listSecond:求并集的第二个线性表
 * 返回值：并集的结果
 */
sqList unionsqlist(sqList listFirst, sqList listSecond)
{
    
    sqList *result = NULL;
    InitList(&result);
    sqList *extraElem =NULL;
    InitList(&extraElem);      //收集listSecond中不在listFirst中的元素
    ElemType e = 0;
    int locate = 1;                                //用来对新的线性表的要插入元素的位置

    for (int i = 0; i < listSecond.listlength; i++)
    {
        if (!LocateElem(listFirst,listSecond.data[i]))  //将不存在于listfirst的listsecond中的元素全部交给extraElem线性表
        {
            ListInsert(extraElem,locate,listSecond.data[i]);
           // printf("不存在于第一张线性表的元素是:%d，此时i=%d\n",listSecond.data[i],i);
            locate++;
        }
    }
    
   // printf("locate=%d\n",locate);
    
    int flag = 0;      //控制extraElem中的元素移动
    
    for(int i=0;i<(extraElem->listlength+listFirst.listlength);i++)//如果listFirst中不存在的listSecond元素与原来listFirst元素总和超过最大长度 舍弃一部分listSecond元素
    {
        if(i<listFirst.listlength)   //先将所有listFirst元素放到result中
        {
           // printf("从线性表1中添加到结果中的元素是:%d",listFirst.data[i]);
            ListInsert(result,i+1,listFirst.data[i]);
           // printf("此时result表长=%d,i=%d\n",result->listlength,i);
        }
        else
        {
            if(i>=MAXSIZE)
            {
                printf("已经超出线性表最大范围，剩余元素将舍弃\n");
                printf("此时线性表表长等于=%d,结果为:\n",result->listlength);
                prtintList(*result);
                break;
            }
            if(extraElem->listlength>0)   
            {
              //  printf("--------\n");
            //    printf("从线性表2中添加到结果中的元素是:%d,此时i=%d,flag=%d\n",extraElem->data[flag],i,flag);
                ListInsert(result,i+1,extraElem->data[flag]);
              //  printf("此时result表长=%d\n",result->listlength);
                flag++;
            }
            
        }
    }
   // printf("###并集函数结束后，结果为：\n");
   // prtintList(*result);
    //printf("\n");
    return *result;

}


int main()
{
    sqList* listFirst = NULL;
    sqList* listSecond = NULL;
    int lengthFirst = 0;
    int lengthSecond = 0;
    srand(time(NULL));  //初始化随机数种子

     if(InitList(&listFirst) && InitList(&listSecond))
     {
         printf("==========初始化成功=======\n");
     }

     printf("请输入第一个线性表数据长度:");
     scanf("%d",&lengthFirst);
     printf("\n");

     printf("请输入第二个线性表数据长度：");
     scanf("%d",&lengthSecond);
     printf("\n");

    if (fillList(listFirst,lengthFirst) && fillList(listSecond,lengthSecond))
    {
         printf("成功填充两个线性表\n");
         printf("线性表1:\n");
         prtintList(*listFirst);
         printf("\n");
         printf("线性表2：\n");
         prtintList(*listSecond);
     }

   

    printf("------对两个线性表求并集-----\n");
    printf("\n");
    sqList *result = NULL;
    InitList(&result);
    *result = unionsqlist(*listFirst,*listSecond);
    if (!ListEmpty(*result))
    {
        printf("并集成功，并集的结果为:\n");
        prtintList(*result);
    }

    
    ClearList(listFirst);
    ClearList(listSecond);
    return 0;
    
    

}