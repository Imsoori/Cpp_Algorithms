#include<iostream>
#include<queue>
#include<vector>

#define endl "\n"
#define MAX 100
using namespace std;

// 2638. 치즈 == softeer 동계 테스트 시점 예측


int N, M;
int MAP[MAX][MAX];
int Visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vector<pair<pair<int, int>, bool>> V;    // 치즈의 좌표를 저장하는 Vector.
vector<pair<int, int>> Cheese;            // 현 시점에서, 녹을 수 있는 치즈만 저장하는 Vector.
queue<pair<int, int>> NQ;                // 외부공기와 내부공기를 합치기 위한 과정에서 사용하는 Queue

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 1)
            {
                V.push_back(make_pair(make_pair(i, j), false));
                Visit[i][j] = -1;
            }
        }
    }
}

void Divide_Air()
{
    /* 외부공기와 내부공기 나누기. */
    /* 맵의 테두리에는 치즈가 놓여있지 않으므로,
     * (0, 0)에서 탐색을 진행하면서 연결되어 있는 공기들만 탐색.
     */
    queue<pair<int, int>> Q;
    Q.push(make_pair(0, 0));
    Visit[0][0] = 1;

    while (Q.empty() == 0)
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M)
            {
                if (Visit[nx][ny] == 0)
                {
                    Visit[nx][ny] = 1;
                    Q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void Find_Cheese_List()
{
    /* 실질적으로 녹는 치즈들만 저장하는 과정. */
    Cheese.clear();
    for (int i = 0; i < V.size(); i++)
    {
        if (V[i].second == true) continue;
        // 이미 녹은 치즈에 대해서는 탐색할 필요 없음.

        int x = V[i].first.first;
        int y = V[i].first.second;
        int Cnt = 0;

        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (MAP[nx][ny] == 0 && Visit[nx][ny] == 1) Cnt++;
            // 단순히, MAP[nx][ny] == 0이 아닌, Visit의 값으로 외부공기인지 내부공기인지
            // 체크도 해줘야 한다.
        }

        if (Cnt >= 2)
        {
            Cheese.push_back(make_pair(x, y));
            V[i].second = true;
        }
    }
}

void Melting_Cheese()
{
    /* 치즈를 실제로 녹이는 과정.*/
    /* 동시에, 외부공기 + 내부공기를 위해 사용될 Queue에 좌표 저장하기. */
    for (int i = 0; i < Cheese.size(); i++)
    {
        int x = Cheese[i].first;
        int y = Cheese[i].second;
        MAP[x][y] = 0;
        NQ.push(make_pair(x, y));
    }
}

void Add_Air()
{
    /* 외부공기와 내부공기를 합쳐주는 과정. */
    while (NQ.empty() == 0)
    {
        int x = NQ.front().first;
        int y = NQ.front().second;
        NQ.pop();

        Visit[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (Visit[nx][ny] == 0)
            {
                Visit[nx][ny] = 1;
                NQ.push(make_pair(nx, ny));
            }
        }
    }
}

bool Clear()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (MAP[i][j] == 1) return false;
        }
    }
    return true;
}

void Solution()
{
    Divide_Air();
    int Time = 0;
    while (1)
    {
        if (Clear() == true) break;
        Find_Cheese_List();
        Melting_Cheese();
        Add_Air();
        Time++;
    }

    cout << Time << endl;
}

void Solve()
{
    Input();
    Solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}


출처: https://yabmoons.tistory.com/342 [얍문's Coding World..]