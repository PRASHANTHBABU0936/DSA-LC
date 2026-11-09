class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free_;
        for (int i = 0; i < k; i++) free_.insert(i);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> busy; // {endTime, id}
        vector<int> cnt(k, 0);

        int n = arrival.size();
        for (int i = 0; i < n; i++) {
            // release servers that finished by now
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                free_.insert(busy.top().second);
                busy.pop();
            }
            if (free_.empty()) continue; // dropped

            auto it = free_.lower_bound(i % k);
            if (it == free_.end()) it = free_.begin(); // wrap around

            int id = *it;
            free_.erase(it);
            cnt[id]++;
            busy.push({arrival[i] + load[i], id}); // arrival + load <= 2e9, fits in long long safely
        }

        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i = 0; i < k; i++)
            if (cnt[i] == mx) ans.push_back(i);
        return ans;
    }
};