#pragma once

public ref class CrosswordAlgorithm
{
public:
    enum class Direction
    {
        Horizontal, 
        Vertical
    };
    CrosswordAlgorithm(int size);
    void GetStartPosition(
        System::String^ word, int% startX, int% startY, int% direction);

private:
    int crosswordSize;

    ref class WordPlacement
    {
    public:
        System::String^ word;
        int startX;
        int startY;
        int direction;

        WordPlacement(System::String^ w, int x, int y, int dir);
    };

    System::Collections::Generic::List<WordPlacement^>^ placedWords 
        = gcnew System::Collections::Generic::List<WordPlacement^>(); // ^_^

    static int CompareWordLength(WordPlacement^ a, WordPlacement^ b);
    int GetOppositeDirection(int dir);
    bool TryFindIntersection(WordPlacement^ placedWord, System::String^ word,
                             int index, int% intersectX, int% intersectY);
};