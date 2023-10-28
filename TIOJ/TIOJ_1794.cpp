#include<bits/stdc++.h>
using namespace std;

const int N = 3e3 + 5;
const short dxy[] = {0, 1, 0, -1, 0};

bool vis[N][N];
int arr[N][N], n, m, ans;

void bfs(int x, int y){
	int xi, yi, cnt = 1;
	vis[x][y] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; ++i){
			xi = x + dxy[i];
			yi = y + dxy[i + 1];
			if(xi > 0 && xi <= n && yi > 0 && yi <= m && arr[xi][yi] == arr[x][y] && !vis[xi][yi]){
				vis[xi][yi] = true;
				++cnt;
				q.push(make_pair(xi, yi));
			}
		}
	}
	ans = max(ans, cnt);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> arr[i][j];
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(!vis[i][j]) bfs(i, j);
		}
	}
	cout << ans << '\n';
	return 0;
}
