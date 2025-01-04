// histogram
// if 100 100 100 100 입력시 작동 x

#include <stdio.h>
#include <stdlib.h>

int n;
int* hist;

#define MIN(a, b) (a<b ? a:b)
#define MAX(a, b) (a>b ? a:b)
#define MAX3(a, b, c) (MAX(MAX(a,b), c))

int centroid(int s, int e, int m) {

    int width, height, marea;

    //초기값은 m만 고려
    width = 1;
    height = hist[m];
    marea = width*height;
    //m을 중심으로 two pointers
    int lptr = m-1;
    int rptr = m+1;

    while (lptr > s || rptr < e) {
        if (lptr <= s || (rptr<e && hist[lptr] <= hist[rptr])) { //rptr 이동
            height = MIN(hist[rptr], height);
            rptr++;
        }
        else { //lptr 이동
            height = MIN(hist[lptr], height);
            lptr--;
        }

        width = rptr - lptr - 1;
        marea = MAX(marea, width*height);
    }

    return marea;
}

int solve(int s, int e) {

    //1. degenerate case
    if (s == e) //histogram이 1개
        return hist[s];
    if (s+1 == e)
        return 2* MIN(hist[s], hist[e]);
    //2. divide
    int m = (s+e) / 2;
    int larea = solve(s, m);
    int rarea = solve(m+1, e);
    //3. combine
    int marea = centroid(s, e, m);
    return MAX3(larea, rarea, marea);
}

int main() {

    FILE* fp;
    fp = fopen("input.txt", "r+t");

    int tc;
    fscanf(fp, "%d", &tc);
    for (int i=0; i<tc; i++) {
        fscanf(fp, "%d", &n);

        hist =  (int*)calloc(n, sizeof(int));
        for (int j=0; j<n; j++) 
            fscanf(fp, "%d", &hist[j]);
        //printf("%d\n", n);
        printf("%d\n", solve(0, n-1));
    }
    fclose(fp);
    return 0;
}
