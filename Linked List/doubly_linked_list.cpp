#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~Node() {
        int val = this->data;
        if (next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << val << endl;
    }
};

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head) {
    int len = 0;
    Node* temp = head;

    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node*& head, Node*& tail, int d) {
    // empty list
    if (head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    } else {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node*& head, Node*& tail, int d) {
    if (tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    } else {
        Node* temp = new Node(d);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node*& head, Node*& tail, int position, int d) {
    // insert at start
    if (position == 1) {
        insertAtHead(head, tail, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertAtTail(head, tail, d);
        return;
    }

    // creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deleteNode(Node*& head, Node*& tail, int position) {
    // deleting first or start node
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next->prev = NULL;
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
        curr->prev = NULL;
        prev->next = curr->next;
        if(curr->next == NULL){
            tail = prev;
        }
        curr->next = NULL;

        delete curr;
    }
}

int main() {
    // Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;

    print(head);
    // cout << getLength(head);

    insertAtHead(head, tail, 11);
    print(head);

    insertAtTail(tail, tail, 12);
    print(head);


    insertAtPosition(head, tail, 3, 13);
    print(head);

    deleteNode(head, tail, 3);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    return 0;
}