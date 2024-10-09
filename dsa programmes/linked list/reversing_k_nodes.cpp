#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
/*inser at tail*/
void insert_at_tail(node* &head,int val){
    node*n=new node(val);
    if(head==NULL){
        head=n;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
int main(){

return 0;}