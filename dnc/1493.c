//박스를 채울 수 있는 최소 큐브 수 dnc

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cnt;
int n; // cube 개수
int A[20]; // cube 크기
int B[20]; // cube 개수

int min3(int a, int b, int c) {

    if (a<b && a<c)
        return a;
    if (b<c)
        return b;
    return c;

}

void solve (int length, int width, int height) {

    //1. degenerate case
    if (length == 0 || width == 0 || height == 0)
        return;
    //2. divide
    int mind = min3(length, width, height);
    int scube = -1; //scube가 비었다는 의미

    for (int i=n-1; i>=0; i--) {
        if (B[i]==0)
            continue;
        if (A[i] > mind)
            continue;
        scube = i;
        break;
    }

    if (scube < 0) {
        cnt = -1;
        return;
    }

    int cube = A[scube];
    cnt++;
    B[scube]--;

    solve(length-cube, width, height);
    solve(length, width, height-cube);
    solve(length, width-cube, height);

}
int main() {

    int length, width, height;
    int a, b;

    scanf("%d %d %d", &length, &width, &height);
    scanf("%d", &n);
    for (int j=0; j<n; j++) {
        scanf("%d %d", &a, &b);
        A[j] = pow(2, a);
        B[j] = b;
    }

    cnt = 0;
    solve(length, width, height);
    printf("%d\n", cnt);
    
    return 0;
}
