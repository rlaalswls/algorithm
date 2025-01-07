//dfs tree

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

int n; //vertex 수
int cnt; //leaf node 수
vector <int> graph[10001];
int visit[10001];

void dfs(int u, int v, int c) { //u의 부모는 v

    visit[u] = 1; //노드를 방문했으면 1로

    if (u == c)
        return;
    
    if (graph[u].size()==1 && graph[u][0] == v) { // leaf 노드인지 확인
        cnt++;
        return;
    }

    int w;
    for (int i=0; i<graph[u].size(); i++) {
        w = graph[u][i];
        if (visit[w]==0)
            dfs(w, u, c);
    }
}
int main() {
    FILE *fp;
    fopen_s(&fp, "input.txt", "r+t");

    int tc, u, c, ans;

    fscanf(fp, "%d", &tc);
    for (int i=0; i<tc; i++) {
        fscanf(fp, "%d", &n);
        for (int j=0; j<n; j++)
            graph[j].clear();

        fscnaf(fp, "%d", &u); //-1이면 버리기, 부모노드
        for (int j=1; j<n; j++) {
            fscanf(fp, "%d", &u); //0을 읽으면 -> 1번 노드의 부모가 0이다
            graph[i].push_back(u); //연결시켜줌
            graph[u].push_back(j);
        }
        fscanf(fp, "%d", &c);
        fscanf(fp, "%d", &ans);

        for (int j=1; j<n; j++)
            sort(graph[j].begin(), graph[j].end());

        //dfs
        for (int j=0; j<=n; j++)
            visit[i]=0;
        cnt = 0;
        dfs(0, -1, c);//0번 vertex에서 시작 
        printf("%d", cnt);   
    }

    fclose(fp);
    return 0;
}
