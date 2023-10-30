#include<bits/stdc++.h>
using namespace std;

unsigned long long dp[105];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	dp[1] = dp[0] = 1;
	for(int i = 2; i < 100; ++i) dp[i] = dp[i - 1] + dp[i - 2];
	while(cin >> n) cout << dp[n] <<'\n';
	return 0;
}
