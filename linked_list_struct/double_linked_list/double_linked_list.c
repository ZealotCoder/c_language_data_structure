#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    Node *pre;
    //������
    int data_Filed;
    Node *next;
}Node;
Node *ptr,*head,*tail;

void init();
void print_link();
void search_link();
void delete_link();

int main()
{
    //printf("�����������\n");
    unsigned int operation = 0;
    printf("\t\t\t\t��ӭ����˫����ѧϰ����!\t\t\t\t\n\n");
    do
    {
        printf("\t\t\t\t1.��ʼ��˫����:\t\t\t\t\n");
        printf("\t\t\t\t2.˫�����������:\t\t\t\t\n");
        printf("\t\t\t\t3.˫����ɾ������:\t\t\t\t\n");
        printf("\t\t\t\t4.˫����༭����:\t\t\t\t\n");
        printf("\t\t\t\t5.˫�����ѯ����:\t\t\t\t\n");
        printf("\t\t\t\t6.˫�����ӡ����:\t\t\t\t\n");
        printf("\t\t\t\t7.�˳�:\t\t\t\n\n");
        printf("\t\t\t\t��ѡ����Ĳ���:\t\t\t\t\n");
        scanf("%u",&operation);
        switch (operation)
        {
            case 1:
                {
                    ;
                    break;
                }
            default:
                {
                    printf("����Ƿ�,����������!\n");
                    break;
                }
        }
        
    } while (1);
    

    return 0;
}

