#include <iostream>
#include <vector>

using namespace std;

//색종이의 최대 크기는 128
int arr[128][128];
//파란색 색종이, 흰색 색종이 개수 
int blue, white;

void Confetti(int y, int x, int size)
{
	//이 좌표의 색종이 색이 파란색인지 흰색인지, 0 or 1
	int check = arr[y][x];
	//해당 영역 내 모든 좌표에 대해 확인
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			//만약 다른 색이 발견된다면, check를 2로 설정, 현재 좌표가 흰색이고 다른 좌표가 파란색일 때.
			if (check == 0 && arr[i][j] == 1)
			{
				check = 2;
			}
			//현재 좌표가 파란색이고 다른 좌표가 흰색일 때.
			else if(check == 1 && arr[i][j] == 0)
			{
				check = 2;
			}
			//이 때 현재 사각형 내에 다른 색이 섞여 있다면, 사각형을 더 작은 사각형으로 분할, 그 후 재귀함
			if (check == 2)
			{
				Confetti(y, x, size / 2);
				Confetti(y, x + size / 2, size / 2);
				Confetti(y + size / 2, x, size / 2);
				Confetti(y + size / 2, x + size / 2, size / 2);
				return;
			}
		}
	}
	//만약 현재 사각형의 색이 모두 같다면, 이에 해당하는 색종이 색깔의 수를 증가시킴. 
	if (check == 0)
	{	
		white++;
	}
	else
	{
		blue++;
	}
}

int main()
{
	int N;
	//2,4,8,16,32,64,128
	cin >> N;
	//배열에 색깔 칠하기, 흰색은 0, 파란색은 1
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	//분할 정복, 색종이 분할하기 
	Confetti(0, 0, N);

	cout << white << "\n";
	cout << blue << "\n";
	return 0;
}