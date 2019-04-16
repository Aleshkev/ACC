#include <bits/stdc++.h>

using namespace std;

typedef intmax_t I;
const I inf = 1e18;
typedef pair<I, I> II;

int main() {
  I n;
  vector<vector<I>> graph(n);

  {
    // <dfs-iterative>
    vector<I> q = {0};
    vector<bool> visited(n);
    while (!q.empty()) {
      I i = q.back();
      q.pop_back();
      for (I j : graph[i]) {
        if (visited[i]) continue;
        visited[i] = true;
        q.push_back(j);
      }
    }
    // </dfs-iterative>
  }
  {
    // <dfs-recursive>
    vector<bool> visited(n);
    function<void(I)> dfs = [&](I i) {
      for (I j : graph[i]) {
        if (visited[i]) continue;
        visited[i] = true;
        dfs(j);
      }
    };
    dfs(0);
    // </dfs-recursive>
  }
  {
    // <bfs-iterative>
    deque<I> q = {0};
    vector<bool> visited(n);
    while (!q.empty()) {
      I i = q.front();
      q.pop_front();
      for (I j : graph[i]) {
        if (visited[i]) continue;
        visited[i] = true;
        q.push_back(j);
      }
    }
    // </bfs-iterative>
  }
#ifdef UNITEST
  cout.flush();
  system("pause");
#endif
}
