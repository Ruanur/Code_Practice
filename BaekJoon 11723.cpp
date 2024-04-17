#include <iostream>
#include <string>
using namespace std;

int S = 0;

//(1 << (x - 1))은 1을 x만큼 왼쪽으로 시프트한 값을 의미한다.
//따라서 x번째 비트만 1이고 나머지는 0인 수를 만든다.
void add(int x) {
    S |= (1 << (x - 1));
}

//(1 << (x - 1))은 원소의 비트를 1로 설정한 수이다.
//~(1<< (x - 1))은 해당 비트를 제외한 나머지 비트가 모두 1인 수를 만든다.
//S &= ~(1 << (x - 1)) 는 S에서 해당 비트를 제거하는 비트 AND 연산이다,
//따라서 주어진 원소에 해당하는 비트를 0으로 설정한다.
void remove(int x) {
    S &= ~(1 << (x - 1));
}

//(1<< (x - 1))은 해당 원소의 비트가 1인 수를 의미한다.
//(S & (1 << (x - 1)))는 S와 해당 원소의 비트를 AND 연산하여 해당 원소의 비트가 1인지 확인한다.
//조건 삼항 연산자를 사용하여 해당 비트가 1이면 1을 반환, 아니면 0을 반환한다.
int check(int x) {
    return (S & (1 << (x - 1))) ? 1 : 0;
}

//(1<< (x - 1))은 해당 원소의 비트가 1인 수를 의미한다.
//S ^= (1 << (x - 1))는 S와 해당 원소의 비트를 XOR 연산하여 해당 원소의 비트를 반전시킨다.
void toggle(int x) {
    S ^= (1 << (x - 1));
}

//(1 << 20) - 1은 20개의 비트가 모두 1인 수를 의미한다. 따라서 모든 원소를 포함한 집합을 나타냄.
void all() {
    S = (1 << 20) - 1;
}

//S = 0은 모든 비트를 0으로 설정하여 공집합을 나타낸다.
void empty() {
    S = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    while (M--) {
        string command;
        cin >> command;

        if (command == "add") {
            int x;
            cin >> x;
            add(x);
        }
        else if (command == "remove") {
            int x;
            cin >> x;
            remove(x);
        }
        else if (command == "check") {
            int x;
            cin >> x;
            cout << check(x) << "\n";
        }
        else if (command == "toggle") {
            int x;
            cin >> x;
            toggle(x);
        }
        else if (command == "all") {
            all();
        }
        else if (command == "empty") {
            empty();
        }
    }

    return 0;
}
