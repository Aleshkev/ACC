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
// vec(string s, vector<uint32_t> &v) – sprawia, że wektor v jest tablicą haszy.
// sub(vector<uint32_t> v, i, j)      → hasz na [i, j] w tablicy haszy v.
// scalar(string s)                   → hasz całego tekstu.
template <uint32_t prime = 31, class Truncate = Mersenne<>>
struct hash_model {
  Truncate truncate;
  uint32_t encode(char c) { return c - 'a' + 1; }
  uint32_t max_n;
  vector<uint32_t> power;
  hash_model(uint32_t max_n) : max_n(max_n) {
    power.resize(max_n);
    power[0] = 1;
    for (uint32_t i = 1; i < max_n; ++i)
      power[i] = truncate(uint64_t(power[i - 1]) * prime);
  }
  void vec(const string &s, vector<uint32_t> &v) {
    v.resize(s.size());
    if (s.empty()) return;
    v[0] = encode(s[0]);
    for (uint32_t i = 1; i < s.size(); ++i)
      v[i] = truncate(uint64_t(v[i - 1]) * prime + encode(s[i]));
  }
  uint32_t sub(const vector<uint32_t> &v, uint32_t i, uint32_t j) {
    if (i == 0) return v[j];
    return truncate(pow(uint64_t(truncate.guard), 2) + v[j] -
                    uint64_t(v[i - 1]) * power[j - i + 1]);
  }
  uint32_t scalar(const string &s) {
    uint64_t r = 0;
    for (char c : s) r = truncate(r * prime + encode(c));
    return r;
  }
};

// Działa tak samo jak hash_model, ale przyjmowane i zwracane typy są parami.
typedef pair<vector<uint32_t>, vector<uint32_t>> paired;
template <class TruncateA = Implicit, class TruncateB = Mersenne<>,
          uint32_t prime_a = 31, uint32_t prime_b = 37>
struct double_hash_model {
  hash_model<prime_a, TruncateA> a;
  hash_model<prime_b, TruncateB> b;
  double_hash_model(uint32_t max_n) : a(max_n), b(max_n) {}
  void vec(const string &s, paired &v) {
    a.vec(s, v.first), b.vec(s, v.second);
  }
  pair<uint32_t, uint32_t> sub(const paired &v, uint32_t i, uint32_t j) {
    return {a.sub(v.first, i, j), b.sub(v.second, i, j)};
  }
  pair<uint32_t, uint32_t> scalar(const string &s) {
    return {a.scalar(s), b.scalar(s)};
  }
};
// </hash-models>

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
}