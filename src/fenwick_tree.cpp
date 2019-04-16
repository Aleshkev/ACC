#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;

// <fenwick-tree>
// prefix(i), i < n     → suma na [0, i], dla i < 0 → 0.
// get(i),    i < n     → element w i,    dla i < 0 → 0.
// get(i, j), i ≤ j < n → suma na [i, j], dla j < 0 → 0.
template <typename T>
struct fenwick_tree {
  T lsb(T x) { return x & (-x); }
  I n;
  vector<T> v;
  fenwick_tree(I n) : n(n) { v.assign(n + 1, 0); }
  void add(I i, T x) {
    for (++i; i <= n; i += lsb(i)) v[i] += x;
  }
  T prefix(I i) {
    T c = 0;
    for (++i; i > 0; i -= lsb(i)) c += v[i];
    return c;
  }
  T get(I i) { return prefix(i) - prefix(i - 1); }
  T get(I i, I j) { return prefix(j) - prefix(i - 1); }
};
// </fenwick-tree>
