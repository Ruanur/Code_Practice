#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	string pokemon;
	string input;
	cin >> N >> M;
	map<string, int> list;
	map<int, string> list1;
	for (int i = 1; i <= N; i++)
	{
		cin >> pokemon;
		list.insert({ pokemon, i });
		list1.insert({ i, pokemon });

	}
	for (int i = 0; i < M; i++)
	{
		cin >> input;
		if (list.find(input) != list.end())
		{
			int number = list[input];
			cout << number << "\n";
		}
		else
		{
			int temp = stoi(input);
			if (list1.find(temp) != list1.end())
			{
				cout << list1[temp] << "\n";
			}
			else
			{
				return 0;
			}
		}
	}
}