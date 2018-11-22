#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
	string strtmp; 
	string author, title;
	vector<pair<string,string> > library;
	int i1, i2;
	getline(cin,strtmp);
	while (strtmp!="END"){
		i1=strtmp.find_first_of('"');
		i2=strtmp.find_last_of('"');
		title=strtmp.substr(i1,i2-i1+1);
		author=strtmp.substr(i2+1);
		i1=author.find("by");
		author=author.substr(i1+1);
		i1=author.find(" ");
		author=author.substr(i1+1);
		pair <string,string> tmp ("","");
		tmp.first=author;
		tmp.second=title;
		library.push_back(tmp);
		getline(cin,strtmp);
	}
	sort(library.begin(), library.end());
	int status[library.size()];
	for (int i=0; i<library.size(); i++){
		status[i]=1;
	}
	cin>>strtmp;
	while (strtmp!="END"){
		if (strtmp=="BORROW"){
			getline(cin,strtmp);
			i1=strtmp.find_first_of('"');
			i2=strtmp.find_last_of('"');
			title=strtmp.substr(i1,i2-i1+1);
			for (int i=0; i<library.size(); i++){
				if (title==library[i].second){
					status[i]=0;
					break;
				}			
			}
		}
		if (strtmp=="RETURN"){
			getline(cin,strtmp);
			i1=strtmp.find_first_of('"');
			i2=strtmp.find_last_of('"');
			title=strtmp.substr(i1,i2-i1+1);
			for (int i=0; i<library.size(); i++){
				if (title==library[i].second){
					status[i]=2;
					break;
				}
			}
		}
		if (strtmp=="SHELVE"){
			int idx=library.size();
			for (int i=0; i<library.size(); i++){
				if (status[i]==1){
					idx=i;
					break;
				}
			}
			int tmp=-1;
			for (int i=0; i<idx; i++){
				if (status[i]==2&&tmp==-1){
					cout<<"Put "<<library[i].second<<" first"<<endl;
					status[i]=1;
					tmp=i;
				}
				else if (status[i]==2){
					cout<<"Put "<<library[i].second<<" after "<<library[tmp].second<<endl;
					status[i]=1;
					tmp=i;
				}
			}
			tmp=idx;
			for (int i=tmp+1; i<library.size(); i++){
				if (status[i]==2){
					cout<<"Put "<<library[i].second<<" after "<<library[idx].second<<endl;
					idx=i;
					status[i]=1;
				}
				else if (status[i]==1){
					idx=i;
				}
			}
			cout<<"END"<<endl;
			getline(cin,strtmp);
		}
		cin>>strtmp;
	}
}