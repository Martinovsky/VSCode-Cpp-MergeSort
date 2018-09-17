#include "mergeSort.hpp"

void mergeSort(std::vector<int> &data)
{
    if (data.empty())
    {
        return;
    }
    unsigned int previousStep = 1;
    bool check = true;
    const unsigned int size = data.size();
    for (unsigned int x = 2; check; x *= 2)
    {
        if (x >= size)
        {
            check = false;
        }
        std::vector<int>::iterator max = data.begin();
        std::vector<int>::iterator min = max;
        unsigned int key = 0;
        do
        {
            std::vector<int>::iterator mid = max;
            key += x;
            if (key >= size)
            {
                max = data.end();
                std::advance(mid, previousStep);
            }
            else
            {
                std::advance(max, x);
                std::advance(mid, previousStep);
            }
            std::vector<int> left(min, mid);
            std::vector<int> right(mid, max);
            for (std::vector<int>::iterator i = left.begin(), j = right.begin();
                 min != max; ++min)
            {
                if ((j == right.end()) ||
                    ((i != left.end()) && (*i <= *j)))
                {
                    *min = *i;
                    ++i;
                }
                else
                {
                    *min = *j;
                    ++j;
                }
            }
        } while (key < size);
        previousStep = previousStep * 2;
    }
    return;
}

std::vector<int> mergeSort(const std::vector<int> &data)
{
    std::vector<int> result = data;
    if (result.empty())
    {
        return result;
    }
    unsigned int previousStep = 1;
    bool check = true;
    const unsigned int size = result.size();
    for (unsigned int x = 2; check; x *= 2)
    {
        if (x >= size)
        {
            check = false;
        }
        std::vector<int>::iterator max = result.begin();
        std::vector<int>::iterator min = max;
        unsigned int key = 0;
        do
        {
            std::vector<int>::iterator mid = max;
            key += x;
            if (key >= size)
            {
                max = result.end();
                std::advance(mid, previousStep);
            }
            else
            {
                std::advance(max, x);
                std::advance(mid, previousStep);
            }
            std::vector<int> left(min, mid);
            std::vector<int> right(mid, max);
            for (std::vector<int>::iterator i = left.begin(), j = right.begin();
                 min != max; ++min)
            {
                if ((j == right.end()) ||
                    ((i != left.end()) && (*i <= *j)))
                {
                    *min = *i;
                    ++i;
                }
                else
                {
                    *min = *j;
                    ++j;
                }
            }
        } while (key < size);
        previousStep = previousStep * 2;
    }
    return result;
}