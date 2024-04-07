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
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
// Integer Ranges
#define imax INT_MAX
#define imin INT_MIN
#define llmax LLONG_MAX
#define llmin LLONG_MIN
#define mod (int)(1e9 + 7)
#define ll long long
#define int ll

// Data Structures
#define v(a) vector<a>
#define p(a, b) pair<a, b>
#define vv(a) vector<vector<a>>
#define ump(a, b) unordered_map<a, b>
#define omp(a, b) map<a, b>
#define ust(a) unordered_set<a>
#define ost(a) set<a>
#define maxheap(a) priority_queue<a>
#define minheap(a) priority_queue<a, vector<a>, greater<a>>

// Sorting Functions
#define Sort(a) sort(a.begin(),a.end())
#define DSort(a) sort(a.begin(),a.end(),greater<a>())

// Debugging
#define debug(i) cout << "debug : " << i << endl;
#define input(arr) for(int i=0;i<arr.size();i++) cin>>arr[i];
#define print(arr) for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
#define nline cout<<endl

class Solution {
public:
    void calculator(ll n, vector<ll>& a) {

    }
};

signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        input(a);
        Solution obj;
        obj.calculator(n, a);
    }
    return 0;
}