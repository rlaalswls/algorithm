// 빙산 dnc
// txt 파일 입력

#include <stdio.h>
#include <stdlib.h>

int n, m;
int graph[10000][10000];
int ngraph[10000][10000];
int cc[10000][10000]; //connected componeent
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//모든 cell이 0이면 1을 리턴, 아니면 0을 리턴
int melt_out() {

    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if(graph[i][j]>0)
                return 0;
        }
    }
    return 1;
}

// x,y에서 이웃한 0 갯수를 세서 빼기
void melt_graph() {

    int nx, ny;
    for (int x=0; x<n; x++) {
        for (int y=0; y<m; y++) {
            if (graph[x][y] == 0) {
                ngraph[x][y] = 0;
                continue;
            }
            
            int cntzero = 0;
            for (int k=0; k<4; k++) {
                nx = x+dx[k];
                ny = y+dy[k];
                if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
                if (graph[nx][ny] == 0)
                    cntzero++;
            }
            ngraph[x][y] = graph[x][y] - cntzero;
            if (ngraph[x][y] < 0)
                ngraph[x][y] = 0;
        }
    }

    for (int x=0; x<n; x++) {
        for (int y=0; y<m; y++) {
            graph[x][y] = ngraph[x][y];
        }
    }
}

void dfs_ccc(int x, int y, int ccflag) {

    int nx, ny;
    cc[x][y] = ccflag;

    for (int i=0; i<4; i++) {
        nx = x+dx[i];
        ny = y+dy[i];

        if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
        if (graph[nx][ny] == 0) continue;
        if (cc[nx][ny] == 0) dfs_ccc(nx, ny, ccflag);
    }

}

int dfs_cc() {

    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cc[i][j] = 0;
        }
    }

    int ccflag = 1;
    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (graph[i][j] == 0)
                continue;
            if (cc[i][j] == 0) {
                dfs_ccc(i, j, ccflag);
                ccflag++;
            }
        }
    }
    return ccflag - 1;
}

int solve() {

    int n_cc;
    int m_year = 0;

    if(melt_out())
        return 0;
    do {
        n_cc = dfs_cc();
        if (n_cc > 1)
            return m_year;
        
        melt_graph();
        if (melt_out())
            return 0;
        
        m_year++;
    } while (n_cc == 1);

    return 0;

}

int main() {

    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("%d", solve());
    return 0;
}
