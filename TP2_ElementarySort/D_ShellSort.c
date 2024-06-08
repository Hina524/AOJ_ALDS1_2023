#include <stdio.h>

int main(){
  int n, i, j, k, v, x, cnt = 0, m = 0;
  int A[1000000];
  int G[1000000];
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  G[0] = 1;
  for (i = 1; G[i - 1] <= n; i++) {
    m++;
    G[i] = G[i - 1] * 3 + 1;
    if (m > 100) break;
  }
  for (i = 0; i < m / 2; i++) {
    x = G[i];
    G[i] = G[m - i - 1];
    G[m - i - 1] = x;
  }

  for (i = 0; i < m; i++) {
    for (j = G[i]; j < n; j++) {
      v = A[j];
      k = j - G[i];
      while (k >= 0 && A[k] > v) {
        A[k + G[i]] = A[k];
        k = k - G[i];
        cnt++;
      }
      A[k + G[i]] = v;
    }
  }

  printf("\n%d\n", m);
  for (i = 0; i < m; i++) {
    printf("%d ", G[i]);
  }
  printf("\n%d\n", cnt);
  for (i = 0; i < n; i++) {
    printf("%d\n", A[i]);
  }
  return 0;
}
