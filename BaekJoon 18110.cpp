#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> //정렬 사용 sort
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	double N;
	int M;
	double result = 0;
	double div = 0;
	vector<int> arr;
	cin >> N;
	div = round((N * 30) / 200); //양 옆 벡터 삭제 값, 1 = 앞뒤 벡터요소 삭제
	double num = N - (div * 2);
	if (N == 0)
	{
		cout << 0;
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> M;
		arr.push_back(M);
	}
	
	sort(arr.begin(), arr.end());

	arr = vector<int>(arr.begin() + div, arr.end() - div);

	for (int element : arr)
	{
		result += element;
	}
	cout << round(result / num);
}