
#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));
        dp[0][1][0]=INT_MIN;
        dp[0][1][1]=INT_MIN;
        dp[0][1][2]=INT_MIN;
        for(int i=1;i<prices.size()+1;i++){
            for(int j=0;j<2;j++){
                for(int k=1;k<3;k++){
                    if(j){
                        dp[i][j][k]=max((-prices[i-1]+dp[i-1][!j][k-1]),dp[i-1][j][k]);
                    }
                    else{
                        dp[i][j][k]=max((prices[i-1]+dp[i-1][!j][k]),dp[i-1][j][k]);
                    }
                }
            }
        }
        return dp[prices.size()][0][2];
    }
};