// sourav sharma : Travel Restriction

#include <bits/stdc++.h>
using namespace std;
#define sourav sharma
#define int long long int
#define fast ios::sync_with_stdio(false); cin.tie(0);


int32_t main(){
    fast;
    int testcase; cin >> testcase;
    for(int tt = 1; tt <= testcase; ++tt) {
        int n; cin >> n;
        string s, d;
        cin >> s >> d;
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; ++i){
            if(i - 1 >= 0 && s[i] == 'Y' && d[i - 1] == 'Y') 
                dp[i - 1][i] = 1;
            if(i + 1 < n && s[i] == 'Y' && d[i + 1] == 'Y') 
                dp[i + 1][i] = 1;
        }
            
        for(int k = 0; k < n; ++k) 
            for(int i = 0; i < n; ++i) 
                for(int j = 0; j < n; ++j) 
                    dp[i][j] = dp[i][j] || (dp[i][k] && dp[k][j]);

        cout << "Case #" << tt << ":\n";
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j)
                    cout << "Y";
                else
                    cout << (dp[i][j] ? "Y" : "N");
            }
            cout << "\n";
        }
    }
    return 0;
}
