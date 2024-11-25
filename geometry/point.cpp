typedef double D;
struct P {
  D x, y;
  P(D _x = 0, D _y = 0) : x(_x), y(_y) {}
  bool operator==(P p) { return tie(x, y) == tie(p.x, p.y); }
  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }
  P operator*(D d) const { return P(x * d, y * d); }
  P operator/(D d) const { return P(x / d, y / d); }
  D dot(P p) { return x * p.x + y * p.y; }
  D cross(P p) { return x * p.y - y * p.x; }
  D cross(P a, P b) { return (a - *this).cross(b - *this); }
  D dist2() { return x * x + y * y; }
  D dist() { return sqrt(dist2()); }
  double angle() { return atan2(y, x); }
  P unit() { return *this / dist(); }
  P perp() { return P(-y, x); }
  P normal() { return perp().unit(); }
  P rotate(double a) {
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
};

int sgn(D x) { return (x > 0) - (x < 0); }
static const D EPS = numeric_limits<D>::epsilon();
using VP = vector<P>;
