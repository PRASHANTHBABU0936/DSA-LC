class Solution {
public:
vector<vector<int>>  dp;

// int hell(int index2,vector<vector<int>>& triangle,int index1,int n){
// if(index1 >= n || index2 >= triangle[index1].size()) return 0;

//  if(memo[index1][index2] != INT_MAX) return memo[index1][index2];

// return memo[index1][index2]=triangle[index1][index2]+min(hell(index2+1,triangle,index1+1,n),hell(index2,triangle,index1+1,n));}


    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        

        dp.resize(n + 1, vector<int>(n + 1, 0));
        // memo.resize(n,vector<int>(m,-1));
        // memo.resize(n);
        for(int i=n-1;i>=0;i--){
            for (int j = 0; j < triangle[i].size(); j++) {
dp[i][j]=triangle[i][j]+min(dp[i+1][j+1],dp[i+1][j]);
            }
            // memo[i].resize(triangle[i].size(), INT_MAX);
        }
        // return hell(0,triangle,0,n);
    return dp[0][0];}
};