#include <iostream>
#include <fstream>
using namespace std;

class Test
{
public:
	int a, b;
    char c;
	friend ostream& operator<<(ostream& os, Test& t)
	{
		os << t.a << " ";
		os << t.b << " ";
		os << t.c << endl;
		return os;
	}
};

int main()
{
	Test t1, t2, t3;
	t1.a=1;t1.b=2;t1.c='A';
	t2.a=3;t2.b=4;t2.c='B';
	t3.a=5;t3.b=6;t3.c='C';
	//cout << t1;
	ofstream out;
	out.open("in.txt", ios::out);
	if(out.is_open())
	{
		out.write((char*)&t1, sizeof(Test));
		out.write((char*)&t2, sizeof(Test));
		out.write((char*)&t3, sizeof(Test));
		out.close();
	}
	ifstream in;
	in.open("in.txt", ios::in);
	Test t4, t5, t6;
	if(in.is_open())
	{
		in.read((char*)&t4, sizeof(Test));
		in.read((char*)&t5, sizeof(Test));
		in.read((char*)&t6, sizeof(Test));
		in.close();
	}
	cout << t4;
	cout << t5;
	cout << t6;
	return 0;
}