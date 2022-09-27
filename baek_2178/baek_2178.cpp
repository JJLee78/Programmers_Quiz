#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define max 101
//int maze[max][max];
bool isVisited[max][max] = { false };
bool isRoad[max][max] = { false };
int isCounter[max][max] = { 0 };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int counter = 0;
int  N = 0;
int M = 0;
int bfs(int n, int m)
{
    queue<pair<int, int>> que;
    que.push(make_pair(n, m));
    isVisited[n][m] = true;
    //  isCounter[n][m] = counter++;
    while (!que.empty())
    {
        int n1 = que.front().first;
        int m1 = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            int x1 = n1 + dx[i];
            int y1 = m1 + dy[i];
            if (x1 >= 0 && x1 < N && y1 >= 0 && y1 < M)
            {
                //   cout << "i " << i << " x1 " << x1 << " y1 " << y1 << " isRoad " << endl;
                if (isRoad[x1][y1] == true && isVisited[x1][y1] == false)
                {
                    // cout << " ok" << endl;
                     //if ()

                      //   cout << "pushed" << endl;
                    //cout << "{ " << x1 << " " << y1 << " } " << counter << endl;

                    isVisited[x1][y1] = true;
                    isCounter[x1][y1] = isCounter[n1][m1] + 1;
                    que.push(make_pair(x1, y1));
                    //x2 = x1;
                    //y2 = y1;
                }
            }
        }
    }
    //cout << maxcounter + 1<< endl;
    return 0;

}
int main()
{
    scanf_s("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf_s("%s", isRoad[i]);
    }
    bfs(0, 0);
    cout << isCounter[N - 1][M - 1] + 1 << endl;
    //cout << bfs(0, 0) << endl;

    //std::cout << "Hello World!\n";
}
