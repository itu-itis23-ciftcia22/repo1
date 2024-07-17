#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>

using namespace std;


class Name {
char *mp;
public:
 Name(const char *p); // constructor
 ~Name(); // destructor
void display();
void reverse();
};


Name::Name(const char *p) {
    cout << "Constructor called" << endl;

    size_t len = strlen(p);

    mp = new char[len + 1]; // len+1 uzunlugunda bir char dizisi kadar yer tahsis edildi
    strcpy(mp, p);
}

Name::~Name() {
    printf("Destructor called\n"); // stdio.h i include ettik bu da calisir.
    delete[] mp;
}

void Name::display() {
    cout << "(" << mp << ")" << endl;
}

void Name::reverse() {
    // strrev(mp);
    int len = strlen(mp);
    int i;
    char ch; //int diye tanimlamislar ornekte

    for (i = 0; i < len / 2; i++) {
        ch = mp[i];
        mp[i] = mp[len - 1 - i];
        mp[len - 1 - i] = ch;
    }
}

int main()
{
Name myname("nese");
 myname.display();
 myname.reverse();
 myname.display();
return 0;
}