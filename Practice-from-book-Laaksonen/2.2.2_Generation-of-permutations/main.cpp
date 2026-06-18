#include <iostream>
#include <vector>
using namespace std;

int n = 0;
vector<int> permutation;
vector <bool> chosen;

void search() {
	if ( permutation.size() == n ) {
		for (auto now : permutation) {
			cout << now << " ";
		}
		cout << "\n";
	}
	else {
		for (int l = 1; l <= n; l++ ) {
			if ( chosen[l] ) continue;
			chosen[l] = true;
			permutation.push_back(l);
			search();
			chosen[l] = false;
			permutation.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	chosen.resize(n + 1);
	search();

	return 0;
}