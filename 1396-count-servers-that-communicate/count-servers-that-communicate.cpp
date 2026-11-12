class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        set<pair<int,int>> st;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++) {

            int count = 0;
            int first = -1, second = -1;

            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1) {
                    count++;

                    if(count == 1) {
                        first = i;
                        second = j;
                    }

                    if(count > 1) {
                        st.insert({first, second});
                        st.insert({i, j});
                    }
                }
            }
        }

        for(int j = 0; j < m; j++) {

            int count = 0;
            int first = -1, second = -1;

            for(int i = 0; i < n; i++) {

                if(grid[i][j] == 1) {
                    count++;

                    if(count == 1) {
                        first = i;
                        second = j;
                    }

                    if(count > 1) {
                        st.insert({first, second});
                        st.insert({i, j});
                    }
                }
            }
        }

        return st.size();
    }
};