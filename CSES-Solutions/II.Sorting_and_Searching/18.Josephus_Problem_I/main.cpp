#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	queue <int> q;
	for (int l = 1; l <= n; l++) {
		q.push(l);
	}
	while (!(q.empty())) {
		q.push(q.front());
		q.pop();
		cout << q.front() << " ";
		q.pop();
	}

	return 0;
}