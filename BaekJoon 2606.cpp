#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool check[101];
vector<int> graph[101];

int virus(int num)
{
    int result = 0;
    queue<int> q;

    q.push(num);
    check[num] = true; //방문한 노드 체크 

    while (!q.empty()) //큐가 빌때까지 반복
    {
        int x = q.front(); //EX. x = 1
        q.pop(); // 큐에서 x = 1 팝 

        for (int i = 0; i < graph[x].size(); i++) //graph[1] 크기만큼 반복, 1-2, 1-5, 그래프의 크기 2
        {
            int y = graph[x][i]; //graph[1][0] = 2, graph[1][1] = 5
            if (!check[y])
            {
                q.push(y); //큐에 2,5 푸시, while문에서 다시 출발
                check[y] = true;
                result += 1;
            }
        }
    }
    return result;
}

int main()
{
    int N, M, a, b;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // 양방향 그래프임을 고려하여 반대 방향도 추가
    }
    cout << virus(1) << "\n";
}
