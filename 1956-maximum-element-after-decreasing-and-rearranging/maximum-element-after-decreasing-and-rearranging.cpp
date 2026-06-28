class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int maxi=1;
        // arr[]
        int n = arr.size();
        sort(arr.begin(),arr.end());
        if(arr[0] != 1){
            // maxi=1;
            arr[0] = 1;

        }
        // else { 
            for(int i=1;i<n;i++){
                if((abs(arr[i] - arr[i - 1])) > 1){
maxi=maxi+1;
arr[i]=maxi;
                }
                else {
                    maxi=max(maxi,arr[i]);
                }
            
        }
  return maxi;  }
};