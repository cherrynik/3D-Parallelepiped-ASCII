#include <vector>

template<typename T>
class Vector2D : public std::vector<std::vector<T>> {
  public:
    using std::vector<std::vector<T>>::vector;
};

template<typename T>
class Vector3D : public std::vector<Vector2D<T>> {
  public:
    using std::vector<Vector2D<T>>::vector;
};
