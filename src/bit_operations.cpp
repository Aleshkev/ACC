#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

// <opposite-signs>
// → true iff sgn(x) ≠ sgn(y).
template <typename T>
bool dsgn(T x, T y) {
  return (x ^ y) < 0;
}
// </opposite-signs>

// <next-permutation>
// → następna leksykograficznie maska bitowa.
template <typename T>
T nxtp(T v) {
  auto t = v | (v - 1);
  return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
}
// </next-permutation>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
}