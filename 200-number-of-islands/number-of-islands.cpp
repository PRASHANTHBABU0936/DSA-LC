class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        queue <pair<int,int>> q;
                vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
count++;
q.push({i,j});

while(!q.empty()){
    int hell1=q.front().first;
    int hell2=q.front().second;
    q.pop();
    vis[hell1][hell2]=1;
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
for(int i=0;i<4;i++){
if((hell1+dx[i])<n && (hell1+dx[i]>=0) && (hell2+dy[i]<m) && (hell2+dy[i]>=0)){
if(grid[hell1+dx[i]][hell2+dy[i]] == '1' && vis[hell1+dx[i]][hell2+dy[i]] == 0){
q.push({hell1+dx[i],hell2+dy[i]});
vis[hell1+dx[i]][hell2+dy[i]]=1;
}
}
}

}

                }
            }
        }
  return count;  }
};