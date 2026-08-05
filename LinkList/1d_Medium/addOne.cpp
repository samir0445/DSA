#include<iostream>
#include<Stack>
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

ListNode* addOne(ListNode*head){
    int num =0;
    int cnt =0;
    if(head == nullptr){
        return head;
    }
    ListNode* temp = head;
    while(temp!=nullptr){
        num = num*10 +(temp->val);
        cnt++;
        temp = temp->next;
    }
    num=num+1;
    stack<int> st;
    while(num>0){
        st.push(num%10);
        num = num/10;
    }
    ListNode* ans = new ListNode(-1);
    ListNode* tail = ans;
    while(!st.empty()){
        ListNode* node = new ListNode(st.top());
        st.pop();
        tail->next = node;
        tail = node;
    }

    return ans->next;
}

int main(){
    ListNode* head = new ListNode(9);
    head->next = new ListNode(9);
    
    head = insertionHead(head,9);
    head = insertionHead(head,9);
    head = insertionHead(head,9);
     head = insertionHead(head,9);
      head = insertionHead(head,9);
       head = insertionHead(head,9); 
       head = insertionHead(head,9);
    traversal(head);

    head =addOne(head);
    traversal(head);


    return 0;
}