#include<iostream>
#include<queue>
#include<vector>

#define endl "\n"
#define MAX 100
using namespace std;

// 2638. ġ�� == softeer ���� �׽�Ʈ ���� ����


int N, M;
int MAP[MAX][MAX];
int Visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vector<pair<pair<int, int>, bool>> V;    // ġ���� ��ǥ�� �����ϴ� Vector.
vector<pair<int, int>> Cheese;            // �� ��������, ���� �� �ִ� ġ� �����ϴ� Vector.
queue<pair<int, int>> NQ;                // �ܺΰ���� ���ΰ��⸦ ��ġ�� ���� �������� ����ϴ� Queue

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
    /* �ܺΰ���� ���ΰ��� ������. */
    /* ���� �׵θ����� ġ� �������� �����Ƿ�,
     * (0, 0)���� Ž���� �����ϸ鼭 ����Ǿ� �ִ� ����鸸 Ž��.
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
    /* ���������� ��� ġ��鸸 �����ϴ� ����. */
    Cheese.clear();
    for (int i = 0; i < V.size(); i++)
    {
        if (V[i].second == true) continue;
        // �̹� ���� ġ� ���ؼ��� Ž���� �ʿ� ����.

        int x = V[i].first.first;
        int y = V[i].first.second;
        int Cnt = 0;

        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (MAP[nx][ny] == 0 && Visit[nx][ny] == 1) Cnt++;
            // �ܼ���, MAP[nx][ny] == 0�� �ƴ�, Visit�� ������ �ܺΰ������� ���ΰ�������
            // üũ�� ����� �Ѵ�.
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
    /* ġ� ������ ���̴� ����.*/
    /* ���ÿ�, �ܺΰ��� + ���ΰ��⸦ ���� ���� Queue�� ��ǥ �����ϱ�. */
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
    /* �ܺΰ���� ���ΰ��⸦ �����ִ� ����. */
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


��ó: https://yabmoons.tistory.com/342 [�幮's Coding World..]