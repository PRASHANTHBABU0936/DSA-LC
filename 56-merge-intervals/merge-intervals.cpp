class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
         vector<vector<int>> res;
         int n=intervals.size();
         int h=intervals[0][0];
         int l=intervals[0][1];

         for(int i=1;i<n;i++){
if(intervals[i][0]<=l && intervals[i][1]>=l){
l=intervals[i][1];
}
else if(intervals[i][0]<=l && intervals[i][1]<=l){
    continue;
}
else {
    res.push_back({h,l});
    h=intervals[i][0];
    l=intervals[i][1];
}
         }
         res.push_back({h,l});
    return res;}
};