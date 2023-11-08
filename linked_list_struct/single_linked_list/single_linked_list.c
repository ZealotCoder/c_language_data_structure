#include <stdio.h>
#include <stdlib.h>
/*
?????????????????????????
created time:2020.07.26
@Author??Jeaten
@E-mail??ljt_IT@163.com
*/
typedef struct Node{
    int data;
    struct Node *next;
}node;
node *ptr,*head;

void init_link(){
    ptr=(node *)malloc(sizeof(node));
    ptr->data=1;
    head=ptr;
    ptr=(node *)malloc(sizeof(node));
    ptr->data=2;
    head->next=ptr;
    ptr->next=head;
}
void insert_link(){
    int choice,data,loc,i;
    choice = 0;
    printf("??????????????锟斤拷??(1:???? 2:???锟斤拷?? 3:锟斤拷???)\n");
    scanf("%d",&choice);
    ptr=(node *)malloc(sizeof(node));
    switch(choice){
        case 1://?????????
            {
                printf("??????????????");
                scanf("%d",&data);
                ptr->data=data;
                if(head){
                    node *temp=head;
                    while(temp->next!=head){
                        temp=temp->next;
                    }
                    ptr->next=head;
                    temp->next=ptr;
                    head=ptr;
                    printf("??????????\n");
                }else{
                    head=ptr;
                    ptr->next=head;
                    printf("??????????\n");
                }
                break;
            }
        case 2://???锟斤拷?锟斤拷???
            {
                printf("?????????锟斤拷???");
                scanf("%d",&loc);
                node *temp=head;
                if(head){
                    for(i=0;i<loc-1;i++){
                        if(temp->next!=head){
                            temp=temp->next;
                        }else{
                            printf("\n??锟斤拷?锟斤拷?????,??????????锟斤拷??????????????????\n");
                            return;
                        }
                    }
                    printf("??????????????");
                    scanf("%d",&data);
                    ptr->data=data;
                    ptr->next=temp->next;
                    temp->next=ptr;
                    printf("??????????\n");
                }
                else
                {
                    printf("??????????锟斤拷?锟斤拷??????\n");
                }
                break;
            }
        case -1://锟斤拷??????
            {
                printf("??????????????");
                scanf("%d",&data);
                ptr->data=data;
                if(head){
                    node *temp=head;
                    while(temp->next!=head){
                        temp=temp->next;
                    }
                    temp->next=ptr;
                    ptr->next=head;
                    printf("??????????\n");
                }else{
                    head=ptr;
                    ptr->next=head;
                    printf("??????????\n");
                }
                break;
            }
        default:
            {
                printf("????????");
                break;
            }

    }
}
void delete_link(){
    int choice,loc,i;
    printf("?????????????????锟斤拷??(1:????2:???锟斤拷??-1:锟斤拷???)\n");
    scanf("%d",&choice);
    switch(choice){
    case 1://???????
        if(head){
            node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            if(temp==head){
                ptr=head;
                head=NULL;
                free(ptr);
                printf("???????????\n");
            }else{
                ptr=head;
                temp->next=head->next;
                head=head->next;
                free(ptr);
                printf("???????????\n");
            }
        }else{
            printf("????????\n");
        }
        break;
    case 2://???锟斤拷?????
        printf("???????????????锟斤拷???\n");
        scanf("%d",&loc);
        if(head){
            node *temp=head;
            for(i=0;i<loc;i++){
                if(temp->next!=head){
                    ptr=temp;
                    temp=temp->next;
                }else{
                    printf("??锟斤拷?锟斤拷????????????????????锟斤拷??????????????????\n");
                    return;
                }
            }
            if(temp==head){
                ptr=head;
                head=NULL;
                free(ptr);
                printf("???????????\n");
            }else{
                ptr->next=temp->next;
                free(temp);
                printf("???????????\n");
            }
        }else{
            printf("????????\n");
        }
        break;
    case -1://锟斤拷??????
        if(head){
            node *temp;
            ptr=head;
            while(ptr->next!=head){
                temp=ptr;
                ptr=ptr->next;
            }
            if(ptr==head){
                head=NULL;
                free(ptr);
                printf("???????????\n");
            }else{
                temp->next=head;
                free(ptr);
                printf("???????????\n");
            }
        }else{
            printf("????????\n");
        }
        break;
    default:
        printf("????????\n");
        break;
    }
}
void print_link(node *head){
    int count=1;
    node *ptr=head;
    if(head){
       while(ptr->next!=head){
            printf("%d-th?????????%d\n",count,ptr->data);
            ptr=ptr->next;
        }
        printf("%d-th?????????%d\n",count,ptr->data);
    }else{
        printf("????????\n");
    }
}
void search_link(){
    int data,count=1,flag=0;
    if(!head){
        printf("????????\n");
    }else{
        ptr=head;
        printf("???????????????????");
        scanf("%d",&data);
        while(ptr->next!=head){
            if(ptr->data==data){
                printf("?????????????锟斤拷??%d??锟斤拷???\n",count);
                flag=1;
                return;
            }else{
            }
            ptr=ptr->next;
            count++;
        }
        if(ptr->data==data){
            printf("?????????????锟斤拷??%d??锟斤拷???\n",count);
            flag=1;
        }
        if(!flag){
            printf("??????????????锟斤拷?\n");
        }
    }
}

int main(){
    int choice=888;
//    init_link();//?????????
    while(choice!=0){
        printf("+-???????????????-+\t\t\n");
        printf("|\t1.????\t     |\n");
        printf("|\t2.???\t     |\n");
        printf("|\t3.????\t     |\n");
        printf("|\t4.??\t     |\n");
        printf("|\t0.???\t     |\n");
        printf("+--------------------+\t\t\n");
        printf("????????????\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            insert_link();
            break;
        case 2:
            delete_link();
            break;
        case 3:
            search_link();
            break;
        case 4:
            print_link(head);
            break;
        case 0:
            break;
        default:
            printf("????????\n");
            break;
        }
    }
    return 0;
}