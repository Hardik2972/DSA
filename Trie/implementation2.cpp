#include<iostream>
#include<string>
using namespace std;
struct Node{
    Node* links[26];
    int countPrefix=0;
    int countWord=0;
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* getNext(char ch){
        return links[ch-'a'];
    }
    void incrementPrefix(){
        countPrefix++;
    }
    void decrementPrefix(){
        countPrefix--;
    }
    void decrementWord(){
        countWord--;
    }
    void incrementWord(){
        countWord++;
    }
    bool isPresent(char ch){
        return (links[ch-'a']!=NULL);
    }
};
class Trie{
    Node* root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->isPresent(word[i])){
                node = node->getNext(word[i]);
                node->incrementPrefix();
            }
            else{
                node->put(word[i],new Node());
                node=node->getNext(word[i]);
                node->incrementPrefix();
            }
        }
        node->incrementWord();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->isPresent(word[i])){
                node=node->getNext(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->countWord;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->isPresent(word[i])){
                node=node->getNext(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->countPrefix;
    }

    void erase(string &word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(node->isPresent(word[i])){
                node=node->getNext(word[i]);
                node->decrementPrefix();
            }
            else{
                return;
            }
        }
        node->decrementWord();
    }
};
