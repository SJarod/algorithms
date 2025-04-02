#include <iostream>

#include "SmartPtr.h"

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
    int* ptr_i = new int(5);
    SmartPtr<int> ptr = SmartPtr<int>(ptr_i);
    SmartPtr<int> ptr2 = ptr;
    std::cout << "int: " << *ptr << std::endl;
    SmartPtr<Test> ptr_t1 = SmartPtr<Test>(new Test);
    SmartPtr<Test> ptr_t2;
    ptr_t1->print();

    {
        Test const& t = *ptr_t1;
        t.print();
    }

    ptr_t2 = ptr_t1;
    ptr_t1.reset();

    {
        SmartPtr<Test> ptr_t3 = ptr_t2;
        (*ptr_t3).print();
    }

    if (ptr_t1)
        std::cout << "SmartPtr is not empty" << std::endl;
    else
        std::cout << "SmartPtr is empty" << std::endl;

    ptr_t1 = SmartPtr<Test>(new Test);
    return EXIT_SUCCESS;
}