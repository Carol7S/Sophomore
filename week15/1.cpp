#include <iostream>
#include <fstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ofstream out;
	out.open("in.txt", ios::out);
	if(out.is_open())
	{
		out << 10 <<"\n";
		out << 12.2 << endl;
		out << "apple" << endl;
		out.close();
	}
	ifstream in;
	in.open("in.txt", ios::in);
	char buff[1024];
	if(in.is_open())
	{
		while(!in.eof())
		{
			in.getline(buff, 1024);
			cout << buff << endl;
		}
	}
	in.close();
	return 0;
}
