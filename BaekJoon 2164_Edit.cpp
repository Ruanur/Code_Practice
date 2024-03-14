#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N;
	int j = 1;
	cin >> N;
	queue<int> arr;
	for (int i = 1; i <= N; i++)
	{
		arr.push(i);
	}
	while (arr.size() > 1)
	{
		arr.pop();
		int top = arr.front();
		arr.pop();
		arr.push(top);
	}
	cout << arr.front() << "\n";

	return 0;
}





//N장의 카드가 있다.
//각각의 카드는 차례로 1부터 N까지의 번호가 붙어있음
//1번 카드가 제일 위, N번 카드가 제일 아래인 상태로 순서대로 카드가 놓임.
//다음과 같은 동작을 카드가 하나 남을 때까지 반복,
//"카드는 제일 위에서부터 1234 순서로 놓여있음, 1을 버리면 234가 남고
//여기서 2를 제일 아래로 옮기면 342가 됨
//3을 버리면 42가 되고, 4를 밑으로 옮기면 24가 됨.
//마지막으로 2를 버리면 남는 카드는 4"
//이때 N이 주어졌을 때, 제일 마지막에 남게 되는 카드를 구하는 프로그램을 작성하여라

