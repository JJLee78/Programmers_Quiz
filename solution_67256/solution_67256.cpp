// solution_67256.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {

    string answer = "";

    int bef_num_right = 12;
    int bef_num_left = 10;

    //vector<bool> ans_bool; // # true면 L, false면 R로 취급

    for (int i = 0; i < numbers.size(); i++)
    {
        if (i == 0 && numbers[i] == 0)
        {
            if (hand == "left")
                answer.append("L");
            else if (hand == "right")
                answer.append("R");
            continue;
        }

        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
        {
            answer.append("L");
            bef_num_left = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
        {
            answer.append("R");
            bef_num_right = numbers[i];
        }
        else if (numbers[i] == 2 || numbers[i] == 5 || numbers[i] == 8 || numbers[i] == 0)
        {
            if (bef_num_left == bef_num_right)
            {
                if (hand == "left")
                {
                    answer.append("L");
                    bef_num_left = numbers[i];
                }
                else if (hand == "right")
                {
                    answer.append("R");
                    bef_num_right = numbers[i];
                }
            }
            else
            {
                if (numbers[i] == 0)
                    numbers[i] == 11;

                int diff_left = abs(bef_num_left - numbers[i]);
                int diff_right = abs(bef_num_right - numbers[i]);
                int dist_left = (diff_left / 3) + (diff_left % 3);
                int dist_right = (diff_right / 3) + (diff_right % 3);

                
              //  cout << "dist_left : " << dist_left << " / dist_right : " << dist_right << endl;

                if (dist_left == dist_right)
                {
                    if (hand == "left")
                    {
                        answer.append("L");
                        bef_num_left = numbers[i];
                    }
                    else if (hand == "right")
                    {
                        answer.append("R");
                        bef_num_right = numbers[i];
                    }
                }
                else if (dist_left < dist_right)
                {
                    answer.append("L");
                    bef_num_left = numbers[i];
                }
                else if (dist_left > dist_right)
                {
                    answer.append("R");
                    bef_num_right = numbers[i];
                }
            }
        }
       // cout << "bef_left :" << bef_num_left << "/ bef_rigjt : " << bef_num_right << "/ i: " << i << endl;
    }
      
    return answer;
}
int main()
{
    vector<int> sample1 = { 1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5 };
    string hand1 = "right";

    cout << solution(sample1, hand1) << endl;

    std::cout << "Hello World!\n";
}

