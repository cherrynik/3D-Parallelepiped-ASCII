#include <iostream>
#include <vector>

struct SymbolsToDraw2D {
  const std::string space = " ",

                    width = "_",
                    widthHidden = ".",

                    height = "\\",
                    heightHidden = "'"; // \u2821
};

class Rectangle {
  protected:
    const SymbolsToDraw2D symbolsToDraw2d;

    unsigned int width, height;
    Vector2D<std::string> rectangle;

    // FIXME: Make it easier if it's possible
    template<typename T>
    void InitRectangleSize (Vector2D<T>& vector2d) {
      // The difference between resize and reserve is explained here:
      // https://stackoverflow.com/questions/7397768/choice-between-vectorresize-and-vectorreserve
      vector2d.resize(height);

      for (unsigned int row = 0; row < height; ++row) {
        vector2d[row].resize(width);
      }
    }

    template<typename T>
    void FillRowWithSymbol (Vector2D<T>& vector2d,
                            const int row,
                            const T symbol) {
      // width - 1, Because of top right angle
      for (int column = 0; column < width - 1; ++column) {
        rectangle[row][column] = symbol;
      }
    }

    template<typename T>
    void FillColumnWithSymbol (Vector2D<T>& vector2d,
                               const int column,
                               const T symbol) {
      // Starts from 1, Because of top side
      for (int row = 1; row < height; ++row) {
        rectangle[row][column] = symbol;
      }
    }

    template<typename T>
    void FillRemainedWithSpace (Vector2D<T>& vector2d,
                                const T symbol) {
      for (int column = 1; column < width - 1; ++column) {
        FillColumnWithSymbol(vector2d, column, symbol);
      }
    }

    // Reversed order of scripts because of vector's symbols replacing
    template<typename T>
    void MakeRectangle (Vector2D<T>& vector2d,
                        const SymbolsToDraw2D& symbolsToDraw2d,
                        const bool isVisible) {
      FillRemainedWithSpace(vector2d, symbolsToDraw2d.space);

      // FIXME: Duplication of code is very-very bad, hm...
      if (isVisible) {
        FillRowWithSymbol(vector2d, height - 1, symbolsToDraw2d.width);
        FillColumnWithSymbol(vector2d, 0, symbolsToDraw2d.height);
      } else {
        FillRowWithSymbol(vector2d, height - 1, symbolsToDraw2d.widthHidden);
        FillColumnWithSymbol(vector2d, 0, symbolsToDraw2d.heightHidden);
      }

      FillColumnWithSymbol(vector2d, width - 1, symbolsToDraw2d.height);
      FillRowWithSymbol(vector2d, 0, symbolsToDraw2d.width);
    }

  public:
    Rectangle (const int width, const int height,
               const SymbolsToDraw2D& symbolsToDraw2d = SymbolsToDraw2D(),
               const bool isVisible = false) {
      this->width = width * 2 + 1; // +1, Because of right side
      this->height = height + 1; // +1, Because of top side
      InitRectangleSize(this->rectangle);
      MakeRectangle(this->rectangle, this->symbolsToDraw2d, isVisible);
    }

    void Show () {
      signed int spaces = -1;
      for (auto& row : rectangle) {
        if (spaces > 0) std::printf("%*c", spaces, ' ');
        for (auto& column : row) {
          std::cout << column;
        }
        std::cout << std::endl;
        spaces++;
      }
    }
};