#include <bits/stdc++.h>
using namespace std; // 49. It's my ____ in the box

const int N = 1e5 + 5;

int ans[N];
vector<int> v[N];

void dfs(int q){
	for(int i : v[q]){
		if(!ans[i]) dfs(i);
		ans[q] += ans[i];
	}
	++ans[q];
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(; t--;){
		int n, m;
		cin >> n >> m;
		int x, y;
		for(int i = 0; i < m; ++i){
			cin >> x >> y;
			v[x].push_back(y);
		}
		for(int i = 1; i <= n; ++i)
			if(!ans[i]) dfs(i);
		int q;
		cin >> q;
		for(; q--;){
			cin >> m;
			cout << ans[m] << '\n';
		}
		for(int i = 1; i <= n; ++i){
			v[i].clear();
			ans[i] = 0;
		}
	}
	return 0;
}