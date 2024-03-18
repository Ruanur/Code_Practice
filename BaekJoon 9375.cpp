#include <iostream>
#include <map>
#include <string>

using namespace std; 

int main()
{
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> M;
		map<string, int> list;
		for (int j = 0; j < M; j++)
		{
			string dress, wear;
			cin >> dress >> wear;
			if (list.find(wear) == list.end())
			//list에 wear 카테고리가 존재하지 않을 때.
			{
				list.insert({ wear, 1 });
				// {Headgear 1}, 후에 중복 시 int 값 ++
			}
			else
			{
				list[wear]++;
				//해당 카테고리 속성 값 증가
			}
		}
		int result = 1;
		for (const auto& i : list)
		{
			result = result * (i.second + 1);
		}
		result = result - 1;
		cout << result << "\n";
	} 
	return 0;
}