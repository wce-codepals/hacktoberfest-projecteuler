#include <cstdio>
#include <set>
#include <NTL/lzz_p.h>
#include <NTL/tools.h>
using namespace std;
using namespace NTL;

const int n = 1e7, k = 1e7, N = n + 10, M = 1048576, MOD = 1000000007;

long f[N];
zz_p g[M], tmp[M];

void fwt(zz_p *g, int width, int n) {
    if (n == 1)
        return;
    fwt(g        , 2 * width, n/2);
    fwt(g + width, 2 * width, n/2);

    for (int i = 0; i < n/2; ++i) {
        zz_p u = g[i * width * 2], v = g[i * width * 2 + width];
        tmp[i        ] = u + v;
        tmp[i + n/2] = u - v;
    }

    for (int i = 0; i < n; ++i) {
        g[width * i] = tmp[i];
    }
}

int main() {
    zz_p::init(MOD);

    for (int i = 1; i <= n; ++i)
        f[i] = -1;
    f[1] = 1;

    int cnt = 0;
    for (int i = 2; i <= n; ++i)
        if (f[i] == -1) {
            ++cnt;
            f[i] = cnt == 1 ? 0 : cnt;
            for (int j = i; j <= n; j += i)
                if (f[j] == -1)
                    f[j] = f[i];
        }
    for (int i = 1; i < n; ++i)
        ++g[f[i]];

    printf("%d\n", cnt);
    fwt(g, 1, M);
    zz_p coef = 1/zz_p(M);
    for (int i = 0; i < M; ++i)
        g[i] = power(g[i], k) * coef;
    fwt(g, 1, M);
    printf("ans = %ld\n", rep(g[0]));

    return 0;
}
