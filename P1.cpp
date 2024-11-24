#include <iostream>
#include <vector>


struct Interval {
  int left = 0;
  int right = 0;

  size_t length() const;
  Interval overlap(const Interval& other) const;
};

size_t Interval::length() const {
  return right - left < 0 ? 0 : right - left + 1;
}

Interval Interval::overlap(const Interval &other) const {
  int overlap_left = std::max(left, other.left);
  int overlap_right = std::min(right, other.right);

  return {overlap_left, overlap_right};
}

void merge(std::vector<Interval>& intervals, int left, int mid, int right) {
  std::vector<Interval> left_sorted(mid - left + 1);
  std::vector<Interval> right_sorted(right - mid);

  for (int i = 0; i < left_sorted.size(); i++)
    left_sorted[i] = intervals[left + i];
  for (int i = 0; i < right_sorted.size(); i++)
    right_sorted[i] = intervals[mid + 1 + i];

  int i = 0;
  int j = 0;
  size_t k = left;
  while (i < left_sorted.size() && j < right_sorted.size()) {
    if (left_sorted[i].left <= right_sorted[j].left) {
      intervals[k] = left_sorted[i];
      i++;
    } else {
      intervals[k] = right_sorted[j];
      j++;
    }
    k++;
  }

  while (i < left_sorted.size()) {
    intervals[k] = left_sorted[i];
    i++;
    k++;
  }

  while (j < right_sorted.size()) {
    intervals[k] = right_sorted[j];
    j++;
    k++;
  }
}

void mergeSort(std::vector<Interval>& intervals, int left, int right) {
  if (left < right) {

    int mid = left + (right - left) / 2;

    mergeSort(intervals, left, mid);
    mergeSort(intervals, mid + 1, right);
    merge(intervals, left, mid, right);
  }
}

Interval SearchInterval(const std::vector<Interval>& arr, int begin, int end) {
  if (end - begin <= 1) {
    return {0,-1};
  }
  int mid = (begin + end) / 2;
  int idx = begin;
  for (int k = begin; k < mid; ++k) {
    if (arr[k].right > arr[idx].right) {
      idx = k;
    }
  }
  Interval left = SearchInterval(arr, begin, mid);
  Interval right = SearchInterval(arr, mid, end);
  for (int l = mid; l < end; ++l) {
    Interval interval = arr[idx].overlap(arr[l]);
    if (interval.length() > left.length()) {
      left = interval;
    }
  }
  return (right.length() > left.length()) ? right : left;
}

int main() {
  int n;
  int left, right;
  std::cin >> n;
  std::vector<Interval> intervals(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> left >> right;
    intervals[i] = {left, right};
  }
  mergeSort(intervals, 0, n - 1);
  Interval max_interval = SearchInterval(intervals, 0, n);
  std::cout << max_interval.length() << "\n";
  if (max_interval.length() != 0) {
    std::cout << max_interval.left << " " << max_interval.right;
  }
  return 0;
}

