// sourav sharma : Alchemy

#include <bits/stdc++.h>
using namespace std;
#define sourav sharma
#define fast ios::sync_with_stdio(false); cin.tie(0);

int main(){
    fast;
    int testcase; cin >> testcase;
    for(int tt = 1; tt <= testcase; ++tt) {
        int n; cin >> n;
        string s; cin >> s;
        long long int cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(s[i] == 'A')
                cnt++;
            else
                cnt--;
        }
        cout << "Case #" << tt << ": ";
        if(abs(cnt) >= 3) 
            cout << "N\n";
        else 
            cout << "Y\n";
    }
    return 0;
}
