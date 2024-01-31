// ***********************************Question*********************************
// Given a matrix and a target, return the number of non-empty submatrices that sum to target.
// A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
// Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate 
// that is different: for example, if x1 != x1'.

 
// ***********************************Example*************************************
// Example 1:
// Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
// Output: 4
// Explanation: The four 1x1 submatrices that only contain 0.
#include<iostream>
#include<queue>
#include<utility>
using namespace std;
class Solution {
public:
    int calculator(vector<vector<int>>& matrix,int startRow,int rowSize,int startCol,int colSize){
        int sum = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=startRow;i<startRow+rowSize;i++){
            for(int j=startCol;j<startCol+colSize;j++){
                sum+=matrix[i][j];
            }
        }
        return sum;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& nums, int target) {
        int n = nums.size();
        int m = nums[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                nums[i][j]+=nums[i][j-1];
            }
        }
        for(int startCol = 0;startCol<m;startCol++){
            for(int endCol = startCol;endCol<m;endCol++){
                for(int startRow = 0;startRow<n;startRow++){
                    int sum = 0;
                    for(int endRow=startRow;endRow<n;endRow++){
                        sum+=nums[endRow][endCol] - (startCol?nums[endRow][startCol-1]:0);
                        if(sum==target) ans++;
                    }
                }
            }
        }
        return ans;
        
    }
};