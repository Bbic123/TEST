#include <iostream>
using namespace std;

int main(){
	char haha[6][6];
	for(int i = 0; i < 5; ++i)
		for(int j = 0; j < 5; ++j)
			cin >> haha[i][j];
	for(int j = 0; j < 5; ++j){
		for(int i = 0; i < 5; ++i)
			cout << haha[i][j];
		cout << '\n';
	}
	return 0;
}