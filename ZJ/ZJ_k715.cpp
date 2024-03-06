#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int boss[N];

struct Q{
	int a, b, c;
}edge[1000005];

bool operator < (Q x, Q y){
	return x.c < y.c;
}

inline int query(int x){
	if(boss[x] != x) boss[x] = query(boss[x]);
	return boss[x];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) boss[i] = i;
	{
		int i;
		while(k--){
			cin >> i;
			boss[i] = 0;
		}
	}
	for(int i = 0; i < m; ++i) cin >> edge[i].a >> edge[i].b >> edge[i].c;
	sort(edge, edge + m);
	int ans = 0;
	for(int i = 0; i < m; ++i){
		int x, y;
		x = query(edge[i].a), y = query(edge[i].b);
		if(x != y){
			ans += edge[i].c;
			boss[x] = y;
		}
	}
	cout << ans << '\n';
	return 0;
}
