#include "Movie.h"
//#include "RatingList.h"
#include "Rating.h"
#include "PTree.h"
using namespace std;

/*
When casting polymorphyc objects:

- Media is a parent class of Video
Video *v = new Video;
Media *m1 = (Media *)v;

Audio *a = dynamic_cast<Audio *>(m);

*/
/*
void print(LinkList *l){
	int s = l->length();
	Rating *r;
	for(int i=0;i<s;i++){
		r = dynamic_cast<Rating *>(l->search(i));
		r->print();
	}
	r = NULL;
	l = NULL;
}
*/
void main(){

//	Rating wow;
//	wow.read(cin);
//	RatingList l;	
//	LinkList *ptr = new LinkList;
//	LinkList t;
//	PTree t;
	
	Rating *r1 = new Rating, *r2=new Rating, *r3= new Rating, *r4= new Rating,*r5= new Rating, *r6 = new Rating, *r7 = new Rating, *r8 = new Rating;
	r1->set(1, "good!");
	r2->set(2, "fell asleep");
	r3->set(3,"@_@");
	r4->set(4,"awesome");
	r5->set(5,"mehh");
	r6->set(6,"so so");
	r7->set(7,"CHicken!!");
	r8->set(100, "wild card");

        Movie *m = new Movie, *b = new Movie;
	
	m->setTitle("Desvaratar");
	m->setRuntime(2,45);
	m->addRating(*r1);
        m->addRating(*r2);
        m->addRating(*r3);
        m->addRating(*r4);
	
	b->setTitle("Good boy Charley");
	b->setRuntime(1,30);
        b->addRating(*r5);	
	b->addRating(*r6);
	b->addRating(*r7);
	b->addRating(*r8);

	MovieTree mt;
	mt.addMovie(m);
	mt.addMovie(b);
	
	Movie* search = mt.findMovie("Good boy Charley");
	search->print();

//	t.addNode((Object*)m);
//	t.addNode((Object*)b);
//	Movie *temp = dynamic_cast<Movie *>(t.search(b));
//	temp->print(cout);
//	t.print(cout);	

/*
	r1->print(cout);
	t.addNode(r4);
	t.addNode(r2);
	t.addNode(r5);
	t.addNode(r1);
	t.addNode(r3);
	t.addNode(r6);
	t.addNode(r7);
	t.addNode(r8);
	cout<<" t's depth is: "<<t.depth()<<endl<<"printing t\n";
	t.print(cout);
	Rating *rt;
	rt = dynamic_cast<Rating *>(t.search(r1));
	cout<<"----------------------\n";
	rt->print(cout);
	cout<<endl;
//	t.clear();
//	t.print(cout);
	
//	ptr->insert(r1);
//	t.insert(r1);
		





/*	t.insert(r2);
	t.insert(r3);
	t.insert(r4);
	t.insert(r5);
	//print(&t);
	t.print(cout);

	cout<<"#######################################\n";			
/*	Rating r;
	r.set(-10,"0_o");
//	r1->set(r);
//
	l.addRating(r);
	l.addRating(*r1);
	l.addRating(*r2);
	l.addRating(*r3);
	l.addRating(*r4);
	l.addRating(*r5);
	l.print();
	cout<<"\n-----------------------------\n";
	l.deleteRating(r);

//	cout<<endl<<"clearing"<<endl;
//	l.removeAllRatings();
	l.print(cout);
	l.read(cin);	
	l.print();
//	Rating test = l.getRating(4);
//	cout<<"pppprosfjdsf\n"<<test<<endl;
//	r1->print();
/*	l.addRating(*r1);
	l.addRating(*r2);
	l.addRating(*r3);
	l.addRating(*r4);
	l.addRating(*r5);
*/
//	l.addRating(100,"@_@");
//	l.print();;
//cout<<"endl\n";
}
