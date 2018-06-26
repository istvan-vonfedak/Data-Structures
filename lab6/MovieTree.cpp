#include "MovieTree.h"

MovieTree::MovieTree(){
	clear();
}

MovieTree::~MovieTree(){
	clear();
}

void MovieTree::addMovie(Movie* m){
	mt.addNode(m);
}
void MovieTree::clear(){
	mt.clear();
}
Movie* MovieTree::findMovie(const string s){
	Movie m; // is there any benefit to making this a pointer?
	m.setTitle(s);
	return dynamic_cast< Movie* >(mt.search(&m));
}

void MovieTree::printTree(bool ascending){
	mt.print(ascending);
}

void MovieTree::print(bool ascending){
	mt.print(ascending);
}

ostream& MovieTree::print(ostream& out, bool ascending){
	out<<"START"<<endl;
	mt.print(out, ascending);
	out<<"END"<<endl;
	return out;
}

void MovieTree::read(){
        clear(); 
        string search;
        while(true){
                
		Movie *m = new Movie;
                m->read();
                addMovie(m);
		m = NULL;
		cout<<"Type END to end MovieTree\n";
		cout<<" Else leave blank         ~>";
		getline(cin,search);
                if(search == "END") break;
        }
}

void MovieTree::peekline(istream &in, string &s){
        streampos sp = in.tellg();
        getline(in, s);
        in.seekg(sp);
}

istream& MovieTree::read(istream& in){
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
                        Movie *m = new Movie;
			m->read(in);
                        addMovie(m);
			m = NULL;
                }
        }
        return in;
}
