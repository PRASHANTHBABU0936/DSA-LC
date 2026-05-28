class Solution {
public:
    struct Node {
        int child[26];
        int idx;
        Node() {
            memset(child, -1, sizeof(child));
            idx = -1;
        }
    };

    vector<Node> trie;

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.push_back(Node());

        int mini = 0;
        for(int i = 1; i < wordsContainer.size(); i++){
            if(wordsContainer[i].size() < wordsContainer[mini].size()){
                mini = i;
            }
        }

        trie[0].idx = mini;

        for(int i = 0; i < wordsContainer.size(); i++){
            string s = wordsContainer[i];
            reverse(s.begin(), s.end());

            int node = 0;

            for(char ch : s){
                int ind = ch - 'a';

                if(trie[node].child[ind] == -1){
                    trie[node].child[ind] = trie.size();
                    trie.push_back(Node());
                }

                node = trie[node].child[ind];

                if(trie[node].idx == -1 || 
                   wordsContainer[i].size() < wordsContainer[trie[node].idx].size() ||
                   (wordsContainer[i].size() == wordsContainer[trie[node].idx].size() && i < trie[node].idx)){
                    trie[node].idx = i;
                }
            }
        }

        vector<int> res;

        for(auto q : wordsQuery){
            reverse(q.begin(), q.end());

            int node = 0;
            int ans = trie[0].idx;

            for(char ch : q){
                int ind = ch - 'a';

                if(trie[node].child[ind] == -1) break;

                node = trie[node].child[ind];
                ans = trie[node].idx;
            }

            res.push_back(ans);
        }

        return res;
    }
};