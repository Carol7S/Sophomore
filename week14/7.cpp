#include <iostream>
#include <map>
#include <string>
#include <fstream>
//#include <mutlimap>
using namespace std;

double sum;

class Book
{
    private:
        string name;
        string press;
        double price;
    public:
        Book(){}
        Book(string n, string p, double _p){name=n; press=p; price=_p;}
        ~Book(){}
        friend ostream& operator<<(ostream& os, Book& b)
        {
            os << b.name << " " << b.press << " " << b.price;
            return os;
        }
        void sell()
        {
            sum += price;
        }
};

int main()
{
    multimap<int, Book> bMap;
    Book b1("基督山伯爵", "吉林出版社", 50.5), b2("百年孤独", "吉林出版社", 55), b3("基督山伯爵", "吉林出版社", 50.5);
    bMap.insert(make_pair(10000, b1));
    bMap.insert(make_pair(10001, b2));
    bMap.insert(make_pair(10000, b3));
    typedef multimap<int ,Book>::iterator BookIt;
    pair<BookIt, BookIt>range = bMap.equal_range(10000);
    for(BookIt it = range.first; it!=range.second; ++it)
    {
        cout << it->second << endl;
    }
    BookIt it = range.first;
    it->second.sell();
    ++it;
    it->second.sell();
    cout << sum << endl;
    system("pause");
    return 0;
}