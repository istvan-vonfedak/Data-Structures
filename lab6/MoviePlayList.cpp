#include "MoviePlayList.h"

MoviePlayList::MoviePlayList(){
	init();
}

MoviePlayList::~MoviePlayList(){
	clear();
}
void man(){
	cout<<"Welcome to the Playlist manual\n";
	cout<<"   - Under construction...\n";
	cout<<"Basics:\n";
	cout<<"   - read() is for user input\n";
	cout<<"   - read(istream&) is for file input\n";
	cout<<"   - print() is more detailed\n";
	cout<<"   - print(ostream&) is less detailed\n";
	cout<<"Reading in data\n";
	cout<<"   - Use ifstream and a properly formated text file\n";
	cout<<"   - the file read should be in the following format:\n";
	cout<<"      PSTART [marks start of playlist]\n";
	cout<<"      playlist title\n";
	cout<<"      movie title\n";
	cout<<"      RSTART [marks start of Ratings]\n";
	cout<<"      rating\n";
	cout<<"      comment\n";
	cout<<"      REND   [marks end of Ratings]\n";
	cout<<"      PSTART [marks end of playlist]\n";
}
void MoviePlayList::init(){
	rt.set(0,0);
	name = "";
	count = 0;
}

void MoviePlayList::clear(){
	pl.clear();
	init();
}

void MoviePlayList::populate(LinkList* l, int runtime){
	if(l == NULL) return;
	int size = l->length();
	//generate an array of ascending numbers
	int *arr = new int[size];
	for(int i = 0; i<size; i++) arr[i] = i+1; 
	
	//Fisher-Yates Shuffle
	for (int i=size; i>0; --i)
	{
		int j = rand()%i;
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}	
	
	//searching the array to find the movies 
	RTime ideal, rtime; 
	ideal.set(runtime);
	rtime.set(0,0);
	Movie *m;
	for(int i = 0; i<size; i++){
		m = dynamic_cast< Movie* >(l->search(arr[i]-1));
		rtime.addRuntime(m->returnRuntime());
		if(ideal.compare(rtime) == 1){
			insert(m);
		}
		else if(ideal.compare(rtime) == -1) rtime.set(rt);
		else{
			insert(m);
			break;
		}	
	}
	m = NULL;
	delete[] arr;
}


void MoviePlayList::insert(Object* obj){
	Movie* m = dynamic_cast< Movie* >(obj);
	rt.addRuntime(m->returnRuntime());	
	pl.insert(m);
	count++;
}

int MoviePlayList::compare(Object* obj){
	MoviePlayList* n = dynamic_cast< MoviePlayList* >(obj);
	return name.compare(n->name);
/*	int ret = rt.compare(n->returnRuntime());
	if(ret == 0){
		return name.compare(n->name);
	} 
	else return ret;
*/
}


Object* MoviePlayList::search(int i){
	return pl.search(i);
}

void MoviePlayList::print(){
	cout<<"Playlist Name: "<<name<<endl;
	cout<<"Playlist Runtime: ";
	rt.print();
	pl.print();
}
void MoviePlayList::printMovies(){
        pl.print();
}

ostream& MoviePlayList::print(ostream& out){
	out<<"PSTART\n";
	out<<name<<endl;
        rt.print(out);
	out<<endl;
	pl.print(out);
	out<<"PEND"<<endl;
	return out;
}

void MoviePlayList::read(){
	clear();
        string search;
	cout<<" Enter Playlist name      ~>";
	cin>>name;
	getline(cin, search);//dummy
	rt.set(search);
        while(true){
                Movie *m = new Movie;
                m->read();
                insert(m);
                m = NULL;
                cout<<"Type PEND to end MoviePlayList\n";
                cout<<" Else leave blank         ~>";
                getline(cin,search);
                if(search == "PEND") break;
        }	
}

void MoviePlayList::peekline(istream &in, string &s){
        streampos sp = in.tellg();
        getline(in, s);
        in.seekg(sp);
}

istream& MoviePlayList::read(istream &in){
	clear();
        string search;
        while(!in.fail()){
                peekline(in,search);
                if(search=="PSTART"){
                        getline(in,search);
			getline(in,search);
			if(!in.fail()) name = search;
			getline(in,search);
//			if(!in.fail()) rt.set(search);
                        peekline(in,search); //checks if MoviePlayList is empty
                }
                if(search=="PEND"){
			getline(in,search);
			 break;
		}
                if(!in.fail()){
                        Movie *m = new Movie;
                        m->read(in);
                        insert(m);
                        m = NULL;
                }
        }
        return in;
}
