#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long cnt = 0;
int n = 8;
vector <bool> col(8);
vector <bool> diag1(15);
vector <bool> diag2(15);
map <pair<int , int>, int> isk;
void matrix( int y ) {
	if (y == n) {
		cnt++;
		return;
	}
	for (int x = 0; x < n; x++) {
		if (col[x] || diag1[x + y] || diag2[x - y + n - 1] || isk[{x, y}] == 1) continue;
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
		matrix(y + 1);
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			char sim;
			cin >> sim;
			if (sim == '*') isk[{x, y}] = 1;
		}
	}

	matrix(0);
	cout << cnt;

	return 0;
}