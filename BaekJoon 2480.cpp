#include <iostream>
using namespace std;

int main(int argc, char const* argv[]) {

	int a, b, c;
	cin >> a >> b >> c;
	// ���� ��� ������ �ٸ� ���
	if (a != b && b != c && a != c) {
		int max;
		// ���� a > b ���
		if (a > b) {
			// c > a > b ���
			if (c > a) {
				max = c;
			}
			// a > (b, c)
			else {
				max = a;
			}
		}
		// b > a ���
		else {
			// c > b > a ���
			if (c > b) {
				max = c;
			}
			// b > (a, c)
			else {
				max = b;
			}
		}
		cout << max * 100;
	}
	// ��� �� �� �̻��� ���� ���� ������ ������ ���
	else {
		// 3���� ������ ��� ���� ���
		if (a == b && a == c) {
			cout << 10000 + a * 1000;
		}
		else {
			// a�� bȤ�� c���� ���� ���
			if (a == b || a == c) {
				cout << 1000 + a * 100;
			}
			// b�� c�� ���� ���
			else {
				cout << 1000 + b * 100;
			}
		}
	}
	return 0;
}