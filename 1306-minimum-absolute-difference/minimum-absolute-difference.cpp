class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
         vector<vector<int>> res;
         int n = arr.size();
         sort(arr.begin(),arr.end());
         int mini=INT_MAX;
         for(int i=0;i<n-1;i++){
if(abs(arr[i]-arr[i+1])<mini){
    mini=abs(arr[i]-arr[i+1]);}}
         for(int i=0;i<n-1;i++){
         if(abs(arr[i]-arr[i+1]) == mini){
// vector <int> comp;
// comp.push_back(arr[i]);
// comp.push_back({arr[i+1]});
res.push_back({arr[i],arr[i+1]});
         }

         }
    

    return res;}
};