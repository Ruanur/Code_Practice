#include <iostream>
using namespace std;

int main() {
    int T; // 테스트 케이스의 개수
    cin >> T;

    while (T--) {
        int k, n;
        cin >> k >> n;

        // 2차원 배열을 사용하여 각 층과 호수에 대한 거주자 수를 저장합니다.
        int residents[15][15] = { 0 }; // 최대 14층, 14호

        // 0층 초기화
        for (int i = 1; i <= 14; ++i) {
            residents[0][i] = i;
        }

        // 거주자 수 계산
        for (int i = 1; i <= k; ++i) { // 층
            for (int j = 1; j <= n; ++j) { // 호
                residents[i][j] = residents[i][j - 1] + residents[i - 1][j];
            }
        }

        // k층의 n호 거주자 수 출력
        cout << residents[k][n] << endl;
    }

    return 0;
}
