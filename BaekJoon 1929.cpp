#include <iostream>
#include <vector>
using namespace std;

void Eratos(int n, int m) {
    if (n <= 1)
    {
        n = 2; // n이 1 이하일 경우, 최소값 2로 설정
    }

    if (m < 2) {
        cout << "X" << "\n";
        return;
    }

    // 소수 여부를 저장하는 배열
    vector<bool> isPrime(m + 1, true);

    // 0과 1은 소수가 아니므로 false로 설정
    isPrime[0] = isPrime[1] = false;

    // 에라토스테네스의 체 알고리즘 적용
    for (int i = 2; i * i <= m; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= m; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // 소수 출력
    for (int i = n; i <= m; i++) {
        if (isPrime[i]) {
            cout << i << "\n";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); //입출력 시간 단축

    int N, M;
    cin >> N >> M;

    if (N <= M) {
        Eratos(N, M);
    }
    else {
        cout << "유효한 범위를 입력하세요." << "\n"; // endl < \n 코드 실행시간 단축
    }

    return 0;
}