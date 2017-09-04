#ifndef QUEUE_TQUEUE_H
#define QUEUE_TQUEUE_H


#include <iostream>
using namespace std;

template <class T>
class TQueue
{
private:
    int begin, end, len, MaxSize;
    T *mas;
public:
    explicit TQueue(int _MaxSize = 10)
    {
        if (_MaxSize <= 0)
            throw "TOO SMALL MAXSIZE";
        MaxSize = _MaxSize;
        mas = new T[MaxSize];
        begin = 0;
        end = -1;
        len = 0;
    }

    ~TQueue()
    {
        delete[] mas;
    }

    TQueue(const TQueue& q)
    {
        MaxSize = q.MaxSize;
        mas = new T[MaxSize];
        for (int i = 0; i < MaxSize; i++)
            mas[i] = q.mas[i];
        begin = q.begin;
        end = q.end;
        len = q.len;
    }

    bool IsEmpty()
    {
        return len == 0;
    }

    bool IsFull()
    {
        return len == MaxSize;
    }

    void Push(const T n)
    {
        if (len == MaxSize)
            throw "QUEUE IS FULL";
        if (end < MaxSize - 1)
            end++;
        else
            end = 0;
        mas[end] = n;
        len++;
    }

    T Pop()
    {
        if (IsEmpty())
            throw "QUEUE IS EMPTY";
        T tmp = mas[begin];
        if (begin < MaxSize - 1)
            begin++;
        else
            begin = 0;
        len--;
        cout << tmp << endl;
        return tmp;
    }

    void Clear()
    {
        begin = 0;
        end = -1;
        len = 0;
    }

    void ShowQueue() {
        if (IsEmpty())
            cout << "QUEUE IS EMPTY" << endl;
        else
        {
            cout << "Current queue: ";
            if (begin > end)
            {
                for (int i = begin; i < MaxSize; i++)
                    cout << mas[i] << " ";
                for (int i = 0; i <= end; i++)
                    cout << mas[i] << " ";
                cout << endl;
            }
            else
                for (int i = begin; i <= end; i++)
                    cout << mas[i] << " ";
        }
        cout << endl;
    }
};

#endif //QUEUE_TQUEUE_H
