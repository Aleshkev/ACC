#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

// <example-functors>
// Dla każdego functora F musi być spełnione F(x, F.neutral) = x.
struct Add {
  I neutral = 0;
  I operator()(I a, I b) { return a + b; }
};

struct Max {
  I neutral = 0;
  I operator()(I a, I b) { return b > a ? b : a; }
};

// Ma sens tylko jako Update.
struct Set {
  I neutral = -1;  // Lub dowolna nieużywana w drzewie wartość.
  I operator()(I a, I b) { return b != neutral ? b : a; }
};
// </example-functors>

// Zawsze najpierw są określenia dotyczące ustawiania, potem zapytań. Czyli
// drzewo punkt-przedział to drzewo ustawiające coś w punkcie, czytające na
// przedziale. Drzewo +, max dodaje na przedziale, zwraca maksimum na
// przedziale. Taka jest więc kolejność functorów w szablonie i będę tego bronił
// jak wyższości Minecrafta nad Factorio.

// <segment-segment-tree>
// ↙↘ Update
// ↗↖ Combine
// change(i, j, x) – każdy element k na [i, j] zmienia na Update(k, x).
// get(i, j)       → wszystkie elementy na [i, j] połączone przez Combine.
template <typename T, class Update, class Combine>
struct segment_tree {
  Update update;
  Combine combine;
  I n, w;
  vector<T> v, d;
  segment_tree(I n) : n(n), w(1 << __lg(2 * n - 1)) {
    v.assign(2 * w, combine.neutral), d = v;
  }
  segment_tree(const vector<T> &initial) {
    segment_tree(initial.size());
    for (I i = 0; i < n; ++i) v[w + i] = initial[i];
    for (I i = w - 1; i > 0; --i) v[i] = combine(v[2 * i], v[2 * i + 1]);
  }
  void push(I i) {
    for (I k = 0; k < 2; ++k) {
      v[2 * i + k] = update(v[2 * i + k], d[i]);
      d[2 * i + k] = update(d[2 * i + k], d[i]);
    }
    d[i] = update.neutral;
  }
  void change(I qb, I qe, I rb, I re, I i, T x) {
    if (qb > re || qe < rb) return;
    if (qb <= rb && re <= qe) {
      v[i] = update(v[i], x);
      d[i] = update(d[i], x);
    } else {
      push(i);
      change(qb, qe, rb, (rb + re) / 2, 2 * i, x);
      change(qb, qe, (rb + re) / 2 + 1, re, 2 * i + 1, x);
      v[i] = combine(v[2 * i], v[2 * i + 1]);
    }
  }
  T get(I qb, I qe, I rb, I re, I i) {
    if (qb > re || qe < rb) return combine.neutral;
    if (qb <= rb && re <= qe) {
      return v[i];
    } else {
      push(i);
      return combine(get(qb, qe, rb, (rb + re) / 2, 2 * i),
                     get(qb, qe, (rb + re) / 2 + 1, re, 2 * i + 1));
    }
  }
  void change(I i, I j, T x) { change(i, j, 0, w - 1, 1, x); }
  T get(I i, I j) { return get(i, j, 0, w - 1, 1); }
};

template <typename T, class U, class V>
ostream &operator<<(ostream &o, segment_tree<T, U, V> &v) {
  o << "{";
  for (I i = 0; i < v.n; ++i) {
    o << v.get(i, i);
    if (i < v.n - 1) o << ", ";
  }
  o << "}";
  return o;
}
// </segment-segment-tree>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

#if 1
  I n, m;         // Rozwiązanie do Tetris 2D.
  cin >> n >> m;  // Drzewo max, max lub =, max.

  segment_tree<int32_t, Set, Max> tree(n);
  // segment_tree<int32_t, Max, Max> tree(n);

  while (m--) {
    I l, x;
    cin >> l >> x;
    tree.change(x, x + l - 1, tree.get(x, x + l - 1) + 1);
  }
  cout << tree.get(0, n) << '\n';
#else
  I n, m, z;           // Rozwiązanie do zadania Koleje.
  cin >> n >> m >> z;  // Drzewo +, max.

  segment_tree<int32_t, Add, Max> tree(n);

  while (z--) {
    I b, e, p;
    cin >> b >> e >> p;
    --b, --e;
    if (tree.get(b, e - 1) + p <= m) {
      tree.change(b, e - 1, p);
      cout << 'T' << '\n';
    } else {
      cout << 'N' << '\n';
    }
  }
#endif

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
}