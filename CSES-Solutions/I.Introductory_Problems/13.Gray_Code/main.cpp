#include <iostream>
#include <vector>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector <string> ans = {"0","1"};
	int n = 0;
	cin >> n;
	for (int l = 1; l < n; l++) {
		vector <string> pob1, pob2;
		for ( auto &now : ans ) {
			pob1.push_back("0" + now);
		}
		for (auto now = ans.rbegin(); now != ans.rend(); now++) {
			pob2.push_back("1" + *now);
		}
		ans = move(pob1);
		ans.insert(ans.end(), pob2.begin(), pob2.end());
	}

	for (auto const&now : ans) {
		cout << now << "\n";
	}
	return 0;
}