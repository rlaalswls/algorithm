// 알파벳 dnc
// txt file로 입력받음


#include <stdio.h>
int R, C; //map size
char graph[20][20];
int visit[26];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int maxd;

void dfs(int x, int y, int dist) {

    int nx, ny;
    visit[graph[x][y] - 'A'] = 1;

    if (dist > maxd)
        maxd = dist;

    for (int i=0; i<4; i++) {
        nx = x+dx[i];
        ny = y+dy[i];

        if(nx<0 || ny<0 || nx>=R || ny>=C) continue;
        if (visit[graph[nx][ny] - 'A'] == 0) {
            dfs(nx, ny, dist+1);
            visit[graph[nx][ny]-'A'] = 0;
        }
    }

}

int main() {

    int tc;
    char c; //carrige 줄바꿈 문자
    scanf("%d %d", &R, &C);
    scanf("%c", &c);
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            scanf("%c", &graph[i][j]);
        }
        scanf("%c", &c); //carrige return
    }
    for (int i=0; i<26; i++) {
        visit[i]=0;
    }
    maxd = 0;
    dfs(0, 0, 1);
    printf("%d", maxd);
    return 0;
}
