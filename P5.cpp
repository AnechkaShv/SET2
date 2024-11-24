//#include <iostream>
//#include <vector>
//#include <valarray>
//
//int distance(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
//  return (int)hypot(p1.first - p2.first, p1.second - p2.second);
//}
//
//int naiveClosest(const std::vector<std::pair<int, int>>& points, int begin, int end) {
//  int min_dist = INT_MAX;
//  for (int i = begin; i < end; ++i) {
//    for (int j = i + 1; j < end; ++j) {
//      min_dist = std::min(distance(points[i], points[j]), min_dist);
//    }
//  }
//  return min_dist;
//}
//
//int closestPair(const std::vector<std::pair<int, int>>& points, int begin, int end) {
//  int size = end - begin;
//  if (size <= 1000) {
//    return naiveClosest(points, begin, end);
//  }
//
//  int mid = (begin + end) / 2;
//  std::pair<int, int> mid_point = points[mid];
//  int min_dist_left = closestPair(points, begin, mid);
//  int min_dist_right = closestPair(points, mid, end);
//  int min_dist = std::min(min_dist_left, min_dist_right);
//
//  std::vector<std::pair<int, int>> sorted_points = points;
//  std::sort(sorted_points.begin(), sorted_points.end(),
//            [](std::pair<int, int> p1, std::pair<int, int> p2) { return p1.second > p2.second; });
//  std::vector<std::pair<int, int>> near_mid;
//  for (int i = 0; i < sorted_points.size(); ++i) {
//    if (distance(sorted_points[i], mid_point) < min_dist) {
//      near_mid.push_back(sorted_points[i]);
//    }
//  }
//
//
//  for (int i = 0; i < near_mid.size(); ++i) {
//    int j = i + 1;
//    while (j < near_mid.size() && (near_mid[j].second - near_mid[i].second) < min_dist) {
//      min_dist = std::min(min_dist, distance(near_mid[i], near_mid[j]));
//      j += 1;
//    }
//  }
//  return min_dist;
//}
//
//int main() {
//  std::ios::sync_with_stdio(false);
//  std::cin.tie(nullptr);
////  int x;
////  int y;
////  std::vector<std::pair<int, int>> points;
////  while (std::cin >> x >> y) {
////    points.push_back(std::pair<int, int>(x, y));
////  }
//
//  int n;
//  std::cin >> n;
//  std::vector<std::pair<int, int>> points(n);
//  for (int i = 0; i < n; ++i) {
//    std::cin >> points[i].first >> points[i].second;
//  }
//  std::sort(points.begin(), points.end(),
//            [](std::pair<int, int> p1, std::pair<int, int> p2) { return p1.first > p2.first; });
//  int min_dist = closestPair(points, 0, points.size());
//  std::cout << min_dist;
//}
//
////#include <iostream>
////#include <vector>
////#include <valarray>
////
////int distance(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
////  return (int)std::sqrt(std::pow(p1.first - p2.first, 2) + std::pow(p1.second - p2.second, 2));
////}
////
////int naiveClosest(const std::vector<std::pair<int, int>>& points, int begin, int end) {
////  int min_dist = INT_MAX;
////  for (int i = begin; i < end; ++i) {
////    for (int j = i + 1; j < end; ++j) {
////      if (distance(points[i], points[j]) < min_dist) {
////        min_dist = std::min(min_dist, distance(points[i], points[j]));
////      }
////    }
////  }
////  return min_dist;
////}
////
////int closestPair(const std::vector<std::pair<int, int>>& points, int begin, int end) {
////  if (points.size() <= 1000) {
////    return naiveClosest(points, begin, end);
////  }
////
////  int mid = (begin + end) / 2;
////  std::pair<int, int> mid_point = points[mid];
////  int min_dist_left = closestPair(points, begin, mid);
////  int min_dist_right = closestPair(points, mid, end);
////  int min_dist = std::min(min_dist_left, min_dist_right);
////
////  std::vector<std::pair<int, int>> near_mid_left;
////  std::vector<std::pair<int, int>> near_mid_right;
////  for (int i = begin; i < mid; ++i) {
////    if (distance(points[i], mid_point) < min_dist) {
////      near_mid_left.emplace_back(points[i]);
////    }
////  }
//
////  for (int i = mid; i < end; ++i) {
////    if (distance(points[i], mid_point) < min_dist) {
////      near_mid_right.emplace_back(points[i]);
////    }
////  }
////
////  std::sort(near_mid_left.begin(), near_mid_left.end(),
////            [](std::pair<int, int> p1, std::pair<int, int> p2) { return p1.second > p2.second; });
////  std::sort(near_mid_right.begin(), near_mid_right.end(),
////            [](std::pair<int, int> p1, std::pair<int, int> p2) { return p1.second > p2.second; });
////  for (int i = 0; i < near_mid_left.size(); ++i) {
////    int j = 0;
////    while (j < near_mid_right.size() && (near_mid_right[j].second - near_mid_left[i].second) < min_dist) {
////      min_dist = std::min(min_dist, distance(near_mid_left[i], near_mid_right[j]));
////      j += 1;
////    }
////  }
////  return min_dist;
////}
////
////int main() {
////  std::ios::sync_with_stdio(false);
////  std::cin.tie(nullptr);
////  int x;
////  int y;
////  std::vector<std::pair<int, int>> points;
////  while (std::cin >> x >> y) {
////    points.push_back(std::pair<int, int>(x, y));
////  }
////  std::sort(points.begin(), points.end(),
////            [](std::pair<int, int> p1, std::pair<int, int> p2) { return p1.first > p2.first; });
////  int min_dist = closestPair(points, 0, points.size());
////  std::cout << min_dist;
////}

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
//  int x;
//  int y;
//  std::vector<std::pair<int, int>> points;
//  while (std::cin >> x >> y) {
//    points.push_back(std::pair<int, int>(x, y));
//  }
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