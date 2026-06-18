#include <iostream>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 0;
	cin >> t;
	for (int l = 0; l < t ; l++) {
		long long x = 0, y = 0;
		cin >> y >> x;
		long long maximum = max(x, y);
		long long maxABS = maximum * maximum;
		long long minABS = (maximum - 1) * (maximum - 1);
		if (y == maximum ) {
			if (y % 2 == 0 ) {
				cout << maxABS - x + 1 << "\n";
			}
			else {
				cout << minABS + x << "\n";
			}
		}
		else if (x == maximum) {
			if (x % 2 == 0) {
				cout << minABS + y << "\n";
			}
			else {
				cout << maxABS - y + 1 << "\n";
			}
		} 
	}
	return 0;
}