//
// Created by Chandler Desforges on 10/3/24.
//

#ifndef BOOTLEG_VECTOR_VECTOR_CPP
#define BOOTLEG_VECTOR_VECTOR_CPP

#include "vector.h"

template<typename T>
vector<T>::vector() : m_size(0), m_capacity(m_default_size)
{
    m_data = new T[m_capacity];
}

template<typename T>
vector<T>::vector(const vector &other)
{
    if(this != &other)
    {
        m_size = other.m_size;
        m_capacity = other.m_capacity;

        m_data = new T[m_capacity];

        for(size_t i = 0; i < m_size; i++)
            m_data[i] = other.m_data[i];
    }
}

template<typename T>
vector<T>::vector(vector&& other) noexcept
{
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_data = other.m_data;

    other.m_data = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
}

template<typename T>
vector<T>::vector(std::initializer_list<T> list) noexcept
{
    m_capacity = list.size() * 2;
    m_size = list.size();
    m_data = new T[m_capacity];

    size_t i = 0;
    for(auto elem : list)
        m_data[i++] = elem;
}

template<typename T>
vector<T>::~vector()
{
    delete[] m_data;
}

template<typename T>
int vector<T>::size()
{
    return m_size;
}

template<typename T>
int vector<T>::capacity()
{
    return m_capacity;
}

// actions

template<typename T>
void vector<T>::push_back(const T &newData)
{
    if(m_size == m_capacity)
        resizeUp();

    m_data[m_size++] = newData;
}

template<typename T>
void vector<T>::pop_back()
{
    assert(m_size > 0);

    m_size--;

    if(m_size < m_capacity / 2)
        resizeDown();
}

template<typename T>
void vector<T>::resizeUp()
{
    T* new_arr = new T[m_capacity *= 2];

    for(int i = 0; i < m_size; i++)
        new_arr[i] = m_data[i];

    delete[] m_data;
    m_data = new_arr;
}

template<typename T>
void vector<T>::resizeDown()
{
    T* new_arr = new T[m_capacity /= 2];

    for(int i = 0; i < m_size; i++)
        new_arr[i] = m_data[i];

    delete[] m_data;
    m_data = new_arr;
}

template<typename T>
T &vector<T>::operator[](size_t index)
{
    assert(index < m_size);

    return m_data[index];
}

template<typename T>
T &vector<T>::operator[](size_t index) const
{
    assert(index < m_size);

    return m_data[index];
}

template<typename T>
vector<T> &vector<T>::operator=(const vector &newData)
{
    if(this == &newData)
        return *this;

    delete[] m_data;

    m_size = newData.m_size;
    m_capacity = newData.m_capacity;
    m_data = new T[m_capacity];

    for(int i = 0; i < m_size; i++)
        m_data[i] = newData[i];

    return *this;
}

template<typename T>
vector<T> &vector<T>::operator=(const std::initializer_list<int> &newData)
{
    delete[] m_data;

    m_capacity = newData.size() * 2;
    m_size = newData.size();
    m_data = new T[m_capacity];

    size_t index = 0;
    for(int it : newData)
        m_data[index++] = it;

    return *this;
}

template<typename T>
vector<T> operator+(const vector<T>& lhs, const vector<T>& rhs)
{
    vector<T> result(lhs);

    for(size_t i = 0; i < rhs.m_size; i++)
        result.push_back(rhs.m_data[i]);

    return result;
}

template<typename T>
vector<T> &vector<T>::operator+=(const vector &newData)
{
    for(size_t i = 0; i < newData.m_size; i++)
        this->push_back(newData.m_data[i]);

    return *this;
}

template<typename T>
std::string vector<T>::vec_to_string()
{
    std::string res;

    res += "{";

    if constexpr (std::is_same<T, char>::value || std::is_same<T, std::string>::value || std::is_convertible<T, std::string>::value)
    {
        for(int i = 0; i < m_size; i++)
        {
            res += m_data[i];

            if (i != m_size - 1)
                res += ", ";
        }
    }
    else if constexpr (std::is_arithmetic<T>::value)
    {
        for(int i = 0; i < m_size; i++)
        {
            res += std::to_string(m_data[i]);

            if (i != m_size - 1)
                res += ", ";
        }
    }

    res += "}";

    return res;
}

template<typename T>
std::string vector<T>::vec_info_to_str()
{
    std::string res;

    res += vec_to_string();
    res += " | size: ";
    res += std::to_string(m_size);
    res += ", capacity: ";
    res += std::to_string(m_capacity) + "\n";

    return res;
}

template<typename T>
T vector<T>::at(size_t index)
{
    return m_data[index];
}

template<typename T>
void vector<T>::insert(const T& object, size_t index)
{
    if(m_size == m_capacity)
        resizeUp();

    for(size_t i = m_size - 1; i >= index; i--)
        m_data[i + 1] = m_data[i];

    m_data[index] = object;
    m_size++;
}

template<typename T>
void vector<T>::erase(size_t index)
{
    for(size_t i = index; i < m_size; i++)
        m_data[i] = m_data[i + 1];

    m_size--;

    if(m_size == m_capacity / 2)
        resizeDown();
}

template<typename T>
int vector<T>::indexOf(const T& val)
{
    for(size_t i = 0; i < m_size; i++)
        if(m_data[i] == val)
            return (int)i;

    return -1;
}

template<typename T>
T vector<T>::front()
{
    if(m_size > 0)
        return m_data[0];
    else
        assert(false && "The vector is empty, cannot access front element");
}

template<typename T>
T vector<T>::back()
{
    if(m_size > 0)
        return m_data[m_size - 1];
    else
        assert(false && "The vector is empty, cannot access front element");
}

#endif