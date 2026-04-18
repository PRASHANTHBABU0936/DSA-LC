class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
       unordered_set <string> st;
       for(int i=0;i<wordList.size();i++){
        st.insert(wordList[i]);
       }
               if (st.find(endWord) == st.end()) return 0;

        queue<pair<string,int>> q;
q.push({beginWord,1});
while(!q.empty()){
    string word=q.front().first;
  int steps = q.front().second;      q.pop();
                if (word == endWord) return steps;

    for(int j=0;j<word.size();j++){
char original = word[j];
       for(char ch = 'a'; ch <= 'z'; ch++){ 
                        word[j] = ch;
                    if (st.find(word) != st.end()) {
                        q.push({word, steps + 1});
                                                st.erase(word);


}
    }

                word[j] = original;

}
// string h=beginWord;
// for(int j=0;j<h.size();j++){
//     for()
// }

    }        return 0;
}
};