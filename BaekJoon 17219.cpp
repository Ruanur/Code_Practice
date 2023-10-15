#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    map<string, string> webInfo;

    for (int i = 0; i < N; i++) {
        string S, P;
        cin >> S >> P;
        webInfo[S] = P;
    }

    for (int i = 0; i < M; i++) {
        string S;
        cin >> S;
        if (webInfo.find(S) != webInfo.end()) {
            cout << webInfo[S] << "\n";
        }
        else {
            cout << "Not Found" << "\n";
        }
    }

    return 0;
}
