// 1. 자료구조 및 데이터 입력 과정 구현
// 2. dfs 구현
// 3. bipartite graph 판정 -> flag

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; //vertex 수, edge 수
int flag_bg;
vector<int> graph[10001];
int visit[10001];

void dfs(int u, int flag) {

    visit[u] = flag;
    flag = (flag+1)%2; //flag=0이면 1이 되고, flag=1이면 0
    int w;
    for (int i=0; i< graph[u].size(); i++) {
        w = graph[u][i];

        if(visit[w] == -1)
            dfs(w, flag);

        if(visit[u] == visit[w]) //bipartite graph가 아님
            flag_bg = 0;
    }
}
int main() {

    int tc;
    int u, v;
    scanf("%d", &tc);
    for (int i=0; i<tc; i++) {
        scanf("%d %d", &n, &m);
        for (int j=1; j<=n; j++) {
            graph[j].clear();
        }
        for (int j=1; j<=m; j++) {
            scanf("%d %d", &u, &v);
            graph[u].push_back(v); //인접 리스트에 정점v 추가
            graph[v].push_back(u); //pushback은 벡터 끝에서 요소를 추가하는 함수
        }
        for (int j=1; j<=n; j++) {
            sort(graph[j].begin(), graph[j].end());
            visit[j] = -1;
        }

        flag_bg = 1;
        for (int j=1; j<=n; j++) {
            if (visit[j]==-1) //방문하지 않으면 -1, orange 0, green 1
            dfs(j, 0);
        }
        if (flag_bg == 0) printf("NO");
        else printf("YES");
    }
    return 0;
}
