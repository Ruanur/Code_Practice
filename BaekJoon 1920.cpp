#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    vector<int> NV;
    int N;
    int NN;
    int M;
    int MN;
    int mid;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> NN;
        NV.push_back(NN);
    }

    sort(NV.begin(), NV.end()); //정렬

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> MN;
        int first = 0;
        int last = NV.size() - 1; //이진 탐색을 수행하기 전에 초기화

        while (first <= last)
        {
            mid = (first + last) / 2;

            if (MN == NV[mid])
            {
                cout << "1" << "\n";
                break; // 찾았으므로 반복문 종료
            }
            if (MN < NV[mid])
            {
                last = mid - 1;
            }
            else if (MN > NV[mid])
            {
                first = mid + 1;
            }
        }
        if (first > last) // 수정된 부분: 못 찾았을 경우 출력
        {
            cout << "0" << "\n";
        }
    }
    return 0;
}
