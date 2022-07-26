
#ifndef SRC_Q2_H_
#define SRC_Q2_H_

#include <vector>
#include <algorithm>

using namespace std;

template<class T>
class Stream {
    vector<T> items;
public:

    void push(T t) {
        items.push_back(t);
    }

    vector<T> get() { return items; }

    // implement distinct
    Stream<T> distinct() {
        Stream<T> result;
        for (auto it = items.begin(); it != items.end(); it++) {
            if (find(result.items.begin(), result.items.end(), *it) == result.items.end()) {
                result.items.push_back(*it);
            }
        }
        return result;
    }

    // implement filter
    template<class func>
    Stream<T> filter(func f) {
        Stream<T> result;
        for (auto it = items.begin(); it != items.end(); it++) {
            if (f(*it)) {
                result.push(*it);
            }
        }

        return result;
    }

    // implement forEach
    template<class func>
    func forEach(func f) {
        return for_each(items.begin(), items.end(), f);
    }

    // implement reduce
    template<class func>
    T reduce(T id, func f) {
        auto it = items.begin();
        T result = f(id, *it);
        it++;
        for (; it != items.end(); it++) {
            result = f(result, *it);
        }
        return result;
    }

    // implement allMatch
    template<class func>
    bool allMatch(func f) {
        for(auto it = items.begin(); it != items.end(); it++) {
            if (!f(*it)) {
                return false;
            }
        }
        return true;
    }

    // implement anyMatch
    template<class func>
    bool anyMatch(func f) {
        for(auto it = items.begin(); it != items.end(); it++) {
            if (f(*it)) {
                return true;
            }
        }
        return false;
    }

};


#endif /* SRC_Q2_H_ */
