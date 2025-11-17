void rtrim(string &s) {
  int i = s.size() - 1;
  for (; i >= 0; i--) {
    if (!isspace(s[i]))
      break;
  }
  s.resize(i + 1);
}

void test(string filename) {
  enum Status { rd_input, rd_expected, idle };
  auto status = idle;

  ifstream testfile(filename);
  stringstream input, expected, observed;
  string line;
  int n_tests;
  bool prev_failed = false;

  while (getline(testfile, line)) {
    rtrim(line);
    if (line.empty() or line[0] == ';')
      continue;
    if (line == "\\input") {
      status = rd_input;
      input = stringstream();
      expected = stringstream();
      observed = stringstream();
    } else if (line == "\\expected") {
      status = rd_expected;
    } else if (line == "\\end") {
      status = idle;
      submit(input, observed);
      auto observed_str = observed.str();
      rtrim(observed_str);

      if (prev_failed) cout << endl;
      if (expected.str() == observed_str) {
        cout << "Test #" << n_tests << " passed" << endl;
        prev_failed = false;
      } else {
        cout << endl << "Test #" << n_tests << " failed" << endl;
        cout << "--INPUT--\n" << input.str() << endl;
        cout << "--EXPECTED--\n" << expected.str() << endl;
        cout << "--OBSERVED--\n" << observed_str << endl;
        prev_failed = true;
      }
      n_tests++;
    } else if (status == rd_input) {
      if (!input.str().empty()) input << endl;
      input << line;
    } else if (status == rd_expected) {
      if (!expected.str().empty()) expected << endl;
      expected << line;
    }
  }
}
