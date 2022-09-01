// https://school.programmers.co.kr/learn/courses/30/lessons/42862
// 총 소요시간 23분, greedy 알고리즘 문제라는데 그냥 map으로도 풀렸다. 하지만 반복문이 많아 O(2n) 이상일 듯

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    map<int, int> members;
    for (int i = 1; i <= n; i++)
    {
        if (find(reserve.begin(), reserve.end(), i) != reserve.end())
        {
            if (find(lost.begin(), lost.end(), i) != lost.end())
                members.insert({ i, 1 });
            else
                members.insert({ i, 2 });
        }
        else
        {
            if (find(lost.begin(), lost.end(), i) != lost.end())
                members.insert({ i, 0 });
            else
                members.insert({ i, 1 });
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (members[i] == 0)
        {
            if (i > 1 && (members[i - 1] == 2))
            {
                members[i] = 1;
                members[i - 1] = 1;
                answer++;
            }
            else if (i < n && (members[i + 1] == 2))
            {
                members[i] = 1;
                members[i + 1] = 1;
                answer++;
            }
        }
        else if (members[i] == 1 || members[i] == 2)
            answer++;
    }
    return answer;
}
int func1(int N)
{
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 3 == 0)
            sum += i;
        else if (i % 5 == 0)
            sum += i;
    }

    return sum;
}

int func2(int arr[], int N)
{
    vector<int> arrvec(arr,  arr + sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < N; i++)
    {
        int findnumber = 100 - arr[i];
        if(findnumber != arr[i])
        {
            cout << findnumber << endl;
            if (find(arrvec.begin(), arrvec.end(), findnumber) != arrvec.end())
            {
                cout << "found!" << endl;
                return 1;
            }
        }
    }
    return 0;
}
int func3(int n)
{
    int nrun = sqrt(n);
    if (nrun * nrun == n)
        return 1;
    return 0;
}

int func4(int n)
{
    int dup = 0;
    int m = 1;
    while (dup < n)
    {
        int temp = pow(2, m);
        if (temp > n)
            break;
        else
            dup = temp;
            m++;
    }
   // cout << m << endl;
    return dup;

}

int main()
{
    int n = 5;
    vector<int> m = { 2, 4 };
    vector<int> o = { 1, 3, 5 };
   /// cout << func1(34567) << endl;

    int arr[4] = { 4, 13, 63, 87 };
    //cout << func2( arr, 4) << endl;

    //cout << func3(756580036) << endl;

    cout << func4(97615282) << endl;
  //  std::cout << solution(n,m,o) << endl;
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
