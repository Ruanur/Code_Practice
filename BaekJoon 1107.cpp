#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

int countDigits(int target, int number) { //횟수
    int count_a = abs(target - number);
    int count_b = abs(100 - target);
    
    if (number == 0)
    {
        count_a++;
    }

    while (number != 0) {
        number /= 10;
        count_a++;
    }

    int count = min(count_a, count_b);
    return count;

}

int FindNumber(int num, const vector<int>& Numbers) //리모컨으로 목표 채널에 근접한 수 입력 함수
{
    int closest = INT_MAX; // 최소값을 최대로 초기화
    int closestDiff = INT_MAX; // 차이의 절댓값을 최대로 초기화

    for (int i = 0; i <= 1000000; ++i) { // 범위는 임의로 설정
        bool exclude = false;
        for (int digit : Numbers) {
            if (to_string(i).find(to_string(digit)) != string::npos) {
                exclude = true;
                break;
            }
        }
        if (exclude) // 사용하지 않는 숫자를 가진 수는 건너뜀
            continue;

        int diff = abs(num - i);
        if (diff < closestDiff) {
            closestDiff = diff;
            closest = i;
        }
    }

    return closest;
}

int main()
{
	int N,M;
	int Num;
	vector<int> BanNumbers;
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> Num;
		BanNumbers.push_back(Num);
	}
    
    if (N == 100)
    {
        cout << 0;
        return 0;
    }

    if (M == 10)
    {
        cout << abs(100 - N);
        return 0;
    }

	int closet = FindNumber(N, BanNumbers);


    int digits = countDigits(N, closet);
	cout << digits;

	return 0;

}