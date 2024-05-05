#include <iostream>
#include <string>

using namespace std;

int N, M;

void count_IO(const string& S) 
{

}

int main() {
    string S;
    // 입력 받기 OOIOIOIOIIOII(13)
    cin >> N;
    cin >> M;
    cin >> S;

    int count = 0;
    for (int i = 0; i < M; i++)
    {
        int length = 0;
        if (S[i] == 'O')
        {
            continue;
        }
        else
        {
            while (S[i + 1] == 'O' && S[i + 2] == 'I')
            {
                length++;
                if (length == N)
                {
                    count++;
                    length--;
                }
                i += 2;
            }
        }
        length = 0;
    }
    cout << count;

    return 0;
}
