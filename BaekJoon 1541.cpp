#include <iostream>
#include <string>
using namespace std;

int main() {
    string input; //문자열 입력 
    cin >> input;

    int result = 0; 
    string num; //숫자를 저장할 문자열 선언 
    bool isMinus = false; //수식이 '-' 인지

    for (int i = 0; i <= input.size(); i++) { //문자열 크기만큼 반복

        if (input[i] == '-' || input[i] == '+' || i == input.size()) { //선택된 문자열이 수식이거나, 제일 마지막 숫자일 경우,
            if (isMinus) { // '-' 라면
                result -= stoi(num); //stoi : string to int, 문자열을 숫자로 변환
                num = "";
            }
            else { 
                result += stoi(num); 
                num = "";
            }
        }
        else {
            num += input[i]; //이에 해당하지 않으면(숫자) num 문자열에 저장
        }

        if (input[i] == '-') { //수식이 '-'이면 
            isMinus = true; //True
        }
    }

    cout << result;
}