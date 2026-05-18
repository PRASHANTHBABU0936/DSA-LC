class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int i = q.front();
                q.pop();

                if(i == n - 1) return steps;

                if(i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = 1;
                    q.push(i + 1);
                }

                if(i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = 1;
                    q.push(i - 1);
                }

                for(int j : mp[arr[i]]) {
                    if(!vis[j]) {
                        vis[j] = 1;
                        q.push(j);
                    }
                }

                mp[arr[i]].clear();
            }
            steps++;
        }

        return -1;
    }
};