class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        bool hell=false;
int count=0;
int res=0;
        for(int i=0;i<n;i++){
            if(s[i] == '('){ hell=true;
            count++;
            }
            else if(s[i]==')' && hell==true){
                count--;
            }
      res=max(res,count);
        }
    return res;}
};