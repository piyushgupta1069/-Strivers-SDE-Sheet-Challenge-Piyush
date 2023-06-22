#include <bits/stdc++.h> 
struct Node{
    Node *links[26];
    bool flag=false;
    bool containsKey(char c){
        return (links[c-'a']!=NULL);
    }
    void put(char c, Node* node){
        links[c-'a']=node;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isTrue(){
        return flag;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Node* root = new Node();
    
    for(int i=0;i<a.size();i++){
        string word = a[i];
        Node *node = root;
        for(int j=0;j<word.size();j++){
            if(!node->containsKey(word[j])){
                node->put(word[j], new Node());
            }
            node=node->get(word[j]);
        }
        node->setEnd();
    }
    string res;
    for(int i=0;i<a.size();i++){
        string word = a[i];
        Node* node = root;
        bool f=true;
        for(int j=0;j<word.size();j++){
            if(!node->containsKey(word[j])){
                f=false;
            }
            node=node->get(word[j]);
            f=f&node->isTrue();
        }
        if(f){
            if(res.size()<word.size())res=word;
            else if(res.size()==word.size())res=min(res,word);
        }
    }
    if(res.size())return res;
    return "None";
}
