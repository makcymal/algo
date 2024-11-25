void euler(vector<hashset<int>> &graph, vi &path, int src = 0) {
  while (!graph[src].empty()) {
    int dst = *graph[src].begin();
    graph[src].erase(dst);
    graph[dst].erase(src);  // only for directed graph
    euler(graph, path, dst);
  }
  path.push_back(src);
}
