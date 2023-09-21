#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T > 0)
	{
		T--;
		string V;
		string answer = "YES";
		cin >> V;
		
		stack<char> st;
		for (int i = 0; i < V.length(); i++)
		{
			if (V[i] == '(')
			{
				st.push(V[i]);
			}
			else if (!st.empty() && st.top() == '(' && V[i] == ')')
			{
				st.pop();
			}
			else
			{
				answer = "NO";
				break;
			}
		}
		if (!st.empty())
		{
			answer = "NO";
		}
		cout << answer << '\n';
	}
	
}