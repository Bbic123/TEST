#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5, NN = 1e4 + 5;
bool q1[N];
int ans[N], qq[N], boss[NN];
pair<int, int> bri[N];

int query(int a){
	if(boss[a] != a) boss[a] = query(boss[a]);
	return boss[a];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, q;
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) cin >> bri[i].first >> bri[i].second;
	cin >> q;
	for(int i = 1; i <= q; ++i){
		cin >> qq[i];
		q1[qq[i]] = true;
	}
	int a, b;
	for(int i = 1; i <= n; ++i) boss[i] = i;
	for(int i = 1; i <= m; ++i){
		if(!q1[i]){
			a = query(bri[i].first), b = query(bri[i].second);
			if(a != b) boss[a] = b;
		}
		q1[i] = false;
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		a = query(i);
		if(!q1[a]) ++cnt;
		q1[a] = true;
	}
	ans[q] = cnt;
	for(int i = q - 1; i > 0; --i){
		a = query(bri[qq[i + 1]].first), b = query(bri[qq[i + 1]].second);
		if(a != b){
			boss[a] = b;
			--cnt;
		}
		ans[i] = cnt;
	}
	for(int i = 1; i <= q; ++i) cout << ans[i] << '\n';
	return 0;
}
// 所以，為什麼你們都喜歡撞來撞去的？