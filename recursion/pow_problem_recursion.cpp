#include<iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n<0){
            n=abs(n);
            x=1/x;
        }
        if(n%2==0){
            cout<<x<<endl;
            return myPow(x*x,n/2);
            
        }
        else if(n%2==1){
            return x*myPow(x,n-1);
        }
        return 0;
    }
};