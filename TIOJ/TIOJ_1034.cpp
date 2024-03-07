#include <bits/stdc++.h>
using namespace std;

const int Inf = 1e9;
int wei[405][405], num[25][25], ans[405][405];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, bu = 0, m;
	cin >> n;
	for(int i = 1; i <= n * n; ++i){
		for(int j = 1; j <= n * n; ++j){
			wei[i][j] = Inf;
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			num[i][j] = ++bu;
			cin >> wei[bu][bu];
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			wei[num[i][j]][num[i + 1][j]] = wei[num[i][j]][num[i][j]] + wei[num[i + 1][j]][num[i + 1][j]];
			wei[num[i][j]][num[i - 1][j]] = wei[num[i][j]][num[i][j]] + wei[num[i - 1][j]][num[i - 1][j]];
			wei[num[i][j]][num[i][j + 1]] = wei[num[i][j]][num[i][j]] + wei[num[i][j + 1]][num[i][j + 1]];
			wei[num[i][j]][num[i][j - 1]] = wei[num[i][j]][num[i][j]] + wei[num[i][j - 1]][num[i][j - 1]];
		}
	}
	for(int k = 1; k <= n * n; ++k){
		for(int i = 1; i <= n * n; ++i){
			for(int j = 1; j <= n * n; ++j){
				wei[i][j] = min(wei[i][j], wei[i][k] + wei[k][j] - wei[k][k]);
			}
		}
	}
	for(int i = 1; i <= n * n; ++i){
		for(int j = 1; j <= n * n; ++j){
			ans[i][j] = wei[i][j];
			for(int k = 1; k <= n * n; ++k){
				ans[i][j] = min(ans[i][j], wei[i][k] + wei[k][j] - wei[k][k] * 2);
			}
		}
	}
	int x, y, x1, y1;
	cin >> m;
	while(m--){
		cin >> x >> y >> x1 >> y1;
		cout << ans[num[x][y]][num[x1][y1]] << '\n';
	}
	return 0;
}
