#include <iostream>

#include "Array.h"

class Test
{
    public:
        Test() { std::cout << "Test::Test()" << std::endl; }
        Test(Test const&) { std::cout << "Test::Test(Test const&)" << std::endl; }
        ~Test() { std::cout << "Test::~Test()" << std::endl; }
        Test& operator=(Test const&)

        {
            std::cout << "Test& Test::operator=(Test const&)" << std::endl;
            return *this;
        }
        
        void print() const { std::cout << "Test::print() const" << std::endl; }
        void print() { std::cout << "Test::print()" << std::endl; }
};

int main(int, char*[])
{
    Array<Test, 3> arr_1;
    arr_1[1].print();

    {
        Array<Test, 1> arr_2;
        Test t1 = arr_2[0];

        {
            Test& t2 = arr_1[2];
            t2.print();
            t1 = arr_1[0];
        }
    }

    std::cout << arr_1.size() << std::endl;

    {
        Array<Test, 3> arr_3 = arr_1;
        arr_1 = arr_3;
    }

    return EXIT_SUCCESS;
}