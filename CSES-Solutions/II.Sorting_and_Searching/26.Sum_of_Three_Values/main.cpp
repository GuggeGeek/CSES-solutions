#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ot {
	long long value;
	int number;

	bool operator<(const ot& other)const {
		return value < other.value;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	long long x = 0;
	cin >> n >> x;
	if (n == 1 || n == 2) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	vector<ot> array(n);
	for (int l = 0; l < n; l++) {
		long long r;
		cin >> r;
		array[l] = ot(r, l);
	}
	sort(array.begin(), array.end());
	for (int l = 0; l < n - 2; l++) {
		long long need = x - array[l].value;
		int left = l + 1, right = n - 1;
		while (left < right) {
			long long sum = array[left].value + array[right].value;
			if (sum > need) right--;
			else if (sum < need) left++;
			else {
				vector <int> ans;
				ans.push_back(array[l].number + 1);
				ans.push_back(array[left].number + 1);
				ans.push_back(array[right].number + 1);
				sort(ans.begin(), ans.end());
				for (auto const& now : ans) {
					cout << now << " ";
				}
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE";

	return 0;
}