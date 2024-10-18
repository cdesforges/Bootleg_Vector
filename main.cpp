#include <iostream>
#include "vector.h"

int main()
{
    vector<int> test1 = {1, 2, 3, 4};

    vector<int> test2;

    test2 = {1, 2, 3, 4};

    test2 = test2 + test1;

    std::cout << "Test 2: " << test2.vec_info_to_str();

    test2.push_back(54);

    std::cout << "Test 2: " << test2.vec_info_to_str();

    test2.insert(10, 2);

    std::cout << "Test 2: " << test2.vec_info_to_str();

    test2.pop_back();

    std::cout << "Test 2: " << test2.vec_info_to_str();

    std::cout << "Index of 10 is: " << test2.indexOf(10) << std::endl;



    vector<int> result1 = {5, 4, 3};

    result1.push_back(4);
    std::cout << result1.vec_info_to_str() << std::endl;
    result1.push_back(4);
    std::cout << result1.vec_info_to_str() << std::endl;
    result1.push_back(4);
    std::cout << result1.vec_info_to_str() << std::endl;

    vector<std::string> result = {"testing1", "testing2", "testing3", "testing4", "testing5"};

    result.push_back("testing6");
    std::cout << result.vec_info_to_str() << std::endl;
    result.push_back("testing7");
    std::cout << result.vec_info_to_str() << std::endl;
    result.push_back("testing8");
    std::cout << result.vec_info_to_str() << std::endl;
    result.push_back("testing9");
    std::cout << result.vec_info_to_str() << std::endl;
    result.push_back("testing10");
    std::cout << result.vec_info_to_str() << std::endl;
    result.push_back("testing11");
    std::cout << result.vec_info_to_str() << std::endl;

    result.pop_back();
    std::cout << result.vec_info_to_str() << std::endl;
    result.pop_back();
    std::cout << result.vec_info_to_str() << std::endl;
    result.pop_back();
    std::cout << result.vec_info_to_str() << std::endl;
    result.pop_back();
    std::cout << result.vec_info_to_str() << std::endl;
    result.pop_back();
    std::cout << result.vec_info_to_str() << std::endl;
    result.pop_back();
    std::cout << result.vec_info_to_str() << std::endl;
    result.pop_back();
    std::cout << result.vec_info_to_str() << std::endl;
    result.pop_back();
    std::cout << result.vec_info_to_str() << std::endl;
    result.pop_back();
    std::cout << result.vec_info_to_str() << std::endl;
    result.pop_back();
    std::cout << result.vec_info_to_str() << std::endl;
    result.pop_back();
    std::cout << result.vec_info_to_str() << std::endl;
    result.pop_back();


    return 0;
}
