#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;

struct Student
{
    int id;
    string name;

    Student(int id, string name) : id(id), name(name) {}
};

class studentHashtable
{
    vector<list<Student>> hashtable;
    int buckets;

    public:
    studentHashtable(int size)
    {
        buckets = size;
        hashtable.resize(buckets);
    }

    int hashvalue(int id)
    {
        return id%buckets;
    }

    void add(int id, string name)
    {
        int idx = hashvalue(id);
        hashtable[idx].push_back(Student(id,name));
    }

    Student* search(int id)
    {
        int idx = hashvalue(id);
        for(Student& s : hashtable[idx])
        {
            if(s.id == id)
            {
                return &s;
            }
        }
    }

    void deleteStudent(int id)
    {
        int idx = hashvalue(id);
        
    }
};


int main()
{

}