#include <iostream>
using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    // Data stored in the node
    int data;

    // Pointer to the next node
    Node* next;

    // Constructor with both data and next node
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


   
int lengthOfLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while(fast != nullptr && fast->next!= nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if(fast==nullptr || fast->next == nullptr){
            return 0;
        }
        int cnt =1;
        while(fast->next != slow){
            cnt++;
            fast= fast->next;
            if(slow == fast){
                break;
            }
        }

        return cnt;
 }



// Main driver function
int main() {
    // Creating a sample linked list with a loop
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Linking the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second;

    cout<< "length of loop : "<< lengthOfLoop(head) <<endl;



    
    return 0;
}