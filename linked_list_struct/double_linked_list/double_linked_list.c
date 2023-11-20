#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    Node *pre;
    //数据域
    int data_Filed;
    Node *next;
}Node;
Node *ptr,*head,*tail;

void init();
void print_link();
void search_link();
void delete_link();

int main()
{
    //printf("中文输出测试\n");
    unsigned int operation = 0;
    printf("\t\t\t\t欢迎来到双链表学习部分!\t\t\t\t\n\n");
    do
    {
        printf("\t\t\t\t1.初始化双链表:\t\t\t\t\n");
        printf("\t\t\t\t2.双链表插入数据:\t\t\t\t\n");
        printf("\t\t\t\t3.双链表删除数据:\t\t\t\t\n");
        printf("\t\t\t\t4.双链表编辑数据:\t\t\t\t\n");
        printf("\t\t\t\t5.双链表查询数据:\t\t\t\t\n");
        printf("\t\t\t\t6.双链表打印数据:\t\t\t\t\n");
        printf("\t\t\t\t7.退出:\t\t\t\n\n");
        printf("\t\t\t\t请选择你的操作:\t\t\t\t\n");
        scanf("%u",&operation);
        switch (operation)
        {
            case 1:
                {
                    ;
                    break;
                }
            default:
                {
                    printf("输入非法,请重新输入!\n");
                    break;
                }
        }
        
    } while (1);
    

    return 0;
}

