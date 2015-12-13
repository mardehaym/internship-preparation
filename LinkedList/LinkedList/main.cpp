//
//  main.cpp
//  LinkedList
//
//  Created by Mark Aizenshtadt on 12/9/15.
//  Copyright © 2015 Mark Ajzenstadt. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
    private :
    ListNode * _head;
    public :
    
    LinkedList() {} //constructor
    
    void add(int x) { //add ListNode to linked list
        ListNode * block = new ListNode(x);
        if (!_head) {
            _head = block;
            return;
        }
        
        ListNode * p = _head;
        
        while (p->next) {
            p = p->next;
        }
        
        p->next = block;
    }
    
    void print() { //print out the list
        if (!_head) {
            cout << "The list is empty!" << endl;
            return;
        }
        ListNode * p = _head;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
    
    void print(ListNode * head) {
        if (!head) {
            cout << "The list is empty!" << endl;
            return;
        }
        ListNode * p = head;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    ListNode * getHead() {
        return _head;
    }
    
    ListNode * rotateRight(ListNode* head, int k) {
        if (!head) {
            return nullptr;
        }
        int len = 0;
        ListNode * p = head;
        while (p) {
            len++;
            p = p->next;
        }
        if (len == k) {
            return nullptr;
        }
        p = head;
        ListNode * q = p;
        ListNode * newList = nullptr;
        int toReach = len - k - 1;
        int index = 0;
        while (index != toReach) {
            index++;
            q = q->next;
        }
        newList = q->next;
        ListNode * newListTail = newList;
        while (newListTail->next) {
            newListTail = newListTail->next;
        }
        q->next = nullptr;
        newListTail->next = p;

        return newList;
    }
    
    
    int len() {
        int len = 0;
        ListNode * p = _head;
        while (p) {
            len++;
            p = p->next;
        }
        return len;
    }
};

int main(int argc, const char * argv[]) {
    LinkedList * l = new LinkedList();
    l->add(1);
    l->add(2);
    l->add(3);
    l->add(4);
    l->add(5);
    l->print();
    cout << l->len() << endl;
    l->print(l->rotateRight(l->getHead(), 4));
    
    return 0;
}
