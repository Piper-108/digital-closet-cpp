#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;
int main(){
	//We start with an empty closet(vector)
	vector<string> myTops, myBottoms;
	string newItem;
	int topIdx, botIdx;
	char choice;
	
	//Start title
	cout<<"---WELCOME TO YOUR DIGITAL CLOSET---"<<endl;
	cout<<"\n----------------------------------"<<endl;
	
	//Step1: Upload tops section. This mimics taking a photo and adding it to the app
	cout<<"Let's add some clothes to your digital closet first!"<<endl; 
	while(true){
		cout<<"Enter the name of a Top(or type 'done' to stop)";
		getline(cin, newItem);//getline lets us type spaces like"Blue Silk Shirt"
		
		if(newItem=="done")
		break;
		//Check if the name is not empty
		if(newItem!=""){
			myTops.push_back(newItem);//Uploads it to my list
		} else if(newItem==""){
			cout<<"Ugh, as if! You have to actually type a name."<<endl;
			cout<<"\n-------------------------------------------"<<endl;
		}
	}
	//Upload bottoms section.
	while(true){
		cout<<"Enter the name of a Bottom(or type 'done' to stop)";
		getline(cin, newItem);//getline lets us type spaces like"Blue Silk Shirt"
		
		if(newItem=="done")
		break;
		//Check if the name is not empty
		if(newItem!=""){
			myBottoms.push_back(newItem);//Uploads it to my list
		} else if(newItem==""){
			cout<<"Ugh, as if! You have to actually type a name."<<endl;
			cout<<"\n-------------------------------------------"<<endl;
		}
	}
	
	//Step2: The scrolling section
	while(true){
		system("cls");//Clears the screen every time the loop repeats
		
		cout<<"\n--------------------"<<endl;
		cout<<"CURRENT TOP:"<<myTops[topIdx]<<endl;
		cout<<"CURRENT BOTTOM:"<<myBottoms[botIdx]<<endl;
		cout<<"\n--------------------"<<endl;
		cout<<"[t]Next Top | [b]Next Bottom | [2]Next Both top&bottom | [q]Quit App"<<endl;
		cout<<"Action:";
		cin>>choice;
		
		if(choice=='t'){
			topIdx=(topIdx+1)%myTops.size();//The "infinite Scroll" logic
		}
		else if(choice=='b'){
			botIdx=(botIdx+1)%myBottoms.size();//The "infinite Scroll" logic
		}
		else if(choice=='2'){
			topIdx=(topIdx+1)%myTops.size();
			botIdx=(botIdx+1)%myBottoms.size();
		}
		else if(choice=='q'){
			break;
		}
	}
	cout<<"Bye~ Stay slay and fabulous!"<<endl;
	return 0;
} 
