#include<bits/stdc++.h>
using namespace std;
//풀이 방법->현재 상태 이후에 벽을 부숴야할지 부쉈어야 했는지 판단 불가->모든 좌표에 대해 각각의 (부숨,안부숨)상태의 최단거리를 유지한다
//->벽 안 뚫고 방문하는 최단거리와 1번 뚫고 방문하는 최단거리 둘다 기록->int dist[1000][1000][2]에다가

//큐에 두가지 상태를 전부 넣어서 돌린다->탐색을 단계별로 하기 때문에 첨 만난게 최단거리 보장 Q{step:1112222333333}이런식으로 드감
//즉 큐에 들어있는것들은 각각의 상태에서 최단거리로 도달한 것들(큐에 있는것들의 step을 봤을때...)

/*bfs를 돌릴때 만난칸이 0 이라면 그냥 cur step+1하면 됨 현재 상태가뭐든 최단거리 +1이 되므로->3차원배열의 1층과 2층에서 각각이 평면적으로 이동
만난칸이1이라면 현재 cur의 상태가 0이면 상태를 1로 바꿔주고 뚫기,상태가 1이면 접근 불가능->벽을 만나면 3차원배열의 1층에서서 2층으로 이동,2층에서 벽 만난다? 못지나감
두 경우 다 step이 각각의 상태에서는 최단거리인게 보장되기 때문에 같은 상태일때 재방문은 불가능
*/

#define X first
#define Y second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

char board[1000][1000];
int dist[1000][1000][2];
// dist[x][y][0] : 벽을 하나도 부수지 않고 (x,y)까지 오는데 걸리는 비용
// dist[x][y][1] : 벽을 하나만 부수고 (x,y)까지 오는데 걸리는 비용, (x,y)가 벽이라서 부수는 경우 포함
//배열을 사용하여 해당 좌표에 특정 상태로 도달하는 데 걸린 최소 거리를 기록합니다.
//두 상태는 서로 독립적이기 때문에, 같은 셀이라도 두 번 방문할 수 있습니다
int n, m;

bool OOB(int x, int y){
  return x < 0 || x >= n || y < 0 || y >= m;
}

int bfs() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      dist[i][j][0] = dist[i][j][1] = -1;//->초기화
  
  dist[0][0][0] = dist[0][0][1] = 1;
  queue<tuple<int, int, int>> q;
  q.push({0,0,0});//시작점 넣기기

  while (!q.empty()) {
    int x, y, broken;
    tie(x, y, broken) = q.front();
    if(x == n-1 && y == m-1) return dist[x][y][broken];//->정답 return
    q.pop();
    int nextdist = dist[x][y][broken] + 1;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(OOB(nx, ny)) continue;
    //현재 칸이 0이면 현재 상태(벽을 부순 상태 or 부수지 않은 상태)를 그대로 유지하면서 이동할 수 있다->벽 안부수는 경우는 이걸로 전부 탐색
      if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
        dist[nx][ny][broken] = nextdist;
        q.push({nx, ny, broken});
      }      
      // (nx, ny)를 부수는 경우==벽을 만나는 경우->state=1의 세상으로 바뀐다
      if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {//이미 부순 상태에서 만나면 불가능
        dist[nx][ny][1] = nextdist;
        q.push({nx, ny, 1});
      }      
      //두 경우 모두 다 각각의 좌표와 "상태"가 같은 상황에서는 최단거리  보장이기 때문에 재 방문 안되는 조건 필요
      //상태가 다르면 같은 칸도 다시 방문 가능 그 상태에서는 그 첫 방문이 최단거리
    }
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> board[i][j];
  cout << bfs();
  return 0;
}


//내 답
/*
//특정 지점까지 최단거리와 특정지점까지 벽 한개를 부쉈을때 최단거리 유지 -> 왜냐면 현재 상태 이후에 벽을 부숴야할지 부쉈어야 했는지 판단 불가이므로


int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
string arr[1002];
int step[1002][1002][2];//0은 벽 안뚫||1은 벽 뚫
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            step[i][j][0]=-1;
            step[i][j][1]=-1;
        }
    }

    queue<pair<int,int>> Q;//일반
    Q.push(make_pair(0,0));
    step[0][0][0]=0;
    while(!Q.empty()){
        pair<int,int> cur=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int x=cur.first+dx[i];
            int y=cur.second+dy[i];
            if(x>=n||x<0||y>=m||y<0)continue;
            if(step[x][y][0]!=-1||arr[x][y]=='1')continue;
            Q.push(make_pair(x,y));
            step[x][y][0]=step[cur.first][cur.second][0]+1;
        }
    }

    Q.push(make_pair(0,0));
    step[0][0][1]=0;
    //특정 지점까지 벽을 한개 이하로 뚫었을때 최소값
    
    //현재 칸이 둘다-1인상태 ->스킵
    //현재 스텝 0=-1,스텝1은 -1아닌 상황 에서 벽만남->스킵
    //현재 스텝 0=-1,스텝1은 -1아닌 상황 에서 그냥->스텝1+1
    //둘다 -1이 아닌상태에서 벽-->뚫기+스텝0
    //둘다 -1이 아닌상태->스텝0+1vs스텝1+1비교하기

    while(!Q.empty()){
        pair<int,int> cur= Q.front();
        //cout<<cur.first<<cur.second<<' ';
        Q.pop();
        if(step[cur.first][cur.second][0]==-1&&step[cur.first][cur.second][1]==-1)continue;
        for(int i=0;i<4;i++){
            int x=cur.first+dx[i];
            int y=cur.second+dy[i];
            if(x>=n||x<0||y>=m||y<0)continue;
            //if(step[x][y][1]!=-1)continue;
            if(arr[x][y]=='1'&&step[cur.first][cur.second][0]==-1)continue;
            int temp=100000000;
            //Q.push({x,y});
            if(arr[x][y]=='1'){
                temp=step[cur.first][cur.second][0]+1;
                
            }
            else if(step[cur.first][cur.second][1]>step[cur.first][cur.second][0]&&step[cur.first][cur.second][0]!=-1) temp=step[cur.first][cur.second][0]+1;
            else temp=step[cur.first][cur.second][1]+1;
    ///////////////bfs순서상 먼저 방문했지만 최단거리 값이 아닐 수 있기에()?? 이미 방문한 칸도 다시 업데이트 해야할 경우 생김 -> 아래처럼 처리
            if(step[x][y][1]==-1){//첫방문
                Q.push({x,y});
                step[x][y][1]=temp;
            }
            else if(step[x][y][1]>temp){//처음 아닐때
                Q.push({x,y});
                step[x][y][1]=temp;
            }
        }
        
    }
    
    if(step[n-1][m-1][1]==-1){
        cout<<-1;
    }
    else cout<<step[n-1][m-1][1]+1;


} */

