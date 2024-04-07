#include<iostream>
#define ll long long
#define mod 1000000007
using namespace std;
ll fastModulo(ll a,ll b){
    ll res = 1;
    while(b){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b=b>>1;
    }
    return res;
}