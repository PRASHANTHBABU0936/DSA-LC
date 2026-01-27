class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int l = bookings.size();
    vector<int> hell(n,0);
    for(int i=0;i<l;i++){
        for(int k = bookings[i][0];k<=bookings[i][1];k++){
hell[k-1]+=bookings[i][2];}}
return hell;}
};