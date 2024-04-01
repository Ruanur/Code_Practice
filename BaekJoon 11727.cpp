#include <iostream>
#include <vector>

using namespace std;

long long countTiling(long long n) {
    vector<long long> dp(n + 1);
    int num = 1;
    // 초기 조건 설정
    dp[1] = 1;
    dp[2] = 3;


    // 다이나믹 프로그래밍 테이블 채우기
    for (int i = 3; i <= n; ++i) {
        if (n == 1)
        {
            return dp[1];
        }
        else if (n == 2)
        {
            return dp[2];
        }
        else
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 2];
            dp[i] %= 10007;
        }
    }

    // 전체 문제의 해 반환
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;// 직사각형의 너비
    cout << countTiling(n) << "\n";
    return 0;
}
