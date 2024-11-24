#include <iostream>
#include <string>
#include <algorithm>

std::string Add(const std::string& first, const std::string& second) {
  int n = std::max(first.size(), second.size());
  std::string result(n + 1, '0');
  int carry = 0;

  for (int i = 0; i < n; ++i) {
    int value = carry;
    if (i < first.size()) {
      value += first[first.size() - 1 - i] - '0';
    }
    if (i < second.size()) {
      value += second[second.size() - 1 - i] - '0';
    }
    result[n - i] = (value % 10) + '0';
    carry = value / 10;
  }

  if (carry != 0) {
    result[0] = carry + '0';
  } else {
    result.erase(result.begin());
  }
  return result;
}


std::string Subtract(const std::string& first, const std::string& second) {
  std::string result = first;
  int borrow = 0;

  for (int i = 0; i < first.size(); i++) {
    int sub = (first[first.size() - 1 - i] - '0') - (i < second.size() ? second[second.size() - 1 - i] - '0' : 0) - borrow;
    if (sub < 0) {
      sub += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }
    result[first.size() - 1 - i] = sub + '0';
  }

  size_t i = result.find_first_not_of('0');
  if (i == std::string::npos) {
    return "0";
  }
  result = result.substr(i);
  return result;
}

std::string Multiply(const std::string& first, const std::string& second) {
  std::string result(first.size() + second.size(), '0');

  for (int i = first.size() - 1; i >= 0; i--) {
    int carry = 0;
    for (int j = second.size() - 1; j >= 0; j--) {
      int temp = (result[i + j + 1] - '0') + (first[i] - '0') * (second[j] - '0') + carry;
      result[i + j + 1] = (temp % 10) + '0';
      carry = temp / 10;
    }
    result[i] += carry;
  }

  size_t startpos = result.find_first_not_of('0');
  if (std::string::npos != startpos) {
    return result.substr(startpos);
  }
  return "0";
}

std::string Karatsuba(const std::string& first_num, const std::string& second_num) {
  if (first_num.size() <= 4 && second_num.size() <= 4) {
    return Multiply(first_num, second_num);
  }
  auto a = first_num;
  auto b = second_num;

  while (a.size() < b.size()) {
    a = '0' + a;
  }

  while (b.size() < a.size()) {
    b = '0' + b;
  }

  int n = a.size();
  if (n <= 1) {
    return std::to_string((a[0] - '0') * (b[0] - '0'));
  }
  int mid = n / 2;
  std::string first_left = a.substr(0, n - mid);
  std::string first_right = a.substr(n - mid);
  std::string second_left = b.substr(0, n - mid);
  std::string second_right = b.substr(n - mid);

  std::string A1B1 = Karatsuba(first_left, second_left);
  std::string A2B2 = Karatsuba(first_right, second_right);
  std::string A12B12 = Karatsuba(Add(first_left, first_right), Add(second_left, second_right));
  std::string subtraction = Subtract(A12B12, Add(A1B1, A2B2));
  std::string result = Add(A1B1 + std::string(mid * 2, '0'), subtraction + std::string(mid, '0'));
  result = Add(result, A2B2);

  size_t i = result.find_first_not_of('0');
  if (i == std::string::npos) {
    return "0";
  }

  return result.substr(i);
}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string first;
  std::string second;
  std::cin >> first >> second;
  std::cout << Karatsuba(first, second);

  return 0;

}

