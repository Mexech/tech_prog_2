#include "CyclicList.h"
#include <iostream>
using namespace std;

CyclicList::CyclicList() {
    head = NULL;
    tail = NULL;
}

void CyclicList::push(int val) {
    Node *tmp = new Node;
    tmp->data = val;
    tmp->next = head;

    if (isEmpty()) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tail->next;
    }
}

int CyclicList::pop() {
    if (isEmpty())
        throw out_of_range("empty");

    Node *tmp = head;
    int data = tmp->data;
    if (head != tail) {
        head = tmp->next;
        tail->next = head;
    } else {
        head = NULL;
        tail = NULL;
    }
    delete tmp;
    return data;
}

void CyclicList::display() {
    if (isEmpty())
        throw out_of_range("empty");
    Node *tmp = head;
    do 
        printf("%d ", tmp->data);
    while (tmp = tmp->next, tmp != head);
    printf("\n");
}

bool CyclicList::isEmpty() {
    return head == NULL;
}

int main() {
    CyclicList c;
    c.push(1);
    c.push(2);
    c.push(3);
    c.display();
    c.pop();
    c.display();
    c.pop();
    c.display();
    c.pop();
    c.display();
    return 0;
}