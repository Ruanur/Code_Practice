#include <iostream>
#include <queue>

using namespace std;

queue<int> stick; //탕후루 꼬치에 꽃힌 과일을 저장하는 큐
int type, cnt[10], answer; //type : 과일 종류, cnt[10] : 과일 빈도수 카운트(최대 10종류 과일)

void processfruit(int fruit); //함수 전방 선언

int main()
{
	int N; //과일의 개수

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int S; //과일의 종류 (1~9)
		cin >> S;
		processfruit(S);
	}

	cout << answer;
	return 0;
}

void processfruit(int fruit)
{
	stick.push(fruit);

	if (cnt[fruit]++ == 0) //cnt 배열의 값, 즉 빈도수를 증가시키고 만약 이 과일이 처음 나타났다면
	{
		++type; //과일 종류를 증가시킨다
	}
	while (type > 2) //과일의 종류가 2개가 남을떄까지 반복
	{
		int target;
		target = stick.front(); //큐의 맨 앞을 변수에 저장
		stick.pop();
		if (--cnt[target] == 0) //target이 더 이상 남지 않을 때, 
		{
			--type; //type 삭제 (1 -> 0)
		}
	}

	answer = max(answer, static_cast<int>(stick.size()));
}