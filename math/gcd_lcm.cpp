// GCD = mini power of each prime factor and multiply them
// LCM = maxi power of each prime factor and multiply them

#include<iostream>
#define ll long long
using namespace std;
class Solution{
    public:
    int gcd(ll a,ll b){
        if(b%a==0) return a;
        return gcd(b%a,a);
    }
    void calculator(ll& a,ll& b){
        ll lcm = a*b/gcd(a,b);
         
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        Solution ob;
        ob.calculator(a,b);
    }
    return 0;
}