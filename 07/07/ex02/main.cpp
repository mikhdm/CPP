#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750

int main(int, char**)
{
    std::cout << "TEST: " << std::endl << std::endl;

    Array<char> arr(26);

    std::cout << "Creation of English alphabet array" << std::endl;
    
    for (unsigned int j = 0, i = 97; j < arr.size() ; ++i, ++j) {
        arr[j] = static_cast<char>(i);
    }
    std::cout << arr << std::endl;

    for (unsigned int i = 20; i < arr.size(); ++i) {
        arr[i] = '0';
    }
    std::cout << arr << std::endl;

    Array<char> arr2(26);
    arr2 = arr;
    std::cout << arr2 << std::endl;

    arr2[25] = 'z';

    Array<char> arr3(arr2);
    std::cout << arr3 << std::endl;

    Array<std::string> arr4;
    
    try {
        arr4[0] = "string";
    }
    catch (std::exception const& e) {
        std::cout << "arr4: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "GIVEN FILE:" << std::endl << std::endl;

    {
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;//
        return 0;
    }
}

