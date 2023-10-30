#include<bits/stdc++.h>
using namespace std;

unsigned long long dp[95][20], ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	dp[1][0] = dp[1][1] = 1;
	for(int i = 2; i <= m; ++i){
		for(int j = 0; j <= n; ++j){
			dp[i][0] += dp[i - 1][j];
			if(j < n) dp[i][j + 1] += dp[i - 1][j];
		}
	}
	for(int i = 0; i <= n; ++i) ans += dp[m][i];
	cout << ans << '\n';
	return 0;
}
