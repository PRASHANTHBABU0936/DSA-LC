#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<vector<int>>& g){
        int n=g.size(), m=g[0].size();
        long long total=0;
  for(auto &r:g) for(auto x:r) total+=x;

        unordered_map<long long,int> right,left;

        for(auto &r:g)
    for(auto x:r)
    right[x]++;

 long long sum=0;

 for(int j=0;j<m-1;j++){
   for(int i=0;i<n;i++){
 int val=g[i][j];
    sum+=val;

                left[val]++;
      right[val]--;
       if(right[val]==0) right.erase(val);
            }

    long long other=total-sum;

          if(sum==other) return true;

   long long diff=abs(sum-other);
 if(sum>other){
         int rows=n, cols=j+1;
          if(rows==1){
       if(g[0][0]==diff || g[0][cols-1]==diff) return true;
                }
                else if(cols==1){
     if(g[0][0]==diff || g[n-1][0]==diff) return true;
                }
                else{
       if(left.count(diff)) return true;}}
            else{
                int rows=n, cols=m-j-1;

                if(rows==1){ 
                    if(g[0][j+1]==diff || g[0][m-1]==diff) return true;}
                
                else if(cols==1){ 
                    if(g[0][j+1]==diff || g[n-1][j+1]==diff) return true;}
                
                else{
                    if(right.count(diff)) return true;}}}
        return false;}
    

    bool canPartitionGrid(vector<vector<int>>& grid) {
        if(check(grid)) return true;

        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> t(m, vector<int>(n));

 for(int i=0;i<n;i++)
     for(int j=0;j<m;j++)
       t[j][i]=grid[i][j];

        return check(t);
    }
};