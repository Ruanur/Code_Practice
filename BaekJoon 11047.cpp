#include <iostream>
#include <vector>
#include <algorithm> // 정렬을 위한 헤더 파일

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K; // 동전의 종류 수와 만들고자 하는 금액을 입력 받음

    vector<int> m(N); // 동전의 종류를 저장할 벡터 생성

    for (int i = 0; i < N; i++)
    {
        cin >> m[i]; // 동전의 종류를 입력 받아 벡터에 저장
    }

    sort(m.rbegin(), m.rend()); // 동전의 금액을 내림차순으로 정렬

    int count = 0; // 필요한 동전의 개수를 저장할 변수
    for (int i = 0; i < N; i++)
    {
        count += K / m[i]; // 현재 동전으로 만들 수 있는 최대 개수를 더함
        K %= m[i]; // 사용한 동전의 금액을 제외한 나머지 금액을 다음 동전으로 만듦
    }

    cout << count << "\n"; // 필요한 동전의 개수 출력

    return 0;
}
