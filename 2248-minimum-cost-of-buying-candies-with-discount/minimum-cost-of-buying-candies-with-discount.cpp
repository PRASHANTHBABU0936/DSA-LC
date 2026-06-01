class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        int sum=0;
        priority_queue <int>  pq;
        for(int i=0;i<n;i++){
            pq.push(cost[i]);
        }
        int c=0;

        while(!pq.empty()){
if(c == 2){
    c=0;
     pq.pop();
    continue;
   }

sum+=pq.top();
pq.pop();
c++;

        }

    return sum;}
};