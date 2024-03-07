#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> v[N];
int in[N], out[N], t, BIT[N], n;

inline void dfs(int x){
	in[x] = ++t;
	for(int i : v[x]) dfs(i);
	out[x] = t;
	return;
}

#define lowbit(x) ((x) & (-x))

inline void update(int idx){
	while(idx <= n){
		BIT[idx] ^= 1;
		idx += lowbit(idx);
	}
	return;
}

inline int query(int idx){
	int re = 0;
	while(idx){
		re ^= BIT[idx];
		idx -= lowbit(idx);
	}
	return re;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m;
	cin >> n >> m;
	for(int i = 1, a, b; i <= n; ++i){
		cin >> b;
		for(int j = 0; j < b; ++j){
			cin >> a;
			v[i].push_back(a);
		}
	}
	dfs(1);
	int b;
	bool a;
	while(m--){
		cin >> a >> b;
		if(a){
			cout << query(in[b]) << '\n';
		}
		else{
			update(in[b]);
			update(out[b] + 1);
		}
	}
	return 0;
}
