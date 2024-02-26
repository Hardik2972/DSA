#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct Node{
    Node* links[2];
    void put(int bit,Node* node){
        links[bit]=node;
    }
    Node* getNext(int bit){
        return links[bit];
    }
    bool isPresent(int bit){
        return links[bit]!=NULL;
    }

};
class Trie{
    Node* root;
    public:
      Trie(){
          root=new Node();
      }
      void insert(int num){
          Node* node = root;
          for(int i=31;i>=0;i--){
              int bit = num>>i & (1);
            //   cout<<bit<<" "<<i<<endl;
              if(node->isPresent(bit)){
                  node=node->getNext(bit);
              }
              else{
                  node->put(bit,new Node());
                  node=node->getNext(bit);
              }
          }
      }
      int getMax(int num){
          int maximum =0;
          Node* node = root;
          for(int i=31;i>=0;i--){
              int bit = num>>i & (1);
              if(node->isPresent(!bit)){
                  maximum = maximum | (1<<i);
                  node = node->getNext(!bit);
              }
              else{
                  node=node->getNext(bit);
              }
          }
          return maximum;
      }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie obj;
        for(int i=0;i<nums.size();i++){
            obj.insert(nums[i]);
        }
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,obj.getMax(nums[i]));
        }
        return maxi;
    }
};