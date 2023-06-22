
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

class Trie {

public:

    /** Initialize your data structure here. */
    Node* root;
    Trie() {
        root=new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
        
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i]))return false;
            node=node->get(word[i]);
        }
        return node->isTrue();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containsKey(prefix[i]))return false;
            node=node->get(prefix[i]);
        }
        return true;
    }
};
