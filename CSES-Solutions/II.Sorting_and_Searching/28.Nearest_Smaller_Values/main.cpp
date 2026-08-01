#include <iostream>
#include <stack>
using namespace std;

struct ot {
	long long value;
	int number;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	stack<ot> array;
	for (int l = 1; l <= n; l++) {
		long long x = 0;
		cin >> x;
		bool flag = false;
		while (!array.empty()) {
			if (array.top().value >= x) array.pop();
			else {
				cout << array.top().number << " ";
				array.push(ot(x, l));
				flag = true;
				break;
			}
		}
		if (!flag) {
			array.push(ot(x, l));
			cout << 0 << " ";
		}
	}


	return 0;
}