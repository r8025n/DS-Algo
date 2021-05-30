#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head,*newnode,*temp;


void insrt(int x){
    newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=x;
    newnode->next=NULL;

    if(head==NULL){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}


void printList(struct node* head){
    while(head->next!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("%d",head->data);

}


int main(){
    int n,i,x;
    head=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        insrt(x);
    }
    printList(head);

    return 0;
}
