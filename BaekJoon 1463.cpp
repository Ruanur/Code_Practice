#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> dp(N + 1);

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    //dp[4] = dp[3] + 1 = 2
    //dp[5] = dp[4] + 1 = 3
    //dp[6] = dp[5] + 1 = 4 => 오류

    for (int i = 4; i <= N; i++) {
        dp[i] = dp[i - 1] + 1;

        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }

    cout << dp[N] << "\n";

    return 0;
}
