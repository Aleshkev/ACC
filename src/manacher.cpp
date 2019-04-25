#include <bits/stdc++.h>
using namespace std;

// <manacher>
// odd_palindromes(s)  → d, d[i] = max. dł. palindromu o środku w i.
// even_palindromes(s) → d, d[i] = max. dł. palindromu o środku między i - 1, i.
//   Zatem zawsze d[0] = 0.
template <int8_t w, typename T>
vector<int32_t> manacher(T s) {
  int32_t n = s.size();
  vector<int32_t> d(n);
  for (int32_t i = 0, l = 0, r = -1; i < n; ++i) {
    auto k = (i > r ? 1 - w : min(d[l + r - i + w], r - i + 1));
    while (i - k - w >= 0 && i + k < n && s[i - k - w] == s[i + k]) ++k;
    d[i] = k--;
    if (i + k > r) l = i - k - w, r = i + k;
  }
  return d;
}
#define odd_palindromes manacher<0>
#define even_palindromes manacher<1>
// </manacher>

int main() {
#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
}