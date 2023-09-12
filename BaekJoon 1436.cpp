#include<iostream>
using namespace std;

int N, ans, cnt, temp;

int main()
{

	cin >> N;

	ans = 0; 
	cnt = 0; 

	while (cnt != N)
	{
		ans++;
		temp = ans;

		while (temp != 0)
		{
			if (temp % 1000 == 666) 
			{
				cnt++;
				break;
			}
			else temp /= 10; 
		}
	}
	cout << ans;
}

//Ex. 2를 입력받았을 때, while(cnt != 2), cnt가 2가 될때까지 ans 값 무한 반복 상승
//666%1000 == 666, cnt 값++, cnt = 1, 1666%1000 == 666, cnt = 2, 반복문 탈출
// cout << ans <- 1666