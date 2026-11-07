class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        using P = pair<int,int>;                 // (weight, index)
        using T = tuple<long long,int,int>;      // (freeTime, weight, index)

        priority_queue<P, vector<P>, greater<P>> freeS;
        priority_queue<T, vector<T>, greater<T>> busy;

        for (int i = 0; i < n; i++) freeS.push({servers[i], i});

        vector<int> ans(m);
        long long t = 0;
        for (int j = 0; j < m; j++) {
            t = max(t, (long long)j);

            // if nobody is free, fast-forward to the next completion
            if (freeS.empty()) t = max(t, get<0>(busy.top()));

            // release all servers finished by time t
            while (!busy.empty() && get<0>(busy.top()) <= t) {
                auto [ft, w, idx] = busy.top(); busy.pop();
                freeS.push({w, idx});
            }

            auto [w, idx] = freeS.top(); freeS.pop();
            ans[j] = idx;
            busy.push({t + tasks[j], w, idx});
        }
        return ans;
    }
};