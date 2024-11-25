#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pair<int, int>>;
using vvi = vector<vector<int>>;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define NL '\n'
#define all(c) (c).begin(), (c).end()

#define hashset unordered_set
#define hashmap unordered_map


void submit(istream &input, ostream &output) {
  int a, b;
  input >> a >> b;
  output << a + b;
}


void test(string filename) {
  enum Status { rd_input, rd_expected, idle };
  auto status = idle;

  ifstream testfile(filename);
  stringstream input, output;
  string line, expected;

  while (getline(testfile, line)) {
    if (line.empty() or line[0] == '#') continue;
    if (line.substr(0, 6) == "\\input") {
      input = stringstream();
      output = stringstream();
      status = rd_input;
    } else if (line.substr(0, 9) == "\\expected") {
      expected.clear();
      status = rd_expected;
    } else if (line.substr(0, 4) == "\\end") {
      status = idle;
      submit(input, output);

      if (output.str() != expected) {
        cout << "--INPUT--\n" << input.str() << NL;
        cout << "--EXPECTED--\n" << expected << NL;
        cout << "--OBSERVED--\n" << output.str() << NL;
        return;
      }
    } else if (status == rd_input) {
      input << line << NL;
    } else if (status == rd_expected) {
      expected += line + NL;
    }
  }
  cout << "All tests are passed!" << NL;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  if (getenv("BACKBONE_LAPTOP")) test("testcases.conf");
  else submit(cin, cout);

  return 0;
}
