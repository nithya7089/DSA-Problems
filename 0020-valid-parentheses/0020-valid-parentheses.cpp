class Solution {
public:
    bool isValid(string s) {
     stack<char> st;
     for(int i=0;i<s.length();i++){
        if(s[i]=='('){
         st.push('(');
        }
        else if(s[i]==')'){
          if(st.empty()){
          return false;
          }
          char d = st.top();
          if(d!='('){
           return false;
          }
          st.pop();
        }
        else if(s[i]=='['){
         st.push('[');
        }
        else if(s[i]==']'){
          if(st.empty()){
          return false;
          }
          char d = st.top();
          if(d!='['){
           return false;
          }
          st.pop();
        }
        else if(s[i]=='{'){
         st.push('{');
        }
        else if(s[i]=='}'){
          if(st.empty()){
          return false;
          }
          char d = st.top();
          if(d!='{'){
           return false;
          }
          st.pop();
        }
     } 
     if(st.empty()){
      return true;
     }
     return false;
    }
};