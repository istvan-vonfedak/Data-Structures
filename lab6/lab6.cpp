#include "MovieTree.h"
#include "PlayListTree.h"
#include <time.h>
#include <stdlib.h>

void peekline(istream &in, string &s){
        streampos sp = in.tellg();
        getline(in, s);
        in.seekg(sp);
}

void readDatabase(LinkList* l, string n){
	ifstream fin(n.c_str());
	l->clear();
        string search;
        while(!fin.fail()){
                peekline(fin,search);
                if(search=="START"){
                        getline(fin,search);
                        peekline(fin,search);
                }
                if(search=="END") break;
                if(!fin.fail()){
                        Movie *m = new Movie;
                        m->read(fin);
                        l->insert(m);
                        m = NULL;
                }
        }
}

void main(){
//	cout<<"start\n";

	int ltime = time(NULL);
	int stime = (unsigned) ltime/2;
	srand(stime);
//	cout<<random()<<endl;	

//	Info contains all the movies in the database
	LinkList *info =  new LinkList;
	string name = "movies.txt";
	readDatabase(info,name);
//	info->print();




	MoviePlayList *pl= new MoviePlayList[8];
	pl[0].setName("Meaning of life");
	pl[0].populate(info,631);
	pl[1].setName("Good Times");
        pl[1].populate(info,138);
	pl[2].setName("Almost 24h");
        pl[2].populate(info,2400);
	pl[3].setName("Title Title");
        pl[3].populate(info,439);
	pl[4].setName("Desvaratar");
        pl[4].populate(info,1190);
	pl[5].setName("Simple Playlist");
        pl[5].populate(info,1573);
	pl[6].setName("Good Vibes");
        pl[6].populate(info,1);
	pl[7].setName("72 hours");
        pl[7].populate(info,7200);
	/*for(int i = 0; i<8 ;i++){
		cout<<"###########################\n";
		pl[i].print();
	}*/
	PlayListTree pt;
	pt.addPlaylist(pl+1);
	pt.addPlaylist(pl+4);
	pt.addPlaylist(pl+5);
	pt.addPlaylist(pl+2);
	pt.addPlaylist(pl+6);
	pt.addPlaylist(pl);
	pt.addPlaylist(pl+3);
	pt.addPlaylist(pl+7);
//	pt.print();


	PlayListTree beta;
	ifstream fin("playlistTree.txt");
	if(fin.fail()) cout<<"couldn't open file\n";
	else beta.read(fin);
//	cout<<beta.size()<<endl;
//	beta.print(cout);
	MoviePlayList *ptr = beta.findPlaylist("Meaning of life");
	ptr->print();	
/*	MoviePlayList* playlist = new MoviePlayList;
	playlist->setName("Meaning of life");
        playlist->populate(info,631);
	beta.addPlaylist(playlist);
	beta.print();
	playlist->print(cout);

	cout<<"\n####################################################\n";
	info->print();

///////////////////////////////////////////////////////////////////////////
/*	Test for MovieTree
 
	Rating *r1=new Rating, *r2=new Rating, *r3=new Rating, *r4=new Rating, *r5=new Rating, *r6=new Rating, *r7=new Rating, *r8=new Rating;
	r1->set(5, "good!");
        r2->set(1, "fell asleep");
        r3->set(100,"@_@");
        r4->set(4,"awesome");
        r5->set(3,"hahaha");
	r6->set(6,"mhh interesting...");
	r7->set(3,"F&cking great");
	r8->set(77,"awesome!");

	Movie* m = new Movie;

	m->setTitle("Desvaratar");
	m->setRuntime(3,21);
	m->addRating(*r1);
	m->addRating(*r2);
	m->addRating(*r3);
	m->addRating(*r4);
	m->addRating(*r4);
	m->addRating(*r4);
	m->addRating(*r4);

	m->print();
	
	Movie* M = new Movie;
	M->setTitle("Avengers");
        M->setRuntime(2,43);
        M->addRating(*r5);
        M->addRating(*r6);
        M->addRating(*r7);
        M->addRating(*r8);
	
	MovieTree mt;
	mt.addMovie(m);
	mt.addMovie(M);
//	Movie *tmp = mt.findMovie("Avengers");
	ifstream fin("movies.txt");
	mt.read(fin);
	fin.close();
	mt.print();
//	cout<<mt.getDepth()<<" , "<<mt.getNumMovies()<<endl;
*/

}
