#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cassert>

using namespace std;
template<typename T>
class MyDeque
{
    private:
        int base;
        int curbase;
        int tail;
        int curtail;
        static const int l = 1;
         map<int, vector<T*>> dq;
    public:
        MyDeque()
            :base(0)
            ,curbase(0)
            ,tail(0)
            ,curtail(0)
        {}
        ~MyDeque()
        {
            for(auto it = dq.begin(); it!=dq.end(); ++it)
            {
                for(auto it2 = it->second.begin(); it2!=it->second.end(); ++it2)
                {
                    delete *it2;
                    *it2 = nullptr;
                }
            }
            dq.clear();
        }
        void push_back(T data)
        {
            while(true)
            {
                if(dq.find(tail) == dq.end())
                {
                    dq[tail] = vector<T*>(l, nullptr);
                    curtail = 0;
                }
                if(curtail >= l)
                {
                    tail += 1;
                    curtail = 0;
                    continue;
                }
                 dq[tail][curtail] = new T(data);
                curtail += 1;
                break;
            } 
        }
        void pop_back()
        {
            if(base = tail && curbase == curtail)
            {
                return;
            }
            delete dq[tail][curtail-1];
            dq[tail][curtail-1]=nullptr;
            curtail -= 1;

            if(curtail <= 0)
            {
                tail -= 1;
                curtail = l;
            }
        }
        void push_front(T data)
        {
            while(true)
            {
                if(dq.find(base) == dq.end())
                {
                    dq[base] = vector<T*>(l, nullptr);
                    curbase = l;
                }
                if(curbase <= 0)
                {
                    base -= 1;
                    curbase = l;
                    continue;
                }
                dq[base][curbase-1] = new T(data);
                curbase -= 1;
                break;
            }
        }
        void pop_front()
        {
            if (base == tail && curbase == curtail)
            {
                return;
            }
            delete dq[base][curbase];
            dq[base][curbase] = nullptr;
            curbase += 1;
            if (curbase == l)
            {
                base += 1;
                curbase = 0;
            }
        }
        T & operator[](int pos)
        {   
            assert(pos >= 0 && pos < size());
            return pos < (l - curbase) ? 
                *(dq[base][curbase + pos]) :
                *(dq[base + (pos - (l - curbase)) / l + 1][(pos - (l - curbase)) % l]);
        }
        int size()
        {
            return (l - curbase) + curtail + (tail - base + 1 - 2) * l;
        }

};

template<typename T>
class MyStack
{
    private:
        MyDeque<T> s;
    public:
        void push(T e)
        {
            s.push_back(e);
        }
        void pop()
        {
            s.pop_back();
        }
        int size()
        {
            return s.size();
        }
        T top()
        {
            return s[s.size()-1];
        }
};

int main()
{
    MyStack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    system("pause");
    return 0;
}