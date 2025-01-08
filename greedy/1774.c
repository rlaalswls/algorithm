// greedy kruskal 우주신 최소 스패닝 트리

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int n,m,o; //vertex 수, edge 수, mcst의 수
vector <pair<int, int>> vertices;
vector <pair<int, pair<int, int>>> edges;
vector <pair<int, int>> mcst;

//union-find 선언해줘야함. 알고리즘 수업 pdf 참고

void kruskal() {
    priority_queue <pair<int, pair<int, int>>, vetor<pair<int, pair<int, int>>>, greater<>>> pq;
    UnionFind uf(n);

    //edge를 pq에 저장
    for (int i=0; i<m; i++) { // 이미 mcst에 포함되어있는지 확인
        for (int j=0; j<o; j++) {
            if (edges[i].second.first == mcst[j].first && edges[i].second.second == mcst[j].second)
                continue;
            if (edges[i].second.first == mcst[j].second && edges[i].second.second == mcst[j].first)
                continue;
        }
        pq.push(edges[i]);
    }
    int u,v,w;
    while(!pq.empty() && mcst.size() < n-1) {
        w = pq.top().first;
        u = pq.top().second.first;
        v = pq.top().second.second;
        pq.pop();

        //cycle 발생하지 않으면
        if (uf.find(u) != uf.find(v)) {
            mcst.push_back(make_pair(u, v));
            dist += w;
            uf.unite(u,v);
        }
    }
    if (mcst.size() < n-1) {
        printf("No mcst\n");
        return;
    }

    for (int i=0; i<mcst.size(); i++)
        printf("%d %d\n", mcst[i].first, mcst[i].second);
    printf("%d", dist);
}

int main() {

    FILE *fp;
    fopen_s(&fp, "input.txt", "r+t");

    int tc, x, y, w;
    fscanf(fp, "%d", &tc);
    for (int t=0; t < tc; t++) {
        fscanf("%d %d", &n, &o);
        for (int i=0; i<n; i++) {
            fscanf(fp, "%d %d", &x, &y);
            vertices.push_back(make_pair(u,v));
        }
        //edge 구축 - complete graph
        m=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i==j)
                    continue;
                w = abs(vertices[i].first - vertices[j].first) + abs(vertices[i].second - vertices[j].second)
                edges.push_back(make_pair(w, make_pair(i,j)));
                m++;
            }
        }

        for (int i=0; i<m; i++) {
            fscnaf(fp, "%d %d", &x, &y);
            mcst.push_back(make_pair(x,y));
        }

    }
    fclose(fp);
    return 0;
}
