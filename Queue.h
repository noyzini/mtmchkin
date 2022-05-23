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
    T front();
    int size();


    class Empty{};

private:
    T m_data;
    Queue<T>* m_next;
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
        Queue<T>* queue_temp= this;
        while (queue_temp->m_next != NULL)
        {
            queue_temp=queue_temp->m_next;
        }
        Queue<T>* new_node = new Queue<T>();
        new_node->m_data=data;
        new_node->m_next=NULL;
        queue_temp->m_next=new_node;
        this->m_size++;
    }

}

template<class T>
T Queue<T>::front()
{
    if(m_size!=0)
    {
        return m_data;
    }
    throw Empty();
}

template<class T>
int Queue<T>::size()
{
    return m_size;
}

template<class T, class Function>
void transform(Queue<T> &queue, Function func)
{
    if(func==NULL || queue.m_size==0)
    {
        return;
    }
    Queue<T>* queue_temp= &queue;
    while (queue_temp != NULL)
    {
        queue_temp->m_data=func(queue_temp->m_data);
        queue_temp=queue_temp->m_data;
    }
}




#endif //MTMCHKIN_QUEUE_H
