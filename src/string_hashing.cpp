#include <bits/stdc++.h>
using namespace std;

// <mod-functors>
template <uint32_t prime>
struct Const {
  uint32_t guard = prime;
  uint32_t operator()(uint64_t x) { return x >= prime ? x % prime : x; }
};

struct Implicit {
  uint32_t guard = 0;
  uint32_t operator()(uint64_t x) { return x; }
};

template <uint32_t K = 31>
struct Mersenne {
  uint32_t guard = (1 << K) - 1;
  uint32_t operator()(uint64_t x) {
    x = (x >> K) + (x & guard);
    x = (x >> K) + (x & guard);
    return x == guard ? 0 : x;
  }
};
// </mod-functors>

// <hash-models>
// vec(s)       → tablica haszy v, używa makra encode() na każdym elemencie.
// sub(v, i, j) → hasz na [i, j] w tablicy haszy v.
// scalar(s)    → hasz całego tekstu.
#define encode(c) (c - 'a' + 1)
template <uint32_t prime = 31, class Truncate = Mersenne<>>
struct hash_model {
  Truncate truncate;
  uint32_t max_n;
  vector<uint32_t> power;
  hash_model(uint32_t max_n) : max_n(max_n) {
    power.resize(max_n);
    power[0] = 1;
    for (uint32_t i = 1; i < max_n; ++i)
      power[i] = truncate(uint64_t(power[i - 1]) * prime);
  }
  template <typename T>
  vector<uint32_t> vec(const T &s) {
    vector<uint32_t> v(s.size());
    for (uint32_t i = 0; i < s.size(); ++i)
      v[i] = truncate(uint64_t(i > 0 ? v[i - 1] : 0) * prime + encode(s[i]));
    return v;
  }
  uint32_t sub(const vector<uint32_t> &v, uint32_t i, uint32_t j) {
    if (i == 0) return v[j];
    return truncate(uint64_t(truncate.guard) * truncate.guard + v[j] -
                    uint64_t(v[i - 1]) * power[j - i + 1]);
  }
  template <typename T>
  uint32_t scalar(const T &s) {
    uint64_t r = 0;
    for (char c : s) r = truncate(r * prime + encode(c));
    return r;
  }
};

typedef pair<vector<uint32_t>, vector<uint32_t>> paired;
template <class TruncateA = Implicit, class TruncateB = Mersenne<>,
          uint32_t prime_a = 31, uint32_t prime_b = 37>
struct double_hash_model {
  hash_model<prime_a, TruncateA> a;
  hash_model<prime_b, TruncateB> b;
  double_hash_model(uint32_t max_n) : a(max_n), b(max_n) {}
  template <typename T>
  paired vec(const T &s) {
    return {a.vec(s), b.vec(s)};
  }
  pair<uint32_t, uint32_t> sub(const paired &v, uint32_t i, uint32_t j) {
    return {a.sub(v.first, i, j), b.sub(v.second, i, j)};
  }
  template <typename T>
  pair<uint32_t, uint32_t> scalar(const T &s) {
    return {a.scalar(s), b.scalar(s)};
  }
};
// </hash-models>

template <typename T>
ostream &operator<<(ostream &o, const vector<T> &v) {
  o << "[";
  for (auto i = v.begin(); i != v.end(); ++i) {
    o << *i;
    if (i != prev(v.end())) o << ", ";
  }
  o << "]";
  return o;
}
template <typename T, typename U>
ostream &operator<<(ostream &o, const pair<T, U> &v) {
  o << "(" << v.first << ", " << v.second << ")";
  return o;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  string s = "czytozrozumialetakczynie";
  hash_model<> simple(s.size());
  auto v_simple = simple.vec(s);
  assert(simple.scalar(s) == v_simple.back());
  double_hash_model<> complex(s.size());
  auto v_complex = complex.vec(s);
  assert(complex.scalar(s) ==
         make_pair(v_complex.first.back(), v_complex.second.back()));

  cout << s << endl;
  cout << v_simple << endl;
  cout << v_complex << endl;

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
}