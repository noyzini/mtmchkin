//
// Created by aviaa on 5/22/2022.
//

#ifndef MTMCHKIN_QUEUE_H
#define MTMCHKIN_QUEUE_H

/*
 * template<class T, class Function>  ??
 * filter(queue, isEven) without assignment ????
 * what if function not returning good type
 */

template<class T>
class Queue {

public:

    Queue();

    void pushBack(T data);
    T front();
    int size();

    void popFront();
    //Queue<T>& operator=(const Queue<T>&) = default;

    //friend Queue<T> filter(Queue<T> queue, Condition c);

    class Empty {};

    class Iterator;
    Iterator begin() const;
    Iterator end() const;

private:
    T m_data;
    Queue<T>* m_next;
    int m_size;

};

template<class T>
class Queue<T>::Iterator
{
    const Queue<T> queue;


};


template <class T, class Function>
Queue<T> filter(Queue<T> queue, Function filter);

template<class T>
Queue<T>::Queue() :
m_data(NULL),m_next(NULL),m_size(0)
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
        Queue<T>* node = this;
        while (node->m_next != NULL)
        {
            node->m_size++;
            node = (node->m_next);
        }
        //add exception and remove size from all on catch
        Queue<T>* newNode = new Queue<T>();
        newNode->m_data = data;
        newNode->m_next = NULL;
        newNode->m_size = 1;
        node->m_next = newNode;
        node->m_size++;
    }
}

template<class T>
void Queue<T>::popFront()
{
    if (m_size == 0)
    {
        throw Empty();
    }
    else if (m_size == 1)
    {
        this->m_data = NULL;
        this->m_size = 0;
        this->m_next = NULL;
    }
    else
    {
        Queue<T> *temp = this->m_next;
        this->m_data = temp->m_data;
        this->m_size = temp->m_size;
        this->m_next = temp->m_next;
        delete[] temp;
    }
}


template<class T>
T Queue<T>::front()
{
    if(m_size==0)
    {
        throw Empty();
    }
    return m_data;
}

template<class T>
int Queue<T>::size()
{
    return m_size;
}

template<class T, class Function>
Queue<T> filter(Queue<T> queue, Function filter)
{
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

#endif //MTMCHKIN_QUEUE_H
