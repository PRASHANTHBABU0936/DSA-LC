class Solution {
public:
vector<vector<int>> meo;
int hell(int index1,int amount,vector<int>& coins,int sum){

if(sum == amount) return 1;
if(sum > amount||index1==coins.size()) return 0;
if(meo[index1][sum] != -1) return meo[index1][sum];
int num1=hell(index1,amount,coins,coins[index1]+sum);
// int num2=hell(index1+1,amount,coins,coins[index1]+sum);
int num3=hell(index1+1,amount,coins,sum);
return meo[index1][sum]=num1+num3;
}
    int change(int amount, vector<int>& coins) {
        // int n = 
        meo.assign(coins.size(),vector<int>(amount,-1));
        return hell(0,amount,coins,0);
    }
};