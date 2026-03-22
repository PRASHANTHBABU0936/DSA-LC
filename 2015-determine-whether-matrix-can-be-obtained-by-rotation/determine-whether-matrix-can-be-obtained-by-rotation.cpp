class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) return true;
        // vector<vector<int>> hell=mat;
 int n = mat.size();
 for(int rot=0;rot<=3;rot++){
 for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }
        for(int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
    if(mat == target) return true;}

   return false; }
};