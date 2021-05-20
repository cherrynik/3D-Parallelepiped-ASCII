#include <iostream>
#include <vector>


const char WIDTH_SYMBOL         = '_',
    WIDTH_SYMBOL_HIDDEN  = '.',

    HEIGHT_SYMBOL        = '\\',
    HEIGHT_SYMBOL_HIDDEN = '`',

    DEPTH_SYMBOL         = '/',
    DEPTH_SYMBOL_HIDDEN  = '\'';


int ReadLine_Int() {
  int x;
  std::cin >> x;
  std::cin.ignore();
  return x;
}

class Vector2D : private std::vector<std::vector<std::string>> {
    std::vector<std::vector<std::string>> vector2d;

  public:
    std::vector<std::vector<std::string>> Init(const int width, const int height) {
      this -> vector2d.reserve(height);

      for (unsigned int row = 0; row < height; ++row) {
        vector2d[row].reserve(width);
      }

      return vector2d;
    }
};

// class Vector3D : Vector2D {
//     std::vector<Vector2D> vector3d;
//
//     std::vector<Vector2D> Init(const int width, const int height, const int depth) : Init(width, height) {
//       this -> vector3d.reserve(height);
//
//       for (unsigned int row = 0; row < height; ++row) {
//         this -> vector3d[row].reserve(width);
//
//         for (unsigned int column = 0; column < width; ++column) {
//           this -> vector3d[row][column].reserve(depth);
//         }
//       }
//
//       return vector3d;
//     }
// };

class Rectangle {
  protected:
    unsigned int width, height;
    Vector2D rectangle;

  public:
    Rectangle(const int width, const int height) {
      this -> width     = width;
      this -> height    = height;
      this -> rectangle.Init(width, height);
    }
};

// class Parallelepiped : protected Rectangle {
//   private:
//     unsigned int depth;
//     // Vector3D parallelepiped;
//
//   public:
//     Parallelepiped(const int width, const int height, const int depth) : Rectangle(width, height) {
//       this -> depth          = depth;
//       this -> parallelepiped = parallelepiped.Init(width, height, depth);
//
//       std::cerr << width << " " << height << " " << depth << std::endl;
//     }
//
// };

int main()
{
  unsigned const int width = ReadLine_Int();
  unsigned const int height = ReadLine_Int();
  // unsigned const int depth = ReadLine_Int();

  // 1st solution
  // Parallelepiped Par = Parallelepiped(width, height, depth);
  Rectangle rect = Rectangle(width, height);

  // std::cout << "ASCII cube" << std::endl;
}
