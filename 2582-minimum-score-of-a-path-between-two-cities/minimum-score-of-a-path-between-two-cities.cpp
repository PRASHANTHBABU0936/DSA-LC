class Solution {
public:
    int minScore(int n, vector<vector<int>>& r) {
        // vector<vector<<pair<int,int>>> adj(n);
        vector<vector<pair<int,int>>> adj(n+1);
for (int i = 0; i < r.size(); i++) {
    adj[r[i][0]].push_back({r[i][1], r[i][2]});
    adj[r[i][1]].push_back({r[i][0], r[i][2]});
}
queue <pair<int,int>> q;
vector<int> vis(n+1,0);
      vis[1]=1;
        q.push({1,INT_MAX});
        int mini=INT_MAX;
  
        // qhil
while(!q.empty()){
auto[hell1,hell2]=q.front();
    q.pop();
    // vis[hell1]=1;
    mini=min(mini,hell2);
    for(int i=0;i<adj[hell1].size();i++){
                        mini = min(mini, adj[hell1][i].second);

        if(vis[adj[hell1][i].first] == 0){
                vis[adj[hell1][i].first] = 1;

            q.push({adj[hell1][i].first,adj[hell1][i].second});
        }
    }
    

}

    return mini;}
};