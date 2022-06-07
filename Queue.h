
#ifndef MTMCHKIN_QUEUE_H
#define MTMCHKIN_QUEUE_H

#include <iostream>


template<class T>
class Queue {

public:

    /*
    * Default C'tor, copy constructor, d'tor and assignment operator of Queue:
    */
    Queue();
    Queue(const Queue<T>& queue);
    ~Queue();
    Queue<T>& operator=(const Queue<T>& queue);

    /*
     *  Insert a new member to the end of the queue
     *  @return
     *          void
     */
    void pushBack(T data);

    /*
    *  Returns the first member on the queue
    *  @return
    *          T object
    */
    T& front() ;
    const T& front() const;

    /*
    *  Removes the first member from the top.
    *  @return
    *          void
    */
    void popFront();

    /*
    *  Check the number of members on the queue
     *  @return
     *          size of the queue
    */
    int size() const;

    /*
     * Exception class
     */
    class EmptyQueue {};

    /*
     * Iterator and ConstIterator classes and functions
     */
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
/*
 *  Accepts a certain condition and filters the queue organs accordingly
 *  @param Queue - Queue with T template to be filtered
 *  @param Function -function to check T values and filter by bool checks.
 *  @return
 *          Filtered Queue
 */
template <class T, class Function>
Queue<T> filter(Queue<T> queue, Function filter);

/*
 *  Goes through all the queue members and changes them by a given operation
 *  @param Queue - Queue with T template to be changed
 *  @param Function - function to be used on all the T values.
 *  @return
 *          void
 */
template<class T, class Function>
void transform(Queue<T>& queue, Function transformFunc);

/*
* Node class for the struct of Queue
*/
template<class T>
class Queue<T>::Node {
public:
    Node(T data);

    T m_data;
    Node* m_next;
};

template<class T>
Queue<T>::Queue() :m_firstNode(NULL), m_size(0)
{
}

template<class T>
Queue<T>::Node::Node(T data) : m_data(data),m_next(NULL) {}


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
        Node* next = ptr->m_next;
        delete ptr;
        ptr = next;
        m_size--;
    }
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
        throw EmptyQueue();
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

//*****************-Iterator-*******************
template<class T>
class Queue<T>::Iterator
{

private:
    Node* m_node;

    /*
     * C'tor for class Iterator
     */
    Iterator(Node* node);

    friend class Queue<T>;

public:
    /*
     * operators for class Iterator
     */
    T& operator*() const;
    bool operator!=(const Iterator& iterator) const;
    Iterator& operator++();
    Iterator operator++(int);

    /*
     * Exception class
     */
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
    return( m_node!=it.m_node);
}

template<class T>
T& Queue<T>::Iterator::operator*() const
{
    return m_node->m_data;
}

//*****************-ConstIterator-*******************
template<class T>
class Queue<T>::ConstIterator
{
private:
    const Node* m_node;
    /*
     * C'tor for class Iterator
     */
    ConstIterator(const Node* node);
    friend class Queue<T>;

public:
    /*
     * operators for class Iterator
     */
    const T& operator*() const;
    bool operator!=(const ConstIterator& iterator) const;
    ConstIterator& operator++();
    ConstIterator operator++(int);
    /*
     * Exception class
     */
    class InvalidOperation {};
};

template<class T>
Queue<T>::ConstIterator::ConstIterator(const Queue<T>::Node *node):
        m_node(node)
{
}

template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
    if (m_node == NULL)
    {
        throw InvalidOperation();
    }
    m_node = m_node->m_next;
    return *this;
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int)
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
    return( m_node!=it.m_node);
}

template<class T>
const T& Queue<T>::ConstIterator::operator*() const
{
    return m_node->m_data;
}

#endif //MTMCHKIN_QUEUE_H
