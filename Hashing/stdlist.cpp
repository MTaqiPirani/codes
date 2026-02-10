#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

struct Student
{
    int id;
    string name;

    Student(int id, string name)
    {
        this->id = id;
        this->name = name;
    }
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
        return id % buckets;
    }

    void add(int id, string name)
    {
        int idx = hashvalue(id);
        hashtable[idx].push_back(Student(id, name));
    }

    Student* search(int id)
    {
        int idx = hashvalue(id);

        for (Student& s : hashtable[idx])
        {
            if (s.id == id)
                return &s;
        }
        return nullptr;
    }

    void deleteStudent(int id)
    {
        int idx = hashvalue(id);

        for (auto it = hashtable[idx].begin(); it != hashtable[idx].end(); ++it)
        {
            if (it->id == id)
            {
                hashtable[idx].erase(it);
                return;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < buckets; i++)
        {
            cout << "Bucket " << i << ": ";
            for (Student s : hashtable[i])
            {
                cout << "[" << s.id << ", " << s.name << "] ";
            }
            cout << endl;
        }
    }
};

int main()
{
    studentHashtable ht(10);

    ht.add(1, "Ali");
    ht.add(11, "Ahmed");   // collision
    ht.add(21, "Usman");   // collision
    ht.add(5, "Sara");

    cout << "Hash Table:\n";
    ht.display();

    Student* s = ht.search(11);
    if (s != nullptr)
        cout << "\nFound: " << s->id << " " << s->name << endl;
    else
        cout << "\nStudent not found\n";

    ht.deleteStudent(11);
    cout << "\nAfter Deleting ID 11:\n";
    ht.display();

    return 0;
}
