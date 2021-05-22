#include <iostream>
#include "vector.h"
#include "rectangle.h" // TODO: Refactoring


int ReadLine_Int () {
  int x;
  std::cin >> x;
  std::cin.ignore();
  return x;
}

class Parallelepiped : protected Rectangle {
  private:
    unsigned int depth;
    Vector3D<std::string> parallelepiped;

    // InitParallelepipedSize() : InitRectangleSize() {
    //
    // }

  public:
    Parallelepiped(const int width, const int height, const int depth) :
    Rectangle(width, height) {
      this -> depth = depth;

      // InitParallelepipedSize();
    }
};

int main () {
  unsigned const int width = ReadLine_Int();
  unsigned const int height = ReadLine_Int();
  // unsigned const int depth = ReadLine_Int();

  // 1st solution
  Rectangle rectangle = Rectangle(width, height);
  rectangle.ShowSkewed();
}