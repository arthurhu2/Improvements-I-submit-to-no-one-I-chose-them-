// @author G. Hemingway, copyright 2024

#include <algorithm>
#include <iostream>

class PrintIt {
public:
  void operator()(const int &i) const { std::cout << i << " "; }
};

// define a special-purpose custom printing function
void printIt(int i) { std::cout << i << " "; }

int main() {
  int intArray[] = {1, 2, 3, 4, 45, 56, 456, 234312};

  // call printIt on every element of the array
  for (const int i : intArray)
    printIt(i);
  std::cout << std::endl;

  // Apply printIt function to each element in the array
  std::for_each(intArray, intArray + 8, printIt);
  std::cout << std::endl;

  // Apply PrintIt functor to each element in the array
  PrintIt functorInst;
  std::for_each(intArray, intArray + 8, functorInst);
  std::cout << std::endl;

  // Apply PrintIt to an array filled with values
  std::for_each(intArray, intArray + 8, PrintIt());
  std::cout << std::endl;

  // Create an instance of functor, and invoke like a function
  functorInst(17);

  return 0;
}
