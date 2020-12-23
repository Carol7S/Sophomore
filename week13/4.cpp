#include <iostream>
#include <list>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
#define N 3

class Student
{
    private:
        string name;
        double grade;
    public:
        Student(){}
        Student(string n, double g){name = n; grade = g;}
        Student(Student &s) {}
        ~Student() {}
        string getName() {return name;}
        double getGrade() {return grade;}
};

bool cmp(Student *s1, Student *s2)
{
    return s1->getGrade() < s2->getGrade();
}

int main()
{
    Student s1("张三", 98.8), s2("阿萍", 77.7), s3("王五", 88.4);
    Student *pS1, *pS2, *pS3;
    pS1 = &s1; pS2 = &s2; pS3 = &s3;
    Student *pArr[N] = {pS1, pS2, pS3};
    list<Student*> arr;
    list<Student*>::iterator it;
    int i;
    for(i=0; i<N; ++i)
    {
        arr.push_back(pArr[i]);
    }
    arr.sort(cmp);
    for(it=arr.begin(); it!=arr.end(); ++it)
    {
        cout << (*it)->getGrade() << " " << (*it)->getName();
        cout << endl;
    }

    system("pause");
    return 0;
}