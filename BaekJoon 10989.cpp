#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int arr[10001] = { 0 };

    // 숫자 개수 카운트
    for (int i = 0; i < T; i++) {
        int a;
        cin >> a;
        arr[a] += 1;
    }
    //ex. a의 값을 10번 입력받을 수 있다고 할 때, 1이 두번 입력되면 arr[1] = 2, 3이 3번 입력되면 arr[3] = 3


    // 각 숫자를 개수만큼 출력해주기
    for (int i = 1; i <= 10000; i++)
        for (int j = 0; j < arr[i]; j++)
            //위에서 명시한 배열대로 결과를 도출하면 arr[1]일 때, j < arr[1] ==> j < 2, arr[i]값 2번 출력
            //cout i \n => 1 두번 출력 오름차순 
            cout << i << "\n";
}
