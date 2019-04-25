#include <bits/stdc++.h>
using namespace std;
typedef intmax_t I;

// <fast-io>
#ifdef UNITEST
#define g getchar
#define p putchar
#else
#define g getchar_unlocked
#define p putchar_unlocked
#endif
inline bool iswhite(char c) { return c == ' ' || c == '\n'; }

struct fast_io {
  char eat_blank() {
    char c = g();
    while (iswhite(c)) c = g();
    return c;
  }
  template <typename T>
  typename enable_if<is_integral<T>::value, fast_io>::type operator>>(T &x) {
    x = 0;
    for (char c = eat_blank(); !iswhite(c); c = g()) x = 10 * x + c - '0';
    return *this;
  }
  fast_io &operator>>(char *s) {
    for (char c = eat_blank(); !iswhite(c); c = g()) *(s++) = c;
    *s = '\0';
    return *this;
  }
  fast_io &operator>>(string &s) {
    s = "";
    for (char c = eat_blank(); !iswhite(c); c = g()) s.push_back(c);
    return *this;
  }

  fast_io &operator<<(char c) {
    p(c);
    return *this;
  }
  template <typename T>
  typename enable_if<is_integral<T>::value, fast_io>::type operator<<(T x) {
    if (x == 0)
      p('0');
    else {
      char d[20];
      int32_t i = 0;
      for (; x > 0; x /= 10) d[i++] = '0' + x % 10;
      for (--i; i >= 0; --i) p(d[i]);
    }
    return *this;
  }
  fast_io &operator<<(char *s) {
    while (*s) p(*(s++));
    return *this;
  }
  fast_io &operator<<(const string &s) { return operator<<((char *)s.c_str()); }
} io;
// </fast-io>

int main() {
  io << "Please input: \n1. a positive number \n2. a string \n3. a string\n";
  I x;
  char s[100];
  string z;
  io >> x >> s >> z;
  io << "1. " << x << "\n2. " << s << " (" << strlen(s) << ")\n3. " << z << " ("
     << z.size() << ")\n";

#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
}