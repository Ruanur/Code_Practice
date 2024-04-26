#include <iostream>
#include <vector>

using namespace std;

int distance(string a, string b)
{
	int dist = 0;
	for (int i = 0; i < 4; i++)
	{
		if (a[i] != b[i])
		{
			dist += 1;
		}
	}
	return dist;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) 
	{
		vector<string> arr;
		int N;
		cin >> N;
		for (int j = 0; j < N; j++) 
		{ //MBTI를 입력 받는다.
			string s;
			cin >> s;
			arr.push_back(s);
		}
		if (N > 32) 
		{	
			//받은 MBTI개수가 32개를 넘는 경우 아무리 거리를 멀리 하려고 해도 MBTI는 16 종류이기 때문에 반드시 3개가 중복되는 것이 발생한다.
			//이 때는 거리가 무조건 0이기 때문에 거리를 측정할 필요가 없다. (비둘기 집 원리)
			cout << 0 << '\n';
		}
		else 
		{ //32개 이하이면 다양한 거리가 나올 수 있기 때문에 최소 거리를 직접 계산한다.
			int min_dist = 100;
			for (int i = 0; i < N - 2; i++) 
			{
				for (int j = i + 1; j < N - 1; j++) 
				{
					for (int k = j + 1; k < N; k++) 
					{ //최소 값 찾기를 한다.
						min_dist = min(min_dist, distance(arr[i], arr[j]) + distance(arr[j], arr[k]) + distance(arr[i], arr[k]));
					}
				}
			}
			cout << min_dist << '\n'; //최소 거리 출력
		}

	}

	return 0;
}