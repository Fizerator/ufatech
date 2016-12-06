#include <iostream>
#include <conio.h>
#include <deque>

int main() {
  std::deque<int> d;
  int n, a, b;
  bool right = true;
  std::cin >> n;
  for (size_t i = 0; i < n; ++i) {
	std::cin >> a >> b;
	switch (a) {
    case 1:
	  d.push_front(b);
      break;
    case 2:
      if (d.empty()) {
		if (b != -1) {
		  right = false;
        }
      }
      else {
        int n = d.front();
        d.pop_front();
		if (b != n) {
		  right = false;
        }
      }
      break;
    case 3:
	  d.push_back(b);
      break;
    case 4:
      if (d.empty()) {
		if (b != -1) {
		  right = false;
        }
      }
      else {
        int n = d.back();
        d.pop_back();
        if (b != n) {
		  right = false;
        }
      }
    default:
      break;
    }
  }
  if (right) {
	std::cout << "YES" << std::endl;
  }
  else {
	std::cout << "NO" << std::endl;
  }
  getch();
  return 0;
}
