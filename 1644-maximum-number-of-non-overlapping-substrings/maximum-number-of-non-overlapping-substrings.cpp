class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        
        // Find first and last occurrence of each character
        vector<int> first(26, -1), last(26, -1);
        for(int i = 0; i < n; i++) {
            if(first[s[i] - 'a'] == -1) {
                first[s[i] - 'a'] = i;
            }
            last[s[i] - 'a'] = i;
        }
        
        // Generate valid substrings
        vector<pair<int,int>> validRanges; // {end, start}
        
        for(int i = 0; i < n; i++) {
            // Only start from first occurrence of each character
            if(first[s[i] - 'a'] != i) continue;
            
            int j = i;
            bool isValid = true;
            
            // Expand j to make the range valid
            while(true) {
                int newJ = j;
                
                // Check all characters in current range
                for(int k = i; k <= j; k++) {
                    // If character's first occurrence is before i, invalid
                    if(first[s[k] - 'a'] < i) {
                        isValid = false;
                        break;
                    }
                    // Expand to include all occurrences
                    newJ = max(newJ, last[s[k] - 'a']);
                }
                
                if(!isValid) break;
                if(newJ == j) break; // No more expansion needed
                j = newJ;
            }
            
            if(isValid) {
                validRanges.push_back({j, i});
            }
        }
        
        // Sort by end position (greedy: pick earliest-ending substrings)
        sort(validRanges.begin(), validRanges.end());
        
        // Greedily select non-overlapping substrings
        vector<string> result;
        int lastEnd = -1;
        
        for(auto [end, start] : validRanges) {
            if(start > lastEnd) {  // No overlap
                result.push_back(s.substr(start, end - start + 1));
                lastEnd = end;
            }
        }
        
        return result;
    }
};