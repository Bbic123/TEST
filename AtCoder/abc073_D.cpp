#include <bits/stdc++.h>
using namespace std; // abc073_D - joisino's travel

const long long Inf = 1e18;
int r[15];
long long dp[205][205];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, R, a, b, c;
	long long ans = Inf, check;
	cin >> n >> m >> R;
	for(int i = 0; i < R; ++i) cin >> r[i];
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			dp[i][j] = Inf;
			dp[i][i] = dp[j][j] = 0;
		}
	}
	for(int i = 0; i < m; ++i){
		cin >> a >> b >> c;
		dp[a][b] = dp[b][a] = c;
	}
	for(int k = 1; k <= n; ++k){
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= n; ++j){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	sort(r, r + R);
	do{
		check = 0;
		for(int i = 1; i < R; ++i) check += dp[r[i - 1]][r[i]];
		ans = min(ans, check);
	}while(next_permutation(r, r + R));
	cout << ans << '\n';
	return 0;
}