//
// Created by Chandler Desforges on 9/12/24.
//

#ifndef BOOTLEG_VECTOR_VECTOR_H
#define BOOTLEG_VECTOR_VECTOR_H

#include <cstddef>
#include <type_traits>
#include <initializer_list>
#include <cassert>
#include <string>


template <typename T>
class vector
{
private:
    T* m_data;
    size_t m_capacity;
    size_t m_size;
    const static int m_default_size = 4;

private:
    void resizeUp();
    void resizeDown();

public:
    vector();
    vector(const vector &other);
    vector(vector &&other) noexcept;
    vector(std::initializer_list<T> list) noexcept;
    ~vector();

    // getters
    int size();
    int capacity();
    T front();
    T back();

    // fns
    void push_back(const T &newData);
    void pop_back();
    std::string vec_to_string();
    std::string vec_info_to_str();
    T at(size_t index);
    void insert(const T& object, size_t index);
    void erase(size_t index);
    int indexOf(const T& val);

    // operators
    T& operator[](size_t index);
    T& operator[](size_t index) const;
    vector<T>& operator=(const vector &newData);
    vector<T>& operator=(const std::initializer_list<int> &newData);
    vector<T>& operator+=(const vector &newData);

    // friends
    template<typename U>
    friend vector<U> operator +(const vector<U>& lhs, const vector<U>& rhs);

};

#include "vector.cpp"


#endif //BOOTLEG_VECTOR_VECTOR_H
