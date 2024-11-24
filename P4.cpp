#include <iostream>
#include <vector>
#include <cmath>

long double SearchDistance(const std::vector<std::pair<long long, long long>>& move, long double time) {
  long double dist = 0;
  long double curr_time = 0;
  int i;
  for (i = 0; i < move.size(); ++i) {
    if (curr_time + move[i].first <= time) {
      dist += move[i].first * move[i].second;
      curr_time += move[i].first;
    } else {
      break;
    }
  }
  if (curr_time < time) {
    dist += (time - curr_time) * move[i].second;
  }
  return dist;
}

bool IsCorrectTime(const std::vector<std::pair<long long, long long>>& move, long long length, long double time) {
  if (SearchDistance(move, time) < length) {
    return false;
  }
  long double distance_first = 0;
  long double time_first = 0;
  long double distance_second;
  int j = 0;
  for (int i = 0; i < move.size(); ++i) {
    time_first += move[i].first;
    distance_first += move[i].first * move[i].second;
    if (time_first < time) {
      continue;
    }
    distance_second = SearchDistance(move, time_first - time);
    j += 1;
    if (distance_first - distance_second < length) {
      return false;
    }
  }
  return true;
}

long double SearchTime(const std::vector<std::pair<long long, long long>>& move, long long length) {
  long double left = 0;
  long double right = INT_MAX;
  for (int i = 0; i < 64; ++i) {
    long double mid = (left + right) / 2.0;
    if (IsCorrectTime(move, length, mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return std::round(right * 1000) / 1000;
}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long max_length;
  long long path_count;
  std::cin >> max_length;
  std::cin >> path_count;
  std::vector<std::pair<long long, long long>> move(path_count);
  for (int i = 0; i < path_count; ++i) {
    std::cin >> move[i].first >> move[i].second;
  }
  long double res = SearchTime(move, max_length);
  std::cout << res;
}
