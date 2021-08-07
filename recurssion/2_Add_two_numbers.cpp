
/*
2 4 3 -1
5 6 4 -1
3->4->2->
7->0->8->
*/


#include <iostream>
#include <string>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = NULL;
    }
    ListNode() : val(0), next(nullptr) {}
};



void insertAtHead(ListNode*&head,int data){
    if(head==NULL){
        head=new ListNode(data);
        return;
    }
    ListNode*temp=new ListNode(data);
    temp->next=head;
    head=temp;
}

ListNode* takeInput(){
    int d;
    cin>>d;

    ListNode*head=NULL;
    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}

//print LL
void printLL(ListNode*head){
    while(head!=NULL){
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<endl;
}

class Solution {
public:
    ListNode* add(ListNode* l1, ListNode* l2, int rem) {
        ListNode* ans = new ListNode();
        
        if(l1!=NULL and l2!=NULL)
        {
            ans->val = (l1->val + l2->val + rem)%10;
            rem = (l1->val + l2->val + rem)/10;

            ans->next = add(l1->next, l2->next, rem);
        }
        else if(l1!=NULL and l2==NULL)
        {
            ans->val = (l1->val + rem)%10;
            rem = (l1->val + rem)/10;

            ans->next = add(l1->next, l2, rem);
        }
        else if(l2!=NULL)
        {
            ans->val = (l2->val + rem)%10;
            rem = (l2->val + rem)/10;

            ans->next = add(l1, l2->next, rem);
        }
        else if(rem!=0)
            ans->val = rem;
        else
            return NULL;
        
        return ans;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Base case : 
        return add(l1,l2,0);
    }
};

int main()
{
    ListNode*head=takeInput();
    ListNode*head1=takeInput();

    printLL(head);

    Solution ob;
    ListNode*head3=ob.addTwoNumbers(head,head1);

    printLL(head3);

    return 0;
}