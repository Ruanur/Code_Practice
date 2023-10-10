#include <iostream>
using namespace std;

long long fiboarr[41] = { 0,1, }; //피보나치 수열의 값 저장. fiboarr[0] = 0, fiboarr[1] = 1
long long fibo(int N) //피보나치 함수
{
    if (N == 0 || N == 1)
    {
        return fiboarr[N];
    }
    else if (fiboarr[N] == 0)
    {
        fiboarr[N] = fibo(N - 1) + fibo(N - 2);
    }
    return fiboarr[N];
}
int main() {
    int T;
    cin >> T;
    int tmp;
    for (int i = 0; i < T; i++)
    {
        cin >> tmp;
        if (tmp == 0)
            cout << "1 0" << '\n';
        else
            cout << fibo(tmp - 1) << ' ' << fibo(tmp) << '\n';
    }
}

//문제를 풀다 막힐 때 각 케이스의 규칙성 찾아보기 