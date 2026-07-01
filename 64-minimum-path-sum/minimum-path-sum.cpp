class Solution {
public:
vector<vector<int>> mini;

// int  hell(int index1,int index2,int n,int m,vector<vector<int>>& grid){
//  if (index1 >= n || index2 >= m)
//             return 1e9;
//     int sum=grid[index1][index2];
       
//        if(mini[index1][index2] != -1){
//         return mini[index1][index2];
//        }
// if(index1 == n-1 && index2 == m-1){
// return sum;
// }

// return mini[index1][index2]=min(sum+hell(index1+1,index2,n,m,grid), sum+hell(index1,index2+1,n,m,grid));
//  }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
// mini.resize(n,vector<int>(m,-1));
// return hell(0,0,n,m,grid);
// vector<vector<int>> dp[m][n];
vector<vector<int>> dp(n+1, vector<int>(m+1,1e9));

dp[n][m - 1] = 0;
dp[n - 1][m] = 0;
for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
        // if(i != n-1 && j != m-1)
dp[i][j]=min((grid[i][j]+dp[i+1][j]),(grid[i][j]+dp[i][j+1]));
    }
}


        
    return dp[0][0];}
};