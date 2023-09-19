#include<bits/stdc++.h>
using namespace std;

int nn[505][505];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, num, x1, y1, x2, y2;
    while(cin >> n >> m){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; j++){
                cin >> num;
                nn[i][j] = nn[i - 1][j] + nn[i][j - 1] + num - nn[i - 1][j - 1];
            }
        }
        while(m--){
            cin >> x1 >> y1 >> x2 >> y2;
            cout << nn[x2][y2] - nn[x2][y1 - 1] - nn[x1 - 1][y2] + nn[x1 - 1][y1 - 1] << '\n';
        }
    }
}
