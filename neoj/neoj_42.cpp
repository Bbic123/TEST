#include <bits/stdc++.h>
using namespace std; // 42. 庭院裡的水池

bool gra[1005][1005];
bool vis[1005][1005];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

struct pii{
	int X, Y;
};

void bfs(int x, int y){
	vis[x][y] = 1;
	queue<pii> q;
	q.push({x, y});
	for(; !q.empty();){
		x = q.front().X;
		y = q.front().Y;
		q.pop();
		for(int i = 0; i < 4; ++i){
			int xi = x + dx[i];
			int yi = y + dy[i];
			if(!vis[xi][yi] && gra[xi][yi]){
				q.push({xi, yi});
				vis[xi][yi] = 1;
			}
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char c;
	int t, h, w, ans;
	cin >> t;
	for(; t--;){
		cin >> h >> w;
		for(int i = 1; i <= h; ++i){
			for(int j = 1; j <= w; ++j){
				cin >> c;
				if(c == '.') gra[i][j] = 1;
			}
		}
		ans = 0;
		for(int i = 1; i <= h; ++i){
			for(int j = 1; j <= w; ++j){
				if(!vis[i][j] && gra[i][j]){
					++ans;
					bfs(i, j);
				}
				vis[i][j] = gra[i][j] = 0;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}