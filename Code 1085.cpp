//น้มุ 1085
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int x, y, w, h;
	int temp1, temp2;

	cin >> x >> y >> w >> h;
	temp1 << min(x, y);
	temp2 << min(w - x, h - y);
	cout << min(temp1, temp2);
	
}