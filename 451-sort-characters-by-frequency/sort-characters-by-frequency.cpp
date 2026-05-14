class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map <char,int> mp;
        for(int i=0;i<n;i++){
mp[s[i]]++;
        }
               priority_queue<pair<int,char>> pq;

  for(auto inter : mp){
    pq.push({inter.second, inter.first}); }
    int h=0;
    
    while(!pq.empty()){
        auto top = pq.top();
        pq.pop();

int freq=top.first;
char ch=top.second;

while(freq>0){
    s[h++]=ch;
    freq--;
}
    }



    return s;}
};