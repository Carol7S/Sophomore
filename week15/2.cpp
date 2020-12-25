#include <iostream>
#include <fstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int N = 5;
int main(int argc, char** argv) {
	int arr[N] = {1,2,3,4,5};
	ofstream out;
	out.open("in.txt", ios::out);
	if(out.is_open())
	{
		for(int i=0; i<N; i++)
		{
			out << arr[i] << endl;
		}
		out.close();
	}
	ifstream in;
	in.open("in.txt", ios::in);
	char brr[5];
	if(in.is_open())
	{
		for(int i=0; i<N; i++)
		{
			in.getline(brr, 100);
			cout << brr << endl;
		}
		in.close();
	}
	return 0;
}