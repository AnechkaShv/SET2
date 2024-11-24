#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

struct Point {
  long long x;
  long long y;
  long long z;
};

struct DistPoints {
  double dist;
  Point p1;
  Point p2;
};

double distance(const Point& p1, const Point& p2) {
  return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2) + std::pow(p1.z - p2.z, 2));
}

DistPoints Naive(const std::vector<Point>& points, int begin, int end) {
  double min_dist = INT_MAX;
  Point p1;
  Point p2;
  for (int i = begin; i < end; ++i) {
    for (int j = i + 1; j < end; ++j) {
      double dist = distance(points[i], points[j]);
      if (dist < min_dist) {
        min_dist = dist;
        p1 = points[i];
        p2 = points[j];
      }
    }
  }
  return {min_dist, p1, p2};
}

DistPoints closestPair(const std::vector<Point>& points, int begin, int end) {
  if (end - begin <= 10) {
    return Naive(points, begin, end);
  }

  int mid = (begin + end) / 2;
  DistPoints left_d = closestPair(points, begin, mid);
  DistPoints right_d = closestPair(points, mid, end);

  double min_dist_left = left_d.dist;
  double min_dist_right = right_d.dist;
  Point p1;
  Point p2;
  double min_dist;
  if (min_dist_right < min_dist_left) {
    min_dist = min_dist_right;
    p1 = right_d.p1;
    p2 = right_d.p2;
  } else {
    min_dist = min_dist_left;
    p1 = left_d.p1;
    p2 = left_d.p2;
  }
  double mid_point_x = (double)points[mid].x;
  double left = mid_point_x - min_dist;
  double right = mid_point_x + min_dist;

  std::vector<Point> near_mid;
  for (int i = begin; i < end; ++i) {
    if (left <= (double)points[i].x && right >= (double)points[i].x) {
      near_mid.push_back(points[i]);
    }
  }

  std::sort(near_mid.begin(), near_mid.end(), [](Point p1, Point p2){return p1.y < p2.y;});

  for (int i = 0; i < near_mid.size(); ++i) {
    for (int j = i + 1; j < near_mid.size() && j < i + 100; ++j) {
      double dist = distance(near_mid[i], near_mid[j]);
      if (dist < min_dist) {
        min_dist = dist;
        p1 = near_mid[i];
        p2 = near_mid[j];
      }
    }
  }
  return {min_dist, p1, p2};
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<Point> points(n);
  std::vector<Point> copy(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> points[i].x >> points[i].y >> points[i].z;
    copy[i].x = points[i].x;
    copy[i].y = points[i].y;
    copy[i].z = points[i].z;

  }
  std::sort(points.begin(), points.end(), [](Point p1, Point p2){return p1.x < p2.x;});
  DistPoints res = closestPair(points, 0, n);
  auto p1_idx = std::find_if(copy.begin(), copy.end(), [copy, res](Point p){ return (p.x == res.p1.x && p.y == res.p1.y && p.z == res.p1.z);});
  auto p2_idx = std::find_if(copy.begin(), copy.end(), [copy, res](Point p){ return (p.x == res.p2.x && p.y == res.p2.y && p.z == res.p2.z);});

  double dist = res.dist;
  std::cout << std::fixed << std::setprecision(5) << res.dist << "\n";
  std::cout << int(p1_idx - copy.begin()) + 1 << " " << int(p2_idx - copy.begin()) + 1;
}
