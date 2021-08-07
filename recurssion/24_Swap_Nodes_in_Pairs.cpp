
/*
1 2 3 4 -1
4->3->2->1->
3->4->1->2->
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
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        //Base case :
        if (head == NULL or head->next == NULL)
        {
            return head;
        }

        //Induction :
        ListNode *n1 = head;
        ListNode *n2 = head->next;
        ListNode *n3 = n2->next;

        n1->next = n3;
        n2->next = n1;

        //Hypothesis :
        if (n1 != NULL)
        {
            n1->next = swapPairs(n3);
        }

        return n2;
    }
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

int main()
{
    ListNode*head=takeInput();

    printLL(head);

    Solution ob;
    head=ob.swapPairs(head);

    printLL(head);

    return 0;
}