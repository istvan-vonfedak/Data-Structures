#include "MovieNet.h"

int main(){

	MovieNet mn;
	string out = "moviesSorted.txt";
	string in = "movies.txt";

	cout<<"loading data...\n";
	mn.loadData(in);

	cout<<"printing loaded data from file "<<in<<endl;
	cout<<mn<<endl;

	cout<<"sotring data in file "<<out<<endl;
	mn.storeData(out);

	cout<<"overwriting stored data with manual input"<<endl;
	cin>>mn;

	cout<<"printing overwritten MovieNet\n";
	cout<<mn<<endl;

	return 0;

}
