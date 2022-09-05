// https://school.programmers.co.kr/learn/courses/30/lessons/12981
// 총 소요시간 58분,문제 자체는 어렵지 않은데 처음에 잘못 생각한 것이 시간이 지연된 원인이었다. 조건을 꼼꼼하게 체크하는 습관을 들일 것

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    int guycounter = 1;
    int wordcounter = 1;
    vector<string> wordbank;
    wordbank.push_back("0");
    for (string& word : words)
    {
        string lastword = wordbank.back();
        //  cout << "lastword : " << lastword << endl;
        if (find(wordbank.begin(), wordbank.end(), word) != wordbank.end()) // 찾을 경우
        {
            //cout << "중복" << endl;
            answer.push_back(guycounter);
            answer.push_back(wordcounter);
            return answer;
        }
        else if ((lastword[lastword.length() - 1] != word[0]) && lastword != "0")
        {
            //cout << "마지막 문자" << endl;
            answer.push_back(guycounter);
            answer.push_back(wordcounter);
            return answer;
        }
        else
            wordbank.push_back(word);

        if (guycounter % n != 0)
            guycounter++;
        else if (guycounter % n == 0)
        {
            guycounter = 1;
            wordcounter++;
        }
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}
int main()
{
    vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
    int n = 3;
    vector<int> answer = solution(3, words);
    std::cout << answer[0] << " " << answer[1] << endl;;
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
