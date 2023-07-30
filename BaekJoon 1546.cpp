#include <iostream>
using namespace std;

//모든 점수를 점수/M * 100으로 고침
//예를 들어 세준이의 최고점이 70, 점수가 50일때 수학점수는 50/70*100
//cout.precision(number)
int main()
{
	int n;
	int score[1000] = {};
	int temp = 0; //최댓값
	double sum = 0;
	double result = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
		if (temp < score[i])
		{
			temp = score[i];
		}
		sum += score[i];
	}
	result = (sum / temp * 100) / n;
	cout << result;
}
