class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){
            auto f = [&]( vector<int>& v ){
                    vector<string> dp(k+1);
                    for( int j = 0 ; j < v.size() ; j++ )
                            for( int i = min(j,k-1) ; i >= 0 ; i-- ) if( dp[i].size() == i )
                                    dp[i+1] = max(dp[i+1],dp[i] + to_string(v[j]) );
                    return dp;
            };
            auto merge = [&]( string &a , string &b ){
                    string c = "";
                    while( !a.empty() && !b.empty() ){
                            if( a >= b ){ c += a[0]; if( a.size() == 1 ) a = ""; else a = a.substr(1); }
                            else{ c += b[0]; if( b.size() == 1 ) b = ""; else b = b.substr(1); }
                    }
                    while( !a.empty() ){
                            c += a[0]; if( a.size() == 1 ) break; a = a.substr(1);
                    }
                    while( !b.empty() ){
                            c += b[0]; if( b.size() == 1 ) break; b = b.substr(1);
                    }
                    return c;
            };
            vector<string> dp1 = f(nums1) , dp2 = f(nums2);
            string ans = max(dp1[k],dp2[k]);
            for( int i = 1 ; i < k ; i++ ){
                    if( dp1[i].empty() || dp2[k-i].empty() ) continue;
                    string tmp = merge(dp1[i],dp2[k-i]);
                    ans = max(ans,tmp);
            }
            vector<int> anso;
            for( auto z : ans ) anso.push_back(z-'0');
            return anso;
    }
};