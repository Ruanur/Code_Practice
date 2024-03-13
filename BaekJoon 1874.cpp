#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int C = 1;

	vector<int> s(N); //수열 
	stack<int> stack; //스택
	vector<char> o; //+,- 
	for (int i = 0; i < N; i++)
	{
		int M;
		cin >> M;
		if (!stack.empty() && stack.top() == M)
		{
			stack.pop();
			o.push_back('-');
		}
		else if (C <= M)
		{
			while (C <= M)
			{
				stack.push(C++);
				o.push_back('+');
			}
			stack.pop();
			o.push_back('-');
		}
		else if(!stack.empty() && stack.top() > M)
		{
			cout << "NO" << "\n";
			return 0;
		}
	}
	for (auto N : o)
	{
		cout << N << "\n";
	}
	return 0;
}