class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int maxi=0;
        int res=0;
        int maxFreq[26]={0};
while(j<n){
maxFreq[s[j]-'A']++;
if(maxFreq[s[j]-'A']>=maxi){
    maxi=maxFreq[s[j]-'A'];
}
if((j-i+1)-maxi>k){
          maxFreq[s[i] - 'A']--;
i++;
    // maxi--;
    // i=j;
    // j=i;
    }
// else{
 res=max(res,j-i+1);
    j++; 
       
   }
  return res;  }
};