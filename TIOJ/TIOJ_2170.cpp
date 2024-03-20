#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 105;

ll arr[N][N], MOD;

inline ll fastpow(ll a, ll n){
	ll re = 1;
	for(; n; n >>= 1){
		if(n & 1){
			re = (re * a) % MOD;
		}
		a = (a * a) % MOD;
	}
	return re;
}

inline ll divi(ll a, ll b){ /*a ÷ b*/
	return (a * fastpow(b, MOD - 2)) % MOD;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n >> MOD;
	for(int i = 1; i <= n; ++i) cin >> arr[i][n + 1];
	for(int j = 1; j <= n; ++j){
		for(int i = 1; i <= n; ++i){
			cin >> arr[i][j];
		}
	}
	for(int i = 1; i <= n; ++i){
		if(!arr[i][i]){
			bool no = 1;
			for(int j = i + 1; j <= n; ++j){
				if(arr[j][i]) no = false;
				if(!no){
					for(int k = 1; k <= n + 1; ++k) swap(arr[i][k], arr[j][k]);
					break;
				}
			}
		}
		for(ll j = i, HA = arr[i][i]; j <= n + 1; ++j){
			arr[i][j] = divi(arr[i][j], HA);
		}
		arr[i][i] = 1;
		for(int j = 1; j <= n; ++j){
			if(j == i) continue;
			ll WA = arr[j][i];
			for(int k = i; k <= n + 1; ++k) arr[j][k] = ((arr[j][k] - arr[i][k] * WA) % MOD + MOD) % MOD;
		}
	}
	for(int i = 1; i <= n; ++i) cout << arr[i][n + 1] % MOD << ' ';
	return 0;
}
