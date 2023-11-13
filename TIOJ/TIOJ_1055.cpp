#include <iostream>
using namespace std;

int main(){
    int n, m, i, j;
    cin >> n >> m;
    if(n <= m){
        for(i = n; i <= m; ++i){
            for(j = 1; j <= i; ++j){
                cout << '*';
			}
            cout << '\n';
        }
    }
    else{
        for(i = n; i >= m; --i){
            for(j = 1; j <= i; ++j){
                cout << '*';
			}
            cout << '\n';
        }
    }
	return 0;
}