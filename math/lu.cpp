pair<vii, vii> LU(vii &A) {
  int n = A.size();
  vii L(n, vi(n, 0)), U(n, vi(n, 0));
  for (int i = 0; i < n; ++i) L[i][i] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i <= j) {
        U[i][j] = A[i][j];
        for (int k = 0; k < i; ++k) U[i][j] -= L[i][k] * U[k][j];
      } else {
        L[i][j] = A[i][j];
        for (int k = 0; k < j; ++k) L[i][j] -= L[i][k] * U[k][j];
        L[i][j] /= U[j][j];
      }
    }
  }
  return {L, U};
}
