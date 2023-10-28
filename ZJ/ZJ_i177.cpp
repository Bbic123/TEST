#include<bits/stdc++.h>
using namespace std;

const short dxy[] = {0, 1, 0, -1, 0};
bool vis[505][505];
int p[505][505], h, w;

void bfs(int xx, int yy, int z){
	int xi, yi, x, y;
	vis[xx][yy] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(xx, yy));
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; ++i){
			xi = x + dxy[i];
			yi = y + dxy[i + 1];
			if(xi > 0 && yi > 0 && xi <= h && yi <= w && p[xi][yi] == p[x][y] && !vis[xi][yi]){
				q.push(make_pair(xi, yi));
				vis[xi][yi] = true;
			}
		}
		p[x][y] = z;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int si ,sj, z;
	cin >> h >> w >> si >> sj >> z;
	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <= w; ++j){
			cin >> p[i][j];
		}
	}
	bfs(si, sj, z);
	for(int i = 1; i <= h; ++i){
		for(int j = 1; j <= w; ++j){
			cout << " "[j == 1] << p[i][j];
		}
		cout << '\n';
	}
	return 0;
}
