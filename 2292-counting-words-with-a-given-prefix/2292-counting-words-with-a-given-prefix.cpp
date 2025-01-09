class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(int i=0;i<words.size();i++){
           int n = words[i].length();
           int j = 0;
           for(int k=0;k<n;k++){
             if(pref[j]==words[i][k]){
               j++;
               if(j==pref.length()){
               ans++;
               break;
               }
             }
             else{
             break;
             }
           }
        }
        return ans;
    }
};