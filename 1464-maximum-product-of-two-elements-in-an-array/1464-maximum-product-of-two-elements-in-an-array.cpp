class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        int maxi = -1 , idx = -1;
        for(int i=0;i<n;i++){
          if(arr[i]>maxi){
           maxi = arr[i];
           idx = i; 
          }
        }
        int maxi2 = - 1;
        for(int i=0;i<n;i++){
          if(arr[i]>maxi2 && idx != i){
           maxi2 = arr[i];
          }
        }
        return (maxi - 1)*(maxi2 - 1);
    }
};