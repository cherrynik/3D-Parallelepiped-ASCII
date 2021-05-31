#include <iostream>
#include <vector>
#include "vector.h"
#include "rectangle.h" // TODO: Improve comments
#include "parallelepiped.h" // TODO: Real 3d simulation

int ReadLine_Int () {
  int x;
  std::cin >> x;
  std::cin.ignore();
  return x;
}

// 2nd solution
int main () {
  const unsigned int width  = ReadLine_Int(),
                     height = ReadLine_Int();
                     // depth  = ReadLine_Int();

  Rectangle rect = Rectangle(width, height);
  rect.Show();
}