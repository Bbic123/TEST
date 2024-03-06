#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, L = 15;
int in[N], out[N], ac[N][L + 5], T, deep[N];
string s1, s2;
vector<int> edge[N];

inline void dfs(int x, int pa){
	deep[x] = deep[pa] + 1;
	in[x] = ++T;
	ac[x][0] = pa;
	for(int i = 1; i <= L; ++i) ac[x][i] = ac[ac[x][i - 1]][i - 1];
	for(int i : edge[x]){
		if(i != pa) dfs(i, x);
	}
	out[x] = ++T;
	return;
}

inline bool is_ac(int a, int b){
	return in[a] <= in[b] && out[a] >= out[b];
}

inline int LCA(int a, int b){
	if(is_ac(a, b)) return a;
	if(is_ac(b, a)) return b;
	for(int i = L; i >= 0; --i)
		if(!is_ac(ac[a][i], b)) a = ac[a][i];
	return ac[a][0];
}

inline int ANS(int a, int h){
	int QQ = 0;
	for(; h; ++QQ, h >>= 1){
		if(h & 1) a = ac[a][QQ];
	}
	return a;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	int n, q, a, b, lca, len, k, an1, an2;
	while(t--){
		cin >> n >> q;
		for(int i = 1; i < n; ++i){
			cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		dfs(0, 0);
		for(int i = 0; i < q; ++i){
			cin >> s1 >> a >> s2 >> b;
			lca = LCA(a, b);
			len = deep[a] + deep[b] - (deep[lca] << 1);
			cout << s1 << " and " << s2 << ": ";
			if(len & 1){
				k = (len >> 1);
				if(k == deep[a] - deep[lca]){
					an1 = lca;
				}
				else if(k < deep[a] - deep[lca]){
					an1 = ANS(a, k);
				}
				else if(k > deep[a] - deep[lca]){
					an1 = ANS(b, deep[a] + deep[b] - deep[lca] * 2 - k);
				}
				++k;
				if(k == deep[a] - deep[lca]){
					an2 = lca;
				}
				else if(k < deep[a] - deep[lca]){
					an2 = ANS(a, k);
				}
				else if(k > deep[a] - deep[lca]){
					an2 = ANS(b, deep[a] + deep[b] - deep[lca] * 2 - k);
				}
				if(an1 > an2) swap(an1, an2);
				cout << an1 << ' ' << an2 << '\n';
			}
			else{
				k = len >> 1;
				if(k == deep[a] - deep[lca]){
					cout << lca << '\n';
				}
				else if(k < deep[a] - deep[lca]){
					cout << ANS(a, k) << '\n';
				}
				else if(k > deep[a] - deep[lca]){
					cout << ANS(b, deep[a] + deep[b] - deep[lca] * 2 - k) << '\n';
				}
			}
			edge[i].clear();
		}
		for(int i = q; i < n; ++i) edge[i].clear();
		deep[0] = T = 0;
	}
	return 0;
}