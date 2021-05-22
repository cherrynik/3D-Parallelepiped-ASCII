#include <iostream>
#include <vector>


const std::string WIDTH_SYMBOL = "_",
    WIDTH_HIDDEN_SYMBOL = ".",

    HEIGHT_SYMBOL = "\\",
    HEIGHT_HIDDEN_SYMBOL = "`",

    DEPTH_SYMBOL = "/",
    DEPTH_HIDDEN_SYMBOL = "'";

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
        for (unsigned int column = 0; column < width; ++column) {
          rectangle[row].resize(width);
        }
      }
    }

    void FillRowWithSymbol (const int row, const std::string symbol) {
      // width - 1, Because of top right angle
      for (int column = 0; column < width - 1; ++column) {
        rectangle[row][column] = symbol;
      }
    }

    void FillColumnWithSymbol (const int column, const std::string symbol) {
      // Starts from 1, Because of top side
      for (int row = 1; row < height; ++row) {
        rectangle[row][column] = symbol;
      }
    }

    void FillRemainedWithSpace () {
      for (int column = 1; column < width - 1; ++column) {
        FillColumnWithSymbol(column, " ");
      }
    }

    void MakeRectangle () {
      FillRemainedWithSpace();
      FillRowWithSymbol(height - 1, WIDTH_SYMBOL);
      FillColumnWithSymbol(0, HEIGHT_SYMBOL);
      FillColumnWithSymbol(width - 1, HEIGHT_SYMBOL);
      FillRowWithSymbol(0, WIDTH_SYMBOL);
    }

  public:
    Rectangle (const int width, const int height) {
      this->width = width * 2 + 1; // +1, Because of right side
      this->height = height + 1; // +1, Because of top side
      InitRectangleSize();
      MakeRectangle();
    }

    void Show () {
      for (auto& row : rectangle) {
        for (auto& column : row) {
          std::cout << column;
        }
        std::cout << std::endl;
      }
    }

    void ShowSkewed () {
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