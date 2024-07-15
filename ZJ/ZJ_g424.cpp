#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define O_O ios::sync_with_stdio(0), cin.tie(0)
#define st first
#define nd second

const int N = 1e5 + 5;

ll dp[N];
deque<pair<ll, ll>> dq; // val, idx

signed main(){
	O_O;
	int n, k;
	cin >> n >> k;
	dq.push_back({0, 0});
	++k;
	ll sum = 0;
	ll a;
	for(int i = 1; i <= n; ++i){
		cin >> a;
		sum += a;
		if(!dq.empty() && dq.front().nd < i - k) dq.pop_front();
		if(!dq.empty()){
			dp[i] = dq.front().st + a;
		}
		else{
			dp[i] = dp[i] + a;
		}
		while(!dq.empty() && dq.back().st >= dp[i]) dq.pop_back();
		dq.push_back({dp[i], i});
	}
	ll ans = LLONG_MAX;
	for(int i = n; i >= n - k + 1 && i >= 1; --i) ans = min(ans, dp[i]);
	cout << sum - ans << '\n';
	return 0;
}