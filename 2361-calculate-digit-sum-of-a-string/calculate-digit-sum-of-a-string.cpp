class Solution {
public:
int sum(string hell){
    int sum = 0;
    for(int i=0;i<hell.size();i++){
    // sum+=stoi(hell[i]);
    sum += hell[i] - '0';
    }
return sum;}


    string digitSum(string s, int k) {
        int n = s.size();
        string h = s;
        // vector<int> ans;
        // ans.push_back(sum(h.substr(i,k)));
// 
while(h.size()>k){
        vector<int> ans;
        int i;
        for(i=0;i<h.size();i+=k){
            // ans[i]=sum(h.substr(i,k));
                    ans.push_back(sum(h.substr(i,k)));
// 
        }
        while(i<h.size()){
            // ans[i]=sum(h.substr(h.size()-i+1));
                 ans.push_back(sum(h.substr(h.size()-i+1)));

            break;
        }

        // h.clear();
        h="";
for(int i=0;i<ans.size();i++){
// h+=ans[i]+'0';
h += to_string(ans[i]);
}

}

    return h;}
};