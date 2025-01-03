//가장 가까운 두 점 거리 dnc

#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <algorithm>

using namespace std;

#define MIN(a, b) (a<b? a:b)
#define MIN3(a, b, c) (MIN(MIN(a,b), c))

int n;
pair<int, int> p[1001];

int centroid(int s, int e, int m, int delta) {

    int nu = 0;
    pair<int, int> u[10001];

    for (int i=s; i<=e; i++) {
        if (p[m].first - delta < p[i].first && p[i].first < p[m].first + delta)
            u[nu++] = p[i];
    }
    //u를 내림차순 정렬
    sort(u, u+nu, [](const std::pait<int, int>& a, const std::pait<int, int>&b) {
        return a.second > b.second;
        });
    //u를 15개씩 쪼개서 최단 거리 쌍 구하기
    if (nu < 15) return closest_pair_square (0, nu-1, u);

    int dist;
    int mdist = closest_pair_square(0, 14, u);
    for (int i=1; i<nu-15; i++) {
        dist = closet_pair_square(i, i+14, u);
        if (dist < mdist)
            mdist = dist;
    }

    return mdist;

}

int solve(int s, int e) {

    //1. degenerate case
    if (s==e) return 0;
    if (e == s+1) return distance(p[s].first, p[s].second, p[e].first, p[e].second);

    //2. divide
    int m = (s+e) / 2;
    int ldist = solve(s, m);
    int rdist = solve(m, e);

    //3. combine
    int delta = MIN(ldist, rdist);
    int mdist = centroid(s, e, m, delta);

    return MIN3(ldist, rdist, mdist);
}

int main() {

    int x, y;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        p[i] = make_pair(x, y);
    }

    sort(p, p+n);
    printf("%d", solve(0, n-1));
    //for (int j=0; i<n; j++)
    //printf("%d %d", p[i].first, p[i].second);
    return 0;
}
