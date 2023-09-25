#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    stack<int> stack;
    cin >> n;
    if (n < 1 || n > 10000)
    {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        string S; //명령어
        int X; //push 값
        cin >> S;

        if (S == "push") 
        {
            cin >> X;
            stack.push(X);
        }

        else if (S == "pop") 
        {
            if (stack.size() == 0)
            {
                cout << "-1" << "\n";
            }
            else
            {
                cout << stack.top() << "\n";
                stack.pop();
            }
        }

        else if (S == "size") 
        {
            cout << stack.size() << "\n";
        }

        else if (S == "empty") 
        {
            if (stack.size() == 0)
            {
                cout << "1" << "\n";
            }
            else
            {
                cout << "0" << "\n";
            }
        }

        else if (S == "top") 
        {
            if (stack.size() == 0)
            {
                cout << "-1" << "\n";
            }
            else
            {
                cout << stack.top() << "\n";
            }
        }
    }

    return 0;
}