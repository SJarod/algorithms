#pragma once

template <typename T, unsigned int A>
class Array
{
    private:
        T values[A];

    public:
        Array() = default;
        Array(const Array& arr)
        {
            for (int i = 0; i < A; ++i)
            {
                values[i] = arr.values[i];
            }
        }

        unsigned int size() const
        {
            return A;
        }

        const T& operator[](unsigned int b) const
        {
            return values[b];
        }

        T& operator[](unsigned int b)
        {
            return values[b];
        }
};

// template <typename T, unsigned int a>
// int Array::size() const
// {

// }

// template <typename T, unsigned int a>
// const T& Array::operator[](unsigned int b) const
// {

// }

// template <typename T, unsigned int a>
// T& Array::operator[](unsigned int b)
// {

// }