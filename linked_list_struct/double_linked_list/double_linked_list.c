#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    struct Node *pre;
    //数据域
    int data_Filed;
    struct Node *next;
}Node;
Node *ptr,*head,*tail;

void init();
void insert_link();
void print_link();
void search_link();
void delete_link();

int main()
{
    //printf("中文输出测试\n");
    init();
    unsigned int operation = 0;
    printf("\t\t\t\t欢迎来到双链表学习部分!\t\t\t\t\n\n");
    do
    {
        printf("\t\t\t\t1.插入:\t\t\t\t\n");
        printf("\t\t\t\t2.删除:\t\t\t\t\n");
        printf("\t\t\t\t3.查找:\t\t\t\t\n");
        printf("\t\t\t\t4.展示:\t\t\t\t\n");
        printf("\t\t\t\t5.退出:\t\t\t\t\n");
        printf("\t\t\t\t请选择你的操作:\t\t\t\t\n");
        scanf("%u",&operation);
        switch (operation)
        {
            case 1:
                {
                    insert_link();
                    break;
                }
            case 2:
                {
                    delete_link();
                    break;
                }
            case 3:
                {
                    search_link();
                    break;
                }
            case 4:
                {
                    print_link();
                    break;
                }
            case 5:
                {
                    printf("\t\t\t\t退出!\t\t\t\t\n");
                    exit(0);
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

void  init()
{




}

void insert_link()
{


}

void print_link()
{


}

void search_link()
 {


 }

 void delete_link()
 {



 }
