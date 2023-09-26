#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	int X;
	string Str;
	deque<int> dec;
	cin >> N;
	if (N < 1 || N > 10000)
	{
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> Str;
		if (Str == "push_front")
		{
			cin >> X;
			dec.push_front(X);
		}
		else if (Str == "push_back")
		{
			cin >> X;
			dec.push_back(X);
		}
		else if (Str == "pop_front")
		{
			if (dec.size() == 0)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << dec.front() << "\n";
				dec.pop_front();

			}
		}
		else if (Str == "pop_back")
		{
			if (dec.size() == 0)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << dec.back() << "\n";
				dec.pop_back();

			}
		}
		else if (Str == "size")
		{
			cout << dec.size() << "\n";
		}
		else if (Str == "empty")
		{
			if (dec.size() == 0)
			{
				cout << "1" << "\n";
			}
			else
			{
				cout << "0" << "\n";
			}
		}
		else if (Str == "front")
		{
			if (dec.size() == 0)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << dec.front() << "\n";

			}
		}
		else if (Str == "back")
		{
			if (dec.size() == 0)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << dec.back() << "\n";

			}
		}

	}
	return 0;
}