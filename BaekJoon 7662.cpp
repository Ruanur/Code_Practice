#include <iostream>
#include <set>
#include <string>

using namespace std;

multiset<int> Q; // 우선순위 큐
int T, k; // T : 테스트 데이터 갯수, k : 연산 개수
string command; // 연산자 (D: 큐 내의 요소 삭제, I: 큐에 요소 삽입)
int n; // D n: 삭제 연산자, I n: 요소, Ex. I 1 : 큐에 1 삽입

void DeleteQueue(int n) {
    if (!Q.empty()) {
        if (n == 1) {
            auto maxQ = Q.end();
            --maxQ; // multiset의 마지막 요소가 최대값
            Q.erase(maxQ);
        }
        else if (n == -1) {
            auto minQ = Q.begin(); // multiset의 첫 번째 요소가 최소값
            Q.erase(minQ);
        }
    }
}

void InsertQueue(int n) {
    Q.insert(n);
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> command >> n;
            if (command == "D" && (n == 1 || n == -1)) {
                DeleteQueue(n);
            }
            else if (command == "I") {
                InsertQueue(n);
            }
        }
        if (!Q.empty()) {
            // 큐의 최대값과 최소값 출력
            cout << *Q.rbegin() << " " << *Q.begin() << endl;
        }
        else {
            cout << "EMPTY" << endl;
        }
        Q.clear(); // 다음 테스트 데이터를 위해 큐를 비움
    }

    return 0;
}
