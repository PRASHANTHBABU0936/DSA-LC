class Solution {
public:

    int MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        while(exp > 0) {
            if(exp % 2) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

// int hell( vector<int> &adj,int res){
// if(a)
// }
    int assignEdgeWeights(vector<vector<int>>& edges) {
int n = edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(auto &ed:edges){
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);  
    }

    queue<int> q;
    vector<int> vis(n+1, 0);

    q.push(1);
    vis[1]=1;
    int res=0;
    int level=1;
    while(!q.empty()){
        level=q.size();
        for(int i=0;i<level;i++){
int hell=q.front();
q.pop();

for(auto curr:adj[hell]){
    if(!vis[curr]){vis[curr]=1;
q.push(curr);}
}
    }res++; }
    int k = res-1;
    // int res=0;
// maxi=hell(adj,res);
if(k == 0) return 0;
return power(2,k-1);}
};