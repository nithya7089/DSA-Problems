string q[1000];
int front=0, back=0;
class Solution {
public:
    int n, maxLen=0;
    int freq[26]={0};
    bool repeatK(const string& s, const string& t, int m, int k){
        for (int i=0, j=0; i<n && k>0; i++) {
            if (s[i]==t[j]) {
                j++;
                if (j==m) {
                    k--;
                    j=0;
                }
            }
        }
    //    cout<<"k="<<k<<endl;
        return k==0;
    }

    string ans="";
    vector<char> chars;
    void bfs(const string& s, int k) {
        front=back=0;// reset for q
        q[back++]="";
        while (front<back) {
            string t=q[front++];
            int m=t.size();
            if (m>ans.size()) ans=t;
            for (char c : chars) {
                if (freq[c-'a']<k) continue;
                freq[c-'a']-=k;// Use c k times
                t.push_back(c);
                if (repeatK(s, t, m+1, k)) {
                    if (m<maxLen) q[back++]=t;
                }
                t.pop_back();// backtracking
                freq[c-'a']+=k;
            }
        }
    }

    string longestSubsequenceRepeatedK(string& s, int k) {
        bitset<26> hasX=0;
        for(char c: s){
            const int x=c-'a';
            if (++freq[x]==k)
                hasX[x]=1;
        }
        if (hasX==0) return "";

        // reuse s, rebuild the string s for c in s with freq[c-'a]>=k 
        // it's faster for checking if a subsequence is reapted k times
        int j=0;
        n=s.size();
        for(int i=0; i<n; i++){
            const int x=s[i]-'a';
            if (hasX[x]) s[j++]=s[i];
        }
        s.resize(j);
        n=j;
        maxLen=n/k;
        chars.reserve(26);
        for(int i=25; i>=0; i--)// lexico large first
            if (hasX[i]) chars.push_back('a'+i);
    
        bfs(s, k);
    
        return ans;
    }
};