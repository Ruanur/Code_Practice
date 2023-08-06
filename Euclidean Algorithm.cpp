#include <iostream>
using namespace std;
//유클리드의 호제법

int gcd(int a, int b)
{

	int n = a % b;
	while (n != 0)
	{
		a = b;
		b = n;
		n = a % b;
	}
	return b;
}

int lcd(int a, int b)
{
	return (a * b) / gcd(a, b);
}

int main()
{
	int num1, num2;
	cin >> num1 >> num2;
	cout << gcd(num1, num2) << endl << lcd(num1, num2);
}