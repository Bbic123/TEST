#include <bits/stdc++.h>
using namespace std; // 293. 樹重心

const int N = 1e5 + 5;
vector<int> vix[N];

int mx_sub[N], n;

int dfs(int x, int pre){
	int nodes = 0;
	for(int i : vix[x]){
		int sub;
		if(i != pre){
			sub = dfs(i, x);
			mx_sub[x] = max(sub, mx_sub[x]);
			nodes += sub;
		}
	}
	mx_sub[x] = max(mx_sub[x], n - nodes - 1);
	return nodes + 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(; t--;){
		cin >> n;
		for(int i = 1, a, b; i < n; ++i){
			cin >> a >> b;
			vix[a].push_back(b);
			vix[b].push_back(a);
		}
		dfs(0, 0);
		int ans = 1111111, ansp = 2e5;
		for(int i = 0; i < n; ++i){
			if(mx_sub[i] < ans){
				ans = mx_sub[i];
				ansp = i;
			}
			mx_sub[i] = 0;
			vix[i].clear();
		}
		cout << ansp << '\n';
	}
	return 0;
}
