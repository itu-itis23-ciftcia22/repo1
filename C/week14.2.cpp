#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>

using namespace std;

class SList {
private:

    class Node {
    public:
        int mval;
        Node *mpnext;
        Node(int val) {
            mval = val;
            mpnext = nullptr;
        }
    };

    Node *mpstart;
    size_t msize;
public:
    SList():mpstart(0), msize(0) {} // uye baslatim listesi
    /* bu constructor ile ayni gorevi yapar.
    SList()
    {
        mpstart = nullptr;
        msize = 0;
    }
    */
    ~SList()
    {
        while (mpstart)
            pop_front();
    }

    void push_front(int val) {
        Node *pNewNode = new Node(val);
        pNewNode->mpnext = mpstart;
        mpstart = pNewNode;
        msize++;
    }

    void display() {
        for (Node *p = mpstart; p != 0; p = p->mpnext) 
            cout << p->mval << " ";

        cout << endl;
    }    

    void pop_front() {
        if (mpstart) {
            Node *ptemp = mpstart;
            mpstart = mpstart->mpnext;
            delete ptemp;
            msize--;
        }
    }
};



int main()
{
SList mylist;
for (int k = 0; k < 100; k++)
 mylist.push_front(k);
 mylist.display();
for (int k = 0; k < 90; k++)
 mylist.pop_front();
 mylist.display();
return 0;
}