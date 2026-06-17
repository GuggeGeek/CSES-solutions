#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;
	vi early;
	vi late;
	long long S = n*(n+1)/2;
	long long T;
	int vie = 0, vil = 0;

	if (S % 2 == 0) {
		T = S / 2;
		cout << "YES" << "\n";
	}
	else {
		cout << "NO";
		return 0;
	}
	long long sum = 0;
	for (int l = n; l > 0; l-- ) {
		
		if (sum + l <= T ) {
			early.push_back(l);
			vie++;
			sum += l;
		}
		else {
			late.push_back(l);
			vil++;
		}
	}
	cout << vie << "\n";
	for (auto now : early) {
		cout << now << " ";
	}
	cout << "\n" << vil << "\n";
	for (auto now : late) {
		cout << now << " ";
	}

	return 0;
}