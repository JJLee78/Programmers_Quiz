
//���� ����
//�־��� ���� �� 3���� ���� ������ �� �Ҽ��� �Ǵ� ����� ������ ���Ϸ��� �մϴ�.
//���ڵ��� ����ִ� �迭 nums�� �Ű������� �־��� ��, nums�� �ִ� ���ڵ� �� ���� �ٸ� 3���� ��� ������ �� 
//�Ҽ��� �Ǵ� ����� ������ return �ϵ��� solution �Լ��� �ϼ����ּ���.

//##### ����, ������ ����Լ��� �ƴ� <algorithm>�� next_permutation���� ���� �� �ִ�. �ش� �Լ��� ������ ������ �� 
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {//2~n�� �����ٱ���
        if (n % i == 0) {//i�� n�� ������ �Ҽ��� �ƴϹǷ� false return
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
    int k = 3; //3���� ���� ���Ƿ�
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
            //  cout << nums[i] << " "; // ���� ���
            if (tempVector[i] == 1)
                sumnum += nums[i];
        }
        if (isPrime(sumnum) == true) //�������� ���� 3���� ���ڸ� ���ؼ� �Ҽ��� ��� ī���͸� 1�� �߰��Ѵ�.
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

// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.
