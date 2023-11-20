#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    //数据域
    int data_Filed;
    struct Node *next;
}Node,*ptr_Node;

Node *ptr,*head;

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
    printf("\t\t\t\t欢迎来到循环单链表学习部分!\t\t\t\t\n\n");
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
                }
            default:
                {
                    printf("输入非法,请重新输入!\n");
                    break;
                }
        }
        
    } while (1);
    

    return 0;


};


void init()
{
    ptr = (ptr_Node)malloc(sizeof(Node));
    ptr->data_Filed = 1;
    ptr->next = ptr;
    head = ptr;

    ptr = (ptr_Node)malloc(sizeof(Node));
    ptr->data_Filed = 10;
    ptr->next = head;
    head->next = ptr;

    ptr = (ptr_Node)malloc(sizeof(Node));
    ptr->data_Filed = 10;
    head->next->next = ptr;
    ptr->next = head;


};

void insert_link()
{
    
};

void print_link()
{
    if (head)
    {
        /* code */
        printf("循环单链表为空\n");
        return ;
    }
    else
    {
        /* code */
        ptr = head;
        int count = 0;
        while (ptr->next == head)
        {
            /* code */
            count++;
            printf("第%d个节点的数据是%d\n",count,ptr->data_Filed);
             ptr = ptr->next;
        }
        
    }
    return ;
    
};

void search_link()
{
    
};

void delete_link()
{
    
};