#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

ll arr[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> arr[i];
	sort(arr + 1, arr + 1 + n);
	ll L = (arr[1] << 1), R = (arr[n] << 1), MID;
	while(L < R){
		MID = (L + R) >> 1;
		ll l = 1, r = n, cnt = 0;
		for(; r >= l; --r){
			while(arr[l] + arr[r] <= MID) ++l;
			if(l > r) break;
			cnt += r - l + 1;
		}
		if(cnt >= k) L = MID + 1;
		else R = MID;
	}
	if(abs(L) % 2) cout << L << "\n2\n";
	else cout << (L / 2) << "\n1\n";
	return 0;
}
