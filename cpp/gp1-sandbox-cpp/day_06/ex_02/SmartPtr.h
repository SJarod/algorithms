#pragma once

#include <iostream>

template <typename T>
class SmartPtr
{
    private:
        T*      ptr;
        int*    countptr;

    public:
        SmartPtr() = default;

        SmartPtr(T* p_ptr)
        {
            ptr = p_ptr;
            countptr = new int;
            *countptr = 1;
        };

        SmartPtr(SmartPtr<T> const& copy)
        {
            ptr = copy.ptr;
            countptr = copy.countptr;
            ++(*countptr);
        };

        ~SmartPtr()
        {
            --(*countptr);
            
            if (*countptr == 0)
            {
                delete ptr;
                delete countptr;
            }
        };

        void reset()
        {
            ptr = nullptr;

            return;
        };

        T& operator*()
        {
            return *ptr;
        };

        T* operator->()
        {
            return ptr;
        };

        SmartPtr<T>& operator=(const SmartPtr<T>& copy)
        {
            this->ptr = copy.ptr;
            this->countptr = copy.countptr;

            return *this;
        };

        operator bool ()
        {
            return ptr != nullptr;
        };
};