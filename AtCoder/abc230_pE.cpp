#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){ // abc230_pE
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, ans = 0, m, n1;
	cin >> n;
	for(ll i = 1; i <= n; ++i){
		m = n / i;
		if(m < i){
			ans += m * ((n / m) - i + 1);
			i = (n / m);
		}
		else ans += m;
	}
	cout << ans << '\n';
	return 0;
}
