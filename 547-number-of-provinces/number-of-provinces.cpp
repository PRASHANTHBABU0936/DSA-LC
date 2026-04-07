class Solution {
public:
void dfs(int i,   vector <int> &vis,vector<vector<int>>& isConnected){
if(vis[i] != 1){
    vis[i] = 1;
    for(int j=0;j<isConnected.size();j++){
                    if (isConnected[i][j] == 1 && !vis[j]) {
        dfs(j,vis,isConnected);}
    }
}
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector <int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
if(!vis[i]) {
    dfs(i,vis,isConnected);
    ans++;
}
        }
   return ans; }
};