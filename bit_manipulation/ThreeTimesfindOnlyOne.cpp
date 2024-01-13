// *************************************question**********************************************
// Find element occuring once when all other are present thrice
// Given an array of integers arr[] of length N, every element appears thrice except
// for one which occurs once.
// Find that element which occurs once.
// ************************************solution***********************************************
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        vector<int> count(32,0);
        int number = 0;
        for(int i=0;i<32;i++){
            for(int j=0;j<N;j++){
                if(arr[j]&(1<<i)) count[i]++;
            }
            if(count[i]%3!=0){
                number+=(1<<i);
            }
        }
        return number;
    }
};