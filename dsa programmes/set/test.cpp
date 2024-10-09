#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> set1{1, 8, 3};
    std::vector<int> set2{3, 4, 5};
    std::vector<int> result;

    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), std::back_inserter(result));

    std::cout << "Result before clearing: ";
    for (auto num : result)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    result.clear();

    std::cout << "Result after clearing: ";
    for (auto num : result)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
