class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        q.push(start);
        
        vector<int> vis(n, 0);
        vis[start] = 1;
        
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            
            if (arr[i] == 0) return true;
            
            int right = i + arr[i];
            int left = i - arr[i];
            
            if (right < n && !vis[right]) {
                vis[right] = 1;
                q.push(right);
            }
            
            if (left >= 0 && !vis[left]) {
                vis[left] = 1;
                q.push(left);
            }
        }
        
        return false;
    }
};