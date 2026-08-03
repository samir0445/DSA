#include<iostream>
#include<vector>
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

//  hash method(just change val not nodes)
ListNode* SortLL(ListNode* head){
    if(head== nullptr || head->next == nullptr){
        return head;
    }
    ListNode* temp = head;
    vector<int> v(3,0);
    while(temp!=nullptr){
        v[temp->val]++;
        temp = temp->next;
    }
    for(auto it:v){
        cout<< it <<" ";
    }cout<<endl;
    temp = head;


    for(int i=0;i<v.size();i++){
        while(v[i]!=0){
        temp->val = i;
        v[i]--;
        temp = temp->next;
        }
    }



    return head;


}

ListNode* sort123(ListNode* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode* zero = new ListNode(-1);
    ListNode* tail0  = zero;
    
    ListNode*ones= new ListNode(-1);
     ListNode* tail1  = ones;

    ListNode* two= new ListNode(-1);
     ListNode* tail2  = two;

     ListNode* temp = head;

     while(temp!=nullptr){
        ListNode* nextnode = temp->next;
        if(temp->val == 0){
            tail0->next = temp;
            temp->next = nullptr;
            tail0 = temp;
        }else if(temp->val == 1){
                tail1->next = temp;
            temp->next = nullptr;
            tail1 = temp;
        }else{
            tail2->next = temp;
            temp->next = nullptr;
            tail2 = temp;
        }
        temp = nextnode;
     }

        if(zero->next!=nullptr){
            head = zero->next;
            tail0->next = ones->next ? ones->next : two->next;
            tail1->next = two->next;
        }else if(ones->next!=nullptr){
            head = ones->next;
            tail1->next = two->next;
        }else{
            head = two->next;
        }

     return head;
}

int main(){
    ListNode* head = new ListNode(2);
    head->next = new ListNode(2);
    
    head = insertionHead(head,2);
    head = insertionHead(head,0);
    head = insertionHead(head,2);
     head = insertionHead(head,1);
      head = insertionHead(head,1);
       head = insertionHead(head,0); 
       head = insertionHead(head,2);
    traversal(head);

    head = sort123(head);
    traversal(head);


    return 0;
}