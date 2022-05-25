//
// Created by aviaa on 5/22/2022.
//

#ifndef MTMCHKIN_QUEUE_H
#define MTMCHKIN_QUEUE_H

#include <assert.h>


/*
 * template<class T, class Function>  ??
 * filter(queue, isEven) without assignment ????
 * what if function not returning good type
 * what if allocation fail? try catch and throw ?
 *meaning of const Queue<T> ?
 *
 * TO DO ?
 * Iterator - replace index with Node/Queue ?
 * Queue - replace m_data + m_next with Node
 *
 * Write - d'tor, operation=, copy c'tor
 */

template<class T>
class Queue {

public:


    Queue();
    void pushBack(T data);
    T front() const;
    void popFront();
    int size() const;

    class EmptyQueue {};

    class Iterator;
    Iterator begin() const;
    Iterator end() const;

private:
    class Node;
    Node m_firstNode;
    //T m_data;
    //Queue<T>* m_next;
    int m_size;

};

template <class T>
class Queue<T>::Node {
public:
    Node(T data);
    T m_data;
    Node* m_next;
    //friend Queue<T>;
};

template <class T>
Queue<T>::Node::Node(T data) : m_data(data),m_next(NULL)
{

}

template <class T, class Function>
Queue<T> filter(Queue<T> queue, Function filter);
template<class T, class Function>
void transform(Queue<T>& queue, Function transformFunc);



template<class T>
Queue<T>::Queue() :
m_firstNode(NULL), m_size(0)
{

}

template<class T>
void Queue<T>::pushBack(T data)
{
    if (m_size == 0)
    {
        m_data = data;
        m_size = 1;
    }
    else
    {
        try
        {
            Queue<T> *newNode = new Queue<T>();
            Queue<T> *node = this;
            while (node->m_next != NULL) {
                node->m_size++;
                node = (node->m_next);
            }
            //add exception and remove size from all on catch
            newNode->m_data = data;
            newNode->m_next = NULL;
            newNode->m_size = 1;
            node->m_next = newNode;
            node->m_size++;
        }
        catch (const std::bad_alloc& e)
        {
            throw e;
        }
    }
}

template<class T>
void Queue<T>::popFront()
{
    if (m_size == 0)
    {
        throw EmptyQueue();
    }
    else if (m_size == 1)
    {
        delete m_data;
        this->m_data = NULL;
        this->m_size = 0;
        this->m_next = NULL;
    }
    else
    {
        Queue<T>* temp = this->m_next;
        this->m_data = temp->m_data;
        this->m_size = temp->m_size;
        this->m_next = temp->m_next;
        delete[] temp;
    }
}

template<class T>
T Queue<T>::front() const
{
    if(m_size==0)
    {
        throw EmptyQueue();
    }
    return m_data;
}

template<class T>
int Queue<T>::size() const
{
    return m_size;
}

template<class T, class Function>
Queue<T> filter(Queue<T> queue, Function filter)
{
    if (filter == NULL)
    {
        //????
    }
    if (queue.size() == 0)
        return queue;

    Queue<T> filtered;
    while (queue.size() > 0)
    {
        if (filter(queue.front()))
        {
            filtered.pushBack(queue.front());
        }
        queue.popFront();
    }
    return filtered;
}

template<class T, class Function>
void transform(Queue<T>& queue, Function transformFunc)
{
    if (transformFunc == NULL)
    {
        //????????????
    }
    if(queue.m_size==0)
    {
        return;
    }
    Queue<T> transformed;
    while (queue.size() > 0)
    {
        transformed.pushBack(transformFunc(queue.front()));
        queue.popFront();
    }

    while (transformed.size() > 0)
    {
        queue.pushBack(transformed.front());
        transformed.popFront();
    }
}

template<class T>
typename Queue<T>::Iterator Queue<T>::begin() const
{
    return Iterator(*this,1);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end() const
{
    return Iterator(this,m_size+1);
}

//*******************************************************

template<class T>
class Queue<T>::Iterator
{

private:
    const Queue<T>& m_queue;
    int m_index;

    Iterator(const Queue<int> *queue, int index);
    //friend class Queue<T>;

public:
    const T& operator*() const;
    bool operator!=(const Iterator& iterator) const;
    Iterator& operator++();

    class InvalidOperation {};
};

template<class T>
Queue<T>::Iterator::Iterator(const Queue<int> *queue, int index):
m_queue(queue),m_index(index)
{
}

template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if (m_index == this->m_queue.m_size)
    {
        throw InvalidOperation();
    }
    this->m_index++;
    return *this;
}

template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator& it) const
{
    if (this->m_queue != it.m_queue)
    {
        throw InvalidOperation();
    }
    return (this->m_index != it.m_index);
}

template<class T>
const T& Queue<T>::Iterator::operator*() const
{
    if (m_index <= 0 || m_index > this->m_queue.m_size)
    {
        throw InvalidOperation();
    }
    Queue<T> temp = this->m_queue;
    for (int i = 1; i < m_index; i++)
    {
        temp = temp.m_next;
    }
    return temp.m_data;
}


#endif //MTMCHKIN_QUEUE_H
