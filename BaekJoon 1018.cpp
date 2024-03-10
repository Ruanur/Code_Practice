#include <iostream>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

string WB[8]
{
    "WBWBWBWBWB",
    "BWBWBWBWBW",
    "WBWBWBWBWB",
    "BWBWBWBWBW",
    "WBWBWBWBWB",
    "BWBWBWBWBW",
    "WBWBWBWBWB",
    "BWBWBWBWBW",
};

string BW[8]
{
    "BWBWBWBWBW",
    "WBWBWBWBWB",
    "BWBWBWBWBW",
    "WBWBWBWBWB",
    "BWBWBWBWBW",
    "WBWBWBWBWB",
    "BWBWBWBWBW",
    "WBWBWBWBWB",
};

string B[50];

int WB_cnt(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (B[x + i][y + j] != WB[i][j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int BW_cnt(int x, int y)
{
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (B[x + i][y + j] != BW[i][j])
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int main()
{
    int N, M;
    cin >> N >> M;
    int mv = 12345;
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            int temp = min(WB_cnt(i,j),BW_cnt(i,j));
            mv = min(mv,temp);
        }
    }
    cout << mv;
    return 0;
}

