#include <iostream>
#include <queue>
using namespace std; // 44. 喵喵抓老鼠

int picture[105][105], visTime[105][105];

struct pii{
	int X, Y;
};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

inline void bfs(int kx, int ky){
	queue<pii> q;
	q.push({kx, ky});
	visTime[kx][ky] = 1;
	for(; !q.empty();){
		kx = q.front().X;
		ky = q.front().Y;
		q.pop();
		for(int i = 0; i < 4; ++i){
			int xi = kx + dx[i];
			int yi = ky + dy[i];
			if(picture[xi][yi] == 1 && !visTime[xi][yi]){
				visTime[xi][yi] = visTime[kx][ky] + 1;
				q.push({xi, yi});
			}
			else if(picture[xi][yi] == 2){
				printf("%d\n", visTime[kx][ky]);
				return;
			}
		}
	}
	printf("= =\"\n");
	return;
}

inline void init(int n, int m){
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			visTime[i][j] = picture[i][j] = 0;
	return;
}

int main(){
	int t, n, m, kx, ky;
	char c;
	scanf("%d", &t);
	for(; t--;){
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; ++i){
			getchar();
			for(int j = 1; j <= m; ++j){
				c = getchar();
				if(c == '#') picture[i][j] = 0;
				else if(c == '.') picture[i][j] = 1;
				else if(c == '@')  picture[i][j] = 2;
				else if(c == 'K'){
					kx = i;
					ky = j;
				}
			}
		}
		bfs(kx, ky);
		init(n, m);
	}
	return 0;
}