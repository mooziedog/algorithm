#include<cstdio>
#include<cassert>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

const double EPSILON = 1e-8;
const double PI = 2.0 * acos(0.0);

// 2���� ���͸� ǥ���Ѵ�
struct vector2 {
	double x, y;
	vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}

	// �� ���Ͱ� ���� ���
	bool operator == (const vector2& rhs) const { return x == rhs.x && y == rhs.y; }

	// ������ ������ ����
	vector2 operator + (const vector2& rhs) const { return vector2(x + rhs.x, y + rhs.y); }
	vector2 operator - (const vector2& rhs) const { return vector2(x - rhs.x, y - rhs.y); }
	vector2 operator - () const { return vector2(-x, -y); }

	// ��Į��� ����
	vector2 operator * (double rhs) const { return vector2(x * rhs, y * rhs); }

	// ������ ���̸� ��ȯ�Ѵ�
	double norm() const { return hypot(x, y); }

	// ������ ���� ���� ���� (unit vector) �� ��ȯ�Ѵ�
	vector2 normalize() const { double n = norm(); return vector2(x / n, y / n); }

	// x���� ���� �������κ��� �� ���ͱ��� �ݽð�������� �� ����
	double polar() const { return fmod(atan2(y, x) + 2 * PI, 2 * PI); }

	// ����/������ ����
	double dot(const vector2& rhs) const { return x * rhs.x + y * rhs.y; }
	double cross(const vector2& rhs) const { return x * rhs.y - rhs.x * y; }

	// �� ���͸� rhs �� �翵�� ���
	vector2 project(const vector2& rhs) const {
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};

// �������� ���� b �� ���� a �� �ݽð� �����̸� ���, �ð� �����̸� ����, �����̸� 0 �� ��ȯ�Ѵ�
double ccw(vector2 a, vector2 b) {
	return a.cross(b);
}

// �� p �� �������� ���� b �� ���� a �� �ݽð� �����̸� ���, �ð� �����̸� ����, �����̸� 0 �� ��ȯ�Ѵ�
double ccw(vector2 p, vector2 a, vector2 b) {
	return ccw(a - p, b - p);
}


// (a,b) �� �����ϴ� ���� (c,d) �� �����ϴ� ���� ������ p �� ��ȯ�Ѵ�.
// �� ���� �����̸� (��ġ�� ��츦 ����) ������, �ƴϸ� ���� ��ȯ�Ѵ�.
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
	double det = (b - a).cross(d - c);
	if (det == 0) return false;
	p = a + (b - a) * ((c - a).cross(d - c) / det);
	return det;
}

bool isLessThan(vector2 a, vector2 b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

// (a,b) �� (c,d) �� ������ �� ������ �� �̵��� �� ������ ��ġ�� Ȯ���Ѵ�
bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
	if (!isLessThan(a, b)) swap(a, b);
	if (!isLessThan(c, d)) swap(c, d);
	if (b == c) { p = b; return true; }
	if (a == d) { p = a; return true; }
	return false;
}

// p �� (a,b) �� ���θ鼭 �� ���� x,y�࿡ ������ �ּ� �簢�� ���ο� �ִ��� Ȯ���Ѵ�
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b) {
	double x1 = a.x, x2 = b.x, y1 = a.y, y2 = b.y;
	if (x1 > x2) swap(x1, x2);
	if (y1 > y2) swap(y1, y2);
	return x1 <= p.x && p.x <= x2 && y1 <= p.y && p.y <= y2;
}

// (a,b) ���а� (c,d) ������ ������ p �� ��ȯ�Ѵ�.
// �� ������ �������� �ʰų�, �ϳ� �̻��� ������ ������ ������ ��ȯ�Ѵ�.
bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
	// �� ������ ������ ��츦 �켱 ���ܷ� ó���Ѵ�
	if (!lineIntersection(a, b, c, d, p)) return parallelSegments(a, b, c, d, p);
	// p �� �� ���п� ���ԵǾ� �ִ� ��쿡�� ���� ��ȯ�Ѵ�
	return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);

}

// �� ���� [a,b], [c,d] �� �������� ������ ���θ� Ȯ���Ѵ�
double disjoint(double a, double b, double c, double d) {
	if (a > b) swap(a, b); if (c > d) swap(c, d);
	return b < c || d < a;
}

// �� ������ ���� �����ϴ��� ���θ� ��ȯ�Ѵ�
bool segmentIntersects(vector2 a, vector2 b, vector2 c, vector2 d) {
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);
	// �� ������ �� ���� ���� �ִ� ���
	if (ab == 0 && cd == 0)
		return !disjoint(a.x, b.x, c.x, d.x) &&
		!disjoint(a.y, b.y, c.y, d.y);
	return ab <= 0 && cd <= 0;
}

// �� p ���� (a,b) ������ ���� ������ ���� ���Ѵ�
vector2 perpendicularFoot(vector2 p, vector2 a, vector2 b) {
	vector2 delta = (b - a).normalize();
	return a + delta * (p - a).dot(delta);
}

// �� p �� (a,b) ���� ������ �Ÿ��� ���Ѵ�
double pointToLine(vector2 p, vector2 a, vector2 b) {
	return (p - perpendicularFoot(p, a, b)).norm();
}

// �־��� �ܼ� �ٰ��� p �� ���̸� ���Ѵ�. p �� �� �������� ��ġ ������ �������� �־�����.
double area(const vector<vector2>& p) {
	double ret = 0;
	for (int i = 0; i < p.size(); ++i) {
		int j = (i + 1) % p.size();
		ret = ret + (p[i].x * p[j].y - p[j].x * p[i].y);
	}
	return fabs(ret) / 2.0;
}

// �� q �� �ٰ��� p �ȿ� ���ԵǾ� ���� ��� ��, �ƴ� ��� ������ ��ȯ�Ѵ�.
// q �� �ٰ����� ��� ���� �ִ� ����� ��ȯ���� ���ǵǾ� ���� �ʴ�.
bool isInside(vector2 q, const vector<vector2>& p) {
	int crosses = 0;
	for (int i = 0; i < p.size(); ++i) {
		int j = (i + 1) % p.size();
		// (p[i], p[j]) �� �������� ���η� ���������°�?
		if ((p[i].y > q.y) != (p[j].y > q.y)) {
			double atX = (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x;
			if (q.x < atX)
				++crosses;
		}
	}
	return crosses % 2 > 0;
}

typedef vector<vector2> polygon;

// ������ �ܼ� �ٰ����� �������� ���Ѵ�.
// (a,b) �� �����ϴ� �������� �ٰ��� p �� �ڸ� ��, (a,b) �� ���ʿ� �ִ� �κе��� ��ȯ�Ѵ�
polygon cutPoly(const polygon& p, const vector2& a, const vector2& b) {
	int n = p.size();
	// �� ���� ����� ���� �ִ��� ���θ� �켱 Ȯ���Ѵ�.
	vector<bool> inside(n);
	for (int i = 0; i < n; ++i)
		inside[i] = ((b - a).cross(p[i] - a) >= 0);
	polygon ret;
	// �ٰ����� �ð� �������� ��ȸ�ϸ鼭 ��� �ٰ����� �� ���� �߰��Ѵ�.
	for (int i = 0; i < n; ++i) {
		int j = (i + 1) % n;
		// ����� ���� �ִ� �� p[i] �� �׻� ��� �ٰ����� ���Եȴ�.
		if (inside[i]) ret.push_back(p[i]);
		// �� p[i] - p[j] �� ������ �����ϸ� �������� ��� �ٰ����� ���Խ�Ų��.
		if (inside[i] != inside[j]) {
			vector2 intersection;
			assert(lineIntersection(p[i], p[j], a, b, intersection));
			ret.push_back(intersection);
		}
	}
	return ret;
}

// ��������-ȣ���� (Sutherland-Hodgman) �˰����� �̿��� �ٰ��� Ŭ����
polygon intersection(const polygon& p, double x1, double y1, double x2, double y2) {
	vector2 a(x1, y1), b(x2, y1), c(x2, y2), d(x1, y2);
	polygon ret = cutPoly(p, a, b);
	ret = cutPoly(ret, b, c);
	ret = cutPoly(ret, c, d);
	ret = cutPoly(ret, d, a);
	return ret;
}

polygon readPoly() {
	int n;
	cin >> n;
	polygon p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	return p;
}

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap(x1, x2);
		if (y1 > y2) swap(y1, y2);
		polygon p = readPoly();
		p = intersection(p, x1, y1, x2, y2);
		printf("%.10lf\n", area(p));
	}
}

