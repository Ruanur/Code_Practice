#include <iostream>
#include <vector>

using namespace std;

long long countTiling(long long n) {
    vector<long long> dp(n + 1, 0);

    // 초기 조건 설정
    dp[0] = 1;
    dp[1] = 1;

    // 다이나믹 프로그래밍 테이블 채우기
    for (long long i = 2; i <= n; ++i) {
        // 현재 칸을 1x2 타일로 채우는 경우
        dp[i] += dp[i - 1];
        // 현재 칸을 2x1 타일로 채우는 경우
        dp[i] += dp[i - 2];
        dp[i] %= 10007;
    }

    // 전체 문제의 해 반환
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;// 직사각형의 너비
    cout << countTiling(n) << "\n";
    return 0;
}
