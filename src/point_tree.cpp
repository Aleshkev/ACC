#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

// Other examples in segment_tree.cpp.
struct Add {
  I neutral = 0;
  I operator()(I a, I b) { return a + b; }
};

// <point-segment-tree>
// ↗↖ Combine
// set(i, x) – ustaw element w i na x.
// get(i)    → element w i, O(1).
// get(i, j) → wartość na [i, j].
template <typename T, class Combine>
struct point_tree {
  Combine combine;
  I n, w;
  vector<I> v;
  point_tree(I n) : n(n), w(1 << __lg(2 * n - 1)) {
    v.assign(2 * w, combine.neutral);
  }
  point_tree(const vector<T> &initial) {
    point_tree(initial.size());
    for (I i = 0; i < n; ++i) v[w + i] = initial[i];
    for (I i = w - 1; i > 0; --i) v[i] = combine(v[2 * i], v[2 * i + 1]);
  }
  void set(I i, T x) {
    for (i += w, v[i] = x, i /= 2; i > 0; i /= 2)
      v[i] = combine(v[2 * i], v[2 * i + 1]);
  }
  T get(I i) { return v[w + i]; }
  T get(I i, I j) {
    if (i == j) return get(i);
    i += w, j += w;
    T c = combine(v[i], v[j]);
    for (; i / 2 != j / 2; i /= 2, j /= 2) {
      if (i % 2 == 0) c = combine(c, v[i + 1]);
      if (j % 2 == 1) c = combine(c, v[j - 1]);
    }
    return c;
  }
};

template <typename T, class U>
ostream &operator<<(ostream &o, point_tree<T, U> &v) {
  o << "{";
  for (I i = 0; i < v.n; ++i) {
    o << v.get(i);
    if (i < v.n - 1) o << ", ";
  }
  o << "}";
  return o;
}
// </point-segment-tree>
