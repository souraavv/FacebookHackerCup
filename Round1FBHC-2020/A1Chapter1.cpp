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
#define PI 3.1415926535897932384626
#define Cout cout << fixed << setprecision(12)
#define fill(v, val) memset((v), val, sizeof(v))
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define hey2(x, y) cerr << #x << " : " << x << "," << #y << " : " << y << '\n';

const int N = 2e7 + 10;
const int mod = 1e9 + 7;
const double pi = acos(-1);

void print(vi &a) {
	cerr << "Printing : \n";
	for(int i : a) cerr << i << ' ';
	cerr << "\n";
}

int add(int a, int b, int MOD) {
	a += b;
	if(a >= MOD)
		return a - MOD;
	return a;
}

int mul(int a, int b, int MOD) {
	return (a * b) % MOD;
}


class SegmentTree {
public:
    SegmentTree(int count) {
        n = count;
        data = std::vector<int>(2 * n, 0);
    }
 
    SegmentTree(std::vector<int> const &values) {
        n = values.size();
        data = std::vector<int>(2 * n);
        std::copy(values.begin(), values.end(), &data[0] + n);
        for (int idx = n - 1; idx > 0; idx--)
            data[idx] = opr(data[idx * 2], data[idx * 2 + 1]);
    }
 
    int opr(int a, int b) {
        return max(a, b); // set this accordingly
    }
    void update(int idx, int value) {
        idx += n;
        data[idx] = max(data[idx], value); // also look at this whether complete new value of old + new value;
 
        while (idx > 1) {
            idx /= 2;
            data[idx] = opr(data[2 * idx], data[2 * idx + 1]);
        }
    }
 
    int query(int left, int right) { // interval [left, right)
        int ret = 0; // Initialize accoring to the range operation
        left += n;
        right += n;
 
        while (left < right) {
            if (left & 1) ret = opr(ret, data[left++]);
            if (right & 1) ret = opr(ret, data[--right]);
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }
 
private:
    int n;
    std::vector<int> data;
};

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int test;
	cin >> test;
	for(int t = 1; t <= test; ++t) {
		int n, k, w;
		cin >> n >> k >> w;
		vi L(n + 1, 0), H(n + 1, 0);
		for(int i = 1; i <= k; ++i)
			cin >> L[i];
		int AL, BL, CL, DL;
		cin >> AL >> BL >> CL >> DL;
		for(int i = 1; i <= k; ++i)
			cin >> H[i];
		int AH, BH, CH, DH;
		cin >> AH >> BH >> CH >> DH;

		for(int i = k + 1; i <= n; ++i) {
			L[i] = ((AL * L[i - 2]) % DL + (BL * L[i - 1]) % DL + CL) % DL;
			L[i] = L[i] + 1;
			H[i] = ((AH * H[i - 2]) % DH + (BH * H[i - 1]) % DH + CH) % DH;
			H[i] = H[i] + 1;
 		}
		vi tell(n + 1, 0); 
		tell[1] = 0;

		for(int i = 2; i <= n; ++i) {
			if(L[i - 1] + w >= L[i]) {
				tell[i] = 1;
			}
 		}
 		for(int i = 2; i <= n; ++i) {
 			if(tell[i] && tell[i - 1]) {
 				tell[i] += tell[i - 1];
 			}
 		}
 		vi P(n + 1, 0);
 		vi only(n + 1, 0);
 		SegmentTree st(N);

		for(int i = 1; i <= n; ++i) {
			if(tell[i] > 0) {
				int idx = i - tell[i];
				int prev = P[idx - 1];
				auto it = lower_bound(all(L), L[i] - w);
				int idx1 = it - L.begin();
				int mxH = st.query(idx1, i + 1);
				int cur = 2 * (L[i] - L[idx] + w);
				int oldHeight = only[i - 1];
				cur += oldHeight;
				int newHeight = 0;
				if(H[i] > mxH) {
					newHeight = (H[i]) + (H[i] - 2 * mxH);
				}
				cur += newHeight;
				only[i] = oldHeight + newHeight;
				P[i] = (prev + cur) % mod;
			}
			else {
				int prev = P[i - 1];
				int cur = 2 * (H[i] + w);
				only[i] = (2 * H[i]);
				P[i] = (cur + prev) % mod;
			}
			st.update(i, H[i]);
		}
		int finalAns = 1;
		for(int i = 1; i <= n; ++i) {
			finalAns = (finalAns % mod * P[i] % mod) % mod;
		}
		cout << "Case #" << t << ": " << finalAns << "\n";
	}    
	return 0;
}
