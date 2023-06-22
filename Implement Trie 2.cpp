#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int countPrefix=0;
    int endWith=0;
    bool contains(char c){
        return (links[c-'a']!=NULL);
    }
    void make(char c, Node* node){
        links[c-'a']=node;
    }
    void increaseEnd(){
        endWith++;
    }
    void increasePrefix(){
        countPrefix++;
    }
    void decreaseEnd(){
        endWith--;
    }
    void decreasePrefix(){
        countPrefix--;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    int getEnd(){
        return endWith;
    }
    int getPrefix(){
        return countPrefix;
    }
};
class Trie{

    public:
    Node* root;
    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!(node->contains(word[i]))){
                node->make(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->contains(word[i]))return 0;
            node=node->get(word[i]);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->contains(word[i]))return 0;
            node=node->get(word[i]);
        }
        return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->contains(word[i]))return;
            node=node->get(word[i]);
            node->decreasePrefix();
        }
        node->decreaseEnd();
        return;
    }
};
