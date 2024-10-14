#include <iostream>
#include <algorithm>
#include <deque>
#include <string>

using namespace std;

int T;
string p;
int n;
bool isError = false;
deque<int> arr; //동적 배열 할당


void R(deque<int>& arr) //배열 뒤집기
{
	if (!arr.empty())
	{
		reverse(arr.begin(), arr.end());
	}
}

void D(deque<int>& arr) //첫 번째 배열 지우기
{
	if (!arr.empty())
	{
		arr.pop_front();
	}
	else
	{
		cout << "error" << '\n';
		isError = true;
		return;
	}
}

void result(deque<int>& arr)
{
	if (!isError)
	{
		cout << '[';
		while (!arr.empty())
		{
			cout << arr.front();
			arr.pop_front();
			if (!arr.empty())
			{
				cout << ',';
			}
		}
		cout << ']';
	}
	arr.clear();
	isError = false;
}

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> p >> n;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			arr.push_back(a);
		}

		for (char command : p)
		{
			if (command == 'R')
			{
				R(arr);
			}
			else if (command == 'D')
			{
				D(arr);
			}
			else
			{
				cout << "잘못된 명령어" << '\n';
				break;
			}
		}
		result(arr);
	}

	return 0;
}
