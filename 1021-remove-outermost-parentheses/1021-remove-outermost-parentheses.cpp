class Solution {
public:
    string removeOuterParentheses(string s) {
      string ans;
      int c = 0;
      for(int i=0;i<s.length();i++){
       if(s[i]=='(' && c==0){
        c++;
       }
       else if(s[i]=='('){
       ans.push_back('(');
       c++;
       }
       else if(s[i]==')' && c!=1){
        ans.push_back(')');
        c--;
       }
       else{
        c--;
       }
      }
      return ans;
    }
};