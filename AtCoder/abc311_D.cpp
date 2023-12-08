#include <bits/stdc++.h>
using namespace std; // abc311_D - Grid Ice Floor

const int N = 205;

int ans;
bool grid[N][N], vis[N][N][4], counted[N][N];

const short dx[] = {-1, 0, 1, 0};
const short dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int dir){ // (x, y) & direction of movement
	ans += !counted[x][y];
	vis[x][y][dir] = true;
	counted[x][y] = true;
	int xi = x + dx[dir], yi = y + dy[dir]; // (nxtX, nxtY)
	if(!vis[xi][yi][dir] && grid[xi][yi]){
		dfs(xi, yi, dir);
	}
	else if(!grid[xi][yi]){
		for(int i = 0; i < 4; ++i){
			xi = x + dx[i], yi = y + dy[i];
			if(!vis[xi][yi][i] && grid[xi][yi]){
				dfs(xi, yi, i);
			}
		}
	}
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	char c;
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin >> c;
			grid[i][j] = (c == '.' ? 1 : 0); // 1: ice, 0: rock
		}
	}
	dfs(2, 2, 0);
	cout << ans << '\n';
	return 0;
}
