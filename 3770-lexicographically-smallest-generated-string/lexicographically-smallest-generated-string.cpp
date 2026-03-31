class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        string word(n + m - 1, '?');
        vector<bool> fixed(n + m - 1, false);

        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                for(int j = 0; j < m; j++){
                    if(word[i + j] == '?' || word[i + j] == str2[j]){
                        word[i + j] = str2[j];
                        fixed[i + j] = true;
                    } else {
                        return "";
                    }
                }
            }
        }

        for(int i = 0; i < word.size(); i++){
            if(word[i] == '?') word[i] = 'a';
        }

        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){
                bool same = true;

                for(int j = 0; j < m; j++){
                    if(word[i + j] != str2[j]){
                        same = false;
                        break;
                    }
                }

                if(same){
                    bool changed = false;

                    for(int j = m - 1; j >= 0; j--){
                        if(fixed[i + j]) continue;

                        for(char c = 'a'; c <= 'z'; c++){
                            if(c != str2[j]){
                                word[i + j] = c;
                                changed = true;
                                break;
                            }
                        }

                        if(changed) break;
                    }

                    if(!changed) return "";
                }
            }
        }

        for(int i = 0; i < n; i++){
            string temp = word.substr(i, m);

            if(str1[i] == 'T' && temp != str2) return "";
            if(str1[i] == 'F' && temp == str2) return "";
        }

        return word;
    }
};