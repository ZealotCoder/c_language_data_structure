#include <stdio.h>
#include <stdlib.h>
struct Node
{
    unsigned int data_field_1;
    struct Node *next;
};

struct Node *head;
struct Node *ptr;

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
unsigned int g_global_IsInit = 0;

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
    printf("\t\t\t\t欢迎来到单链表学习部分!\t\t\t\t\n\n");
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
    //判断链表初始化是否已经完成, 如果完成则无需再次初始化!
    if (g_global_IsInit)
    {
        printf("链表初始化已经完成,请勿重复初始化链表\n\n");
        return 1;
    }
    
    //链表初始化, 既是插入头结点
    printf("***********************链表节点初始化开始!**************************\n");
    ptr = (struct Node *)malloc(sizeof(struct Node *));
    ptr->data_field_1 = 419000;
    ptr->next = NULL;
    head = ptr;


    //插入一个数据
    ptr= (struct Node *)malloc(sizeof(struct Node *));
    ptr->next = NULL;
    ptr->data_field_1 = 419010;
    head->next= ptr;
    printf("***********************链表节点初始化正在进行......*******************\n");

    //插入一个数据
    ptr = (struct Node *)malloc(sizeof(struct Node*));
    ptr->next = NULL;
    ptr->data_field_1 = 416030;
    head->next->next = ptr;
    printf("***********************链表节点初始化结束!**************************\n\n");
    g_global_IsInit = 1;
    return 0;
}

int singeled_Linked_List_Insert()
{
    printf("***********************链表节点插入开始!**************************\n");

    printf("请选择数据插入位置!(1:头部    2:指定位置(指定位置的下一个节点)    3:尾部    4:终止插入操作)\n");
    unsigned int operation_Insert = 0;
    scanf("%u", &operation_Insert);

    if (operation_Insert == 4)
    {
        printf("用户终止了链表节点插入操作!\n\n");
        return 0;

    }
    

    ptr = (struct Node *)malloc(sizeof(struct Node *));
    if (ptr)
    {
        /* code */
        unsigned data_Field = 0;
        printf("请输入节点数据:\n");
        scanf("%u",&data_Field);
        ptr->data_field_1 = data_Field;
        ptr->next = NULL;
        g_global_IsInit = 1;
    }
    else
    {
        printf("内存申请失败! 单链表数据插入中断!\n\n");
        g_global_IsInit = 0;
        return 0;
    }

    switch (operation_Insert)
    {
        case Linked_List_HEAD_Node:     //链表头部插入
            {
                if (head==NULL)
                {
                    //如果链表为空,则当前插入的节点成为头结点
                    head = ptr;
                }
                else 
                {
                    //如果链表不为空,那需要将当前节点的next指向原先的头结点
                    ptr->next = head;
                    head = ptr;
                }
                g_global_IsInit = 1;
                break;
            }
        case Linked_List_Mid_Node:     //链表指定位置插入
            {
                unsigned int target_index = 0;
                printf("请输入节点位置:\n");
                scanf("%u",&target_index);//
                struct Node *temp = head;
                int i = 0;
                for (i = 0; i < target_index-1; i++)
                {
                    // 这里是为了找到第target_index个节点, 然后将新节点当做target_index节点的下一个节点, 新节点的next指向原本target_index节点的next;
                    if (temp)
                    {
                        temp = temp->next;
                    }
                    else
                    {
                        printf("该位置不存在!已超出当前链表长度!\n节点数据将被插入到链表尾部!\n");
                        return 0;
                    }
                    
                }
                ptr->next = temp->next;
                temp->next = ptr;
                g_global_IsInit = 1;
                break;
            }
        case Linked_List_Tail_Node:     //链表尾部插入
            {
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
                    struct Node *temp = head;
                    while (NULL != temp->next)
                    {
                        //先找到最后一个节点
                        temp = temp->next;
                    }
                    temp->next = ptr;
                }
                g_global_IsInit = 1;
                break;
            }
        default:
            {
                printf("插入位置选择无效! 节点插入操作被中断!\n");
                g_global_IsInit = 0;
                break;
            }

    }
    printf("***********************链表节点插入结束!**************************\n\n");
    return 0;
    
}

int singeled_Linked_List_Delete()
{
    printf("***********************链表节点删除开始!**************************\n");
    printf("请选择刪除的节点的位置!(1:头部    2:指定位置    3:尾部    4:终止节点删除)\n");
    unsigned int operation_Delete = 0;
    scanf("%d",&operation_Delete);

    if (operation_Delete == 4)
    {
        printf("用户终止了删除节点操作!\n\n");
        return 1;
    }
    
    if (head == NULL)
    {
        printf("当前链表为空, 无法进行节点删除操作!\n\n");
        return 1;
    }

    switch (operation_Delete)
    {
        case Linked_List_HEAD_Node:
            {
                ptr = head;
                head = ptr->next;
                free(ptr);  //奇怪的问题:VScode + MinGW 执行到这里, 就卡主了, 没有什么报错!!!
                printf("删除头节点成功!\n");
                break;
            }

        case Linked_List_Mid_Node:
            {
                /* code */
                ptr = head;
                struct Node* pre_Node = head;
                unsigned int delete_Index = 0;
                printf("请输入删除节点的位置:\n");
                scanf("%u", &delete_Index);

                if (delete_Index == 0)
                {
                    printf("您输入的位置不存在,删除指点节点操作已结束!\n\n");
                    return 0;
                }
                

                if (delete_Index == 1)
                {
                    ptr = head;
                    head = ptr->next;
                    free(ptr);  //奇怪的问题:VScode + MinGW 执行到这里, 就卡主了, 没有什么报错!!!
                    printf("删除节点成功!\n");
                    break;
                }
                
                int i = 0;
                for ( i = 0; i < delete_Index -1 ; i++)
                {
                    pre_Node = ptr;
                    ptr = ptr->next;
                    if (ptr == NULL)
                    {
                        printf("您输入的位置不存在, 删除节点操作已结束!\n\n");
                        return 0;
                    }

                }
                if (ptr)
                {
                    pre_Node->next = ptr->next;
                    free(ptr);
                }
                break;
            }
        case Linked_List_Tail_Node:
            {
                ptr = head;
                struct Node* pre_Node = head;
                while (ptr-> next != NULL)
                {
                    pre_Node = ptr;
                    ptr = ptr->next;
                }
                pre_Node -> next = NULL;
                free(ptr);
                printf("删除尾节点成功!\n");
                break;
            }
        default:
            {
                printf("用户输入无效! 删除节点操作已结束!\n\n");
                break;
            }
    }
    printf("***********************链表节点删除结束!**************************\n\n");
    return 0;
    
}
int signeled_Linked_List_Query()
{
    printf("***********************链表节点查询开始!**************************\n");

    if (head == NULL)
    {
        printf("链表为空!请先初始化链表或者加入新的数据!\n\n");
        return 0;
    }
    
    unsigned int target_Data = 0;
    unsigned int targetData_Index  =0;
    unsigned int targetData_find = 0; // 1 找到了, 0 没找到
    printf("请输入想要查找的数据:\n");
    scanf("%u",&target_Data);
    ptr = head ;
    while (ptr != NULL)
    {
        targetData_Index++;
        if (ptr->data_field_1 == target_Data)
        {
            printf("你要找的数据 %d 位于链表的第 %u 个节点!\n", target_Data, targetData_Index );
            targetData_find = 1;
            break;
        }
        ptr = ptr->next;
        
    }
    if (targetData_find == 0)
    {
        printf("你要找的数据 %d 在当前链表中没有找到!\n", target_Data, targetData_Index );
    }
    
    printf("***********************链表节点查询结束!**************************\n");
    return 0;
    
}

int singeled_Linked_List_Edit()
{
    printf("***********************链表节点编辑开始!**************************\n");
    if (g_global_IsInit == 0 || head == NULL)
    {
        printf("链表暂未初始化 或者 数据为空, 请先添加数据!\n\n");
        return 0;
    }

    unsigned int target_Index = 0;
    unsigned int new_Data = 0;
    unsigned int targetIndex_Find = 0; // 1 找到了指定位置,修改成功    ;          0 没找到指定位置, 修改失败
    printf("请输入你想修改的节点的序号:\n");
    scanf("%u", &target_Index);
    printf("请输入节点的新数据:\n");
    scanf("%u", &new_Data);
    ptr = head;

    int i = 0;
    while (ptr != NULL)
    {
        i++;
        if (i == target_Index)
        {
            printf("链表第 %u 个节点 数据域 从 %u 修改为 %u \n\n", target_Index, ptr->data_field_1, new_Data);
            ptr->data_field_1 = new_Data;
            targetIndex_Find = 1;
        }
        
        ptr = ptr->next;
    }
    
    if (targetIndex_Find == 0)
    {
        printf("用户想要修改的链表第 %u 个节点不存在! 请先确认数据的有效性!\n", target_Index);
    }
    printf("***********************链表节点编辑结束!**************************\n\n");
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
    unsigned int list_Index = 0;
    for ( ptr = head ; ptr != NULL ; ptr = ptr->next)
    {
        list_Index++;
        printf("第 %u 个节点数据段 data_field_1 = %u\n", list_Index , ptr->data_field_1);
    }
    
    printf("***********************链表节点打印结束!**************************\n\n");
    return 0;
    
}

int singeled_Linked_List_Destroy()
{
    printf("链表删除完成!\n");
#if 0       //还没想好怎么一次性删除整个链表
    if (head == NULL || g_global_IsInit == 0)
    {
        printf("链表暂未初始化 或者 数据为空, 请先添加数据!\n\n");
        return 0;
    }

    ptr = head;
    unsigned int node_Num = 0;
    struct Node* tail_Node = NULL;
    while (ptr!= NULL )
    {
        ptr = ptr->next;
        node_Num++;
    }
    //free(head,head+node_Num));
    
#endif
    printf("还没想好怎么一次性删除整个链表,所以这里没实现!\n\n");
    return 0; 
}

int singeled_Linked_List_Quit()
{
    printf("即将退出单链表学习部分, 欢迎下次再来!\n");
    return 0; 
}
