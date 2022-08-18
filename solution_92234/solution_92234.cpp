// 문제 설명 : https://school.programmers.co.kr/learn/courses/30/lessons/92334
// 풀이 소요시간 : 약 42분, 늦어진 이유는 구상 자체는 어렵지 않았으나 이중 map에 대한 경험이 부족해 헤맸음.
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{

    map<string, int> isAccused;
    for (string& member : id_list)
        isAccused.insert({ member, 0 });

    map<string, int> isMailReceivedMember;
    for (string& member : id_list)
        isMailReceivedMember.insert({ member, 0 });

    map<string, map<string, int>> isAccusing;
    for (string& memAccusing : id_list)
    {
        map<string, int> eachObjection;
        for (string& eachAccusing : id_list)
        {
            if (memAccusing != eachAccusing)
                eachObjection.insert({ eachAccusing, 0 });
        }
        isAccusing.insert({ memAccusing, eachObjection });
    }

    for (string& member : report)
    {
        string id;
        istringstream cats(member);
        int i = 0;
        string accusingMem;
        string accusedMem;
        while (getline(cats, id, ' '))
        {
            if (i == 0)
                accusingMem = id;
            else if (i == 1)
                accusedMem = id;
            i++;
        }
        if (isAccusing[accusingMem][accusedMem] == 0)
        {
            isAccusing[accusingMem][accusedMem] = 1;
            isAccused[accusedMem] += 1;
        }
    }


    for (auto iter = isAccused.begin(); iter != isAccused.end(); iter++)
    {
        if (iter->second >= k)
        {
            for (string& member : id_list)
            {
                if (isAccusing[member][iter->first] >= 1)
                {
                    isMailReceivedMember[member] += 1;
                }
            }
        }
    }
    vector<int> answer;
    for (string& member : id_list)
    {
        answer.push_back(isMailReceivedMember[member]);
    }
    return answer;
}


int main()
{
    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" };
    int k = 2;
    vector<int> answer;

    answer = solution(id_list, report, k);
    for (auto iter = answer.begin(); iter != answer.end(); iter++)
        cout << *iter << " ";

    std::cout << "\n";
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
