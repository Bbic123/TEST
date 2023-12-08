#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int t, L;
int deep[N], in[N], out[N], ac[25][N];
vector<int> eg[N];

void dfs(int x, int pa){
	deep[x] = deep[pa] + 1;
	in[x] = ++t;
	ac[0][x] = pa;
	for(int i = 1; i <= L; ++i) ac[i][x] = ac[i - 1][ac[i - 1][x]];
	for(int i : eg[x]) if(i != pa) dfs(i, x);
	out[x] = ++t;
}

bool is_ac(int a, int b){
	return in[a] <= in[b] && out[b] <= out[a];
}

int LCA(int a, int b){
	if(is_ac(a, b)) return a;
	if(is_ac(b, a)) return b;
	for(int i = L; i >= 0; --i)
		if(!is_ac(ac[i][a], b)) a = ac[i][a];
	return ac[0][a];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, a, b;
	cin >> n >> m;
	L = ceil(log10(n) / log10(2));
	for(int i = 1; i < n; ++i){
		cin >> a >> b;
		eg[a].push_back(b);
		eg[b].push_back(a);
	}
	dfs(0, 0);
	while(m--){
		cin >> a >> b;
		cout << deep[a] + deep[b] - deep[LCA(a, b)] * 2 << '\n';
	}
    return 0;
}