#include <stdio.h>
#include <stdlib.h>
struct student_Node
{
    unsigned int student_ID;
    unsigned int student_Score;
    struct student_Node *next;

} *head, *tail;

#define Linked_List_init 1
#define Linked_List_insert 2
#define Linked_List_delete 3
#define Linked_List_Edit 4
#define list_List_Query 5
#define Linked_List_Print 6
#define Linked_List_Quit 7

#define TRUE 1
#define FALSE 0

unsigned int g_global_exit = 0;

int signeled_Linked_List_Init();
int singeled_Linked_List_Insert();
int singeled_Linked_List_Delete();
int signeled_Linked_List_Query();
int singeled_Linked_List_Edit();
int singeled_Linked_List_Print();
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
        printf("\t\t\t\t7.退出:\t\t\t\n\n");
        printf("\t\t\t\t请选择你的操作:\t\t\t\t\n");
        scanf("%u",&operation);
        switch (operation)
        {
            case Linked_List_init:
                {
                    /* code */
                    signeled_Linked_List_Init();
                    break;
                }
            case Linked_List_insert:
                {
                    /* code */
                    singeled_Linked_List_Insert();
                    break;
                }
            case Linked_List_delete:
                {
                    singeled_Linked_List_Delete();
                    break;
                }
            case Linked_List_Edit:
                {
                    singeled_Linked_List_Edit();
                    break;
                }
            case list_List_Query:
                {
                    signeled_Linked_List_Query();
                    break;
                }
            case Linked_List_Print:
                {
                    singeled_Linked_List_Print();
                    break;
                }
            case Linked_List_Quit:
                {
                    singeled_Linked_List_Quit();
                }
                /* code */
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
    printf("链表初始化完成!\n");
    return 0;
}

int singeled_Linked_List_Insert()
{
    printf("链表节点插入完成!\n");
    return 0; 
    return 0;
    
}

int singeled_Linked_List_Delete()
{
    printf("链表节点删除完成!\n");
    return 0; 
    return 0;
    
}
int signeled_Linked_List_Query()
{
    printf("链表节点查询完成!\n");
    return 0; 
    return 0;
    
}

int singeled_Linked_List_Edit()
{
    printf("链表节点编辑完成!\n");
    return 0; 
    return 0;
    
}

int singeled_Linked_List_Print()
{
    printf("链表节点打印完成!\n");
    return 0; 
    return 0;
    
}

int singeled_Linked_List_Quit()
{
    printf("即将退出单链表学习部分, 欢迎下次再来!\n");
    return 0; 
    return 0;

}
