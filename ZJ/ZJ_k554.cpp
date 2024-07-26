#include <iostream>
using namespace std;

int main(){
	int ans[105][105] = {};
	int n, m, now;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> now;
			if(now == 1){
				++ans[i][j];
				++ans[i + 1][j];
				++ans[i - 1][j];
				++ans[i][j + 1];
				++ans[i][j - 1];
			}
			else if(now == 2){
				for(int k = 1; k <= n; ++k) ++ans[k][j];
				for(int k = 1; k <= m; ++k) ++ans[i][k];
				--ans[i][j];
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(j != 1) cout << ' ';
			cout << ans[i][j];
		}
		cout << '\n';
	}
	return 0;
}