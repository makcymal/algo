vvi floyd_warshall(vvi &g) {
  int n = g.size(); auto d(g);
  for (int i = 0; i < n; ++i) d[i][i] = 0;
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (d[i][k] != NO_EDGE and d[k][j] != NO_EDGE and d[i][j] > d[i][k]+d[k][j])
          d[i][j] = d[j][i] =  d[i][k] + d[k][j];   // = d[j][i] only for undirected
      } } }
  return d;
}