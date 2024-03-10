
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string S;
	int cnt = 0;
	//그룹 단어가 아닌 조건.
	//1. 현재 단어가 이전에 쓰이지 않음
	//2. '1번 조건'에 부합하고 현재 단어가 이전에 쓰인 적이 있음.
	for(int i = 0; i < N; i++)
	{
		cin >> S;
		int l = S.length();
		bool check = true;
		for (int j = 0; j < l; j++)
		{
			for (int k = 0; k < j; k++)
			{
				if (S[j] != S[j - 1] && S[j] == S[k])
				{
					check = false;
					break;
				}
			}
		}
		if (check)
		{
			cnt++;
		}
	}
	cout << cnt << endl;
}


