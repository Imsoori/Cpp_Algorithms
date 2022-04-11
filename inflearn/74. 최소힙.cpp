#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 74. 최소힙
priority_queue <int> pq;
int main()
{
	int n;

	while (true)
	{
		scanf_s("%d", &n);

		if (n == -1) { break; }
		if (n == 0) {
			if (pq.empty()) { printf("-1\n"); }
			else {
				printf("%d\n", -pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(-n);
		}
	

	}
	return 0;
}