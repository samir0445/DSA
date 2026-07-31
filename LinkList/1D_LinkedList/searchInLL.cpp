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

ListNode* insertionHead(ListNode* head,int val){
    ListNode* node = new ListNode(val);
    node->next = head;
    head = node;

    return head;
}

bool search(ListNode* head ,int target){
    ListNode* temp =head; 
   
    while(temp!=nullptr){
        if(temp->val==target){
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int main(){
    ListNode* head = new ListNode(2);
    head->next = new ListNode(5);
    head = insertionHead(head,9);
    head = insertionHead(head,0);
    head = insertionHead(head,89);
    traversal(head);
    int target = 5;
    bool result = search(head,target);
    cout <<" searching "<<target << " :" << result <<endl;


    return 0;
}