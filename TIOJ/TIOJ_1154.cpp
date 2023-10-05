#include<bits/stdc++.h>
using namespace std;

bool f = false;
string bk[150];

void haha(int x, int y, int len){
    if(f) cout << ' ';
    int cntB = 0, cntW = 0;
    for(int i = 0; i < len; ++i){
        for(int j = 0; j < len; ++j){
            ++(bk[x + i][y + j] - '0' ? cntB : cntW);
        }
    }
    f = true;
    if(cntB == len * len) cout << 'b';
    else if(cntW == len * len) cout << 'w';
    else{
        cout << 'g';
        haha(x, y + (len >> 1), (len >> 1));
        haha(x, y, (len >> 1));
        haha(x + (len >> 1), y, (len >> 1));
        haha(x + (len >> 1), y + (len >> 1), (len >> 1));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> bk[i];
    haha(0, 0, n);
    return 0;
}