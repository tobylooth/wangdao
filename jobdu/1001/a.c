#include<stdio.h>

#include<stdlib.h>



int n, m;

int a[15][15];



int main() {

    int i, j, b, cnt;

    while(scanf("%d", &n), n) {

        scanf("%d", &m);

        for(i = 0; i < n; ++i) {

            for(j = 0; j < m; ++j) {

                scanf("%d", &a[i][j]);

            }

        }

        for(i = 0 ; i < n; ++i) {

            for(j = 0; j < m; ++j) {

                scanf("%d", &b);

                a[i][j] +=b;

            }

        }

        cnt = 0;

        for(i = 0; i < n; ++i) {

            for(j = 0; j < m; ++j) {

                if(a[i][j] != 0 ) break;

            }

            if(j == m) ++cnt;

        }

        for(i = 0; i < m; ++i) {

            for(j = 0; j < n; ++j) {

                if(a[j][i] != 0 ) break;

            }

            if(j == n) ++cnt;

        }

        printf("%d\n", cnt);

    }

    return 0;

}

