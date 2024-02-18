#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;

    // constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node*& head, int d) {
    // create new node
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node*& tail, int d) {
    // create new node
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node*& head, Node*& tail, int position, int d) {
    // insert at start
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }
    // creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node*& head,Node*&tail, int position) {
    // deleting first or start node
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        // memory free start node
        delete temp;
    }

    // deleting any midddle or last node
    else {
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        if(curr->next == NULL){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void print(Node*& head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // creates a new nodw
    Node* node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    // head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(head, tail, 4, 22);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    deleteNode(head, tail, 4);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    return 0;
}