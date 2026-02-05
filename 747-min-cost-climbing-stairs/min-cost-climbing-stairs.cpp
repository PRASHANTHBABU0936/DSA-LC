class Solution {
public:
vector <int> dp;
int hell(int i,vector<int>& cost){
if(i == 0)return cost[0];
if(i == 1) return cost[1];
        if (dp[i] != -1) return dp[i];

        return dp[i] = cost[i] + min(hell(i-1, cost), hell(i-2, cost));
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n,-1);
        return min(hell(n-1,cost),hell(n-2,cost));
    }
};