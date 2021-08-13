#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode*next;

    ListNode(int d){
        val=d;
        next=NULL;
    }
};


int length(ListNode *head)
{
    int l = 0;
    while (head != NULL)
    {
        l++;
        head = head->next;
    }
    return l;
}

ListNode *sortList(ListNode *head)
{
    int l = length(head);

    vector<int> item(l);
    ListNode *temp = head;
    int i = 0;
    while (i <= l and temp != NULL)
    {
        item[i] = temp->val;
        temp = temp->next;
        i++;
    }
    sort(item.begin(), item.end());
    temp = head;
    i = 0;
    while (i <= l and temp != NULL)
    {
        temp->val = item[i];
        temp = temp->next;
        i++;
    }
    return head;
}

void insertAtHead(ListNode*&head,int data){
    if(head==NULL){
        head=new ListNode(data);
        return;
    }
    ListNode*temp=new ListNode(data);
    temp->next=head;
    head=temp;
}

//print LL
void printLL(ListNode*head){
    while(head!=NULL){
        cout<<head->val<<"->";
        head=head->next;
    }
    cout<<endl;
}

ListNode* takeInput(){
    int d;
    cin>>d;
    ListNode*head=NULL;
    insertAtHead(head,d);
    while(d!=-1){
        cin>>d;
        insertAtHead(head,d);
    }

    return head;
}

int main(){
    ListNode*head=takeInput();

    printLL(head);

    ListNode*h=sortList(head);

    printLL(head);

}