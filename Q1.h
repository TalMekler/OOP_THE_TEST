#ifndef SRC_Q1_H_
#define SRC_Q1_H_


#include <string>
#include <vector>

using namespace std;

class Item{
    public:
    const string name;
    Item(string name):name(name){}
    virtual ~Item(){}
};

class Song : public Item{
    public:
    Song(string name):Item(name){}
};

#endif



