#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a, vector<int> b) {
	int answer = 0;
	for (auto aval : a)
	{
		answer += (a.back() * b.back());
		a.pop_back();
		b.pop_back();
	}
	return answer;
}
int main()
{
	vector<int> a = { 1, 2, 3, 4 };
	vector<int> b = { -3, -1, 0, 2 };
	
	cout << "answer : " << solution(a, b) << endl;

	return 0;

}