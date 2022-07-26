#include<iostream>

// question 1:
#include "Q1.h"
#include "PlayList.h"

// question 2:
#include "Q2.h"


using namespace std;

void test1(); // tests for question 1
void test2(); // tests for question 2

int main() {
//    test1();
   test2();
    cout << "done" << endl;
    return 0;
}

//void testPL(PlayList &pl, const string exp) {
//    string test = "";
//    for (string songName: pl)
//        test += songName;
//
//
//    if (test != exp)
//        cout << "you got a wrong result (-16)" << endl;
//
//}
//
//void test1() {
//    PlayList pl0("rock");
//    Song r01("r01"), r02("r02"), r03("r03");
//    pl0 += &r01;
//    pl0 += &r02;
//
//    PlayList pl1("Rock&Roll");
//    Song r11("r11"), r12("r12");
//    pl1 += &r11;
//
//    PlayList pl2("Slow Rock");
//    Song r21("r21");
//    pl2 += &r21;
//
//    pl1 += (&pl2);
//    pl1 += &r12;
//
//    pl0 += (&pl1);
//    pl0 += &r03;
//
//
//    testPL(pl2, "r21");
//    testPL(pl1, "r11r21r12");
//    testPL(pl0, "r01r02r11r21r12r03");
//
//}


void test2() {
    Stream<int> s;
    s.push(12);
    s.push(12);
    s.push(34);
    s.push(56);

    vector<int> result = s.distinct().get();

    if (result.size() != 3 || result[0] != 12 || result[1] != 34 || result[2] != 56)
        cout << "wrong result for distinct (-8)" << endl;

    result = s.filter([](int i) { return i > 20; }).get();
    if (result.size() != 2 || result[0] != 34 || result[1] != 56)
        cout << "wrong result for filter (-8)" << endl;

    int sum = 0;
    s.forEach([&sum](int i) { sum += i; });
    if (sum != 114)
        cout << "wrong result for forEach (-8)" << endl;

    if (s.reduce(0, [](int x, int y) { return x + y; }) != 114)
        cout << "wrong result for reduce (-8)" << endl;

    if (s.allMatch([](int i) { return i > 15; }))
        cout << "wrong result for allMatch (-4)" << endl;

    if (!s.allMatch([](int i) { return i > 5; }))
        cout << "wrong result for allMatch (-4)" << endl;

    if (!s.anyMatch([](int i) { return i > 10; }))
        cout << "wrong result for anyMatch (-4)" << endl;

    if (s.anyMatch([](int i) { return i == 20; }))
        cout << "wrong result for anyMatch (-4)" << endl;

    int pr = s.distinct()
            .filter([](int i) { return i > 15; })
            .reduce(1, [](int x, int y) { return x * y; });

    if (pr != 1904)
        cout << "wrong result for combination of methods (-2)" << endl;

}


