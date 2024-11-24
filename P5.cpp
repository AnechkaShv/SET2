
#include <iostream>
#include <vector>
#include <valarray>

double distance(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
  return hypot(p1.first - p2.first,p1.second - p2.second);
}

double naiveClosest(std::vector<std::pair<int, int>>& points, int begin, int end) {
  double min_dist = INT_MAX;
  for (int i = begin; i < end; ++i) {
    for (int j = i + 1; j < end; ++j) {
      if (distance(points[i], points[j]) < min_dist) {
        min_dist = std::min(distance(points[i], points[j]), min_dist);
      }
    }
  }

  return min_dist;
}

double closestPair(std::vector<std::pair<int, int>>& points, int begin, int end) {
  int size = end - begin;
  if (size <= 3) {
    return naiveClosest(points, begin, end);
  }

  int mid = (begin + end) / 2;
  std::pair<int, int> mid_point = points[mid];
  double min_dist_left = closestPair(points, begin, mid);
  double min_dist_right = closestPair(points, mid, end);
  double min_dist = std::min(min_dist_left, min_dist_right);


  std::vector<std::pair<int, int>> near_mid;
  near_mid.reserve(end - begin);
  for (int i = begin; i < end; ++i) {
    if (std::abs(points[i].first - mid_point.first) < min_dist) {
      near_mid.push_back(points[i]);
    }
  }

  std::sort(near_mid.begin(), near_mid.end(),[](std::pair<int, int> p1, std::pair<int, int> p2) { return p1.second < p2.second; });


  for (int i = 0; i < near_mid.size(); ++i) {
    for (int j = i + 1; j < near_mid.size() && near_mid[j].second - near_mid[i].second < min_dist; ++j) {
      min_dist = std::min(min_dist, distance(near_mid[j], near_mid[i]));
    }
  }
  return min_dist;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> points(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> points[i].first >> points[i].second;
  }
  if (points.size() < 2) {
    std::cout << "0";
    return 0;
  }
  std::sort(points.begin(), points.end(),
            [](std::pair<int, int> p1, std::pair<int, int> p2) { if (p1.first == p2.first) return p1.second < p2.second; else return p1.first < p2.first; });
  double min_dist = closestPair(points, 0, points.size());
  std::cout << (int)min_dist;
  return 0;
}