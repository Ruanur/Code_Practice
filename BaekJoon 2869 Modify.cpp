#include <iostream>
using namespace std;

int main()
{
	int A, B, V;
	cin >> A >> B >> V;
	int count = 1;

	count += (V - A) / (A - B);
	//EX. Day = 2 ,Night = 1, Length = 5
	//(5-2) / (2-1) + 1 = "4" >> Count.
	if (A >= V)
	{
		cout << "1";
	}
	if ((V - A) % (A - B) != 0)
	{
		count++;
	}
	//Ex. Day = 5, Night = 1, Length = 6
	//1/4 + 1 = 1(False), if.
	cout << count;
}