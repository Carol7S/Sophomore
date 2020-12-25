#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
const int N = 3;
class Player
{
public:
	char* name;
	char* team;
    int age;
	int no;
	friend ostream& operator<<(ostream& os, Player& p)
	{
		os << p.name << " ";
		os<< p.team << " ";
		os << p.age << " ";
		os << p.no << endl;
		return os;
	}
};

bool compare(Player p1, Player p2)
{
	return p1.no < p2.no;
}

int main()
{
	Player pArr[N];
	pArr[0].name="zhangsan"; pArr[0].team="t1"; pArr[0].age=20; pArr[0].no=1;
	pArr[1].name="lisi"; pArr[1].team="t1"; pArr[1].age=19; pArr[1].no=3;
	pArr[2].name="wangwu"; pArr[2].team="t1"; pArr[2].age=21; pArr[2].no=2;
	//cout << pArr[0];
	sort(pArr, pArr+N, compare);
	//cout << pArr[1];

	ofstream out;
	out.open("in.txt", ios::out);
	if(out.is_open())
	{
		out.write((char*)&pArr[0], sizeof(Player));
		out.write((char*)&pArr[1], sizeof(Player));
		out.write((char*)&pArr[2], sizeof(Player));
		out.close();
	}
	ifstream in;
	in.open("in.txt", ios::in);
	Player pBrr[N];
	if(in.is_open())
	{
		in.read((char*)&pBrr[0], sizeof(Player));
		in.read((char*)&pBrr[1], sizeof(Player));
		in.read((char*)&pBrr[2], sizeof(Player));
		in.close();
	}
	cout << pBrr[0];
	cout << pBrr[1];
	cout << pBrr[2];
	return 0;
}