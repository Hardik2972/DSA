// #include<bits/stdc++.h>
using namespace std;
#include<algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define SORT(arr) sort(arr.begin(),arr.end())
#define mod (int)(1e9+7)
#define ll long long
#define v(a) vector<a>
#define p(a,b) pair<a,b>
#define vv(a) vector<vector<a>>
#define ump(a,b) unordered_map<a,b>
#define omp(a,b) map<a,b>
#define ust(a) unordered_set<a>
#define ost(a) set<a>
#define maxheap(a) priority_queue<a>
#define minheap(a) priority_queue <a, vector<a>, greater<a>>
#define REVERSE(arr) reverse(arr.begin(),arr.end())
#define all(cont) cont.begin(), cont.end()
#define SUMARR(v,initial_sum) accumulate(v.begin(), v.end(), initial_sum)

// class TreeNode {
//     public:
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
// };


// class ListNode {
//     public:
//     int val;
//     ListNode* next;

//     ListNode(int data){
//         val=data;
//         next=NULL;
//     }
// };

// ListNode* merge(ListNode* head1,ListNode* head2){
//     if(head1==NULL && head2==NULL) return NULL;
//     if(head1==NULL)return head2;
//     if(head2==NULL)return head1;
//     ListNode* result=new ListNode(-1);
//     ListNode* dummy=result;
//     ListNode* prev=head1;
//     ListNode* curr=head2;
//     while(prev!=NULL && curr!=NULL){
//         if(prev->val <= curr->val){
//             dummy->next=prev;
//             ListNode* forward=prev->next;
//             prev->next=NULL;
//             prev=forward;
//             dummy=dummy->next;
//         }
//         else{
//             dummy->next=curr;
//             ListNode* forward=curr->next;
//             curr->next=NULL;
//             curr=forward;
//             dummy=dummy->next;
//         }
//     }
//     if(prev!=NULL) dummy->next=prev;
//     if(curr!=NULL) dummy->next=curr;
//     ListNode*temp=result;
//     result=result->next;
//     delete temp;
//     return result;
// }

// ListNode* middleNodeRighmost(ListNode* head) {
//         ListNode*slow=head;
//         ListNode*fast=head;
//         while(fast!=NULL && fast->next!=NULL){
//             fast=fast->next->next;
//             slow=slow->next;
//         }
//         return slow;
//     }

// ListNode* middleNodeLeftmost(ListNode* head) {
//         ListNode*slow=head;
//         ListNode*fast=head;
//         while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
//             fast=fast->next->next;
//             slow=slow->next;
//         }
//         return slow;
//     }

// ListNode* reverseList(ListNode* head) {
//         ListNode*prev=NULL,*curr=head;
//         while(curr!=NULL){
//             ListNode*temp=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=temp;
//         }
//         return prev;
//     }

// ListNode*mergesortLL(ListNode*head){
//     if(head==NULL) return NULL;
//     if(head->next==NULL) return head;
//     ListNode*middle=middleNodeLeftmost(head);

//     ListNode*right=middle->next;
//     middle->next=NULL;
//     ListNode*l=mergesortLL(head);
//     ListNode*r=mergesortLL(right);
//     return merge(l,r);

// }

template <typename T>
class PrimeGenerator {
public:
    PrimeGenerator(T size) : isPrime(size, true), size(size) {
        sieve();
    }

    const std::vector<T>& getPrimes() const {
        return primes;
    }

private:
    void sieve() {
        isPrime[0] = isPrime[1] = false;
        for (T i = 2; i < size; ++i) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (T j = 2 * i; j < size; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    std::vector<bool> isPrime;
    std::vector<T> primes;
    T size;
};

// PrimeGenerator<int> primeGen(n);
// const std::vector<int>& primeNumbers = primeGen.getPrimes();
int main(){
    int te;
    cin>>te;
    while(te--){

    }
    return 0;
}