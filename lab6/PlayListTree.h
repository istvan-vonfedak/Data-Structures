/*
* PlayListTree.h
*
* created: dec 6, 2016
*	 Author: Istvan
*/

#ifndef PLAYLISTTREE_H_
#define PLAYLISTTREE_H_
#include "PTree.h"
#include "MoviePlayList.h"

class PlayListTree {
        PTree pt;
        void peekline(istream &, string &);
public:
        PlayListTree();
        virtual ~ PlayListTree();
        void clear();
        void addPlaylist(MoviePlayList*);
        MoviePlayList* findPlaylist(const string);
        int getDepth(){ return pt.depth(); }
        int size(){ return pt.size(); }
        void printTree(bool ascending = true);
        void print(bool ascending = true);
        void read();
        ostream& print(ostream&, bool ascending = true);
        istream& read(istream&);

};

#endif /* PLAYLISTTREE_H_ */
