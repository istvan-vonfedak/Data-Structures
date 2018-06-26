#include <sys/ioctl.h>
#include <time.h>
#include <stdlib.h>
#include "MovieTree.h"
#include "PlayListTree.h"
using namespace std;

/*
* Default dimensions of application: 15 X 63
*
*
*/

//I know a lot of globals... but they dont take up that much memory
int length=0;
int width=0;
const int size = 15;
string mainMenu[size];
string loadMenu[size];
string movieMenu[size];
string playlistMenu[size];
string helpMenu[size];

void clear(){for(int i=0;i<length; i++) cout<<"\n";}

void peekline(istream &in, string &s){
        streampos sp = in.tellg();
        getline(in, s);
        in.seekg(sp);
}

void readGui( string name){
	ifstream fin(name.c_str());
	if(fin.fail()){
		cout<<" file for GUI couldn't open\n";
		exit(1);
	}
	else{
		string search;
		while(!fin.fail()){
			peekline(fin,search);
			if(search == "mainMenuStart"){
				getline(fin,search);
				for(int i=0;!fin.fail()&&i<size;i++){
					getline(fin,search);
					if(!fin.fail()&& search != "mainMenuEnd") mainMenu[i] = search;
					else break;
				}
			}
			else if(search == "loadMenuStart"){
				getline(fin,search);
                                for(int i=0;!fin.fail()&&i<size;i++){
                                        getline(fin,search);
                                        if(!fin.fail()&& search != "loadMenuEnd") loadMenu[i] = search;
                                        else break;
                                }
			}
			else if(search == "movieMenuStart"){
				getline(fin,search);
                                for(int i=0;!fin.fail()&&i<size;i++){
                                        getline(fin,search);
                                        if(!fin.fail()&& search != "movieMenuEnd") movieMenu[i] = search;
                                        else break;
                                }
			}
			else if(search == "playlistMenuStart"){
				getline(fin,search);
                                for(int i=0;!fin.fail()&&i<size;i++){
                                        getline(fin,search);
                                        if(!fin.fail()&& search != "playlistMenuEnd") playlistMenu[i] = search;
                                        else break;
                                }
			}
			else if(search == "helpMenuStart"){
                                getline(fin,search);
                                for(int i=0;!fin.fail()&&i<size;i++){
                                        getline(fin,search);
                                        if(!fin.fail()&& search != "helpMenuEnd") helpMenu[i] = search;
                                        else break;
                                }
                        }
			else getline(fin,search);
		}
	}
	fin.close();
}
//prints GUI
void print(string s[], int l = size){
	for(int i = 0;i<l;i++){
		cout<<s[i];
		if(i+1 != size) cout<<endl;
	}
}
//read movie LinkList file
// I didn't want to do a real Movie list class, this works with my polymorphic link-list
void LinkListLoad(LinkList* l, string name, bool start = false){
	ifstream fin(name.c_str());
	if(fin.fail()){
		if(start) cout<<" |LL ERROR "<<name;
		else{
			clear();
			print(loadMenu,14);
			cout<<"Couldn't open "<<name<<" ~>";
		}
	}
	else{
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
		if(start) cout<<" |LL "<<name;
		else{
			clear();
			print(loadMenu,14);
                	cout<<name<<" loaded ~>";
		}
        }
	fin.close();
}

void LM(MovieTree &t, string name, bool start = false){
	ifstream fin(name.c_str());
        if(fin.fail()){
                if(start)cout<<"|LM ERROR "<<name;
		else{
			clear();
			print(loadMenu,14);
        		cout<<"Couldn't open "<<name<<" ~>";
		}
	}
        else{
		t.read(fin);
		if(start)cout<<"|LM "<<name;
		else{
			clear();
			print(loadMenu,14);
			cout<<name<<" loaded ~>";
		}
	}
	fin.close();
}
void LP(PlayListTree &t, string name, bool start = false){
	ifstream fin(name.c_str());
        if(fin.fail()){
		if(start)cout<<"|LP ERROR "<<name<<"|";
                else{
			clear();
                        print(loadMenu,14);
                        cout<<"Couldn't open "<<name<<" ~>";
                }
        }
        else{
		t.read(fin);
        	if(start)cout<<"|LP "<<name<<"|";
        	else{
			clear();
                	print(loadMenu,14);
                	cout<<name<<" loaded ~>";
        	}
	}
        fin.close();
}

void main (int argc, char **argv) {
	struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        length = w.ws_row;
        width = w.ws_col;
	srand(time(NULL));
	clear();
	string gui = "gui.txt";
	string movies = "movies.txt";
	string playlist = "playlistTree.txt";
	readGui(gui);
	print(mainMenu,14);
	
	LinkList *info =  new LinkList;
	LinkListLoad(info,movies, true);
	
	MovieTree mt;
	LM(mt,movies, true);	
	
	PlayListTree pt;
	LP(pt,playlist, true);
	cout<<" ~> ";

	string input;
	int menu = 1;
	while(true){
		cin>>input;
                if(menu == 0 || input == "Q" || input == "q"){
                        ofstream fmovies(movies.c_str());
                        ofstream fplaylists(playlist.c_str());
                        if(!fmovies.fail()&&!fplaylists.fail()){
				mt.print(fmovies);
                                pt.print(fplaylists);
			}
			fmovies.close();
                        fplaylists.close();
			exit(0);
			
                }
		if(menu == 1 || input == "R" || input == "r"){
			clear();
			print(mainMenu);
			menu = 1;
		}
		if(menu == 2 || input == "L" || input == "l"){
			clear();
			print(loadMenu);
			menu = 2;
		}
		if(menu == 3 || input == "M" || input == "m"){
                        clear();
                        print(movieMenu);
                        menu = 3;
                }
                if(menu == 4 || input == "P" || input == "p"){
                        clear();
                        print(playlistMenu);
                        menu = 4;
                }
		if(menu == 5 || input == "?" || input == "help"|| input == "HELP"){
                	clear();
                        print(helpMenu);
                        menu = 5;
                }

		if(input == "S" || input == "s"){

                        ofstream fmovies(movies.c_str());
                        ofstream fplaylists(playlist.c_str());
                        if(fmovies.fail()||fplaylists.fail()){
                                clear();
                                print(mainMenu,14);
                                cout<<" Error couldn't save data ~ >";
                        }
                        else{
                                mt.print(fmovies);
                                pt.print(fplaylists);
                                clear();
                                print(mainMenu,14);
                                cout<<" Data successfully saved ~>";
                        }
			fmovies.close();
			fplaylists.close();
                }
		if(input == "lm" || input == "LM"){
                        clear();
                        print(loadMenu,14);
                        cout<<" File name ~>";
			cin>>input;
			LM(mt,input);
		}
		if(input == "lp" || input == "LP"){
                        clear();
                        print(loadMenu,14);
                        cout<<" File name ~>";
                        cin>>input;
                        LP(pt,input);
		}
		if(input == "lsm" || input == "LSM"){
			cout<<endl;
			mt.print();
			cout<<" ~>";
                }
		if(input == "sm" || input == "SM"){
                        clear();
			print(movieMenu,14);
			cout<<" Movie name ~>";
                        cin>>input; 
                        Movie *temp = mt.findMovie(input);
			if(temp == NULL){
				clear();
				print(movieMenu,14);
				cout<< " Couldn't find Movie ~>";
                        }
			else{ temp->print(); cout<<" ~>";}
                }
		if(input == "am" || input == "AM"){
			clear();
                        print(movieMenu,14);
                        cout<<" Number of Movies added ~>";
			int n;
			cin>>n;
			Movie *m = new Movie[n];
			getline(cin,input);
			for(int i = 0; i<n;i++){
				if(i%5 == 0){
					cout<<" Do you want to quit [Q] ~>";
					getline(cin,input);
					if(input == "y" || input == "Y" || input == "yes" || input == "YES"|| input == "q" ||input == "Q") break;
				}
				m[i].read();
			}
			clear();             
                        for(int i = 0; i<n ;i++) m[i].print();
                        cout<<" Do you want to keep the movies [y]/[n]~>";
                        cin>>input;
			if(input == "y" || input == "Y" || input == "yes" || input == "YES"){
				if(m != NULL){
					for(int i=0;i<n;i++){
						info->insert(m+i);
						mt.addMovie(m+i);
					}
				}
			}
			else delete[] m;
			
			clear();
                        print(movieMenu);
			m = NULL;
                }
		if(input == "lsp" || input == "LSP"){
                        cout<<endl;
                        pt.print();
                        cout<<" ~>";
                }
		if(input == "sp" || input == "SP"){
                        clear();
                        print(playlistMenu,14);
                        cout<<" Playlist name ~>";
                        cin>>input;
                        MoviePlayList *temp = pt.findPlaylist(input);
                        if(temp == NULL){
				clear();
				print(playlistMenu,14);
				cout<< " Couldn't find Playlist ~>";
                        }
			else{ temp->print(); cout<<" ~>";}
                }
		if(input == "pls" || input == "PLS"){
                        clear();
                        print(playlistMenu,14);
                        cout<<" Playlist name ~>";
                        cin>>input;
                        MoviePlayList *temp = pt.findPlaylist(input);
                        if(temp == NULL) cout<< " Couldn't find Playlist ~>";
                        else{ temp->printMovies(); cout<<" ~>";}
                }
		if(input == "mkp" || input == "MKP"){
                        clear();
                        print(playlistMenu,14);
			MoviePlayList* temp = new MoviePlayList;
			cout<<"Do you want to create a random playlist [y]/[n] ~>";
			cin>>input;
                        if(input == "y" || input == "Y" || input == "yes" || input == "YES"){
				clear();   
                        	print(playlistMenu,14);
				cout<<" Playlist name ~>";
                                cin>>input;
                                temp->setName(input);
				cout<<" Enter the ideal runtieme ~>";
				int rt;
				cin>>rt;
				temp->populate(info,rt);	
			}
			else if(input == "q"||input == "Q"){
				delete temp;
				clear();
                                print(playlistMenu);
				continue;
			}			
			else{
				clear();
                        	print(playlistMenu,14);
				cout<<" Playlist name ~>";
				cin>>input;
				temp->setName(input);
				getline(cin,input);
				while(true){
					//clear();
                                	//print(playlistMenu,14);
                                	cout<<" Movie name ~>";
					getline(cin,input);
					if(input == "lsm"||input == "LSM"){
						cout<<endl;
                        			mt.print();
					} else if(input == "Q" || input == "q") break;
					else{
						Movie *m = mt.findMovie(input);
                       				if(m == NULL){
                                			//clear();
                                			//print(movieMenu,14);
                                			cout<< " Couldn't find";
                        			}
						else{
							temp->insert(m);
						}
					}
				}
			}
			clear();
			temp->print();
			cout<<" Do you want to keep the Paylist [y]/[n] ~>";
			cin>>input;
			if(input == "y" || input == "Y" || input == "yes" || input == "YES") pt.addPlaylist(temp);
			else{
				temp->shallowClean();
				 delete temp;
			}
                        clear();
                        print(playlistMenu);
			temp = NULL;
                }
		
		
	}
}
