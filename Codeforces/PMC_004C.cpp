#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

bool vis[N];
int in[N], out[N], t;
vector<int> vir[N];

void dfs(int x, int pa){
	vis[x] = true;
	in[x] = ++t;
	for(int i : vir[x])
		if(i != pa && i != x) dfs(i, x);
	out[x] = ++t;
}

bool is_ac(int a, int b){
	return in[a] <= in[b] && out[a] >= out[b];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1, a; i <= n; ++i){
		cin >> a;
		vir[a].push_back(i);
	}
	for(int i = 1; i <= n; ++i){
		if(!vis[i]) dfs(i, i);
	}
	int q, x, y, z;
	cin >> q;
	while(q--){
		cin >> x >> y >> z;
		cout << (is_ac(z, x) && is_ac(z, y) ? "Yes\n" : "No\n");
	}
	return 0;
}