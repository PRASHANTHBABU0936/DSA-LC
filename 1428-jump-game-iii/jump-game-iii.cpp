class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n,0);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int hell=q.front();
            q.pop();
if(hell < 0 || hell >= n || vis[hell]) continue;            if(arr[hell] == 0){
return true;}
vis[hell] = 1;
            q.push(hell + arr[hell]);
            q.push(hell - arr[hell]);
        }
    return false;}
};