#include <iostream>
using namespace std;

int main(){
	int n;
	int arr[25][25];
	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i < n; i += 2){
		for(int j = 0; j < n; j += 2){
			cout << max(arr[i][j], max(arr[i][j + 1], max(arr[i + 1][j], arr[i + 1][j + 1]))) << ' ';
		}
		cout << '\n';
	}
	return 0;
}