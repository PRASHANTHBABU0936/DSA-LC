class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // vector<pair<vector<int>,int>> graph;
        vector<vector<pair<int,int>>> graph(n+1);
        for(int i=0;i<times.size();i++){
graph[times[i][0]].push_back({times[i][1], times[i][2]});
// graph[times[0]]
        }
        // vector <int> dis(n,INT_MAX);
         vector<int> dis(n + 1, INT_MAX);
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int hell1=pq.top().first;
            int hell2=pq.top().second;
            pq.pop();
        for(int i=0;i<graph[hell2].size();i++){
            if(hell1+graph[hell2][i].second < dis[graph[hell2][i].first]){
                dis[graph[hell2][i].first]=hell1+graph[hell2][i].second;

            
            pq.push({dis[graph[hell2][i].first],graph[hell2][i].first});}
        }
        }
if(find(dis.begin()+1, dis.end(), INT_MAX) != dis.end())
    return -1;
return *max_element(dis.begin() + 1, dis.end());}};