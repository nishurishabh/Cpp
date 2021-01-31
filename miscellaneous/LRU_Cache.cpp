#include <bits/stdc++.h>
using namespace std;

class Node
{
    public: 
        int val;
        Node* front;
        Node* back;

        Node(int x)
        {
            val = x;
            front=nullptr;
            back=nullptr; 
        }
};

unordered_map<int, pair<int, Node*>> lookup;
Node* head =  new Node(-1);
Node* back;
int C, currentSize;

void deleteNodeFromLL(Node* pt)
{ 
    if(pt == back) back = pt->back;
    if(pt->front == nullptr)
    {
        pt->back->front = nullptr;
    }
    else
    {
        Node* prev = pt->back;
        Node* next = pt->front;
        prev->front = next;
        next->back = prev;
    }
    free(pt);           
}

void addNodeFromFront(int val)
{
    Node* newNode = new Node(val);
    if(head->front == nullptr) back = newNode;
    Node* next = head->front;
    if(next) next->back = newNode;
    newNode->front = next;
    newNode->back = head;
    head->front = newNode;
    currentSize++;
}
void bringNodeFront(unordered_map<int, pair<int, Node*>>::iterator it)
{
    deleteNodeFromLL(it->second.second);
    int key = it->first;
    addNodeFromFront(key);
    lookup[key].second = head->front;
}

int get(int key)
{
    if(lookup.find(key) == lookup.end()) return -1;
    else
    {
        auto it = lookup.find(key);
        bringNodeFront(it);
        return lookup[key].first;
    }
}

int put(int key, int val)
{
    if(lookup.find(key) != lookup.end()) lookup[key].first = val;
    else
    {
        if(currentSize < C)
        {
            addNodeFromFront(key);
            lookup[key] = {val, head->front};
        }
        else
        {
            lookup.erase(back->val);
            deleteNodeFromLL(back);
            addNodeFromFront(key);
            lookup[key] = {val, head->front};
        }
    }
}


int main()
{
    int capacity = 2;
    C=capacity;
    currentSize=0;
    back=head;
    put(1,1);
    put(2,2);
    cout << "GET 1 = " << get(1) <<endl;
    put(3,3);
    cout << "GET 2 = " << get(2) <<endl;
    put(4,4);
    cout << "GET 1 = " << get(1) <<endl;
    cout << "GET 3 = " << get(3) <<endl;
    cout << "GET 4 = " << get(4) <<endl;
}