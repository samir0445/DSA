#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node in the list (forward direction)
    Node* back; // Pointer to the previous node in the list (backward direction)

    // Constructor for a Node with both data, next, and back references
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with only data, no next or back references (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    Node* prev = head; // Initialize 'prev' to the head node

    // Traverse the array to create the doubly linked list
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; // Set 'next' of the previous node to the new node
        prev = temp; // Move 'prev' to the new node
    }
    return head;  // Return the head of the doubly linked list
}

void print(Node* head) {
   
    while (head != nullptr) {
        cout << head->data << " ";  
        head = head->next;          
    }
}

Node* deleteHead (Node* head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }

    Node* temp = head->next;
    delete(head);
    return temp;

   
}

Node* deleteTail (Node* head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->back->next = nullptr;
    delete(temp);

    return head;
}

int main() {

    vector<int> arr = {12, 5, 8, 7, 4};

    Node* head = convertArr2DLL(arr);
    cout << "Doubly Linked List Initially: " << endl;
    print(head);


    cout << endl << "Doubly Linked List After Inserting at the tail with value 10: " << endl;
    // head =deleteHead(head);
    head =deleteTail(head);
    print(head);

    return 0;
}