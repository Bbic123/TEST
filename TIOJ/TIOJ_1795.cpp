#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int boss[N];
struct xyc{
	int x, y, c;
};
vector<xyc> eg;

bool operator < (xyc a, xyc b){
	return a.c < b.c;
}

int query(int a){
	if(a != boss[a]) boss[a] = query(boss[a]);
	return boss[a];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k, mx = 0, mn = 0, a, b, c;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) boss[i] = i;
	for(int i = 0; i < m; ++i){
		cin >> a >> b >> c;
		eg.push_back({a, b, c});
	}
	sort(eg.begin(), eg.end());
	for(int i = 0; i < m; ++i){
		a = query(eg[i].x), b = query(eg[i].y);
		if(a != b){
			boss[a] = b;
			mn += eg[i].c;
		}
	}
	for(int i = 1; i <= n; ++i) boss[i] = i;
	for(int i = m - 1; i >= 0; --i){
		a = query(eg[i].x), b = query(eg[i].y);
		if(a != b){
			boss[a] = b;
			mx += eg[i].c;
		}
	}
	if(k <= mx && k >= mn) cout << "TAK\n";
	else cout << "NIE\n";
	return 0;
}
// 咕嚕咕嚕呱啦呱啦