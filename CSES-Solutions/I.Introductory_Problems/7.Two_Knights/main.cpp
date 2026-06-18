#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;
	for ( ll l = 1; l <= n; l++ ) {
		cout << ( ( l*l  * (l*l - 1)) / 2 ) - ( 4*(l - 1)*(l - 2)) << "\n";
	}
	return 0;
}