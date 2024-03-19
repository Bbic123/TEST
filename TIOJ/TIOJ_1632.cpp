#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 5;

ll arr[N], sum[N];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	ll k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	for(int i = n - 1; i >= 1; --i) arr[i] -= arr[i - 1];
	for(int i = 1; i < n; ++i) sum[i] = arr[i] + sum[i - 1];
	ll R = sum[n - 1] + 1, L = -1, MID;
	while(L + 1 < R){
		MID = (L + R) >> 1;
		ll chk = 0;
		int l = 1;
		for(int i = 1; i < n; ++i) chk += arr[i] < MID;
		for(int r = 1; r <= n - 1; ++r){
			while(l < r && !(sum[r] - sum[l - 1] < MID)){
				++l;
				if(l < r - 1) chk += ((r - 1) - l);
			}
			if(l < r) ++chk;
		}
		++l;
		while(l < n - 1){
			chk += ((n - 1) - l);
			++l;
		}
		if(chk < k) L = MID;
		else R = MID;
	}
	cout << L << '\n';
	return 0;
}
