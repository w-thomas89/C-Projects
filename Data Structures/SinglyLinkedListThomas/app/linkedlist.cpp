#include "linkedlist.h"
#include "can.cpp"
using namespace std;

Node::Node() {
    Can can = Can();
    next = NULL;
}

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    //list<Can> listCans;
}

bool LinkedList::isFull() {
    return size() == (int)listCans.max_size();
}

bool LinkedList::isEmpty() {
    return size() == 0;
}

void LinkedList::insert(Can can) {
    Node *temp = new Node();
    temp->can = can;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = tail->next;
    }
}

void LinkedList::remove(int index) {
    if (isEmpty()) {
        throw listEmptyException("List is empty");
        return;
    }
    Node* temp = head;
    Node* prev = NULL;
    int count = 0;

    if (temp != NULL && (count == index)) {
        head = temp->next;
        delete temp;
        return;
    }
    else {
        while (temp != NULL && (count != index)) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
}

int LinkedList::size() {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

string LinkedList::printList() {
    if (isEmpty()) {
        throw listEmptyException("List is empty");
    }
    string listString = "";
    Node *tmp;
    tmp = head;
    while (tmp != NULL) {
        listString += tmp->can.toString() + "\n";
        tmp = tmp->next;
    }
    return listString;
}




