class Solution {
public:
int reverse(int h){
    int mim=0;
    while(h>0){
        // if(h%10 != 0){
            // h=h/10;
            // continue;
            mim=mim*10+(h%10);
        // }
        // else {

h=h/10;}
   return mim; }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map <int,int> mp;
        int dis=INT_MAX;
        for(int i=n-1;i>=0;i--){
if(!mp.empty() && mp.find(reverse(nums[i])) != mp.end()){
    int numj = reverse(nums[i]);
// dis=min(dis,mp[numj].second()-i);
dis = min(dis, mp[numj] - i);
}
mp[nums[i]]=i;
        }
        if(dis==INT_MAX) return -1;
  return dis;  }
};