#include <iostream>
using namespace std;

int main(){
    int n, i, j, j1;
    cin >> n;
    for(i = 1, j1 = 1; i <= n; ++i, j1 += 2){
		for(j = n - i; j > 0; --j){
			cout << "_";
		}
		for(j = 1; j <= j1; ++j){
			cout << "*";
		}
		for(j = n - i; j > 0; --j){
			cout << "_";
		}
		cout << "\n";
	}
}