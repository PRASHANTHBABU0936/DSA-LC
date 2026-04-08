class Solution {
public:

void bfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>  &vis){
      int n = grid.size();
        int m = grid[0].size();
    vis[i][j]=1;
queue<pair<int,int>> q;
q.push({i,j});
while(!q.empty()){
    int hell=q.front().first;
    int hell2=q.front().second;
    vis[hell][hell2]=1;

    q.pop();
if((hell-1>=0 && grid[hell-1][hell2] == '1')&&vis[hell-1][hell2] != 1)  {
    // vis[hell-1][hell2] = 1;
    q.push({hell-1,hell2});
}
    if((hell2-1>=0 && grid[hell][hell2-1] == '1')&&vis[hell][hell2-1] != 1) {
         vis[hell][hell2-1] = 1;
         q.push({hell,hell2-1});
   }
    if((hell+1<n && grid[hell+1][hell2] == '1')&&vis[hell+1][hell2] != 1)  {vis[hell+1][hell2] = 1;
        q.push({hell+1,hell2});
    }
  if(hell2+1 < m && grid[hell][hell2+1] == '1' && vis[hell][hell2+1] != 1){
    vis[hell][hell2+1] = 1;
    q.push({hell,hell2+1});
}
}
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
vector<vector<int>> vis(n,vector<int>(m,0));
int res=0;
        for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(grid[i][j] == '1' && vis[i][j] != 1){
        res++;
    bfs(i,j,grid,vis);
}
}
        }
   return res; }
};