#include <iostream>
#include <vector>
using namespace std;

int n = 0;
long long cnt = 0;
vector <bool> col;
vector <bool> diag1;
vector <bool> diag2 ;

void matrix(int y) {
	if ( y == n ) {
		cnt++;
		return;
	}
	for (int x = 0; x < n; x++) {
		if ( col[x] || diag1[ x+y ] || diag2[ x - y + n - 1]) continue;
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
		matrix(y + 1);
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	col.resize(n);
	diag1.resize(2 * n - 1);
	diag2.resize(2 * n - 1);
	matrix(0);
	cout << cnt;
	return 0;
}