#include "linklist.h"
#include "linklist.c"

int main(){
    LinkList list ;
    int result = InitList(&list);
    if (result == OK)
    {
        printf("初始化成功\n");
    }

    int e = 0;
    result = GetElem(list,1,&e);
    if (result == OK)
    {
        printf("第1个元素是%d\n",e);
    }else{
        printf("查询失败！");
    }
    
    
}