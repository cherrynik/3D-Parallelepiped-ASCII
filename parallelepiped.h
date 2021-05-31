#include <iostream>
#include <vector>

struct SymbolsToDraw3D : SymbolsToDraw2D {
  const std::string depth = "/",
                    depthHidden = "'"; // \u280C
};

class Parallelepiped : protected Rectangle {
  private:
    unsigned int depth;
    Vector2D<std::string> parallelepiped; // 2D until great times
    SymbolsToDraw3D symbolsToDraw3d;

    // TODO: Make it easier if it's possible
    template<typename T>
    void InitParallelepipedSize (Vector2D<T>& parallelepiped) {
      // The difference between resize and reserve is explained here:
      // https://stackoverflow.com/questions/7397768/choice-between-vectorresize-and-vectorreserve
      parallelepiped.resize(height + depth);

      for (unsigned int level = 0; level < height + depth; ++level) {
        InitRectangleSize(parallelepiped);
      }
    }

    /* It's gonna be real simulation of 3d graphics right in console.
     * I wished I do it from scratch,
     * But I've decided to make it later, and I will do it anyways.
     * Stay up to date ;)
     * -------------------------------------------
     * But for now you're getting pseudo 3D. Yup...
     * TODO: Real 3D
     */
    void MakeParallelepiped (const SymbolsToDraw3D& symbolsToDraw3d) {

    }

  public:
    Parallelepiped(const int width, const int height, const int depth)
        : Rectangle(width, height) {
      this -> depth = height + depth + 1;
      InitParallelepipedSize(parallelepiped);
      MakeParallelepiped(symbolsToDraw3d);
    }
};