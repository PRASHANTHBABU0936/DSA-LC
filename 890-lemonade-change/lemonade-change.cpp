class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map <int,int> mp;
    
        int n = bills.size();

        for(int i=0;i<n;i++){
          if(bills[i] == 5){
            mp[5]++;
          }  

          else if(bills[i] == 10){
if(mp.find(5) == mp.end() || mp[5] == 0) return false;
else {
    mp[10]++;
    mp[5]--;
}
          }

          else {
                  if((mp.find(5) != mp.end()) && (mp.find(10) != mp.end()) && mp[5]>=1 && mp[10]>=1){mp[10]--;
            mp[5]--;
          }
            else if(mp.find(5) != mp.end() && mp[5] >= 3){ mp[5]=mp[5]-3;}
      
          else return false;}
        }

    return true;}
};