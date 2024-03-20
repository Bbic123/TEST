#include <bits/stdc++.h>
using namespace std; // abc230_E - Fraction Floor Sum

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, ans = 0, m;
	cin >> n;
	for(ll i = 1; i <= n; ++i){
		m = n / i;
		ans += m * ((n / m) - i + 1);
		i = (n / m);
	}
	cout << ans << '\n';
	return 0;
}
