//
// Created by aviaa on 5/22/2022.
//

#ifndef MTMCHKIN_QUEUE_H
#define MTMCHKIN_QUEUE_H


/*
 * filter(queue, isEven) without assignment ????
 * what if function not returning good type
 * what if allocation fail? try catch and throw ?
 *meaning of const Queue<T> ?
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

template <class T, class Function>
Queue<T> filter(Queue<T> queue, Function filter);
template<class T, class Function>
void transform(Queue<T>& queue, Function transformFunc);

template<class T>
class Queue<T>::Node {
public: //? or friend ?
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
Queue<T>::Queue(const Queue<T>& queue) :m_firstNode(NULL), m_size(0){
    const Node* temp=&queue.m_firstNode;

    while (temp!=NULL)
    {
        this->pushBack(temp->m_data);
        temp=temp->m_next;
    }
    this->m_size=queue.m_size;
}

template<class T>
Queue<T>::~Queue<T>()
{
    Node* ptr = &m_firstNode;
    while (ptr != NULL)
    {
        Node* next = m_firstNode.m_next;
        delete ptr;
        ptr = next;
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
    const Node* node = &queue.m_firstNode;
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
    return *this;
}


template<class T>
void Queue<T>::pushBack(T data)
{

    if (m_size == 0)
    {
        m_firstNode.m_data = data;
        m_size = 1;
    }
    else
    {
        try
        {
            Node* newNode = new Node(data);
            Node* temp = &m_firstNode;
            while (temp->m_next != NULL)
            {
                temp = temp->m_next;
            }

            temp->m_next = newNode;
            m_size++;

            /*Queue<T> *newNode = new Queue<T>();
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
             */
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
        delete &m_firstNode;
        m_firstNode.m_data=NULL;
        this->m_size = 0;
    }
    else
    {
        Node* temp = m_firstNode.m_next;
        m_firstNode.m_data = temp->m_data;
        m_firstNode.m_next= temp->m_next;
        m_size--;
        delete temp;
    }
}

template<class T>
T Queue<T>::front() const
{
    if(m_size==0)
    {
        throw EmptyQueue();
    }
    return m_firstNode.m_data;
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
    {
        return queue;
    }
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
    return Iterator(&m_firstNode);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end() const
{
    return Iterator(NULL);
}

//*******************************************************

template<class T>
class Queue<T>::Iterator
{

private:
    Node* m_node;
    //int m_index;

    Iterator(Node* node);
    friend class Queue<T>;

public:
    const T& operator*() const;
    bool operator!=(const Iterator& iterator) const;
    Iterator& operator++();

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
bool Queue<T>::Iterator::operator!=(const Iterator& it) const
{
    //if (this->m_queue != it.m_queue)
    {
   //     throw InvalidOperation();
    }
    return( m_node!=it.m_node);
   // return (this->m_index != it.m_index);
}

template<class T>
const T& Queue<T>::Iterator::operator*() const
{
    return m_node->m_data;
}

//****************************************************


#endif //MTMCHKIN_QUEUE_H
