#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0 , m = 0;
	cin >> n >> m;
	vector <vector<char>> a( n , vector<char>( m ) );
	
	for (int l = 0; l < n; l++) {
		for( int j = 0; j < m; j++){
			char ch;
			cin >> ch;
			if ((l + j) % 2 == 0) {
				if (ch == 'A') a[l][j] = 'C';
				else a[l][j] = 'A';
			}
			else {
				if (ch == 'B') a[l][j] = 'D';
				else a[l][j] = 'B';
			}
		}
	}

	for (int l = 0; l < n; l++) {
		for (int j = 0; j < m; j++) {
			cout << a[l][j];
		}
		cout << "\n";
	}
	return 0;
}