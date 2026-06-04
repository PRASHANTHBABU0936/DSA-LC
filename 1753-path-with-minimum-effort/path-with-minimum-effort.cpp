class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& graph) {
      
        int n = graph.size();
        int m = graph[0].size();

       priority_queue<
    pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>> pq;
        int ans=0;
        // pq.push(0,{0,0});
        vector<vector<int>> vis(n, vector<int>(m, 0));
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            int hell1=pq.top().second.first;
            int hell2=pq.top().second.second;
            int dis=pq.top().first;
            pq.pop();

            if(vis[hell1][hell2]) continue;
            vis[hell1][hell2] = 1;
            ans=max(ans,dis);
            if(hell1 == n-1 && hell2 == m-1) return ans;
  int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            if(hell1+dx[i] < n && hell1+dx[i] >= 0 && hell2+dy[i] < m && hell2 + dy[i] >= 0){
pq.push({abs(graph[hell1][hell2] - graph[hell1+dx[i]][hell2+dy[i]]),{hell1+dx[i],hell2+dy[i]}});
            }
        }

        }

 return -1;   }
};