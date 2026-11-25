typedef double D; // or ll, avoid int
struct P {
  D x, y;
  P(D _x = 0, D _y = 0) : x(_x), y(_y) {}
  bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
  bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }
  P operator*(D d) const { return P(x * d, y * d); }
  P operator/(D d) const { return P(x / d, y / d); }
  D dot(P p) const { return x * p.x + y * p.y; }
  D cross(P p) const { return x * p.y - y * p.x; }
  D cross(P a, P b) const { return (a - *this).cross(b - *this); }
  D dist2() const { return x * x + y * y; }
  double dist() const { return sqrt(dist2()); }
  double angle() const { return atan2(y, x); } // angle to x-axis in interval [-pi, pi]
  P unit() const { return *this / dist(); } // makes dist() = 1
  P perp() const { return P(-y, x); } // rotates +90 degrees
  P normal() const { return perp().unit(); }
  P rotate(double a) const {  // rotates 'a' radians ccw around the origin
    return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
  }
};
using VP = vector<P>;