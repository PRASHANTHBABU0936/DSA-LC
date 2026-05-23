#include <algorithm>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> hell = nums;
        sort(hell.begin(), hell.end());

        vector<int> oer = nums;
        oer.insert(oer.end(), nums.begin(), nums.end());

        return search(oer.begin(), oer.end(), hell.begin(), hell.end()) != oer.end();
    }
};