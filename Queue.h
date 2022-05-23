//
// Created by aviaa on 5/22/2022.
//

#ifndef MTMCHKIN_QUEUE_H
#define MTMCHKIN_QUEUE_H
template<class T>
class Queue{

public:

    Queue();



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


#endif //MTMCHKIN_QUEUE_H
