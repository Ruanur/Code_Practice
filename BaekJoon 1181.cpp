#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;


//N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬 
//1. 길이가 짧은 것 부터 
//2. 길이가 같으면 사전 순으로, a,b,c
//중복된 단어는 하나만 남기고 제거
bool compare(pair<int, string>a, pair<int, string>b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    string S;
    cin >> N;

    vector<pair<int, string>> arr;

    for (int i = 0; i < N; i++)
    {
        cin >> S;
        arr.push_back(make_pair(S.size(), S));

    }

    
    sort(arr.begin(), arr.end(), compare);
    //arr 벡터 처음부터 끝까지 정렬, 문자열 사전순

    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    //중복 제거

    for (int i = 0; i < arr.size(); i++)
    //i < N; => i < arr.size()
    //중복된 값을 지우고 난 후에는 벡터의 길이가 짧아지기에 arr.size로 변경해주어야 한다. 
    {
        cout << arr[i].second << "\n";
    }

    return 0;
}

