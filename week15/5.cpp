#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
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
	multimap<int, Player> pMap;
	pArr[0].name="zhangsan"; pArr[0].team="t1"; pArr[0].age=20; pArr[0].no=1;
	pArr[1].name="lisi"; pArr[1].team="t1"; pArr[1].age=19; pArr[1].no=3;
	pArr[2].name="wangwu"; pArr[2].team="t1"; pArr[2].age=21; pArr[2].no=2;
	pMap.insert(make_pair(pArr[0].no, pArr[0]));
	pMap.insert(make_pair(pArr[1].no, pArr[1]));
	pMap.insert(make_pair(pArr[2].no, pArr[2]));
	
	ofstream out;
	out.open("in.txt", ios::out);
	multimap<int, Player>::iterator it;
	if(out.is_open())
	{
		for(it=pMap.begin(); it!=pMap.end(); ++it)
		{
			out.write((char*)&it->second, sizeof(Player));
		}
		out.close();
	}
	
	ifstream in;
	in.open("in.txt", ios::in);
	Player pB;
	vector<Player> pVec;
	if(in.is_open())
	{
		for(int i=0; i<N; i++)
		{
			in.read((char*)&pB, sizeof(Player));
			pVec.push_back(pB);
		}
		in.close();
	}
	vector<Player>::iterator it2;
	/*
	for(it2=pVec.begin(); it2!=pVec.end(); ++it2)
	{
		cout<< *it2;
	}
	*/
	for(auto it2 : pVec)
	{
		cout << it2;
	}
	return 0;
}