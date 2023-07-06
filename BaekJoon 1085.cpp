#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x, y, w, h;
	int temp1, temp2, result;
	cin >> x >> y >> w >> h;

	temp1 = w - x;
	temp2 = h - y;
	result = x;
	if (temp1 < result)
	{
		result = temp1;
	}
	if (y < result)
	{
		result = y;
	}
	if (temp2 < result)
	{
		result = temp2;
	}
	cout << result;
}

