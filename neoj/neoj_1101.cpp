#include <bits/stdc++.h>
using namespace std; // 1101. 哪裡有卦，哪裡就有源

const int N = 1e5 + 5;

bool vis[N];
int gen[N], ok;
vector<int> graph[N];

void dfs(int x){
	for(int i : graph[x]){
		if(!vis[i]){
			gen[i] = gen[x] ^ 1;
			vis[i] = 1;
			dfs(i);
		}
		else{
			if(gen[i] == gen[x]){
				ok = 0;
				return;
			}
		}
	}
	return;
}

void init(int n){
	for(int i = 0; i < n; ++i){
		vis[i] = gen[i] = 0;
		graph[i].clear();
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(; t--;){
		ok = 1;
		int n, m;
		cin >> n >> m;
		for(int i = 0, a, b; i < m; ++i){
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for(int i = 0; i < n; ++i){
			if(!vis[i]) dfs(i);
			if(!ok) break;
		}
		cout << (ok ? "NORMAL.\n" : "RAINBOW.\n");
		init(n);
	}
	return 0;
}