#include <iostream>

using namespace std;

int N;
int main() {
	cin >> N;
	int result = 0;
	while (N >= 0) 
	{
		if (N % 5 == 0) 
		{	
			result += (N / 5);	
			cout << result << "\n";
			return 0;
		}
		N -= 3;	
		result++;
	}
	cout << -1 << "\n";
}