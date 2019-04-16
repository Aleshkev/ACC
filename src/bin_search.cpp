#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;

// <f-search>
// f(i) ⇒ wynik jest w miejscu ≥ i.
// Przeszukuje zakres [Lo, Hi), zwraca Hi jeżeli f(Hi - 1) ≡ 1.
// f(i) = {t[i] < x} – lower_bound.
// f(i) = {t[i] ≤ x} – upper_bound.
// f(i) = {g(i + 1) > g(i)} – maksimum ściśle bitonicznej funkcji; jeżeli g(Hi)
//   nie istnieje, można użyć Hi ↦ Hi - 1. (Odwrotny znak dla minimum.)
I f_search(I lo, I hi, function<bool(I)> f) {
  while (lo < hi) {
    I mid = (lo + hi) / 2;
    if (f(mid))
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo;
}
// </f-search>

int main() {
  {
    vector<I> t = {0, 0, 1, 3, 3, 3, 4, 8, 9, 9};
    I n = t.size();
    for (I x : vector<I>{-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}) {
      assert(lower_bound(t.begin(), t.end(), x) - t.begin() ==
             f_search(0, n, [&](I i) { return t[i] < x; }));
      assert(upper_bound(t.begin(), t.end(), x) - t.begin() ==
             f_search(0, n, [&](I i) { return t[i] <= x; }));
    }
  }

  for (auto t : vector<vector<I>>{{0, 1, 4, 16, 17, 25, 24, 23},  //
                                  {0, 1, 2},
                                  {2, 1, 0},
                                  {0},
                                  {0, 1, 2, 1, 0}}) {
    assert(max_element(t.begin(), t.end()) - t.begin() ==
           f_search(0, t.size() - 1, [&](I i) { return t[i + 1] > t[i]; }));
  }
  for (auto t : vector<vector<I>>{{10, 8, 4, 1, 3, 4},  //
                                  {0, 1, 2},
                                  {2, 1, 0},
                                  {0}}) {
    assert(min_element(t.begin(), t.end()) - t.begin() ==
           f_search(0, t.size() - 1, [&](I i) { return t[i + 1] < t[i]; }));
  }

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
}
