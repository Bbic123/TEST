#include <bits/stdc++.h>
using namespace std; // CSES 1095

typedef long long ll;
const int MOD = 10007;

int fastpow(ll x, int n){
	int re = 1;
	for(; n; n >>= 1){
		if(n & 1) re = (re * x) % MOD;
		x *= x;
		x %= MOD;
	}
	return re % MOD;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	cout << fastpow(a, b) << '\n';
	return 0;
}