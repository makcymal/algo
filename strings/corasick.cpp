static char buf[450 << 20];  // 450mb
void *operator new(size_t s) {
  static size_t i = sizeof buf;
  return (void *)&buf[i -= s];
}
void operator delete(void *) {}

const int K = 26;
auto al = [](char c) { return c - 'a'; };
struct Node {
  Node *go[K] = {0}, *link = 0, *par = 0;
  int ord, cnt = 0;
  Node(int ord, Node *par) : ord(ord), par(par) {}
};
struct PrefixTree {
  Node * root = new Node(-1, 0);

  PrefixTree() = default;
  void insert(string &s) {
    auto node = root;
    for (char c : s) {
      if (node->go[al(c)] == 0) node->go[al(c)] = new Node(al(c), node);
      node = node->go[al(c)];
    }
    node->cnt++;
  }
  Node *search(string &s) {
    auto node = root;
    for (char c : s) {
      if (node->go[al(c)] == 0) return 0;
      node = node->go[al(c)];
    }
    return node;
  }
  int count(string &s) {
    auto node = search(s);
    return node == 0 ? 0 : node->cnt;
  }
  Node *link(Node *node) {
    if (node->link == 0) {
      if (node == root or node->par == root) node->link = root;
      else node->link = go(link(node->par), node->ord); // node->ord is subject to change
    }
    return node->link;
  }
  Node *go(Node *node, char c) {
    int ord = al(c);
    if (node->go[ord] == 0) {
      if (node == root) node->go[ord] = node;
      else node->go[ord] = go(link(node), ord);
    }
    return node->go[ord];
  }
};
