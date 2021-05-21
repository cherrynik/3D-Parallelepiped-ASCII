#include <iostream>
#include "vector.h"

const char WIDTH_SYMBOL = '_',
    WIDTH_SYMBOL_HIDDEN = '.',

    HEIGHT_SYMBOL = '\\',
    HEIGHT_SYMBOL_HIDDEN = '`',

    DEPTH_SYMBOL = '/',
    DEPTH_SYMBOL_HIDDEN = '\'';


int ReadLine_Int () {
  int x;
  std::cin >> x;
  std::cin.ignore();
  return x;
}

// TODO: Make vector filling with given const symbols of 2D Skewed Rectangle 
class Rectangle {
  protected:
    unsigned int width, height;
    Vector2D<std::string> rectangle;

    // TODO: Make it easier
    void InitRectangleSize () {
      // The difference between resize and reserve is explained here:
      // https://stackoverflow.com/questions/7397768/choice-between-vectorresize-and-vectorreserve
      rectangle.resize(height);

      for (unsigned int row = 0; row < height; ++row) {
        if (row == 0 && row == height - 1) {
          for (unsigned int column = 0; column < width; ++column) {
            rectangle[row].resize(width);
          }
        }
      }
    }

  public:
    Rectangle (const int width, const int height) {
      this -> width = width;
      this -> height = height;
      InitRectangleSize();
    }
};

// class Parallelepiped : protected Rectangle {
//   private:
//     unsigned int depth;
//     Vector3D<std::string> parallelepiped;
//
//   public:
//     Parallelepiped (const int width, const int height, const int depth) :
//     Rectangle (width, height) {
//       this -> depth = depth;
//
//     }
//
// };


int main () {
  unsigned const int width = ReadLine_Int();
  unsigned const int height = ReadLine_Int();
  unsigned const int depth = ReadLine_Int();

  // 1st solution
  Rectangle rectangle = Rectangle(width, height);
}
