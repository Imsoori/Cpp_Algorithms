#include<iostream>
#include<vector>
#include <queue>

using namespace std;

int h,w,q;
int image[130][130];
vector <pair<pair<int,int>,int>> vectorQ;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

void bfs(int y, int x, int before, int after)
{
	int checked[130][130]={0,};
	queue <pair<int,int>> q;
	vector <pair<int,int>> v;
	q.push({y,x});
	v.push_back({y,x});
	checked[y][x]=1;


	while(!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for(int i=0; i<4; i++)
		{
			int nx = cx+ dx[i];
			int ny = cy+ dy[i];

			if(nx<0 || ny<0 || ny>h-1 || nx>w-1) continue;

			if(image[ny][nx]== before && !checked[ny][nx])
			{
				q.push({ny,nx});
				checked[ny][nx]=1;
				v.push_back({ny,nx});
			}
		}
	}

	for(int i=0; i<v.size(); i++)
	{
		image[v[i].first][v[i].second]=after;
	}
}



int main(int argc, char** argv)
{
	cin>>h>>w;

	for(int i=0; i<h; i++)
		for(int j=0; j<w; j++)
		{
			cin>>image[i][j];
		}

	cin>>q;

	int x,y,value;

	for(int i=0; i<q; i++)
	{
		cin>>y>>x>>value;
		vectorQ.push_back({{y-1,x-1},value});
	}

	int vx,vy,vvalue;
	for(int i=0; i<vectorQ.size(); i++)
	{
		vy = vectorQ[i].first.first;
		vx = vectorQ[i].first.second;
		vvalue = vectorQ[i].second;
		bfs(vy,vx,image[vy][vx],vvalue);

	}

	for(int i=0; i<h; i++)
	{
		for(int j=0; j<w; j++)
		{
			cout<<image[i][j]<<" ";
		}
		cout<<"\n";
	}
	

	return 0;
}