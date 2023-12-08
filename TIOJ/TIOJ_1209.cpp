#include <bits/stdc++.h>
using namespace std;

const int N = 4e4 + 5;

vector<int> ver[N];
short color[N];
bool ok;

void dfs(int x){
	for(int i : ver[x]){
		if(color[i] == -1){
			color[i] = color[x] ^ 1;
			dfs(i);
		}
		else if(color[i] == color[x]){
			ok = false;
			return;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	while(cin >> n >> m, n){
		for(int i = 1; i <= n; ++i){
			ver[i].clear();
			color[i] = -1;
		}
		for(int i = 0, a, b; i < m; ++i){
			cin >> a >> b;
			ver[a].push_back(b);
			ver[b].push_back(a);
		}
		ok = true;
		color[1] = 0;
		dfs(1);
		cout << (ok ? "Yes\n" : "No\n");
	}
	return 0;
}
