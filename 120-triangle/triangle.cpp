class Solution {
public:
vector<vector<int>> memo;
int hell(int index2,vector<vector<int>>& triangle,int index1,int n){
if(index1 >= n || index2 >= triangle[index1].size()) return 0;

 if(memo[index1][index2] != INT_MAX) return memo[index1][index2];

return memo[index1][index2]=triangle[index1][index2]+min(hell(index2+1,triangle,index1+1,n),hell(index2,triangle,index1+1,n));}

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        // memo.resize(n,vector<int>(m,-1));
        memo.resize(n);
        for(int i=0;i<n;i++){
            memo[i].resize(triangle[i].size(), INT_MAX);
        }
        return hell(0,triangle,0,n);
    }
};