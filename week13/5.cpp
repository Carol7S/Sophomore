#include <iostream>
#include <algorithm>
#include <cassert>
#include <ostream>
using namespace std;
template <typename T>
class Myvector
{
    private:
        T* p;
        int size;
        int capacity;
        void _CheckCapacity()
	    {
            if (size == capacity){
                reserve(capacity * 2);
            }
	    }

    public:
        //无参数
        Myvector()
            : p(new T[3])
            , size(0)
            , capacity(3)
        {}
        //有参数
        Myvector(T* arr, int _size)
            :p(new T[_size])
            ,size(_size)
            ,capacity(_size)
        {
            for(int i=0; i<size; i++)
            {
                p[i] = arr[i];
            }
        }
        //区间构造函数
        Myvector(T* first, T* last)
        {
            size = last - first;
            p = new T[size];
            capacity = size;
            for(int i=0; i<size; i++)
            {
                p[i] = first[i];
            }
        }
        //拷贝构造
        Myvector(Myvector &m)
        {
            size = m.size;
            capacity = size;
            p = new T[size];
            for(int i=0; i<m.size; i++)
            {
                p[i] = m.p[i];
            }
        }
        //析构
        ~Myvector()
        {
            if(p)
            {
                delete[] p;
                p = NULL;
                size = 0;
                capacity = 0;
            }
        }
        //运算符重载
        T operator[](int index)
        {
            assert(index < size && index >= 0);
            return p[index];
        }
        T front()
        {
            return p[0];
        }
        T back()
        {
            return p[size-1];
        }
        int Size()
        {
            return size;
        }
        int Capacity()
        {
            return capacity;
        }
        //重设size
        void resize(int newsize, T data)
        {
            if(newsize < size)
            {
                size = newsize;
            }
            else
            {
                if(newsize < capacity)
                {
                    for(int i=size; i<newsize; i++)
                        p[i] = data;
                }
                else
                {
                    int oldsize = Size();
                   reserve(newsize);
                   size = newsize;
                   capacity = size;
                   for(int i=oldsize-1; i<newsize; i++)
                   {
                       p[i] = data;
                   }
                }
                
            }
        }
        //重设capacity
        void reserve(int newcapacity)
        {
            if(newcapacity > capacity)
            {
                T* pTmp = new T[capacity];
                for(int i=0; i<size; i++)
                {
                    pTmp[i] = p[i];
                }
                delete[] p;
                p = new T[newcapacity];
                for(int i=0; i<size; i++)
                {
                    p[i] = pTmp[i];
                }
                capacity = newcapacity;
            }
        }
        void push_back(T data)
        {
            _CheckCapacity();
            p[size++] = data;
        }
        void pop_back()
        {
            size--;
        }
        void Insert(int pos, T data)
        {
            if(pos > size)
            {
                return;
            }
            _CheckCapacity();
            for(int i=size; i >= pos; i--)
            {
                p[i] = p[i-1];
            }
            p[pos-1] = data;
            size++;
        }
        void Earse(int pos)
        {
            if(pos >= size)
            {
                return;
            }
            for(int i=pos; i <= size-1; i++)
            {
                p[i-1] = p[i];
            }
            size--;
        }
        void clear()
        {
            size = 0;
        }
        friend ostream& operator<<(ostream& _cout, const Myvector& v)
	    {
            for (int i = 0; i < v.size; ++i){
                cout << v.p[i] << " ";
            }
            return _cout;
	    }
};

void Test()
{
    Myvector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    cout << arr << endl;
    cout << arr.front() << endl;
    cout << arr.back() << endl;
    arr.pop_back();
    cout << arr << endl;
    cout << arr.Size() << endl;
    arr.push_back(4);
    arr.push_back(5);
    cout << arr << endl;
    arr.Insert(3, 3);
    cout << arr << endl;
    arr.Earse(3);
    cout << arr << endl;
    cout << arr.Capacity() << endl;
    cout << arr[2] << endl;
    arr.resize(10, 6);
    cout << arr << endl;
    arr.clear();
    cout << arr << endl;
}

int main()
{
    Test();
    system("pause");
    return 0;
}