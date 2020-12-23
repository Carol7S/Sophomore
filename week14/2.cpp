#include <iostream>
#include <queue>
#include <string>
#include <fstream>
using namespace std;

class Book
{
    private:
        string name;
        double price;
    public:
        Book() {}
        Book(string n, int p){
            name = n;
            price = p;
        }
        
        ~Book() {}
        friend ostream& operator<<(ostream& os, Book& b)
        {
            os << b.name << endl;
            os << b.price << endl;
            //os << endl;
            return os;
        }

};

int main()
{
    
    queue<Book> b;
    Book b1("基督山伯爵", 50.55), b2("百年孤独", 56), b3;
    b.push(b1);
    b.push(b2);
    b3 = b.front();
    cout << b3 << endl;
    b.pop();
    cout << b.front() << endl;
    
    system("pause");
    return 0;
}