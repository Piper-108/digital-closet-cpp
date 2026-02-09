#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>//For "cls"
#include<fstream>//For file handling
#include<ctime>//Let's us use the computer's clock
using namespace std;

//void means this fuction does a job, but it doesn't send back a number
//saveCloset is the name of the fuction
void saveCloset(vector<string>&myTops, vector<string>&myBottoms){
		ofstream tFile("tops.txt");//Open tops.txt
		//Go into the tops vector, grab the first item, and call it s. Then do the next part. Then grab the second item, call it s, and repeat until you hit the end
		for(string s:myTops)tFile<<s<<endl;//Grabs Shirt A, writes it to the file, and hits Enter
		//Instead of using cout, use tFile to send text to the File
		//s is the current piece of clothing that the loop just grabbed
		tFile.close();//Put the cap back on the pen and saves the file
		
		ofstream bFile("bottoms.txt");
		for(string s:myBottoms)bFile<<s<<endl;
		bFile.close();
	}
void loadCloset(vector<string>&myTops, vector<string>&myBottoms){
	string newItem;
	//Load tops
	ifstream tFile("tops.txt");
	while(getline(tFile, newItem)){
		if(newItem!=""){
			myTops.push_back(newItem);
		}
	}
		tFile.close();
		//load bottoms
		ifstream bFile("bottoms.txt");
	while(getline(bFile, newItem)){
		if(newItem!=""){
			myBottoms.push_back(newItem);
		}
	}bFile.close();
	}	

int main(){
	srand(time(0));//It "seeds" the random number gererator
	
	//We start with an empty closet(vector)
	vector<string> myTops, myBottoms;
	string newItem;
	int topIdx, botIdx, mainMenuChoice,category, itemNum;
	char choice;
	
	//Pulls the data from the .txt files
	loadCloset(myTops, myBottoms);
	
	//Start title
	while(true){
		system("cls");
	cout<<"---WELCOME TO YOUR DIGITAL CLOSET---"<<endl;
	cout<<"\n----------------------------------"<<endl;
	cout<<"1. View Closet"<<endl;
	cout<<"2. Add New Tops"<<endl;
	cout<<"3. Add New Bottoms"<<endl;
	cout<<"4. Delete an Item"<<endl;
	cout<<"5. Exit App"<<endl;
	cout<<"What would you like to do? Please enter the number:";
	cin>>mainMenuChoice;
	cin.ignore();//This cleans up the 'Enter' key
	
	if(mainMenuChoice==1){
		//Sately check
		if (myTops.empty() || myBottoms.empty()) {
    cout << "Ugh, as if! Your closet is empty. Add items first!" << endl;
    system("pause");
    break; // This takes you back to the main menu safely
}
		//The scrolling section
	while(true){
		system("cls");//Clears the screen every time the loop repeats
		
		cout<<"\n--------------------"<<endl;
		cout<<"CURRENT TOP:"<<myTops[topIdx]<<endl;
		cout<<"CURRENT BOTTOM:"<<myBottoms[botIdx]<<endl;
		cout<<"\n--------------------"<<endl;
		cout<<"[t]Next Top | [b]Next Bottom | [2]Next Both top&bottom | [r]Randomize | [m]Bak To Menu"<<endl;
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
		else if(choice=='r'){
			//rand()%size picks a number between 0 and the last item in my closet
			topIdx=rand()%myTops.size();
			botIdx=rand()%myBottoms.size();
		}
		else if(choice=='m'){
			break;
		}
	}
	cout<<"Closeing Closet~~~"<<endl;
	}
	else if(mainMenuChoice==2){
		system("cls");
		//Upload tops section. This mimics taking a photo and adding it to the app
	cout<<"Let's add some clothes to your digital closet!"<<endl; 
	while(true){
		cout<<"Enter the name of a Top(or type 'done' to stop)";
		getline(cin, newItem);//getline lets us type spaces like"Blue Silk Shirt"
		
		if(newItem=="done"){
			saveCloset(myTops, myBottoms);//It locks in my new clothes
		    break;	
		}
		
		//Check if the name is not empty
		if(newItem!=""){
			myTops.push_back(newItem);//Uploads it to my list
		} else if(newItem==""){
			cout<<"Ugh, as if! You have to actually type a name."<<endl;
			cout<<"\n-------------------------------------------"<<endl;
		}
	}
	}
	else if(mainMenuChoice==3){
		system("cls");
		//Upload bottoms section.
	while(true){
		cout<<"Let's add some clothes to your digital closet!"<<endl;
		cout<<"Enter the name of a Bottom(or type 'done' to stop)";
		getline(cin, newItem);//getline lets us type spaces like"Blue Silk Shirt"
		
		if(newItem=="done"){
			saveCloset(myTops, myBottoms);//It locks in my new clothes
			break;
		}
		
		//Check if the name is not empty
		if(newItem!=""){
			myBottoms.push_back(newItem);//Uploads it to my list
		} else if(newItem==""){
			cout<<"Ugh, as if! You have to actually type a name."<<endl;
			cout<<"\n-------------------------------------------"<<endl;
		}
	}
	}
	else if(mainMenuChoice==4){
		system("cls");
		cout<<"What do you want to delete?(1 for top, 2 for bottom):";
		cin>>category;
		if(category==1){
			//Show the list of tops with numbers
			for(int i=0;i<myTops.size();i++){//Short cut for saying i=i+1
				cout<<i+1<<". "<<myTops[i]<<endl;
			}
			cout<<"Enter the number of the top to remove:";
			cin>>itemNum;
			if(itemNum>0&&itemNum<=myTops.size()){
				myTops.erase(myTops.begin()+(itemNum-1));//Erase the command
				saveCloset(myTops,myBottoms);//Save the change to the file
				cout<<"Deleted! Your closet is updated."<<endl;
			}
			else if(itemNum<0&&itemNum>myTops.size()){
				cout<<"Ugh, as if! That item doesn't exit, please enter the number again:";
			}
		}
		if(category==2){
			//Sjow the list of bottoms with numbers
			for(int i=0;i<myBottoms.size();i++){
				cout<<i+1<<". "<<myBottoms[i]<<endl;
			}
			cout<<"Enter the number of the botom to remove:";
			cin>>itemNum;
			if(itemNum>0&&itemNum<=myBottoms.size()){
				myBottoms.erase(myBottoms.begin()+(itemNum-1));//Erase the command
				saveCloset(myTops,myBottoms);//Save the change to the file
				cout<<"Deleted! Your closet is updated."<<endl;
			}
			else if(itemNum<0&&itemNum>myBottoms.size()){
				cout<<"Ugh, as if! That item doesn't exit, please enter the number again:";
			}
		}
		cout<<"\Press any key to return to the Main Menu...";
		system("pause>nul");
	}
	else if(mainMenuChoice==5){
		system("cls");
		//Exit part
		cout<<"Bye~ Stay slay and fabulous!"<<endl;
		break;
	}
	}
	return 0;
} 
