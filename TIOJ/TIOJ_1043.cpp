#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e4 + 5;
ll dp[N] = {1};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, p, num;
	while(cin >> n >> p, n + p){
		for(int i = 0; i < n; ++i){
			cin >> num;
			for(int i = num; i <= p; ++i) dp[i] += dp[i - num];
		}
		cout << dp[p] << '\n';
		for(int i = 1; i <= p; ++i) dp[i] = 0;
	}
	return 0;
}
