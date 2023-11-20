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
    int target_Index = 0;
    printf("请输入期望插入的位置:(1:头结点:2:指定结点;3:尾结点)\n");
    scanf("%d",&target_Index);
    switch (target_Index)
    {
        case 1:
            /* code */
            //ptr = head;
            ptr = (Node *)malloc(sizeof(Node));
            printf("请输入数据:\n");
            scanf("%d",&(ptr->data_Filed));
            if (head == NULL)
            {
                /* code */
                ptr ->next = NULL;
                ptr->pre = NULL;
                head = ptr;
                printf("头结点插入成功!\n");
                break;
            }
            else
            {
                ptr->pre = NULL;
                ptr->next = head;
                head->pre = ptr;
                head = ptr;
                printf("头结点插入成功!\n");
                break;

            }
            
            break;
        case 2:
            /* code */
            ptr = (Node *)malloc(sizeof(Node));
            int index = 0;
            printf("请输入数据:\n");
            scanf("%d",&(ptr->data_Filed));
            printf("请输入要插入的位置:\n");
            scanf("%d",&index);
            Node *temp = head;
            if (head)
            {
                /* code */
                for (size_t i = 0; i < index-1; i++)
                {
                    /* code */
                    if (!temp->next)
                    {
                        /* code */
                        //已经找到尾结点了,还是没找到指定位置index
                        printf("位置不存在!\n");
                        return;

                    }
                    //已经找到了指定的位置!
                    temp= temp->next;
                }
                if (temp->next == head)
                {
                    /* code */
                    head ->next = ptr;
                    ptr->next = head;
                    head->pre = ptr;
                    ptr->pre = head;
                    printf("结点插入成功!\n");

                }
                else
                {
                    ptr->next = temp->next;
                    ptr->pre = temp;
                    temp->next->pre = ptr;
                    temp->next = ptr;
                    printf("结点插入成功!\n");
                }
                
                
            }
            else
            {
                printf("链表为空!\n");
            }
            break;
        case 3:
            printf("请输入要插入的数据:");
            int num = 0;
            scanf("%d",&num);
            ptr=(Node *)malloc(sizeof(Node));
            if(head){//头结点不为空
                Node *temp=head;
                while(temp->next){
                    temp=temp->next;
                }
                temp->next=ptr;
                ptr->data_Filed=num;
                ptr->pre=temp;
                ptr->next=NULL;
                printf("结点插入成功！\n");
            }else{//头结点为空
                ptr->next=NULL;
                ptr->pre=NULL;
                ptr->data_Filed=num;
                head=ptr;
                printf("结点插入成功！\n");
            }
            break;
        default:
            break;
    }


}

void print_link()
{
    if (head == NULL)
    {
        /* code */
        printf("链表为空!\n");
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
    int choice,i,loc;
    printf("请输入要删除的位置(1:头结点;2:指定结点;3:尾结点)\n");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        if(head){//链表不为空则进行操作
            ptr=head;
            head=head->next;
            head->pre=NULL;
            free(ptr);
            printf("结点删除成功！\n");
        }else{
            printf("链表为空！\n");
        }
        break;
    case 2:
        if(head){
            printf("请输入要删除结点的位置：");
            scanf("%d",&loc);
            Node *temp=head;
            for(i=0;i<loc;i++){
                if(temp->next){
                    temp=temp->next;
                }else{
                    printf("该插入位置不存在（可能是由于输入位置大于链表长度导致的）！\n");
                    return;
                }
            }
            if(temp->next){
                ptr=temp;
                ptr->pre->next=ptr->next;
                ptr->next->pre=ptr->pre;
                free(ptr);
            }else{
                temp->pre->next=NULL;
                free(temp);
                printf("该结点为尾结点，已删除！\n");
            }
        }else{
            printf("链表为空！\n");
        }
        break;
    case 3:
        if(head){
            ptr=head;
            while(ptr->next){
                ptr=ptr->next;
            }
            ptr->pre->next=NULL;
            free(ptr);
            printf("结点删除成功！\n");
        }else{
            printf("链表为空！\n");
        break;
    default:
        printf("输入有误，请重新输入！\n");
        delete_link();
        break;
        }
    }


 }
