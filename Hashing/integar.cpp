#include<iostream>
#include<list>
#include<vector>
#include<algorithm> 

using namespace std;

class Hashing
{
    vector<list<int>> hashtable;
    int buckets;
    public:

    Hashing(int size)
    {
        buckets = size;
        hashtable.resize(buckets);
    }

    int hashvalue(int key)
    {
        return key%buckets;
    }

    void add(int key)
    {
        int idx = hashvalue(key);
        hashtable[idx].push_back(key);
    }

    list<int>::iterator search(int key)
    {
        int idx = hashvalue(key);
        return find(hashtable[idx].begin(), hashtable[idx].end(), key);
    }

    void deletekey(int key)
    {
        int idx = hashvalue(key);
        auto it = search(key);
        if(it != hashtable[idx].end())
        {
            hashtable[idx].erase(it);
            cout << key << "is deleted." << endl;
        }
        else
        {
            cout << "key is not avb" << endl;
        }
    }

    void display() {
        for(int i = 0; i < buckets; ++i) {
            cout << i << ": ";
            for(int val : hashtable[i]) {
                cout << val << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
    
};

int main()
{
    Hashing h(10);

    h.add(50);
    h.add(90);
    h.add(5);
    h.add(25);

    h.display();

    h.deletekey(75);
    h.deletekey(50);

    h.display();
}