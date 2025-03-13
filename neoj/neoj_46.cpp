#include <bits/stdc++.h>
using namespace std; // 46. 染色遊戲

int mx_r, mx_y, mx_b, mx_o, mx_g, mx_p, mx_d;
int rx1, rx2, ry1, ry2;
int yx1, yx2, yy1, yy2;
int bx1, bx2, by1, by2;
int n;

void next_second(){
	if(rx1) --rx1;
	if(ry1) --ry1;
	if(rx2 < n) ++rx2;
	if(ry2 < n) ++ry2;
	
	if(yx1) --yx1;
	if(yy1) --yy1;
	if(yx2 < n) ++yx2;
	if(yy2 < n) ++yy2;

	if(bx1) --bx1;
	if(by1) --by1;
	if(bx2 < n) ++bx2;
	if(by2 < n) ++by2;
}

void check_max(){
	int r = (rx2 - rx1 + 1) * (ry2 - ry1 + 1);
	int y = (yx2 - yx1 + 1) * (yy2 - yy1 + 1);
	int b = (bx2 - bx1 + 1) * (by2 - by1 + 1);
	int ox1, oy1, ox2, oy2, o = 0; // RY
	int gx1, gx2, gy1, gy2, g = 0; // YB
	int px1, px2, py1, py2, p = 0; // RB

	int dx1, dx2, dy1, dy2, d = 0; // RYB
	
	ox1 = max(yx1, rx1);
	ox2 = min(yx2, rx2);
	oy1 = max(yy1, ry1);
	oy2 = min(yy2, ry2);
	if(ox1 <= ox2 && oy1 <= oy2)
		o = (ox2 - ox1 + 1) * (oy2 - oy1 + 1);

	gx1 = max(yx1, bx1);
	gx2 = min(yx2, bx2);
	gy1 = max(yy1, by1);
	gy2 = min(yy2, by2);
	if(gx1 <= gx2 && gy1 <= gy2)
		g = (gx2 - gx1 + 1) * (gy2 - gy1 + 1);

	px1 = max(bx1, rx1);
	px2 = min(bx2, rx2);
	py1 = max(by1, ry1);
	py2 = min(by2, ry2);
	if(px1<=px2 && py1<=py2)
		p = (px2 - px1 + 1) * (py2 - py1 + 1);

	dx1 = max(bx1, max(rx1, yx1));
	dx2 = min(bx2, min(rx2, yx2));
	dy1 = max(by1, max(ry1, yy1));
	dy2 = min(by2, min(ry2, yy2));
	if(dx1 <= dx2 && dy1 <= dy2)
		d = (dx2 - dx1 + 1) * (dy2 - dy1 + 1);

	mx_r = max(mx_r, r - p - o + d);
	mx_y = max(mx_y, y - g - o + d);
	mx_b = max(mx_b, b - p - g + d);
	mx_o = max(mx_o, o - d);
	mx_g = max(mx_g, g - d);
	mx_p = max(mx_p, p - d);
}

int main(){
	char c;
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		mx_o = mx_g = mx_p = 0;
		mx_r = mx_b = mx_y = 0;
		mx_d = n * n;
		--n;
		for(int i = 0; i < 3; i++){
			scanf("%c", &c);
			scanf("%c", &c);
			// cin >> c;
			if(c == 'R'){
				scanf("%d%d", &rx1, &ry1);
				rx2 = rx1;
				ry2 = ry1;
			}
			else if(c == 'Y'){
				scanf("%d%d", &yx1, &yy1);
				yx2 = yx1;
				yy2 = yy1;
			}
			else if(c == 'B'){
				scanf("%d%d", &bx1, &by1);
				bx2 = bx1;
				by2 = by1;
			}
		}
		scanf("%c", &c);
		scanf("%c", &c);
		check_max();
		while(
		  (rx1 || rx2 < n || ry1 || ry2 < n) || 
		  (yx1 || yx2 < n || yy1 || yy2 < n) || 
		  (bx1 || bx2 < n || by1 || by2 < n)){
			next_second();
			check_max();
		}

		if(c == 'R') printf("%d", mx_r);
		else if(c == 'Y') printf("%d", mx_y);
		else if(c == 'B') printf("%d", mx_b);
		else if(c == 'O') printf("%d", mx_o);
		else if(c == 'G') printf("%d", mx_g);
		else if(c == 'P') printf("%d", mx_p);
		else if(c == 'D') printf("%d", mx_d);
		putchar('\n');
	}
	return 0;
}