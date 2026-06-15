#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	if (n == 3 || n == 2) {
		cout << "NO SOLUTION";
		return 0;
	}
	vector <int> R , NR ;
	for (int l = 0; l < n; l++) {
		if ( (l + 1) % 2 == 0) R.push_back(l + 1);
		else NR.push_back(l + 1);
	}

	sort(R.begin() , R.end());
	sort(NR.begin(), NR.end());
	for (auto now : R) {
		cout << now << " ";
	}
	for (auto now : NR) {
		cout << now << " ";
	}
	return 0;
}