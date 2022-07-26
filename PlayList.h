
#ifndef SRC_PLAYLIST_H_
#define SRC_PLAYLIST_H_

#include <vector>
#include <typeinfo>
#include "Q1.h"
#include <string.h>

using namespace std;


class PlayList : public Item {
    vector<Item *> items;
    vector<string> deepListOfSongs;
public:

    PlayList(string name) : Item(name) {};

    PlayList &operator+=(Item *item) {
        items.push_back(item);
        if (typeid(*item) == typeid(Song)) {
            deepListOfSongs.push_back(item->name);
        } else if (typeid(*item) == typeid(PlayList)) {
            PlayList *pl = (PlayList *) item;
            for (int i = 0; i < pl->deepListOfSongs.size(); i++) {
                deepListOfSongs.push_back(pl->deepListOfSongs[i]);
            }
        }
        return *this;
    }

    class iterator {
        Item *current;
        PlayList *pl;
    public:
        iterator(Item *item = nullptr, PlayList *pl = nullptr) : current(item), pl(pl) {}

        string operator*() {
            string s = "";
            if (typeid(*current) == typeid(Song)) {
                s = current->name;
            } else if (typeid(*current) == typeid(PlayList)) {
                PlayList *pl = dynamic_cast<PlayList *>(current);
                for (int i = 0; i < pl->deepListOfSongs.size(); i++) {
                    s += pl->deepListOfSongs[i];
                }
            }
            return s;
        }

        iterator &operator++() {
            if (typeid(*current) == typeid(Song)) {
                for (int i = 0; i < pl->items.size(); i++) {
                    if ( pl->items[i] == current) {
                        if (i + 1 < pl->items.size())
                            current = pl->items[i + 1];
                        else
                            current = nullptr;
                        return *this;
                    }
                }
            } else if (typeid(*current) == typeid(PlayList)) {
                for (int i = 0; i < pl->items.size(); i++) {
                    if (pl->items[i] == current) {
                        if (i + 1 < pl->items.size())
                            current = pl->items[i + 1];
                        else
                            current = nullptr;
                        return *this;
                    }
                }
            }
            return *this;
        }

        bool operator!=(const iterator &other) {
            return current != other.current;
        }

        ///TODO: operator==
    };

    iterator begin() {
        return iterator(items[0], this);
    }

    iterator end() {
        return nullptr;
    }

};

#endif /* SRC_PLAYLIST_H_ */
