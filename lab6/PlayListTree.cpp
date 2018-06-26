#include "PlayListTree.h"

PlayListTree ::PlayListTree(){
	clear();
}

PlayListTree::~PlayListTree(){
        clear();
}

void PlayListTree::addPlaylist(MoviePlayList* p){
        pt.addNode(p);
}
void PlayListTree::clear(){
        pt.clear();
}
MoviePlayList* PlayListTree::findPlaylist(const string s){
        MoviePlayList p; // is there any benefit to making this a pointer?
        p.setName(s);
        return dynamic_cast< MoviePlayList* >(pt.search(&p));
}

void PlayListTree::printTree(bool ascending){
        pt.print(ascending);
}

void PlayListTree::print(bool ascending){
        pt.print(ascending);
}

ostream& PlayListTree::print(ostream& out, bool ascending){
        out<<"START"<<endl;
        pt.print(out, ascending);
        out<<"END"<<endl;
        return out;
}

void PlayListTree::read(){
        clear();
        string search;
        while(true){

                MoviePlayList *p = new MoviePlayList;
                p->read();
                addPlaylist(p);
                p = NULL;
                cout<<"Type END to end PlayListTree\n";
                cout<<" Else leave blank         ~>";
                getline(cin,search);
                if(search == "END") break;
        }
}

void PlayListTree::peekline(istream &in, string &s){
        streampos sp = in.tellg();
        getline(in, s);
        in.seekg(sp);
}

istream& PlayListTree::read(istream& in){
        clear();
        string search;
        while(!in.fail()){
                peekline(in,search);
                if(search=="START"){
                        getline(in,search);
                        peekline(in,search); //checks if MovieList is empty
                }
                if(search=="END") break;
                if(!in.fail()){
                        MoviePlayList *p = new MoviePlayList;
                        p->read(in);
                        addPlaylist(p);
                        p = NULL;
                }
        }
        return in;
}
