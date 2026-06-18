class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
         vector<vector<int>>  res;
bool boolene = false;
if(n == 1) return intervals;
         for(int i=1;i<intervals.size();i++){
if(intervals[i][0] <= intervals[i-1][1]){
vector<int> crea;
crea.push_back(intervals[i-1][0]);
int hell=intervals[i-1][1];
while(i<n && intervals[i][0] <= hell){
    hell=max(intervals[i][1],hell);
i++;
}
crea.push_back(hell);
res.push_back(crea);
i--;}
else{
        // if((i == n-1)) boolene=true;
     if(res.empty() || res.back()[1] < intervals[i-1][0]) {
                    res.push_back(intervals[i-1]);
                }
}
         }
        if(res.empty() || res.back()[1] < intervals[n-1][0]) {
            res.push_back(intervals[n-1]);}
        return res;}
};