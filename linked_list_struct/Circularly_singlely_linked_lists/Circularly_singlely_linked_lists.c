#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    //������
    int data_Filed;
    struct Node *next;
}Node,*ptr_Node;

Node *ptr,*head;

void init();
void insert_link();
void print_link();
void search_link();
void delete_link();
void main()
{
    //printf("�����������\n");
    init();
    unsigned int operation = 0;
    printf("\t\t\t\t��ӭ����ѭ��������ѧϰ����!\t\t\t\t\n\n");
    do
    {
        printf("\t\t\t\t1.����:\t\t\t\t\n");
        printf("\t\t\t\t2.ɾ��:\t\t\t\t\n");
        printf("\t\t\t\t3.����:\t\t\t\t\n");
        printf("\t\t\t\t4.չʾ:\t\t\t\t\n");
        printf("\t\t\t\t5.�˳�:\t\t\t\t\n");
        printf("\t\t\t\t��ѡ����Ĳ���:\t\t\t\t\n");
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
                    printf("\t\t\t\t�˳�!\t\t\t\t\n");
                    exit(0);
                }
            default:
                {
                    printf("����Ƿ�,����������!\n");
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
    head->next = ptr;
    ptr->next = head;
    
};

void insert_link()
{
    
};

void print_link()
{
    
};

void search_link()
{
    
};

void delete_link()
{
    
};