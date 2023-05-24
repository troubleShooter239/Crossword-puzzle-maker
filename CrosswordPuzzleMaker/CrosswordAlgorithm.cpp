#include "CrosswordAlgorithm.h"

CrosswordAlgorithm::CrosswordAlgorithm(int size){
    crosswordSize = size;
}

void CrosswordAlgorithm::GetStartPosition(String^ word, int% startX, int% startY, int% direction){
    Random^ random = gcnew Random();

    // Случайно выбираем направление слова
    direction = random->Next(2) == 0 ? static_cast<int>(Direction::Horizontal) : static_cast<int>(Direction::Vertical);

    // Случайно выбираем начальные координаты
    if (direction == static_cast<int>(Direction::Horizontal)){
        startX = random->Next(crosswordSize - word->Length + 1);
        startY = random->Next(crosswordSize);
    }
    else{
        startX = random->Next(crosswordSize);
        startY = random->Next(crosswordSize - word->Length + 1);
    }
}
