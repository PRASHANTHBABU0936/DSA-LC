class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
         vector<int> ans;
        int n = grid.size();
       int h = n*n;
        vector<int> freq(h + 1, 0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
freq[grid[i][j]]++;
            }
        }
        int missing=-1;
        int repeated=-1;
    for(int i = 1; i <= h; i++){
            if(freq[i] == 0){
                missing = i;
            }
            if(freq[i] == 2){
                repeated = i;
            }
        }

        ans.push_back(repeated);
        ans.push_back(missing);

        return ans;}
};