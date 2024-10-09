#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val)    {
        data=val;
        next=NULL;
    }
};
                                    /*insert at tail*/
void insert_at_tail(node* &head,int val){//we will be changing the value of head that's why taking it by reference
    /*dynamic memory allocation using pointer*/
        node *n=new node(val);
        if(head==NULL){
            head=n;//here we are change the address stored in head for this like we took head by reference
           return ;
        }
        node *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
}                
                                         /*display*/
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }
    cout<<endl;
}
                                    /*REVERSE USING A ITERATOR*/
/*
we need three pointers because we need to store the address of three nodes
we would need three pointers (previos next and current)
1.at initial state current will point towards head,next will pointr towards currents next and previous will points toward NULL
2.the thing we will be doing is changing currents link to previous thus we will reverse the list
3.after changing current's next we will update pointers ( previous points to current,,current to next,,and nxt will point to currents nxt)
4.we repeat this till current is not null
5.at end we will return previous as new head
*/
node* reverse(node* &head){
    node* previous_ptr=NULL;//
    node* current_ptr=head;//
    node* nxt_ptr;//
    //continue till current is not null (until the last node)
    while(current_ptr!=NULL){
        /*store the address of currents next node which link will change later*/
        nxt_ptr=current_ptr->next;
        /*store address of previous node in current*/
        current_ptr->next=previous_ptr;

        /*updating pointers*/
        /*update previous with current*/
        previous_ptr=current_ptr;
        /*update current with nxt node which's link we will be changing in the next node*/
        current_ptr=nxt_ptr;

    }
    /*return the new head*/
    return previous_ptr;//new head is previous;the last node
}
/*reverse using recursion*/
/*WATCH VIDEO FOR MORE CLARITY*/
/*
1.iterate to the end node of the link list 
2.set end node as new head and return through all call
3.store the value of head to its next nodes next field
4.set next of head to null
*/
node* reverserecursion (node* &head){
    if(head==NULL or head->next==NULL)
    return head;
    node* newhead=reverserecursion(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
int main(){
    node* head=NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    insert_at_tail(head,6);
    display(head);
    /*this funcation will reverse a new head we should copy it in head else we can't use head*/
   // head=reverse(head);
    display(head);
    display(reverserecursion(head));

return 0;}