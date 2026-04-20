class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int dis=0;
        if(colors[n-1] != colors[0]) return n-1;
int k=0;
int j=n-1;
for(int i=1;i<n;i++){
if(colors[i] != colors[k]){
    dis=max(dis,max(abs(i-0),abs(n-1-i)));
}
}

// while(i<n){
//     if(colors[]i == colors[0]) {
//         i++;
//         j++;
//     }
//     else{
//     max()
//     }  

// }
    return dis;}
};