#include <iostream>
#include <string>

#define r 31
#define M 1234567891

using namespace std;

int main() {
    int l, i;
    long long hash = 0, R = 1;
    string str;

    cin >> l >> str;

    for (i = 0; i < str.length(); i++) {
        hash += ((str[i] - 'a' + 1) * R) % M; 
        //str[i] - 'a' + 1의 의미.
        //각 문자를 숫자로 변환하여 해시 값을 계산하기 위함
        //a는 ASCII 코드에서 97을 의미. 
        //str에 abcde가 입력되었다고 가정할 때,
        /*
        * 'a' - 'a' + 1 = 1 / 97 - 97 + 1
        * 'b' - 'a' + 1 = 2 / 98 - 97 + 1
        * 'c' - 'a' + 1 = 3 / 99 - 97 + 1
        * 'd' - 'a' + 1 = 4 / 100 - 97 + 1
        * 'e' - 'a' + 1 = 5 / 101 - 97 + 1
        */
        hash %= M;
        R = (R * r) % M;
    }
    cout << hash;
}