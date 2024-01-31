// *******************************************question*******************************
// 1969. Minimum Non-Zero Product of the Array Elements
// You are given a positive integer p. Consider an array nums (1-indexed) that consists of the
// integers in the inclusive range [1, 2p - 1] in their binary representations. You are allowed 
// to do the following operation any number of times:
// Choose two elements x and y from nums.
// Choose a bit in x and swap it with its corresponding bit in y. Corresponding bit refers to the bit 
// that is in the same position in the other integer.
// For example, if x = 1101 and y = 0011, after swapping the 2nd bit from the right, we have x = 1111 and y = 0001.
// Find the minimum non-zero product of nums after performing the above operation any number of times. Return this 
// product modulo 109 + 7.
// Note: The answer should be the minimum product before the modulo operation is done.
// **********************************example********************************************
// Input: p = 3
// Output: 1512
// Explanation: nums = [001, 010, 011, 100, 101, 110, 111]
// - In the first operation we can swap the leftmost bit of the second and fifth elements.
//     - The resulting array is [001, 110, 011, 100, 001, 110, 111].
// - In the second operation we can swap the middle bit of the third and fourth elements.
//     - The resulting array is [001, 110, 001, 110, 001, 110, 111].
// The array product is 1 * 6 * 1 * 6 * 1 * 6 * 7 = 1512, which is the minimum possible product.
// **********************************************approch*********************************************************
// the main approch
// always remember                   x*y  >  (x-1)*(y+1)
// and binary exponentiation for calculation high powers always
#define mod 1000000007
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    long long power(long long x, long long y){
        if(y==0){
            return 1;
        }
        long long ans = power(x,y/2);
        if(y%2 == 0){
            return (ans*ans)%mod;
        }
        else{
            return  (((ans*ans)%mod)*(x%mod))%mod;
        }
    }
    int minNonZeroProduct(int p) {
      
       long long pa = pow(2,p);
       
       return ((power((pa-2),((pa-2)/2))%mod)*((pa-1)%mod))%mod; 
    }
};