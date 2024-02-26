#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    // time complexity o(nlog(log(n)))
    // log(log(n)) = (1/2)+(1/3)+(1/5)+(1/7).............
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