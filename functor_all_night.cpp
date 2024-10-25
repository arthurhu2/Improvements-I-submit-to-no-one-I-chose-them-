// @author G. Hemingway, copyright 2024

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <cstdint>

/*
 * Write your functor here.  Requirements:
 * 1) Print values for items with even indexes (i.e. 0th element, 2nd element, 4th element, etc.)
 * 2) Count number of elements
 * 3) Determine min value
 * 4) Determine max value
 * 5) Do not use std::cout directly inside your class (look at the constructor)
 * 6) Must work across all types that support operator<, operator>
 * !!!) Can you do it in just a few lines of code (mine is 18 lines total)
 */
template<typename T>
class FunctorAllNight {
public:
  explicit FunctorAllNight(std::ostream &os) : count(0), min (T()), max(T()), os(os) {};
  void operator()(const T value) {
    if (count % 2 == 0) os << value << " ";
    if (count == 0) min = max = value;
    if (value < min) min = value;
    if (value > max) max = value;
    ++count;
  }
  uint32_t getCount() { return count; }
  T getMin() { return min; }
  T getMax() { return max; }
private:
  uint32_t count;
  T min, max;
  std::ostream &os;
};

int main() {
  // We could print output to a file -
  // output.txt will be inside your cmake-build-debug folder
  std::ofstream os;
  os.open("output.txt", std::fstream::out | std::fstream::trunc);
  // Or we could print to std::cout -
  // comment out the above two lines and uncomment out the one below to try
  // std::ostream& os = std::cout;

  // Let's try this with ints
  std::list<int> iList{1, 2, 4, 8, 16, 32, 64, 128};
  // Now build me a functor
  auto i = std::for_each(iList.begin(), iList.end(),
    FunctorAllNight<int>(os)); // Expect "1 4 16 64"
  os << std::endl << i.getCount() << std::endl;     // Expect "8"
  os << i.getMin() << std::endl;                    // Expect "1"
  os << i.getMax() << std::endl;                    // Expect "128"
  os << std::endl;

  // Do it again, but with doubles
  std::list<double> dList{4.233, 234.234, 2.1234, -123.22};
  // Now build me a functor
  auto d = std::for_each(dList.begin(), dList.end(),
    FunctorAllNight<double>(os)); // Expect "4.233 2.1234"
  os << std::endl << d.getCount() << std::endl;     // Expect "4"
  os << d.getMin() << std::endl;                    // Expect "-123.22"
  os << d.getMax() << std::endl;                    // Expect "234.234"
  os << std::endl;

  // Do it again, but with strings
  std::list<std::string> sList{"Lazy", "Brown", "Dog"};
  // Now build me a functor
  auto s = std::for_each(sList.begin(), sList.end(),
    FunctorAllNight<std::string>(os)); // Expect "Lazy Dog"
  os << std::endl << s.getCount() << std::endl;     // Expect "3"
  os << s.getMin() << std::endl;                    // Expect "Brown"
  os << s.getMax() << std::endl;                    // Expect "Lazy"
  os << std::endl;

  return 0;
}
