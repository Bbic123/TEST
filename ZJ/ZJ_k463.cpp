#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> ver[N];
short color[N];
int cnt[2], ans;
bool ok = true;

void dfs(int x){
	for(int i : ver[x]){
		if(color[i] == -1){
			color[i] = color[x] ^ 1;
			++cnt[color[i]];
			dfs(i);
		}
		else if(color[i] == color[x]){
			ok = false;
			return;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0, a, b; i < m; ++i){
		cin >> a >> b;
		ver[a].push_back(b);
		ver[b].push_back(a);
	}
	fill(color + 1, color + 1 + n, -1);
	for(int i = 1; i <= n && ok; ++i){
		if(color[i] == -1){
			++cnt[0];
			color[i] = 0;
			dfs(i);
			ans += max(cnt[0], cnt[1]);
			cnt[0] = cnt[1] = 0;
		}
	}
	cout << (ok ? ans : 0) << '\n';
	return 0;
}
