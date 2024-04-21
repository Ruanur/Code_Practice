#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxScore(int n, vector<int>& scores) {
    if (n == 1) return scores[0];
    if (n == 2) return scores[0] + scores[1];

    vector<int> dp(n); // dp[i]는 i번째 계단까지의 최대 점수를 저장

    dp[0] = scores[0];
    dp[1] = scores[0] + scores[1];
    dp[2] = max(scores[0] + scores[2], scores[1] + scores[2]); // 세 번째 계단은 두 가지 선택 가능

    for (int i = 3; i < n; ++i) {
        // i번째 계단을 밟았을 때의 최대 점수는 i-1번째 계단을 밟은 경우와 i-2번째 계단을 밟은 경우 중 큰 값을 선택
        dp[i] = max(dp[i - 2] + scores[i], dp[i - 3] + scores[i - 1] + scores[i]);
    }

    return dp[n - 1]; // 마지막 계단까지의 최대 점수 반환
}

int main() {
    int n;
    cin >> n;

    vector<int> scores(n);
    for (int i = 0; i < n; ++i) {
        cin >> scores[i];
    }

    cout << maxScore(n, scores) << endl;

    return 0;
}
