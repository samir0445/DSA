#include<iostream>
using namespace std;

class ListNode{

public:
    int val;
    ListNode* next;

    ListNode(int v){
        val = v;
        next = nullptr;
    }
    ListNode(int v,ListNode* node){
        val = v;
        next = node;
    }
};

void traversal(ListNode* head){
    ListNode* temp = head;
    while(temp!=nullptr){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int length(ListNode* head){
    ListNode* temp = head;
    if(head == nullptr){
        return 0;
    }
    int n=0;
    while(temp!=nullptr){
        n++;
        temp=temp->next;
    }
    return n;
}

ListNode* insertionHead(ListNode* head,int val){
    ListNode* node = new ListNode(val);
    node->next = head;
    head = node;

    return head;
}


int main(){
    ListNode* head = new ListNode(2);
    head->next = new ListNode(5);
    
    head = insertionHead(head,9);
    head = insertionHead(head,0);
    head = insertionHead(head,89);
    traversal(head);
    int size =length(head);

    cout<<"length of linked list "<< size<<endl;



    return 0;
}