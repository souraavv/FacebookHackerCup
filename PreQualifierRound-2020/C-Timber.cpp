// Sourav Sharma : Timber (C)

#include <bits/stdc++.h>
using namespace std;

#define hey(x) cerr << #x << " : " << x << "\n";
#define int long long int
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpi vector<pair<int, int> >
#define vvpi vector<vector<pair<int, int> > >
#define all(v) (v).begin(), (v).end()	
#define rall(v) (v).rbegin(), (v).rend()
#define pii pair<int, int>
#define pb push_back
#define SZ(x) (int)(x).size()
#define inf 1e12
#define F first
#define S second
#define fill(v, val) memset((v), val, sizeof(v))
#define PI 3.1415926535897932384626
#define out cout << fixed << setprecision(12)
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define hey2(x, y) cerr << #x << " : " << x << "," << #y << " : " << y << '\n';

const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const double pi = acos(-1);

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for(int test = 1; test <= t; ++test) {
		int n;
		cin >> n;
		vpi a;
		map<int, int> tell;
		for(int i = 0; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			a.pb({u, v});
		}
		sort(all(a));
		vi h(n), p(n);
		for(int i = 0; i < n; ++i) {
			p[i] = a[i].F, h[i] = a[i].S;
		}
		for(int i = 0; i < n; ++i) {
			tell[p[i] + h[i]] = max(tell[p[i] + h[i]], tell[p[i]] + h[i]);
			tell[p[i]] = max(tell[p[i]], tell[p[i] - h[i]] + h[i]);
		}
		int mx = 0;
		for(auto it : tell) {
			mx = max(mx, it.S);
		}
		cout << "Case #" << test << ": " << mx << '\n';
	}
	return 0;
}
