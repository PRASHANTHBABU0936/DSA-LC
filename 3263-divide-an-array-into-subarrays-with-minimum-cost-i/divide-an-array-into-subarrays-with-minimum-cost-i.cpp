class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum = nums[0];
        priority_queue <int,vector<int>,greater<int>> pq;
        for(int i=1;i<nums.size();i++){
            pq.push(nums[i]);
        }
        sum+=pq.top();
        pq.pop();
        sum+=pq.top();
    return sum;}
};