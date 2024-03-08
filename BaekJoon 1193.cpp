#include <iostream>
using namespace std;

// 이와 같이 나열된 분수들을 1/1 → 1/2 → 2/1 → 3/1 → 2/2 → … 과 같은 
// 지그재그 순서로 차례대로 1번, 2번, 3번, 4번, 5번, … 분수라고 하자.
// X가 주어졌을 때, X번째 분수를 구하는 프로그램을 작성하시오.
int main()
{
	int X;
	cin >> X;

	int i = 1;
	while (X > i)
	{
		X -= i;
		i++;
	} //X가 몇번째 대각선에 위치해있는지 계산

	if (i % 2 == 1) // i번째 대각선이 짝수인지 홀수인지 판별
	{
		cout << i + 1 - X << "/" << X << "\n";
	}
	else
	{
		cout << X << "/" << i + 1 - X << "\n";
	}

	return 0;
}