#ifndef ITERATOR_H
#define ITERATOR_H

template <class N, class T>
class Iterator {
public:
    Iterator(const std::shared_ptr<N>& item);

    std::shared_ptr<T> operator*();
    std::shared_ptr<T> operator->();
    Iterator operator++();
    Iterator operator++(int index);
    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;

private:
    std::shared_ptr<N> m_item;
};

template <class N, class T>
Iterator<N, T>::Iterator(const std::shared_ptr<N>& item)
{
    m_item = item;
}

template <class N, class T>
std::shared_ptr<T> Iterator<N, T>::operator*()
{
    return m_item->getItem();
}

template <class N, class T>
std::shared_ptr<T> Iterator<N, T>::operator->()
{
    return m_item->getItem();
}

template <class N, class T>
Iterator<N, T> Iterator<N, T>::operator++()
{
    m_item = m_item->getNext();

    return *this;
}

template <class N, class T>
Iterator<N, T> Iterator<N, T>::operator++(int index)
{
    Iterator tmp(m_item);

    m_item = m_item->getNext();

    return tmp;
}

template <class N, class T>
bool Iterator<N, T>::operator==(const Iterator& other) const
{
    return m_item == other.m_item;
}

template <class N, class T>
bool Iterator<N, T>::operator!=(const Iterator& other) const
{
    return !(*this == other);
}

#endif
