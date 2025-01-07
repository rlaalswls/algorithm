//bfs DSLR 연산

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <queue>

using namespace std;

//bfs 구현 함수
string solve(int a, int b) {

    int currv, nextv;
    string currs, nexts;

    queue<pair<int, string>> myq;

    myq.push(make_pair(a, ""));

    while (!myq.empty()) {
        currv = myq.front().first;
        currs = myq.front().second;
        myq.pop();

        //D
        nextv = (currv*2)%10000;
        nexts = currs + "D";
        if (nextv == b)
            return nexts;
        myq.push(make_pair(nextv, nexts));

        //S
        nextv = (currv-1 < 0) ? 9999 : currv-1;
        nexts = currs + "S";
        if (nextv == b)
            return nexts;
        myq.push(make_pair(nextv, nexts));

        //L
        nextv = (currv%1000)*10 + (currv/100);
        nexts = currs + "L";
        if (nextv == b)
            return nexts;
        myq.push(make_pair(nextv, nexts));

        //R
        nextv = (currv%10) * 1000 + (currv/10);
        nexts = currs + "R";
        if (nextv == b)
            return nexts;
        myq.push(make_pair(nextv, nexts));

    }
    return NULL;
}
int main() {
    FILE *fp;
    fopen(&fp, "input.txt", "r+t")

    int tc;
    int a, b;
    char ans[1000];

    scanf(fp, "%d", &tc);
    for (int i=0; i<tc; i++) {
        scanf(fp, "%d %d", &a, &b);
        scnaf(fp, "%c", &c);
        gets(ans, 1000, fp);
        printf("%s", ans);
        printf("%\n", solve(a, b).c_str());
    }
    fclose(fp);
    return 0;
}
