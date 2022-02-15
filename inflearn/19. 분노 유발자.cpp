#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;


int main() {

  int n, cnt = 0, height;
  bool flag = true;
  vector <int> seat;
  scanf("%d", &n);


  for (int i = 0; i < n; i++)
  {
     scanf("%d", &height);
     seat.push_back(height);
  }

  int cmp;

  for (int i = 0; i < seat.size() - 1; i++)
  {
     cmp = seat[i];

     for (int j = i + 1; j < seat.size(); j++)
     {
        if (cmp > seat[j])
        {
           flag = true;
        }
        else {
           flag = false;
           break;
        }
     }

     if (flag)
     {
        cnt++;
     }
  }

  cout << cnt << "\n";
  return 0;
}