int K = 26;

struct Node {
  char ch;
  int par;
  int idx = -1;
  int suff = -1;
  int exit = -1;
  vector<int> forward = vector(K, -1);
  vector<int> automat = vector(K, -1);

  Node(char ch = '^', int par = -1) : ch(ch), par(par) {}
};

struct Trie {
  vector<Node> buf = vector<Node>(1);

  void insert(string &s, int idx) {
    int b = 0;
    for (char ch : s) {
      int chi = ch - 'a';
      if (buf[b].forward[chi] == -1) {
        buf[b].forward[chi] = buf.size();
        buf.emplace_back(ch, b);
      }
      b = buf[b].forward[chi];
    }
    buf[b].idx = idx;
  }

  int search(string &s) {
    int b = 0;
    for (char ch : s) {
      int chi = ch - 'a';
      if (buf[b].forward[chi] == 0) return -1;
      b = buf[b].forward[chi];
    }
    return b;
  }

  int get_suff(int b) {
    if (buf[b].suff == -1) {
      if (b == 0 || buf[b].par == 0) buf[b].suff = 0;
      else
        buf[b].suff = get_transition(get_suff(buf[b].par), buf[b].ch);
    }
    return buf[b].suff;
  }

  int get_exit(int b) {
    if (buf[b].exit == -1) {
      if (b == 0 || buf[b].par == 0) buf[b].exit = 0;
      else if (buf[get_suff(b)].idx >= 0) buf[b].exit = get_suff(b);
      else buf[b].exit = get_exit(get_suff(b));
    }
    return buf[b].exit;
  }

  int get_transition(int b, char ch) {
    int chi = ch - 'a';
    if (buf[b].automat[chi] == -1) {
      if (buf[b].forward[chi] != -1) buf[b].automat[chi] = buf[b].forward[chi];
      else buf[b].automat[chi] = (b == 0 ? 0 : get_transition(get_suff(b), ch));
    }
    return buf[b].automat[chi];
  }
};
