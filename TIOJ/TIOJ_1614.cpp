#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int a[N], b[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, ans = 0;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < m; ++i) cin >> b[i];
	sort(b, b + m);
	for(int i = 0; i < n; ++i){
		int *it = lower_bound(b, b + m, a[i]);
		if(*it == a[i]) continue;
		else if((it - b) & 1) continue;
		++ans;
	}
	cout << ans << '\n';
	return 0;
}
