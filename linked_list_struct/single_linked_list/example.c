#include <stdio.h>
/*
���ļ���������ʵ�ֵ�����
created time:2020.07.24
@Author��Jeaten
@E-mail��ljt_IT@163.com
*/
typedef struct Node{
    int data;
    struct Node *next;
}node;
node *head, *ptr;
void main(){
    init();
    int choice=8,num;
    while(choice!=0){
        printf("+----�������ϵͳ----+\t\t\n");
        printf("|\t1.����\t     |\n");
        printf("|\t2.ɾ��\t     |\n");
        printf("|\t3.����\t     |\n");
        printf("|\t4.չʾ\t     |\n");
        printf("|\t0.�˳�\t     |\n");
        printf("+--------------------+\t\t\n");
        printf("���������ѡ��\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
            insert_link();//�������
            break;
        case 2:
            delete_link(head);//ɾ������
            break;
        case 3:
            printf("�������Ҫ���ҵ�����\n");
            scanf("%d",&num);
            query_link(head,num);//���Ҳ���
            break;
        case 4:
            print_link(head);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("�����������������룡\n");
            break;
        }
    }
}
void init(){//��ʼ��
    ptr=(node *)malloc(sizeof(node *));
    ptr->data=1;
    ptr->next=NULL;
    head=ptr;
    ptr=(node *)malloc(sizeof(node *));
    ptr->data=2;
    head->next=ptr;
    ptr->next=NULL;
    ptr=(node *)malloc(sizeof(node *));
    ptr->data=3;
    head->next->next=ptr;
    ptr->next=NULL;
    ptr=(node *)malloc(sizeof(node *));
    ptr->data=4;
    head->next->next->next=ptr;
    ptr->next=NULL;
}
void print_link(node *ptr){
    int count=1;
    if (ptr==NULL){
        printf("����Ϊ��!\n");
    }
    else{
        while(ptr!=NULL){
            printf("%d-th����ֵ:%d\n",count,ptr->data);
            ptr=ptr->next;
            count++;
        }
    }
}
void insert_link(){//�������
    int data=0;
    int choice;
    printf("���������λ��(1:��ͷ,2:�м�,3:��β):\n");
    scanf("%d",&choice);
    switch(choice){
    case 1://�ӿ�ʼ����
        printf("������Ҫ��������ݣ�");
        scanf("%d",&data);
        ptr=(node *)malloc(sizeof(node *));
        if (ptr){
            ptr->data=data;//Ϊ�����㸳ֵ
            ptr->next=head;//���½�����ӵ�ԭʼ����ͷ��
            head=ptr;//���������ͷ
            printf("����Ѳ��룡\n");
        }else{
            printf("�����ڴ�ʧ�ܣ�");
        }
        break;
    case 2://���м����
        printf("������Ҫ��������ݣ�");
        scanf("%d",&data);
        ptr=(node *)malloc(sizeof(node *));
        ptr->data=data;
        if(ptr){
            int loc,i;
            node *temp=head;
            printf("������Ҫ�����λ�ã������λ��֮�󣩣�");
            scanf("%d",&loc);
            for(i=0;i<loc-1;i++){
                if(temp){
                    temp=temp->next;
                }else{
                    printf("��λ�ò����ڣ�����������λ�ó��ȴ��������ȵ��µģ�\n");
                    return;
                }
            }
            ptr->next=temp->next;
            temp->next=ptr;
            printf("����Ѳ��룡\n");
        }else{
            printf("�����ڴ�ʧ�ܣ�");
        }
        break;
    case 3://�ӽ�β����
        printf("������Ҫ��������ݣ�");
        scanf("%d",&data);
        ptr=(node *)malloc(sizeof(node *));
        ptr->data=data;
        if (ptr){
            if(head){//����Ϊ��
                node *temp=head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=ptr;
                ptr->next=NULL;
                printf("����Ѳ��룡\n");
            }else{//����Ϊ��
                ptr->next=NULL;
                head=ptr;
            }
        }else{
            printf("�����ڴ�ʧ�ܣ�");
        }
        printf("����Ѳ��룡\n");
        break;
    default:
        printf("�����������������룡");
        insert_link();
        break;
    }
}
void delete_link(){//ɾ������
    int loc;
    int i;
    node *p;
    printf("��������Ҫɾ������λ��(1:��һ��,-1:���һ��,����:�м�λ��):\n");
    scanf("%d",&loc);
    switch(loc){
    case 1:
        ptr=head;
        head=ptr->next;
        free(ptr);
        printf("��һ�����ɾ���ɹ���\n");
        break;
    case -1:
        if(head->next==NULL){
            ptr=head;
            head=NULL;
            free(ptr);
        }else{
            ptr=head;
            while(ptr->next!=NULL){
                p=ptr;
                ptr=ptr->next;
            }
            p->next=NULL;
            free(ptr);
        }
        printf("���һ�����ɾ���ɹ���\n");
        break;
    default:
        ptr=head;
        for(i=0;i<loc-1;i++){
            p=ptr;
            ptr=ptr->next;
            if(ptr==NULL){
                printf("��λ�ò�����(����������λ�ó��ȴ��������ȵ��µ�!\n");
                return;
            }
        }
        p->next=ptr->next;
        free(ptr);
        printf("%d-th�����ɾ���ɹ�!\n",loc);
        break;
    }
}
void query_link(node *ptr,int data){//���Ҳ���
    int count=1;
    int flag=0;
    if (ptr==NULL){
        printf("����Ϊ��!\n");
    }
    else{
        while(ptr!=NULL){
            if(ptr->data==data){
                flag=1;
                printf("�������������еĵ�%d��λ��...\n",count);
            }
            ptr=ptr->next;
            count++;
        }
        if (!flag){
            printf("�����ֲ��������У�\n");
        }
    }
}