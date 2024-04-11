#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	vector<int> arr(N);
	vector<int> result;
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	
	//중복 값 삭제 및 정렬
	set<int> uniqueNum(arr.begin(), arr.end());

	//uniqueNum 값 temp 벡터로 복사 
	vector<int> temp(uniqueNum.begin(), uniqueNum.end());

	for (int i = 0; i < N; i++)
	{
		// i번째 요소값의 위치 it
		auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
		// it에서 cv벡터의 시작 주소값을 빼준 값이 답
		cout << it - temp.begin() << ' ';
	}
	return 0;
}