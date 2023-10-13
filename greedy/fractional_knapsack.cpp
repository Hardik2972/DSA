#include <iostream>
#include<utility>
#include<algorithm>
#include<vector>
using namespace std;

struct Item{
    int value;
    int weight;
};
bool cmp(struct Item a, struct Item b ){
    double r1 = (a.value/(double)a.weight);
    double r2 = (b.value/(double)b.weight);
    return r1>r2;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
       sort(arr,arr+n,cmp);
       double ans=0;
       for(int i=0;i<n;i++){
           if(W>=arr[i].weight){
               W=W-arr[i].weight;
               ans+=(double)arr[i].value;
           }
           else{
               ans+=(arr[i].value/(double)arr[i].weight)*(double)W;
               break;
           }
       }
       return ans;
    }
        
};