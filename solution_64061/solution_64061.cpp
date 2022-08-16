// solution_64061.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> pot;
    vector<vector<int>> b = board;
    for (int& cur_move : moves)
    {
        int cols = -1 + cur_move;
        int rows = 0;
        while (b[rows][cols] == 0)
        {
            rows++;
            if (rows == b.size())
            {
                rows -= 1;
                break;
            }
                
        }

        if (b[rows][cols] == 0)
        {
            continue;
        }
        else
        {
            if (pot.empty())
            {
                pot.push_back(b[rows][cols]);
                b[rows][cols] = 0;
                continue;
            }
            else if (pot.back() == b[rows][cols])
            {
                pot.pop_back();
                answer+=2;
            }
            else if (pot.back() != b[rows][cols])
            {
                pot.push_back(b[rows][cols]);
            }
            b[rows][cols] = 0;
        }

    }
    return answer;
}

vector<int> solution(long long n) {
    vector<int> answer;
    int curr = (int)n;
    
    while (curr > 9)
    {
        cout << curr % 10 << endl;
        answer.push_back(curr % 10);
        curr = curr / 10;
    }
    answer.push_back(curr);

    cout << "0--" << endl;
    for (auto& val : answer)
    {
        cout << val << endl;
    }

    return answer;
}
int main()
{
    //vector<vector<int>> q1 = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};
    //vector<int> moves = { 1, 5, 3, 5, 1, 2, 1, 4 };
   // int ans = solution(q1, moves);
   // std::cout << ans << "\n";

    solution(54321);
    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
