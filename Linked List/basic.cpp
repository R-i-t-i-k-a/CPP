#include <iostream>
using namespace std;

//linked list - non continous memory location
//linear data structure
//dynamically grow and shrink
//Node - data and address of next node
//types : Singly, circular singly, doubly circular doubly

//in this code - singly linked list basics covered - creation - insertion - deletion - print

//creating a node
class Node{
    public:
        int data;
        Node* next; 
        //default behaviour of a new node
        Node(){
            this->data = 0;
            this->next = NULL;
        }
        //a new node with a value;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

//insert new node right at the beginning of the linked list
void insertAtHead(Node* &head, int data){
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
//insert at the end of the linked list
void insertAtTail(Node* &head, int data){
    Node* temp = head;
    Node* newNode = new Node(data);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newNode;
}
//insert at kth position
void insertAtK(Node* &head, int data, int k){
    int count = 1;
    Node* temp = head;
    Node* newNode = new Node(data);
    while(count!=k-1){
        if(temp->next!=NULL){
            temp=temp->next;
            count++;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
//insert after k data position
void insertAfterData(Node* &head, int data, int dataInsertion){
    Node* temp = head;
    Node* newNode = new Node(data);
    while(temp->data!=dataInsertion && temp->next!=NULL){
        temp=temp->next;
    }
    if(temp->data == dataInsertion){
        newNode->next = temp->next;
        temp->next = newNode;
    }else{
        cout<<"Value after which you want to insert data not found"<<endl;
    }
}
//delete a node with particular data
void deleteNodeData(Node* &head, int dataToDelete){
    Node* temp = head;
    Node* nodeToDelete = temp->next;
    while(nodeToDelete->data!=dataToDelete){
        nodeToDelete=nodeToDelete->next;
        temp=temp->next;
    }
    temp->next = nodeToDelete->next;
}
//delete kth node
void deleteKthNode(Node* &head, int k){
    Node* temp = head;
    Node* nodeToDelete = temp->next;
    int count = 1;
    while(count!=k-1){
        nodeToDelete=nodeToDelete->next;
        temp=temp->next;
    }
    temp->next = nodeToDelete->next;
}
//delete head node
void deleteFromBeginning(Node* &head){
    Node* temp = head->next;
    head = temp;
}
//delete last node
void deleteFromEnd(Node* &head){
    Node* temp = head;
    Node* ptrToNode = temp->next;
    while(ptrToNode->next!=NULL){
        ptrToNode=ptrToNode->next;
        temp=temp->next;
    }
    temp->next=NULL;
}
void printl(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

int main(){
    //to create a node
    Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);
    // Node* fourth = new Node(40);
    // Node* fifth = new Node(50);

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;

    insertAtHead(first,40);
    insertAtHead(first,60);
    insertAtHead(first,100);

    insertAtTail(first, 2);
    insertAtK(first,21,3);
    insertAfterData(first,78,40);
    deleteNodeData(first,10);
    deleteKthNode(first,2);

    deleteFromBeginning(first);
    deleteFromEnd(first);

    printl(first);

    return 0;
}
