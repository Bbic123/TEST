#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N = 1e4 + 5;

ll arr[N], BIT[N][15], n;

#define lowbit(x) ((x) & (-x))

inline void update(int idx, int num, int mod){
	while(idx <= n){
		BIT[idx][mod] += num;
		idx += lowbit(idx);
	}
	return;
}

inline ll query(int idx, int mod){
	ll re = 0;
	while(idx){
		re += BIT[idx][mod];
		idx -= lowbit(idx);
	}
	return re;
}

inline void modify(int idx, int pre, int nxt, int mod1, int mod2){
	for(int i = idx; i <= n; i += lowbit(i)){ // decrease
		BIT[i][mod1] -= pre;
	}
	for(int i = idx; i <= n; i += lowbit(i)){ // increase
		BIT[i][mod2] += nxt;
	}
	arr[idx] = nxt;
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int m, q;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> arr[i];
		update(i, arr[i], arr[i] % m);
	}
	cin >> q;
	char c;
	while(q--){
		cin >> c;
		if(c == 's'){
			int l, r, mod;
			cin >> l >> r >> mod;
			cout << query(r, mod) - query(l - 1, mod) << '\n';
		}
		else if(c == '+'){
			int p, r;
			cin >> p >> r;
			cout << arr[p] + r << '\n';
			modify(p, arr[p], arr[p] + r, arr[p] % m, (arr[p] + r) % m);
		}
		else if(c == '-'){
			int p, r;
			cin >> p >> r;
			if(arr[p] - r > 0){
				cout << arr[p] - r << '\n';
				modify(p, arr[p], arr[p] - r, arr[p] % m, (arr[p] - r) % m);
			}
			else cout << arr[p] << '\n';
		}
	}
	return 0;
}