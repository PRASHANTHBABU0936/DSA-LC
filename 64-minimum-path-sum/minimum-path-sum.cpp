class Solution {
public:
vector<vector<int>> mini;

int  hell(int index1,int index2,int n,int m,vector<vector<int>>& grid){
 if (index1 >= n || index2 >= m)
            return 1e9;
    int sum=grid[index1][index2];
       
       if(mini[index1][index2] != -1){
        return mini[index1][index2];
       }
if(index1 == n-1 && index2 == m-1){
return sum;
}

return mini[index1][index2]=min(sum+hell(index1+1,index2,n,m,grid), sum+hell(index1,index2+1,n,m,grid));
 }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
mini.resize(n,vector<int>(m,-1));
return hell(0,0,n,m,grid);
        
    }
};