#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    
};
struct node *createnode(int data){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;


    
}
struct node *insertend(struct node*head,int data){
    struct node *newnode=createnode(data);
    if(head==NULL)
      return newnode;
    struct node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    temp->next=newnode;
    return head;
    }
}
struct node*mergelist(struct node *l1,struct node *l2){
    if(l1==NULL)
      return l2;
    if(l2==NULL)
      return l1;
    struct node *head=NULL;
    struct node *tail=NULL;
    if(l1->data<=l2->data){
        head=l1;
        l1->next;

    }else{
        head=l2;
        l2=l2->next;
    }
    tail=head;
    while(l1!=NULL && l2!=NULL){
        if(l1->data<=l2->data){
            tail->next=l2;
            l1=l1->next;
        }
        else{
        tail->next=l2;
        l2=l2->next;

        }
        tail=tail->next;

    }
    if(l1!=NULL)
        tail->next=l1;
    else
       tail->next=l2;
    return head;
}
void printlist(struct node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;

    }
}
int main(){
    int n,m,i,value;
    struct node *list1=NULL,*list2=NULL,*mergelist=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&value);
        list1=
    }
}   
         
       