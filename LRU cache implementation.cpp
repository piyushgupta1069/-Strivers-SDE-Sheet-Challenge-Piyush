#include "bits/stdc++.h"
class Node{
    public:
        int key,val;
        Node* next;
        Node* prev;
        Node(int key, int val){
            this->key=key;
            this->val=val;
        }
};
class LRUCache {
public:
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int,Node*>m;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void Add(Node* node)
    {
        Node* temp = head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
    }
    void Delete(Node* node)
    {
        Node* nxt = node->next;
        Node* pre = node->prev;
        pre->next=nxt;
        nxt->prev=pre;
    }
    int get(int key) {
        if(m.find(key)!=m.end()){
            Node* temp = m[key];
            Delete(temp);
            Add(temp);
            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            Node* temp = m[key];
            temp->val=value;
            Delete(temp);
            Add(temp);
        }
        else{
            if(m.size()==cap){
                m.erase(tail->prev->key);
                Delete(tail->prev);
                
            }
            Node* temp = new Node(key, value);
            m[key]=temp;
            Add(temp);

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
