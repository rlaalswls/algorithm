//greedy. knapsack. encoded

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int N, K;
pair<int, int>

int solve() {

    sort(jewel, jewel+N);
    sort(knap, knap+K);

    prior_queue<int> pq;

    int profit = 0; //최대 이익
    int here = 0; //우선순위 큐에 삽입을 시작할 위치

    for (int i=0; i<K; i++) { //가장 가벼운 knapsack부터 순서대로 처리
        for (int j=here; j<N; j++) {
            if (jewel[j].first > knap[i])
                break;
            pq.push(jewel[j].second); //jewel 이익을 저장
            here++;
        }
        if(!pq.empty()) { //가방에 담을 수 있는 jewel 중 가장 pro가 큰 jewel 선택
            profit += pq.top();
            pq.pop();
        }
    }
    return profit;
}

int main() {

    FILE *fp;
    fopen_s(&fp, "input.txt", "r+t");

    int tc, a, b, ans;
    fscanf(fp, "%d", &tc);
    for (int t=0; t < tc; t++) {
        fscanf("%d %d", &N, &K);
        for (int i=0; i<N; i++) {
            fscanf(fp, "%d %d", &a, &b);
            jewel[i] = make_pair(a,b);
        }
        for (int i=0; i<K; i++)
            fscanf(fp, "%d", &knap[i]);
        fscanf(fp, "%d", &ans);

        printf("%d -> %d\n", ans, solve());
    }
    fclose(fp);
    return 0;
}
