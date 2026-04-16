class Solution {
public:

 int hell(int n,int idx1,int idx2,string s,int i){
    int count=0;
while(i<s.size()){
    if(s[i] == 'R'){
idx2++;
    }
     else if(s[i] == 'U'){
        idx1--;
    }
      else if(s[i] == 'D'){
        idx1++;
    }
     else if(s[i] == 'L'){
        idx2--;
    }
 
            if(idx1 < 0 || idx1 >= n || idx2 < 0 || idx2 >= n)
                break;

            count++;
            i++;
        }
        return count;
 }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        // int n = s.size();
                vector<int> ans(s.size());
for(int i=0;i<s.size();i++){
    ans[i]=hell(n,startPos[0],startPos[1],s,i);
}
    return ans;}
};