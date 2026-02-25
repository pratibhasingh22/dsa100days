#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;

};
int main(){
    int n,i,value;
    struct node *head=NULL,*temp=NULL,*newnode=NULL;

    printf("enter the no of nodes needed");
    scanf("%d",&n);
    printf("enter the values in the nodes");
    for(i=0;i<n;i++){
        scanf("%d",&value);

        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=NULL;

        if(head==NULL){
            head=newnode;
            temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
    }
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;

    }
    return 0;
    
}