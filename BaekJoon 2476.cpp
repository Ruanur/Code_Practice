#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin 가속화
	int N;
	cin >> N;

	vector<int> prices(N); //길이가 N인 prices 벡터 선언

	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		int dices[6 + 1] = { 0, };
		dices[a]++;
		dices[b]++;
		dices[c]++;

		int sum = 0;

		bool flag = (a != b) && (b != c) && (c != a);

		for (int dice = 6; dice >= 1; dice--)
		{
			if (dices[dice] == 3)
			{
				sum += (10000 + dice * 1000);

				break;
			}

			if (dices[dice] == 2)
			{
				sum += (1000 + dice * 100);

				break;
			}

			if (flag && dices[dice] == 1)
			{
				sum += (dice * 100);

				break;
			}
		}

		prices[i] = sum;
		prices[i] = sum;
	}

	sort(prices.begin(), prices.end());

	::cout << prices[N - 1] << "\n";

	return 0;
}