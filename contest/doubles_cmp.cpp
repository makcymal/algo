const double EPS = 1e-9; // or try 1e-12
double scale(double a, double b) { return max({1.0, abs(a), abs(b)}); }
bool eq(double a, double b)      { return a == b || abs(a - b) <= EPS * scale(a, b); }
bool lt(double a, double b)      { return a < b - EPS * scale(a, b); }
bool le(double a, double b)      { return a <= b + EPS * scale(a, b); }
int sgn(double a)                { return (a > EPS) - (a < -EPS); }
int sgn(double a, double eps)    { return (a > eps) - (a < -eps); }

