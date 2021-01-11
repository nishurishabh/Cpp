#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public: 
        ListNode* next;
        int val;
    ListNode(int v)
    {
        val=v;
        next=nullptr;
    }
};

void printList(ListNode* head)
{
    while(head)
    {
        cout << head->val <<" ";
        head=head->next;
    }
}

ListNode* insertNodeInSortedList(ListNode* head, int data)
{
    if(head == nullptr)
    {
        ListNode* temp = new ListNode(data);
        head = temp;
    }
    else if(data < head->val)
    {
        ListNode* temp = new ListNode(data);
        temp->next = head;
        head=temp;
    }
    else {
        ListNode* prev = nullptr, *itr = head;
        while(itr && data >= itr->val)
        {
            prev = itr;
            itr = itr->next;
            
        }
        
        ListNode* temp = new ListNode(data);
        temp->next = itr;
        prev->next = temp;
        
    }
    return head;
}


int main()
{
    // Linked list : 1-2-4-5-6
    ListNode* head = nullptr;
    head = insertNodeInSortedList(head,1);
    head = insertNodeInSortedList(head,2);
    head = insertNodeInSortedList(head,6);
    head = insertNodeInSortedList(head,3);
    head = insertNodeInSortedList(head,-1);
    printList(head);
}