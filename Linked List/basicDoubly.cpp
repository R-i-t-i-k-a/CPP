//doubly linked list is all similar to the singly linked list
// just the difference is prev connection
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        Node(){
            this->data = 0;
            this->prev = NULL;
            this->next = NULL;
        }
        Node(int data){
            this->data = data;
            this->prev = NULL;
            this->next = NULL;
        }
};

//insert at a position
//delete from a position

void deleteAtHead(Node* &head){
    head = head->next;
    head->prev = NULL;
}

void insertAtHead(Node* &head, int data){
    Node* temp = head;
    Node* newNode = new Node(data);
    newNode->next = temp;
    temp->prev = newNode;
    head = newNode;
}

void deleteAtTail(Node* &head){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* tailNew = temp->prev;
    temp->prev = NULL;
    tailNew->next = NULL;
}

void insertAtTail(Node* &head, int data){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(data);
    temp->next = newNode;
    newNode->prev = temp;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

int main(){
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    first->next = second;
    second->next = third;
    third->prev = second;
    second->prev = first;
    print(first);
    cout<<getLength(first)<<endl;
    deleteAtHead(first);
    insertAtHead(first, 40);
    deleteAtTail(first);
    insertAtTail(first,100);
    print(first);
    return 0;
}

//doubly linked list -> circular doubly linked list
//tail->next = head && head->prev = tail
//job done