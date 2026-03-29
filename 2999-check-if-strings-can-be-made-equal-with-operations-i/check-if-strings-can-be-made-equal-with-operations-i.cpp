class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_set<string> st;

 st.insert(s1);
       string t = s1;

       
        swap(t[0], t[2]);       st.insert(t);

        t = s1;
        swap(t[1], t[3]);
        st.insert(t);
        t = s1;
    
        swap(t[0], t[2]);
    swap(t[1], t[3]);
 st.insert(t);

        
  if(st.find(s2) != st.end()) return true;
        return false;
    }
};