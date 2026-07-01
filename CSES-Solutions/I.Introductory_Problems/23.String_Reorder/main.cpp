#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string s = "" , ans = "";
	int ch = 0, pro = -1;;
	vector <int> a(26);
	getline(cin, s);
	for (auto now : s) {
		a[int(now) - 'A']++;
		ch++;
	}

	for (auto now : a) {
		if ( now > (ch + 1)/2) {
			cout << -1;
			return 0;
		}
	}
	while (ch--) {
		bool ok = false;

		for (int l = 0; l < 26; l++) {
			if (a[l] != 0 && l != pro) {
				a[l]--;
				int rem = ch;
				int mx = 0;
				for (int k = 0; k < 26; k++) mx = max( mx , a[k]);

				if (mx <= (ch + 1) / 2) {
					ans += char( 'A' + l );
					pro = l;
					ok = true;
					break;
				}

				a[l]++;
			}
		}

		if (!ok) {
			cout << -1;
			return 0;
		}
	}

	for (auto now : ans) {
		cout << now;
	}
}