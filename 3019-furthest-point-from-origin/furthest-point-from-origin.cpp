class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n= moves.size();
        int l=0,r=0,g=0;
        for(int i=0;i<n;i++){
            if(moves[i] == 'L') l++;
            else if(moves[i] == 'R') r++;
            else g++;
        }
        if(g == n) return n;
    else if(l>=r){
return l+g-r;
    }
    else {
        return r+g-l;
    }
  return 0;  }
};