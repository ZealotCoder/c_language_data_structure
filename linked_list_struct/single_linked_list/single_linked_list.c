#include <stdio.h>
#include <stdlib.h>
struct student_Node
{
    unsigned int student_ID;
    float student_Score;
    struct student_Node *next;
};

struct student_Node *head;
struct student_Node *ptr;

#define Linked_List_Init 1
#define Linked_List_Insert 2
#define Linked_List_Delete 3
#define Linked_List_Edit 4
#define Linked_List_Query 5
#define Linked_List_Print 6
#define Linked_List_Destroy 7
#define Linked_List_Quit 8

#define Linked_List_HEAD_Node 1
#define Linked_List_Mid_Node 2
#define Linked_List_Tail_Node 3

#define TRUE 1
#define FALSE 0

unsigned int g_global_exit = 0;

int signeled_Linked_List_Init();
int singeled_Linked_List_Insert();
int singeled_Linked_List_Delete();
int signeled_Linked_List_Query();
int singeled_Linked_List_Edit();
int singeled_Linked_List_Print();
int singeled_Linked_List_Destroy();
int singeled_Linked_List_Quit();

int main()
{
    //printf("中文输出测试\n");
    unsigned int operation = 0;
    printf("\t\t\t\t欢迎来到单链表(学生数据)学习部分!\t\t\t\t\n\n");
    do
    {
        printf("\t\t\t\t1.初始化单链表:\t\t\t\t\n");
        printf("\t\t\t\t2.单链表插入数据:\t\t\t\t\n");
        printf("\t\t\t\t3.单链表删除数据:\t\t\t\t\n");
        printf("\t\t\t\t4.单链表编辑数据:\t\t\t\t\n");
        printf("\t\t\t\t5.单链表查询数据:\t\t\t\t\n");
        printf("\t\t\t\t6.单链表打印数据:\t\t\t\t\n");
        printf("\t\t\t\t7.单链表整体删除:\t\t\t\t\n");
        printf("\t\t\t\t8.退出:\t\t\t\n\n");
        printf("\t\t\t\t请选择你的操作:\t\t\t\t\n");
        scanf("%u",&operation);
        switch (operation)
        {
            case Linked_List_Init:
                {
                    signeled_Linked_List_Init();
                    break;
                }
            case Linked_List_Insert:
                {
                    singeled_Linked_List_Insert();
                    break;
                }
            case Linked_List_Delete:
                {
                    singeled_Linked_List_Delete();
                    break;
                }
            case Linked_List_Edit:
                {
                    singeled_Linked_List_Edit();
                    break;
                }
            case Linked_List_Query:
                {
                    signeled_Linked_List_Query();
                    break;
                }
            case Linked_List_Print:
                {
                    singeled_Linked_List_Print();
                    break;
                }
            case Linked_List_Destroy:
                {
                    singeled_Linked_List_Destroy();
                    break;
                }
            case Linked_List_Quit:
                {
                    singeled_Linked_List_Quit();
                }
                g_global_exit = 1;
                break;
            default:
                {
                    printf("输入非法,请重新输入!\n");
                    break;
                }
        }
        if ( g_global_exit == TRUE)
        {
            break;
        }
        
    } while (1);
    

    return 0;
}

int signeled_Linked_List_Init()
{
    //链表初始化, 既是插入头结点
    //struct student_Node *ptr;
    printf("***********************链表节点初始化开始!**************************\n");
    //printf("demo数据,请勿当真,仅做测试使用\n");
    ptr = (struct student_Node *)malloc(sizeof(struct student_Node *));
    ptr->student_ID = 419030210;
    ptr->student_Score = 99.99f;
    ptr->next = NULL;
    head = ptr;


    //再插入一个数据
    ptr= (struct student_Node *)malloc(sizeof(struct student_Node *));
    ptr->next = NULL;
    ptr->student_ID = 419030280;
    ptr->student_Score = 55.55;
    head->next= ptr;
    printf("***********************链表节点初始化结束!**************************\n");
    return 0;
}

int singeled_Linked_List_Insert()
{
    printf("***********************链表节点插入开始!**************************\n");
    printf("请选择数据插入位置!\n");
    printf("1.链表头部\n");
    printf("2.链表指定位置!\n");
    printf("3.链表尾部!\n");
    unsigned int operation_Insert = 1;
    scanf("%u", &operation_Insert);
    switch (operation_Insert)
    {
        case Linked_List_HEAD_Node:     //链表头部插入
            {
                /* code */
                ptr = (struct student_Node *)malloc(sizeof(struct student_Node *));
                unsigned studeng_ID = 0;
                float student_Score = 0.0;
                printf("请输入学号:\n");
                scanf("%u",&studeng_ID);
                printf("请输入分数:\n");
                scanf("%f",&student_Score);
                ptr->student_ID = studeng_ID;
                ptr->student_Score = student_Score;
                ptr->next = NULL;
                if (head==NULL)
                {
                    /* code */
                    //如果头结点为空,则当前插入的节点成为头结点
                    head = ptr;
                    ptr = NULL;
                }
                else 
                {
                    /* code */
                    //如果头姐点不是空的,那需要将当前节点的next指向原先的头结点
                    ptr->next = head;
                    head = ptr;
                    ptr = NULL;
                }
                break;
            }
        case Linked_List_Mid_Node:     //链表指定位置插入
            {
                /* code */
                //根据指定的位置n6, 将新插入的节点插入链表当做第n+1个节点
                ptr = (struct student_Node *)malloc(sizeof(struct student_Node *));
                unsigned studeng_ID = 0;
                float student_Score = 0.0;
                printf("请输入学号:\n");
                scanf("%u",&studeng_ID);
                printf("请输入分数:\n");
                scanf("%f",&student_Score);
                ptr->student_ID = studeng_ID;
                ptr->student_Score = student_Score;

                unsigned int target_index = 0;
                printf("请输入目标节点位置:\n");
                scanf("%u",&target_index);

                struct student_Node *pre_Node, *current_Node;
                unsigned int node_num = 0;
                current_Node = head;

                if (head == NULL || target_index == 1)
                {
                    //如果当前链表为空, 则直接插入, 无需再查找位置
                    ptr->next = head;
                    head = ptr;
                    ptr = NULL;
                    break;
                }

                do
                {
                    /* code */
                    node_num++;
                    if (target_index == node_num)
                    {
                        /* code */
                        //pre_Node = current_Node;
                        if (node_num == 1)
                        {
                            /* code */
                            //在头部插入
                            ptr->next = head;
                            head = ptr;
                            break;
                        }


                        pre_Node->next = ptr;
                        ptr->next = current_Node;
                        break;
                    }
                    pre_Node = current_Node;
                    current_Node = current_Node->next;
                } while (NULL != current_Node);
                
                if (target_index > node_num)
                {
                    /* code */
                    //在链表尾部插入
                    pre_Node->next = ptr;
                    ptr->next = NULL;
                    break;
                }
                break;
            }
        case Linked_List_Tail_Node:     //链表尾部插入
            {
                /* code */
                ptr = (struct student_Node *)malloc(sizeof(struct student_Node *));
                unsigned studeng_ID = 0;
                float student_Score = 0.0;
                printf("请输入学号:\n");
                scanf("%u",&studeng_ID);
                printf("请输入分数:\n");
                scanf("%f",&student_Score);
                ptr->student_ID = studeng_ID;
                ptr->student_Score = student_Score;
                ptr->next = NULL;
                if (head==NULL)
                {
                    /* code */
                    //如果头结点为空, 那么这个节点就会被放在头结点位置
                    head = ptr;
                    ptr = NULL;
                    break;
                }
                else
                {
                    struct student_Node *temp = head;
                    while (NULL != temp->next)
                    {
                        /* code */
                        //先找到最后一个节点
                        temp = temp->next;
                    }
                    temp->next = ptr;
                    ptr = NULL;
                }
                
                break;
            }
        default:
            break;
    }
    printf("***********************链表节点插入结束!**************************\n");
    return 0;
    
}

int singeled_Linked_List_Delete()
{
    printf("***********************链表节点删除开始!**************************\n");
    printf("请选择刪除的节点的位置!(1.链表头部,2.链表指定位置,3.链表尾部)\n");
    unsigned int operation = 0;
    scanf("%d",&operation);
    switch (operation)
    {
        case Linked_List_HEAD_Node:
            {
                ptr = head;
                head = head->next;
                free(ptr);  //奇怪的问题, 执行到这里, 就卡主了, 没有什么报错!!!
                break;
            }
        case Linked_List_Mid_Node:
            {
                /* code */
                break;
            }
        case Linked_List_Tail_Node:
            {
                break;
            }
        default:
            {
                /* code */
                break;
            }
    }
    printf("***********************链表节点删除结束!**************************\n");
    return 0;
    
}
int signeled_Linked_List_Query()
{
    printf("***********************链表节点查询开始!**************************\n");
    printf("***********************链表节点查询结束!**************************\n");
    return 0;
    
}

int singeled_Linked_List_Edit()
{
    printf("***********************链表节点编辑开始!**************************\n");
    printf("***********************链表节点编辑结束!**************************\n");
    return 0;
    
}

int singeled_Linked_List_Print()
{
    printf("***********************链表节点打印开始!**************************\n");
    if (head == NULL)
    {
        printf("当前链表为空!\n");
        printf("***********************链表节点打印结束!**************************\n\n");
        return 0;
    }
    
    for ( ptr = head ; ptr != NULL ; ptr = ptr->next)
    {
        printf("studeng ID = %u, student Score = %f\n", ptr->student_ID,ptr->student_Score);
    }
    
    printf("***********************链表节点打印结束!**************************\n\n");
    return 0;
    
}

int singeled_Linked_List_Destroy()
{
    printf("链表删除完成!\n");
    return 0; 
    return 0;

}

int singeled_Linked_List_Quit()
{
    printf("即将退出单链表学习部分, 欢迎下次再来!\n");
    return 0; 
    return 0;

}
