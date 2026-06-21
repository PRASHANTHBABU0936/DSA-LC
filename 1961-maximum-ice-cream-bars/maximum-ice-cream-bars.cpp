class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue <int,vector<int>,greater<int>> pq;

   for(auto ed:costs){
    pq.push(ed);
   }
    int sum=0;
int c=0;
    while(!pq.empty()){
        if(sum+pq.top()<=coins){
            c++;
            sum+=pq.top();
            pq.pop();
        }
        else break;
    }
  return c;  }
};