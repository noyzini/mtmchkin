//
// Created by aviaa on 5/22/2022.
//

#ifndef MTMCHKIN_QUEUE_H
#define MTMCHKIN_QUEUE_H
template<class T>
class Queue{

public:

    Queue();
    void pushBack(T data);



private:
    T m_data;
    T* m_next;
    int m_size;

};

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
        Queue<T> temp = this;
        while (m_next != NULL)
        {
            //temp = temp->m_next;
        }
    }
}


#endif //MTMCHKIN_QUEUE_H
