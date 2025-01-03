//map 3^n, 0, 1, -1로 채워진 종이맵 개수 dnc

#include <stdio.h>
#include <stdlib.h>

int n;
int **arr;
int cnt[3];

// 범위 체크 수정: 'xe'와 'ye'도 포함되도록 수정
int is_same(int xs, int xe, int ys, int ye) {
    int flag = arr[xs][ys];
    for (int i = xs; i <= xe; i++) {  // <= 사용
        for (int j = ys; j <= ye; j++) {  // <= 사용
            if (arr[i][j] != flag)
                return 0; // not same
        }
    }
    return 1; // same
}

void solve(int xs, int xe, int ys, int ye) {
    // 1. degenerate case
    if (xs == xe && ys == ye) {
        if (arr[xs][ys] == -1)
            cnt[0]++;
        else if (arr[xs][ys] == 0)
            cnt[1]++;
        else if (arr[xs][ys] == 1)
            cnt[2]++;
        return;
    }

    // all same cells
    if (is_same(xs, xe, ys, ye)) {
        if (arr[xs][ys] == -1)
            cnt[0]++;
        else if (arr[xs][ys] == 0)
            cnt[1]++;
        else if (arr[xs][ys] == 1)
            cnt[2]++;
        return;
    }

    // 2. divide
    int xm1 = xs + (xe - xs) / 3;
    int xm2 = xs + 2 * (xe - xs) / 3;
    int ym1 = ys + (ye - ys) / 3;
    int ym2 = ys + 2 * (ye - ys) / 3;

    solve(xs, xm1, ys, ym1);
    solve(xm1 + 1, xm2, ys, ym1);
    solve(xm2 + 1, xe, ys, ym1);
    solve(xs, xm1, ym1 + 1, ym2);
    solve(xm1 + 1, xm2, ym1 + 1, ym2);
    solve(xm2 + 1, xe, ym1 + 1, ym2);
    solve(xs, xm1, ym2 + 1, ye);
    solve(xm1 + 1, xm2, ym2 + 1, ye);
    solve(xm2 + 1, xe, ym2 + 1, ye);
}

int main(void) {
    int tc;
    scanf("%d", &tc);
    
    for (int i = 0; i < tc; i++) {
        scanf("%d", &n);
        arr = (int **)calloc(n, sizeof(int *));
        for (int j = 0; j < n; j++)
            arr[j] = (int *)calloc(n, sizeof(int));

        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                scanf("%d", &arr[j][k]);

        cnt[0] = cnt[1] = cnt[2] = 0;
        solve(0, n - 1, 0, n - 1);
        printf("[%d, %d, %d]\n", cnt[0], cnt[1], cnt[2]);

        for (int j = 0; j < n; j++)
            free(arr[j]);
        free(arr);
    }

    return 0;
}
