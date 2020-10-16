#include "fmt/format.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>
#include <NTL/ZZ.h>
using namespace std;
using namespace fmt;
using namespace NTL;

namespace PE566 {
    const int n = 53, M = 4000000, Q = 3;
    const double eps = 1e-9;

    double loc[M];
    int mx_top = 0, m;
    int pa[M], pb[M], pc[M], sum[M], aux[M], inv[M], id[M];
    int wa[M], wb[M], wc[M];
    set<double> seps[Q];
    double ws[Q];

    int find(int k, double x) {
        int ret = 0;
        for (auto y : seps[k]) {
            if (abs(y - x) < eps) {
                return ret;
            }
            ++ret;
        }
        return -1;
    }

    void extend(int k, double x) {
        while (true) {
            auto it = seps[k].lower_bound(x - eps);
            if (it != seps[k].end() && abs(x - *it) < eps) {
                return;
            }
            seps[k].insert(x);
            double t = ws[k];
            if (x < t - eps) {
                x = 1 - x;
            } else {
                x = x - t;
            }
            k = (k + 1) % Q;
        }
    }

    tuple<int, int, int> get_perms(double a, double b, double c) {
        ws[0] = a, ws[1] = b, ws[2] = c;
        for (int i = 0; i < Q; ++i) {
            seps[i].clear();
        }
        for (int i = 0; i < Q; ++i) {
            extend(i, 1);
        }

        int A = find(0, ws[0]);
        int B = find(1, ws[1]);
        int C = find(2, ws[2]);

       //for (int i = 0; i < 3; ++i) {
       //    for (auto x : seps[i]) {
       //        print("{} ", x);
       //    }
       //    print("\n");
       //}

        m = seps[0].size() - 1;
        if (m * 2 >= M) {
            print("{}\n", m);
            assert(m < M);
        }
       //print("(A, B, C) = ({}, {}, {}), ms = ({}, {}, {})\n", A, B, C, seps[0].size(), seps[1].size(), seps[2].size());

       //for (int i = 0; i <= C; ++i) {
       //    print("{} ", loc[i]);
       //}
       //print("\n");
       //for (int i = A + B; i <= A + B + C; ++i) {
       //    print("{} ", loc[i] - loc[A + B]);
       //}
       //print("\n");
       //print("A = {}, B = {}, C = {}, idx = {} {} {}, tb = {}, tc = {}\n", loc[A] - a, loc[B] - a - b, loc[C] - a - b - c, A, B, C, tb, tc);
        return {A, B, C};
    }

    void add(int *a, int *b, int *c) {
        for (int i = 0; i < m; ++i) {
            aux[i] = b[a[i]];
        }
        for (int i = 0; i < m; ++i) {
            c[i] = aux[i];
        }
    }

    bool visited[M];
    int vs[M * 2], vr[M];
    long TIME = 0;

    int next[M];

    void kmp_init(int n, int *S) {
        next[0] = -1;
        for (int i = 1, j = -1; i < n; ++i) {
            for (; j > -2 && S[i] != S[j + 1]; j = j == -1 ? -2 : next[j]);
            next[i] = ++j;
        }
    }

    tuple<int, int> match(int n) {
        kmp_init(n, vr);
        for (int i = 0; i < n; ++i) {
            vs[i + n] = vs[i];
        }
       //print("next: ");
       //for (int i = 0; i < n; ++i) {
       //    print("{} ", next[i]);
       //}
       //print("\n");

        for (int i = 0, j = -1; i < n * 2; ++i) {
            for (; j > -2 && vs[i] != vr[j + 1]; j = j == -1 ? -2 : next[j]);
            ++j;
            if (j == n - 1) {
               //print("i = {}, j = {}, nx = {}\n", i, j, next[n - 1]);
                int period = n - next[n - 1] - 1;
                if (n % period != 0) period = n;
                return {period, (1 + i % period) % period};
            }
        }
        return {0, 0};
    }

    long solve(int *S, int *R) {//start = S, each = R
        for (int i = 0; i < m; ++i) {
            visited[i] = false;
            inv[S[i]] = i;
        }

        long ret = 0, MOD = 1;
        for (int i = 0; i < m; ++i) {
            if (visited[i]) continue;
           //print("--- loop ---\n");
            int loop = 0;
            for (int j = i; !visited[j]; j = R[j]) {
               //print("{} ", j);
                visited[j] = true;
                vs[loop] = S[j] % 2;
                vr[loop] = j % 2;
                ++loop;
            }
           //print("\n");
            TIME += loop;

            int mod, rem;
            tie(mod, rem) = match(loop);
           //for (int i = 0; i < loop; ++i) {
           //    print("{} {}\n", vs[i], vr[i]);
           //}
           //print("mod = {}, rem = {}\n", mod, rem);

            if (mod == 0) {
                return 1e18;
            }
            long g = GCD(MOD, mod);
            if (ret % g != rem % g) {
                return 1e18;
            }
           //print("mod = {}, rem = {}\n", mod, rem);
            MOD/= g, mod/= g;
            long t = InvMod(MOD, mod) * ((rem - ret)/g % mod + mod) % mod;
           //print("t = {}\n", t);
            assert((t * MOD * g + ret) % (mod * g) == rem);
            ret = t * MOD * g + ret;
            MOD = MOD * mod * g;
           //print("MOD = {}, REM = {}\n", MOD, ret);

           //print("loop: {}\n", n);
        }
        return ret;
    }

    long count(long a, long b, long c) {
       //print("a = {} b = {} c = {}\n", a, b, c);
        m *= 2, a *= 2, b *= 2, c *= 2;
        for (int i = 0; i < m; ++i) {
            pa[i] = i >= a ? (i - a) : (m - 1 - i);
            pb[i] = i >= b ? (i - b) : (m - 1 - i);
            pc[i] = i >= c ? (i - c) : (m - 1 - i);
            id[i] = i;
        }
        add(id, pa, wa);
        add(wa, pb, wb);
        add(wb, pc, wc);

       //for (int i = 0; i < m; ++i) {
       //    print("{} ", pa[i]);
       //}
       //print("\n");
       //for (int i = 0; i < m; ++i) {
       //    print("{} ", pb[i]);
       //}
       //print("\n");
       //for (int i = 0; i < m; ++i) {
       //    print("{} ", pc[i]);
       //}
       //print("\n");

        long ans = 1e18;
        ans = min(ans, solve(wa, wc) * 3 + 1);
        ans = min(ans, solve(wb, wc) * 3 + 2);
        ans = min(ans, solve(wc, wc) * 3 + 3);

       //add(id, id, sum);
       //for (int i = 0; ; ++i) {
       //    if (i % 3 == 0) {
       //        add(sum, pa, sum);
       //    } else if (i % 3 == 1) {
       //        add(sum, pb, sum);
       //    } else {
       //        add(sum, pc, sum);
       //    }

       //    bool ok = true;
       //    for (int t = 0; t < m; ++t) {
       //        if (sum[t] % 2 != t % 2) {
       //            ok = false;
       //            break;
       //        }
       //    }
       //    if (ok) {
       //        print("bf = {}, ans = {}\n", i + 1, ans);
       //        assert(i + 1 == ans);
       //        break;
       //    }
       //}

        return ans;
    }

    void main() {
        long ans = 0;

       //int A, B, C;
       //tie(A, B, C) = get_perms(1./12, 1./13, 1./sqrt(14));
       //print("m = {}\n", m);
       //print("T = {}\n", count(A, B, C));

        for (int a = 9; a <= n; ++a) {
            for (int b = a + 1; b <= n; ++b) {
                for (int c = b + 1; c <= n; ++c) {
                    int A, B, C;
                    tie(A, B, C) = get_perms(1./a, 1./b, 1./sqrt(c));
                    ans += count(A, B, C);
                    if (m > mx_top) {
                        mx_top = m;
                        print("max m = {}\n", mx_top);
                    }
                }
            }
        }
        print("ans = {}, TIME = {}\n", ans, TIME);
    }
}

int main() {
    PE566::main();
    return 0;
}
