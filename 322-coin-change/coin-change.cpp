class Solution {
public:
    vector<vector<int>> dp;

int hell(vector<int>& coins, int amount,int index){
    if(amount == 0) return 0;
         if (amount < 0 || index == coins.size()) return 1e9;
 
        if (dp[index][amount] != -1)
            return dp[index][amount];
   int take = 1 + hell(coins, amount - coins[index], index);
        int skip = hell(coins, amount, index + 1);

        return dp[index][amount] = min(take, skip);
}
    int coinChange(vector<int>& coins, int amount) {
                dp.assign(coins.size(), vector<int>(amount + 1, -1));

        int h=0;
            int ans = hell(coins, amount, 0);
        return (ans >= 1e9) ? -1 : ans;
    }
};