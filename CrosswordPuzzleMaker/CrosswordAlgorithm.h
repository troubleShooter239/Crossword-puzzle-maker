#pragma once

using namespace System;

ref class CrosswordAlgorithm
{
private:
    int crosswordSize;

public:
    CrosswordAlgorithm(int size);

    enum class Direction
    {
        Horizontal,
        Vertical
    };

    void GetStartPosition(String^ word, int% startX, int% startY, int% direction);
};

