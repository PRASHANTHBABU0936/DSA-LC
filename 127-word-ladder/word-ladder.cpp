class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string> st;
        st.insert(wordList.begin(), wordList.end());
        
        if(st.find(endWord) == st.end()) return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int c = 1;
        
        while(!q.empty()){ 
            int size = q.size();               
            for(int k = 0; k < size; k++){ 
                string hell = q.front();
                q.pop();
                
                string original = hell;
                
                if(original == endWord) return c;
                
                for(int i = 0; i < hell.size(); i++){
                    char temp = hell[i]; 
                    
                    for(char j='a'; j<='z'; j++){
                        hell[i] = j;
                        
                        if(hell != original){
                            if(st.find(hell) != st.end()){
                                q.push(hell);
                                st.erase(hell);
                            }
                        }
                    }
                    
                    hell[i] = temp;  
                }
            }
            c++; 
        }
        
        return 0;
    }
};