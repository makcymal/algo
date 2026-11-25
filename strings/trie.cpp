const int K = 26;
struct Node {
  char ch = '^';
  int par = -1, cnt = 0, suff = -1, exit = -1;
  vi forward = vi(K, -1), automat = vi(K, -1);
  Node(char ch, int par) : ch(ch), par(par) {}
};
struct Trie {
  vector<Node> buf = vector<Node>(1);
  void insert(string &s) {
    int b = 0;
    for (char ch : s) {
      if (buf[b].forward[ch-'a'] == -1) {
        buf[b].forward[ch-'a'] = buf.size(); buf.emplace_back(ch, b);
      }
      b = buf[b].forward[ch-'a'];
    } buf[b].cnt++;
  }
  int count(string &s) {
    int b = search(s);
    return b == -1 ? 0 : buf[b].cnt;
  }
  int search(string &s) {
    int b = 0;
    for (char ch : s) {
      if (buf[b].forward[ch-'a'] == -1) return -1;
      b = buf[b].forward[ch-'a'];
    } return b;
  }
  int get_suff(int b) {
    if (buf[b].suff == -1) {
      if (b == 0 || buf[b].par == 0) buf[b].suff = 0;
      else buf[b].suff = get_transition(get_suff(buf[b].par), buf[b].ch);
    } return buf[b].suff;
  }
  int get_exit(int b) {
    if (buf[b].exit == -1) {
      if (b == 0 || buf[b].par == 0) buf[b].exit = 0;
      else if (buf[get_suff(b)].cnt > 0) buf[b].exit = get_suff(b);
      else buf[b].exit = get_exit(get_suff(b));
    } return buf[b].exit;
  }
  int get_transition(int b, char ch) {
    if (buf[b].automat[ch-'a'] == -1) {
      if (buf[b].forward[ch-'a'] != -1) buf[b].automat[ch-'a']= buf[b].forward[ch-'a'];
      else buf[b].automat[ch-'a'] = (b == 0 ? 0 : get_transition(get_suff(b), ch));
    } return buf[b].automat[ch-'a'];
  }
};