#include<iostream>
#include<string>
using namespace std;
struct Node{
    Node* links[26];
    bool flag=false;
    Node* getNext(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    bool isPresent(char ch){
        return (links[ch-'a']!=NULL);
    }
    void setEnd(){
        flag = true;
    }
};
class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->isPresent(word[i])){
                node = node->getNext(word[i]);
            }
            else{
                node->put(word[i],new Node());
                node = node->getNext(word[i]); 
            }
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->isPresent(word[i])){
                node = node->getNext(word[i]);
            }
            else{
                return false;
            }
        }
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(node->isPresent(prefix[i])){
                node = node->getNext(prefix[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */