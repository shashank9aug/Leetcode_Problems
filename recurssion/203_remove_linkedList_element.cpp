/*
    we will have one linkedList with number of nodes : 
    given value : x

    we have to delete all the nodes have all the nodes have value x.
*/

#include<iostream>
using namespace std;

class node{
    public: 
        int data;
        node*next;
    node(int d){
        data=d;
        next=NULL;
    }    
};

void insertAtHead(node*head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }
    node* temp=new node(d);
    temp->next=head;
    head=temp;
}

node* takeInput(){
    int data;
    cin>>data;

    node*head=NULL;
    while(data!=-1){
        insertAtHead(head,data);
        cin>>data;
    }
    return head;
}

void printLL(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<endl;
}
void removeElement(node*&curr,int val){
    //Iterative : 
    while(curr!=NULL and curr->data==val){
        curr=curr->next;
    }
    node*newNode=curr;
    while(newNode!=NULL and newNode->next!=NULL){
        if(newNode->next->data==val){
            newNode->next=newNode->next->next;
        }
        else{
            newNode=newNode->next;
        }
    }
}


int main(){
    node* head=takeInput();
    printLL(head);

    int val;
    cout<<"Enter value need to delete : ";
    cin>>val;

    // node*curr=head;
    removeElement(head,val);

    // curr=head;
    printLL(head);
}