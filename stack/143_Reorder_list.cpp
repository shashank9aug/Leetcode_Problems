/*
    ---- Aproach ----

    - store every node in stack 
        stack<node*>st

    - traverse LL and add every alternate node from stack top()    


void reorderList(ListNode *head)
{
    stack<ListNode *> st;
    int size = 0;

    ListNode *temp = head;
    while (temp)
    {
        st.push(temp);
        size++;
        temp = temp->next;
    }
    //take one node from linked List and one from stack if(size%2==0) take from stack
    // i.e: n/2 elements from stack and n/2 element from ll

    for (int i = 0; i < size / 2; i++)
    {
        temp = head->next;
        head->next = st.top();
        st.pop();
        head = head->next;
        head->next = temp;
        head = head->next;
    }
    head->next = NULL;
}
*/