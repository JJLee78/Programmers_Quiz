//문제 설명 : https://school.programmers.co.kr/learn/courses/30/lessons/42889
// !
// 각 도전자수와 스테이지 실패율을 구하는 데는 힘들지 않았으나,
// 답안 제출 시 실패율은 내림차순/ 동일 실패율 시 스테이지 순서별로 오름차순으로 정렬하는 부분이 발목을 잡았다.
// sort 함수의 세번째 파라미터에 유념해 마킹해놓고 일주일 후 다시 풀어볼 것. 
// (lower_bound, upper_bound도 처음 써 보았는데 유용할 것 같으니 기억해두도록 한다.)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
bool comp(pair<int, double>& a, pair<int, double>& b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;

}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, double>> stageper;

    int allguys = stages.size();
    sort(stages.begin(), stages.end());
    for (int i = 1; i <= N; i++)
    {
        int lowest = lower_bound(stages.begin(), stages.end(), i) - stages.begin(); //최저값의 인덱스
        int highest = upper_bound(stages.begin(), stages.end(), i) - stages.begin();
        int challangers = allguys - lowest;
        int stoppers = highest - lowest;
        if (stoppers == 0)
        {
            stageper.push_back({ i , 0 });
            continue;
        }
        stageper.push_back({ i , (double)stoppers / (double)challangers });
    }

    sort(stageper.begin(), stageper.end(), comp);
    for (pair<int, double> stage : stageper)
    {
        cout << stage.first << endl;
    }
    return answer;
}
int main()
{
    vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};
    int N = 5;
    solution(N, stages);
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
