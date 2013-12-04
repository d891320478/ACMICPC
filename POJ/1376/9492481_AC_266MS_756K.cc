#include <iostream>
 #include <queue>
 #include <cmath>
 #include <cstdio>
 using namespace std;

const int INF = 100000000;
 typedef struct node
 {
  int x,y;//记录坐标
  int time;//记录时间
  int d;//记录方向
 }State;
 int n,m;//代表行和列
 State state[52][52];//用于记录搜索的状态
 int map[52][52];//用于记录地图
 State start,end;//记录开始与目标坐标
 int ans;//记录当前最小步数

bool Go(State old,State *now,int ct)
 {
  if (old.d == 0)//向north
  {
   now->x = old.x - ct;
   now->y = old.y;
  }
  else if (old.d == 1)//向east
  {
   now->x = old.x;
   now->y = old.y + ct;
  }
  else if (old.d == 2)//向south
  {
   now->x = old.x + ct;
   now->y = old.y;
  }
  else//向west
  {
   now->x = old.x;
   now->y = old.y - ct;
  }
  now->time = old.time + 1;
  now->d = old.d;
  if (now->x >= 1 && now->y >= 1 && now->x <= n - 1 && now->y <= m - 1 &&
    !map[now->x - 1][now->y - 1] && !map[now->x - 1][now->y] && !map[now->x][now->y - 1]
    && !map[now->x][now->y])
    return true;
  return  false;
 }
 void Dfs()
 {
  int i,j;
  queue<State> q;
  State old,now;
  start.time = 0;
  state[start.x][start.y].time = 0;
  q.push(start);
  while (!q.empty())
  {
   old = q.front();
   q.pop();
 //  cout << "(" << old.x << "," << old.y << "," << old.time << "," << old.d << ") ";
   //穷举4个方向
   for (i = 0; i < 4; i ++)
   {
    switch (i)
    {
    case 0: //先是自己方向
     break;
    case 1://走左边
     old.d = (old.d - 1 + 4) % 4;
     old.time ++;
     break;
    case 2://走右边
     old.d = (old.d + 2) % 4;
     break;
    case 3://走后面
     old.d = (old.d + 1) % 4;
     old.time ++;
    }
    for (j = 1; j <= 3; j ++)
    {
     if (Go(old,&now,j))//判断是否可以走
     {
      if (now.x == end.x && now.y == end.y)
      {
       if (now.time < ans)
        ans = now.time;
      }
      else if (state[now.x][now.y].time > now.time)
      {
       state[now.x][now.y].time = now.time;
       q.push(now);
      }
     }
     else
      break;
    }
   }
  }
  if (ans == INF)
   cout << "-1" << endl;
  else
   cout << ans << endl;
 }
 int main(void)
 {

  int i,j;
  char temp[10];
  while (cin >> n >> m,n || m)
  {
   for (i = 0; i < n; i ++)
    for (j = 0; j < m; j ++)
     cin >> map[i][j];
   cin >> start.x >> start.y >> end.x >> end.y >> temp;
   if (start.x == end.x && start.y == end.y)
   {
    cout << "0" << endl;
    continue;
   }
   if (temp[0] == 'n')//north
    start.d = 0;
   else if (temp[0] == 'e')//east
    start.d = 1;
   else if (temp[0] == 's')//south
    start.d = 2;
   else if (temp[0] == 'w')//west
    start.d = 3;
   for (i = 0; i < n; i ++)
    for (j = 0; j< m; j ++)
     state[i][j].time = INF;
   ans = INF;
   Dfs();
  }
  return 0;
 }