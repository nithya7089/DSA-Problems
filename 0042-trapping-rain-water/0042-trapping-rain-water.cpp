class Solution {
public:
    int trap(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<n;i++){
          while(!st.empty() && arr[i]>arr[st.top()]){
            int top = st.top();
            st.pop();
            if(st.empty()){
             break;
            }
            int width = i-st.top()-1;
            int br = min(arr[i],arr[st.top()]) - arr[top];
            ans += (width*br);
          }
          st.push(i);
        }
        return ans;
    }
};