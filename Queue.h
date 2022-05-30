//
// Created by aviaa on 5/22/2022.
//

#ifndef MTMCHKIN_QUEUE_H
#define MTMCHKIN_QUEUE_H

#include <iostream>

/*
 * filter(queue, isEven) without assignment ????
 * what if function not returning good type
 * what if allocation fail? try catch and throw ?
 * meaning of const Queue<T> ?
 *
 * TO DO ?
 * if making copy c'tor use try catch
 * const queueueue
 * const iterator ?????
 * make d'tor for Node if valgrind fail ?
 *
 */

template<class T>
class Queue {

public:

    Queue();
    Queue(const Queue<T>& queue);
    Queue<T>& operator=(const Queue<T>& queue);
    ~Queue();

    void pushBack(T data);
    T& front() ;
    const T& front() const;
    void popFront();
    int size() const;

    class EmptyQueue {};

    class Iterator;
    Iterator begin() ;
    Iterator end() ;

    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;

private:
    class Node;

    Node* m_firstNode;
    int m_size;

};

template <class T, class Function>
Queue<T> filter(Queue<T> queue, Function filter);
template<class T, class Function>
void transform(Queue<T>& queue, Function transformFunc);

template<class T>
class Queue<T>::Node {
public:
    Node(T data);

    T m_data;
    Node* m_next;
};

template<class T>
Queue<T>::Node::Node(T data) : m_data(data),m_next(NULL) {}

template<class T>
Queue<T>::Queue() :m_firstNode(NULL), m_size(0)
{
}

template<class T>
Queue<T>::Queue(const Queue<T>& queue) :
m_firstNode(NULL), m_size(0)
{
    const Node* temp=queue.m_firstNode;
    try
    {
        while (temp!=NULL)
        {

            this->pushBack(temp->m_data);
            temp=temp->m_next;
        }
    }
    catch (std::bad_alloc& e)
    {
        while (m_size>0)
        {
            this->popFront();
        }
        throw e;
    }

    this->m_size=queue.m_size;

}

template<class T>
Queue<T>::~Queue<T>()
{
    Node* ptr = m_firstNode;
    while (ptr != NULL)
    {
        //this->popFront();
        Node* next = ptr->m_next;
        delete ptr;
        ptr = next;
        m_size--;
    }
    /*
    while (this->m_firstNode!=NULL)
    {
        Node* temp = m_firstNode->m_next->m_next;
        delete m_firstNode->m_next;
        this->m_firstNode=temp;

    }
     */

}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& queue)
{
    if (this == &queue)
    {
        return *this;
    }

    Queue<T> temp;
    const Node* node = queue.m_firstNode;
    while (node != NULL)
    {
        temp.pushBack(node->m_data);
        node = node->m_next;
    }
    while (m_size > 0)
    {
        this->popFront();
    }
    m_firstNode = temp.m_firstNode;
    m_size = temp.m_size;
    temp.m_firstNode = NULL;
    return *this;
}

template<class T>
void Queue<T>::pushBack(T data)
{
    try
    {
        if (m_size == 0)
        {
            m_firstNode = (new Node(data));
            m_size = 1;
        }
        else
        {
            Node* newNode = new Node(data);
            Node* temp = m_firstNode;
            while (temp->m_next != NULL)
            {
                temp = temp->m_next;
            }
            temp->m_next = newNode;
            m_size++;
        }
    }
    catch (const std::bad_alloc& e)
    {
        throw e;
    }
}


template<class T>
void Queue<T>::popFront()
{
    if (m_size == 0)
    {
        throw EmptyQueue(); // doing throw without try catch
    }
    else if (m_size == 1)
    {
        delete m_firstNode;
        m_firstNode = NULL;
        this->m_size = 0;
    }
    else
    {
        Node* temp = m_firstNode->m_next;
        m_firstNode->m_data = temp->m_data;
        m_firstNode->m_next= temp->m_next;
        m_size--;
        delete temp;
    }
}

template<class T>
T& Queue<T>::front()
{
    if(m_size==0)
    {
        throw EmptyQueue();
    }
    return m_firstNode->m_data;
}

template<class T>
const T& Queue<T>::front() const
{
    if(m_size==0)
    {
        throw EmptyQueue();
    }
    return m_firstNode->m_data;
}

template<class T>
int Queue<T>::size() const
{
    return m_size;
}

template<class T, class Function>
Queue<T> filter(Queue<T> queue, Function filter)
{
    if (queue.size() == 0)
    {
        return queue;
    }
    Queue<T> filtered;
    /*
    for (typename Queue<T>::Iterator it = queue.begin(); it != queue.end(); ++it)
    {
        if (filter(*it))
            filtered.pushBack(*it);
    }
    */
    for (T value : queue)
    {
        if (filter(value))
            filtered.pushBack(value);
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
    if(queue.size() ==0)
    {
        return;
    }
    Queue<T> transformed;
    while (queue.size() > 0)
    {
        transformFunc(queue.front());
        transformed.pushBack(queue.front());
        queue.popFront();
    }

    while (transformed.size() > 0)
    {
        queue.pushBack(transformed.front());
        transformed.popFront();
    }
}

template<class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
    return Iterator(m_firstNode);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end()
{
    return Iterator(NULL);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    return ConstIterator(m_firstNode);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
    return ConstIterator(NULL);
}
//*******************************************************

template<class T>
class Queue<T>::Iterator
{

private:
    Node* m_node;

    Iterator(Node* node);
    friend class Queue<T>;

public:
    T& operator*() const;
    bool operator!=(const Iterator& iterator) const;
    Iterator& operator++();
    Iterator operator++(int);


    class InvalidOperation {};
};

template<class T>
Queue<T>::Iterator::Iterator(Node* node):
m_node(node)
{
}

template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if (m_node == NULL)
    {
        throw InvalidOperation();
    }
    m_node = m_node->m_next;
    return *this;
}


template<class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int)
{
    if (m_node == NULL)
    {
        throw InvalidOperation();
    }
    Queue<T>::Iterator temp=*this;
    m_node = m_node->m_next;
    return temp;
}



template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator& it) const
{
    //if (this->m_queue != it.m_queue)
    {
   //     throw InvalidOperation();
    }
    return( m_node!=it.m_node);

}

template<class T>
T& Queue<T>::Iterator::operator*() const
{
    return m_node->m_data;
}

//****************************************************
template<class T>
class Queue<T>::ConstIterator
{
private:
    const Node* m_node;

    explicit ConstIterator(const Node* node);
    friend class Queue<T>;

public:
    const T& operator*() const;
    bool operator!=(const ConstIterator& iterator) const;
    ConstIterator& operator++();
    ConstIterator operator++(int );

    class InvalidOperation {};
};

template<class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T>::Node *node):
        m_node(node)
{
}

template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++() //avia thinks it is'nt node
{
    if (m_node == NULL)
    {
        throw InvalidOperation();
    }
    m_node = m_node->m_next;
    return *this;
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int) //avia thinks it is'nt node
{
    if (m_node == NULL)
    {
        throw InvalidOperation();
    }
    Queue<T>::ConstIterator temp=*this;
    m_node = m_node->m_next;
    return temp;
}

template<class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& it) const
{
    //if (this->m_queue != it.m_queue)
    {
        //     throw InvalidOperation();
    }
    return( m_node!=it.m_node);
    // return (this->m_index != it.m_index);
}

template<class T>
const T& Queue<T>::ConstIterator::operator*() const
{
    return m_node->m_data;
}

#endif //MTMCHKIN_QUEUE_H
