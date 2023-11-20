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
    if (head)
    {
        /* code */
    }
    else
    {
        /* code */
        ptr = (Node *)malloc(sizeof(Node));
        ptr->data_Filed = 3;
        ptr->pre = NULL;
        ptr->next = NULL;
        head = ptr;
        ptr = (Node *)malloc(sizeof(Node));
        ptr->data_Filed = 9;
        ptr->next = head;
        ptr->pre = NULL;
        head = ptr;
        ptr = (Node *) malloc(sizeof(Node));
        ptr->data_Filed = 10;
        ptr->next = head;
        ptr->pre = NULL;
        head = ptr;

    }
    



}

void insert_link()
{


}

void print_link()
{
    if (head == NULL)
    {
        /* code */
        printf("链表为空!");
    }
    int count = 0;
    ptr = head;
    while (ptr)
    {
        /* code */
        count++;
        printf("第%d个节点数据是:%d\n",count, ptr->data_Filed);
        ptr = ptr->next;
    }
    
    

}

void search_link()
 {
    ptr = head;
    if (ptr == NULL)
    {
        printf("链表为空!\n");
    }
    int count = 0;
    int target = 0;
    printf("请输入要查找的数据:\n");
    scanf("%d", &target);
    while (ptr)
    {
        /* code */
        count++;
        if (target == ptr->data_Filed)
        {
            /* code */
            printf("要查找的数据:%d位于链表第%d个节点\n",target,count);
            break;
        }
        ptr = ptr->next;
        if (ptr == NULL)
        {
            /* code */
            printf("查找失败!\n");
        }
        
    }
 }

 void delete_link()
 {



 }
