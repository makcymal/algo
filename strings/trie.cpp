static char buf[450 << 20];  // 450mb
void *operator new(size_t s) {
  static size_t i = sizeof buf;
  return (void *)&buf[i -= s];
}
void operator delete(void *) {}

const int K = 26;
struct Node {
  Node* suc[K] = {0};
  int cnt = 0;
};
struct Trie {
  Node root;

  Trie() = default;
  void insert(string& s) {
    auto node = &root;
    for (char c : s) {
      if (node->suc[c - 'a'] == 0) node->suc[c - 'a'] = new Node;
      node = node->suc[c - 'a'];
    }
    node->cnt++;
  }
  int count(string& s) {
    auto node = search(s);
    return node == 0 ? 0 : node->cnt;
  }
  Node* search(string& s) {
    auto node = &root;
    for (char c : s) {
      if (node->suc[c - 'a'] == 0) return 0;
      node = node->suc[c - 'a'];
    }
    return node;
  }
};
