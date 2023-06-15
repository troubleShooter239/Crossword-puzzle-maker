#pragma once

using namespace System;
using namespace System::Collections::Generic;
//ref class CrosswordAlgorithm
//{
//private:
//    int crosswordSize;
//
//public:
//    CrosswordAlgorithm(int size);
//
//    enum class Direction{
//        Horizontal,
//        Vertical
//    };
//
//    void GetStartPosition(String^ word, int% startX, int% startY, int% direction);
//};

public ref class CrosswordAlgorithm
{
public:
    CrosswordAlgorithm(int size)
    {
        crosswordSize = size;

    }

    void GetStartPosition(String^ word, int% startX, int% startY, int% direction)
    {
        if (placedWords->Count == 0)
        {
            // Первое слово помещается по центру кроссворда
            direction = static_cast<int>(Direction::Horizontal);
            startX = crosswordSize / 2 - word->Length / 2;
            startY = crosswordSize / 2;
        }
        else
        {
            // Сортируем уже размещенные слова по длине (от самого короткого до самого длинного)
            //std::sort(placedWords.begin(), placedWords->end(), CompareWordLength);
            placedWords->Sort(gcnew Comparison<WordPlacement^>(CompareWordLength));

            bool foundPlacement = false;
            for each (WordPlacement^ placedWord in *placedWords)
            {
                for (int i = 0; i < word->Length; i++)
                {
                    int x, y;
                    if (TryFindIntersection(placedWord, word, i, x, y))
                    {
                        startX = x;
                        startY = y;
                        direction = GetOppositeDirection(placedWord->direction);
                        foundPlacement = true;
                        break;
                    }
                }
                if (foundPlacement)
                    break;
            }

            // Если не удалось найти пересечение со словами, уже размещенными на кроссворде, выбираем случайные координаты
            if (!foundPlacement)
            {
                Random^ random = gcnew Random();

                direction = random->Next(2) == 0 ? static_cast<int>(Direction::Horizontal) : static_cast<int>(Direction::Vertical);
                if (direction == static_cast<int>(Direction::Horizontal))
                {
                    startX = random->Next(crosswordSize - word->Length + 1);
                    startY = random->Next(crosswordSize);
                }
                else
                {
                    startX = random->Next(crosswordSize);
                    startY = random->Next(crosswordSize - word->Length + 1);
                }
            }
        }

        // Добавляем размещенное слово в список
        placedWords->Add(gcnew WordPlacement(word, startX, startY, direction));
    }

    enum class Direction
    {
        Horizontal, Vertical
    }; // Перечисление для определения направления слова

private:
    int crosswordSize; // Размер кроссворда

    ref class WordPlacement
    {
    public:
        String^ word;
        int startX;
        int startY;
        int direction;

        WordPlacement(String^ w, int x, int y, int dir)
        {
            word = w;
            startX = x;
            startY = y;
            direction = dir;
        }
    };

    //std::vector<WordPlacement^>* placedWords;
    List<WordPlacement^>^ placedWords = gcnew List<WordPlacement^>(); // ^_^

    static int CompareWordLength(WordPlacement^ a, WordPlacement^ b)
    {
        return a->word->Length.CompareTo(b->word->Length);
    }

    int GetOppositeDirection(int dir)
    {
        return (dir == static_cast<int>(Direction::Horizontal)) ? static_cast<int>(Direction::Vertical) : static_cast<int>(Direction::Horizontal);
    }

    bool TryFindIntersection(WordPlacement^ placedWord, String^ word, int index, int% intersectX, int% intersectY)
    {
        int x, y;
        x = placedWord->startX;
        y = placedWord->startY;
        for (int i = 0; i < index; i++)
        {
            if (placedWord->direction == static_cast<int>(Direction::Horizontal))
                x++;
            else
                y++;
        }

        for (int i = 0; i < word->Length; i++)
        {
            if (x >= 0 && x < crosswordSize && y >= 0 && y < crosswordSize)
            {
                if (word[i] != placedWord->word[i])
                    return false;
            }
            else
            {
                return false;
            }

            if (placedWord->direction == static_cast<int>(Direction::Horizontal))
                x++;
            else
                y++;
        }

        intersectX = x - word->Length;
        intersectY = y - word->Length;
        return true;
    }
};