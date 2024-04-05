#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct ABS_Compare
{
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
        {
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

void ABS_Queue(int N)
{
    priority_queue<int, vector<int>, ABS_Compare> q;
    int M;
    for (int i = 0; i < N; i++)
    {
        cin >> M;
        if (M == 0)
        {
            if (q.empty())
            {
                cout << "0" << "\n";
            }
            else
            {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else
        {
            q.push(M);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    ABS_Queue(N);

    return 0;
}
