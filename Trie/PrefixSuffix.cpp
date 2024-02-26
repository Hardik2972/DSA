// ****************************Count Prefix and Suffix Pairs II**********************************

// Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:

// isPrefixAndSuffix(str1, str2) returns true if str1 is both a prefix and a suffix
// of str2, and false otherwise. For example, isPrefixAndSuffix("aba", "ababa") is true
// because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd")
// is false.
// Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.

// Example 1:

// Input: words = ["a","aba","ababa","aa"]
// Output: 4
// Explanation: In this example, the counted index pairs are:
// i = 0 and j = 1 because isPrefixAndSuffix("a", "aba") is true.
// i = 0 and j = 2 because isPrefixAndSuffix("a", "ababa") is true.
// i = 0 and j = 3 because isPrefixAndSuffix("a", "aa") is true.
// i = 1 and j = 2 because isPrefixAndSuffix("aba", "ababa") is true.
// Therefore, the answer is 4.

#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
struct Node{
    map<pair<int,int>,Node*> m;
    int count=0;
    void put(pair<char,char> p,Node* node){
        m[{p.first-'a',p.second-'a'}]=node;
    }
    Node* getNext(pair<char,char> p){
        return m[{p.first-'a',p.second-'a'}];
    }
    bool isExist(pair<char,char> p){
        return (m.find({p.first-'a',p.second-'a'})!=m.end());
    }
    void increaseCount(){
        count++;
    }
};
class Trie{
    Node* root;
    public:
      Trie(){
          root = new Node();
      }
      void insert(string word){
          Node* node = root;
          int n = word.size();
          for(int i=0;i<word.size();i++){
              pair<char,char> temp = {word[i],word[n-i-1]};
              if(node->isExist(temp)){
                  node = node->getNext(temp);
              }
              else{
                  node->put(temp,new Node());
                  node=node->getNext(temp);
              }
          }
          node->increaseCount();
      }
      int check(string word){
          Node* node = root;
          int n=word.size();
          long long count = 0;
          for(int i=0;i<n;i++){
              pair<char,char> temp = {word[i],word[n-i-1]};
              if(node->isExist(temp)){
                  node=node->getNext(temp);
                  count+=node->count;
              }
              else{
                  break;
              }
          }
          return count;
      }
};
class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
         long long ans =0 ;
        Trie obj;
        for(int i=0;i<words.size();i++){
            ans+=obj.check(words[i]);
            obj.insert(words[i]);
        }     
        return ans;
    }
};