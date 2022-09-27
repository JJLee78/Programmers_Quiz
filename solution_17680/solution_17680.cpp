#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    deque<string>::iterator it;

    for (int i = 0; i < cities.size(); i++)
    {
        for (int n = 0; n < cities[i].length(); n++)
        {
            if (cities[i][n] >= 65 && cities[i][n] <= 90)
                cities[i][n] ^= 32;
            //cout << cities[i][n] << endl;
        }
        auto it = find(cache.begin(), cache.end(), cities[i]);
        if (it != cache.end())
        {
            //cache hit
            answer += 1;
            string ittemp = *it;
            cache.erase(it);
            cache.push_front(ittemp);
            //    cout << ittemp << endl;
        }
        else if (cache.size() < cacheSize)
        {
            answer += 5;
            //cache miss
            cache.push_front(cities[i]);
        }
        else if (cache.size() == cacheSize)
        {
            //cache miss
            answer += 5;
            if (cacheSize >= 1)
            {
                cache.pop_back();
                cache.push_front(cities[i]);
            }
        }
    }
    return answer;
}

int main()
{
    vector<string> cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
    int cacheSize = 5;
    
    std::cout << solution(cacheSize, cities) << endl;
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
