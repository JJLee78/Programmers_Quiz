
//문제 설명
//주어진 숫자 중 3개의 수를 더했을 때 소수가 되는 경우의 개수를 구하려고 합니다.
//숫자들이 들어있는 배열 nums가 매개변수로 주어질 때, nums에 있는 숫자들 중 서로 다른 3개를 골라 더했을 때 
//소수가 되는 경우의 개수를 return 하도록 solution 함수를 완성해주세요.

//##### 순열, 조합은 재귀함수가 아닌 <algorithm>의 next_permutation으로 구할 수 있다. 해당 함수의 사용법을 숙지할 것 
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {//2~n의 제곱근까지
        if (n % i == 0) {//i가 n의 약수라면 소수가 아니므로 false return
            return false;
        }
    }
    return true;
}

int sumnums = 0;

int solution(vector<int> nums) {
    int answer = -1;
    vector<int> sumvec;
    vector<int> tempVector;
    int k = 3; //3개의 수를 고르므로
    int primecounter = 0;

    for (int i = 0; i < 3; i++)
        tempVector.push_back(1);

    for (int i = 0; i < nums.size() - k; i++)
        tempVector.push_back(0);

    sort(tempVector.begin(), tempVector.end());
    do
    {
        int sumnum = 0;
        for (int i = 0; i < tempVector.size(); i++)
        {
            //  cout << nums[i] << " "; // 조합 출력
            if (tempVector[i] == 1)
                sumnum += nums[i];
        }
        if (isPrime(sumnum) == true) //조합으로 구한 3개의 숫자를 더해서 소수일 경우 카운터를 1씩 추가한다.
            primecounter++;
        //  cout << endl;
        //printf("\n");
    } while (next_permutation(tempVector.begin(), tempVector.end()));
    answer = primecounter;
    return answer;
}
int main()
{
    vector<int> q1 = { 1, 2, 3, 4 };
    vector<int> q2 = { 1, 2, 7, 6, 4 };
    cout << solution(q1) << endl;
    cout << solution(q2) << endl;
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
