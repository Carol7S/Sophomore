#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
#define N 3
class Student
{
    private:
        string name;
        int grade;
    public:
        Student() {}
        Student(string n, int g){name=n; grade=g;}
        //Student(Student& s){}
        ~Student() {}
        friend ostream& operator<<(ostream& os, Student& s) 
        {
            os << s.name << " " << s.grade;
            return os;
        }
};

int main()
{
    int idx;
    map<int, Student> mapS;
    Student s1("张三", 98), s2("李四", 97), s3("王五", 95);
    mapS[1] = s1;
    mapS[2] = s2;
    //mapS[3] = s3;
    mapS.insert(pair<int ,Student>(3, s3));
    for(auto it=mapS.begin(); it!=mapS.end(); ++it)
    {
        cout << it->first <<" " << it->second << endl;
    }
    
    system("pause");
    return 0;
}