#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<bool> isPrime(n,1);
    isPrime[0]=isPrime[1]=0;
    for(int i=2;i<n;i++){
        if(isPrime[i]){
            for(int j=2*i;j<n;j+=i){
                isPrime[j]=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(isPrime[i]){
            cout<<i<<"  ";
        }
    }
    return 0;
}