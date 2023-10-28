#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int T;
	int x1, y1, r1, x2, y2, r2;
	double d;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));


		if (d == 0) {
			if (abs(r1 - r2) == 0)
				cout << "-1" << '\n';
			//동심원이면서 반지름의 크기도 같음, 교점이 무한대
			else
				cout << "0" << '\n';
			//동심원, 교점이 없음
		}
		else if (d == abs(r1 - r2) || d == r1 + r2)
		{
			cout << "1" << '\n';
			//외접하거나 내접한다. 교점 하나
		}
		else if (abs(r1 - r2) < d && d < r1 + r2)
		{
			cout << "2" << '\n';
			//두 원이 두 교점을 이루며 만난다. 교점 둘
		}
		else
		{
			cout << "0" << '\n';
			//이 외에는 만나지 않는 원으로 간주함
		}
	}
}