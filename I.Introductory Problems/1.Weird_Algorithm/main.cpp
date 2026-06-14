#include <iostream>

int main() {
	long long n = 0;
	std::cin >> n;
	while (true) {
		std::cout << n << " ";
		if (n == 1) break;
		if (n % 2 == 0) n = n / 2;
		else n = n * 3 + 1;
	}

	return 0;
}