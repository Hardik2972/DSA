#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
int recursion(int i,int j,int m,int n,vector<vector<int>> &dp,vector<vector<int>> &nums){
        if(i==0 && j==0) return dp[i][j]=1;
        if(i<0 || j<0 || i>=m || j>=n || nums[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left  = recursion (i-1,j,m,n,dp,nums);
        int right = recursion (i,j-1,m,n,dp,nums);
        return dp[i][j]=left + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        recursion(m-1,n-1,m,n,dp,obstacleGrid);
        return dp[m-1][n-1];
    }
};