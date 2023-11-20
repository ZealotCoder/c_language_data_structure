#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    //Êý¾ÝÓò
    int data_Filed;
    struct Node *next;
}Node;
Node *ptr,*head,*tail;

void init();
void insert_link();
void print_link();
void search_link();
void delete_link();
void main(){};