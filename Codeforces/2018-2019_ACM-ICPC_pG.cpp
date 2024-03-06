#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
 
bool instk[N];
int low[N], dfn[N], t, scc[N], scc_num;
stack<int> sk;
vector<int> v[N];
 
inline void tarjan(int x){
	dfn[x] = low[x] = ++t;
	instk[x] = true;
	sk.push(x);
	for(int i : v[x]){
		if(instk[i] && dfn[i] < dfn[x]) low[x] = min(low[x], dfn[i]);
		else if(!dfn[i]){
			tarjan(i);
			low[x] = min(low[x], low[i]);
		}
	}
	if(dfn[x] == low[x]){
		++scc_num;
		int oao;
		while(!sk.empty()){
			oao = sk.top(), sk.pop();
			scc[oao] = scc_num;
			instk[oao] = false;
			if(oao == x) break;
		}
	}
	return;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		for(int i = 0, a, b; i < m; ++i){
			cin >> a >> b;
			v[a].push_back(b);
		}
		for(int i = 0; i < n; ++i) if(!dfn[i]) tarjan(i);
		cout << scc_num << '\n';
		{ // init
			for(int i = 0; i < n; ++i){
				v[i].clear();
				dfn[i] = low[i] = scc[i] = instk[i] = 0;
			}
			scc_num = t = 0;
			while(!sk.empty()) sk.pop();
		}
	}
	return 0;
}