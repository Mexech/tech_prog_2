#include "CyclicList.h"
#include <iostream>
using namespace std;

CyclicList::CyclicList() {
    head = NULL;
    tail = NULL;
}

CyclicList::~CyclicList() {
    if (!isEmpty()) {
        Node *tmp = head;
        Node *next_node;
        do {
            next_node = tmp->next;
            delete tmp;
        } while (tmp = next_node, tmp != head);
    }
}

void CyclicList::push(int val) {
    Node *tmp = new Node;
    tmp->data = val;
    tmp->next = head;

    if (isEmpty()) {
        head = tmp;
        tail = tmp;
    } 
    tail->next = tmp;
    tail = tail->next;
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
    if (isEmpty()) {
        printf("List is empty\n");
        return;
    }
    Node *tmp = head;
    do 
        printf("%d ", tmp->data);
    while (tmp = tmp->next, tmp != head);
    printf("\n");
}

bool CyclicList::isEmpty() {
    return head == NULL;
}

CyclicList CyclicList::copy() {
    CyclicList c;
    if (isEmpty())
        return c;
    Node *tmp = head;
    do
        c.push(tmp->data);
    while (tmp = tmp->next, tmp != head);
    return c;
}

CyclicList CyclicList::operator++() {
    int val;
    printf("Type one value:\n>> ");
    scanf("%d", &val);
    push(val);
    return copy();
}

CyclicList CyclicList::operator++(int) {
    int val1, val2;
    printf("Type two values separated by space:\n>> ");
    scanf("%d %d", &val1, &val2);
    push(val1); push(val2);
    return copy();
}

CyclicList operator--(CyclicList& c) {
    if (c.isEmpty()) {
        CyclicList res;
        return res;
    }
    printf("Head is %d\n", c.head->data);
    c.pop();
    return c.copy();
}

CyclicList operator--(CyclicList& c, int) {
    if (c.isEmpty()) {
        CyclicList res;
        return res;
    } 
    printf("Head is %d; ", c.head->data);
    printf("Next is %d\n", c.head->next->data);
    try {
        c.pop(); c.pop();
    } catch(out_of_range) {}
    return c.copy();
}