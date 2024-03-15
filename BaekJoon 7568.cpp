#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<pair<int, int>> info(N);

    for (int i = 0; i < N; i++)
    {
        cin >> info[i].first >> info[i].second;
    }

    for (int i = 0; i < N; i++)
    {
        int rank = 1;
        for (int j = 0; j < N; j++)
        {
            if (i != j && info[i].first < info[j].first && info[i].second < info[j].second)
            {
                rank++;
            }
        }
        cout << rank << " ";
    }

    return 0;
}
