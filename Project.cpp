#include<iostream>
#include<conio.h>
#include <fstream>

using namespace std; 

// Declare Global Variable 
int main_exit;
string plate;
string name, brand, color;
int model,capacity,rent,rate_per_hour;
char trans;		

// Declare Functions
void close();
void admin_menu();
void menu();
void login();

// Function For Loading !
void fordelay(int j)
{   
	int i,k;
    for(i=0; i<j; i++){
    	k=i;
	}
}
 
// ================================================= ADMIN PANEL START =========================================================== 

// 1. Function For Add Record In Admin Panel ! 
void add_car(void)
{	
	insert:
	// Create and open a text file 
	ofstream MyFile("record.txt",ios::app);
	
	// Read and open a text file where record is stored 
	ifstream file("record.txt");
	
	//Declare Local Variable	
	string plate2;
	
	cout<<"\n\n\n\t\t\t\t\t===================================================================="<<endl<<endl;
	cout<<"\t\t\t\t\t\t                                       __        __    "<<endl;
	cout<<"\t\t\t\t\t\t   _________ ______   ________  ____  / /_____ _/ / "<<endl;
	cout<<"\t\t\t\t\t\t  / ___/ __ `/ ___/  / ___/ _ \\/ __ \\/ __/ __ `/ /          "<<endl;
	cout<<"\t\t\t\t\t\t / /__/ /_/ / /     / /  /  __/ / / / /_/ /_/ / / "<<endl;
	cout<<"\t\t\t\t\t\t \\___/\\__,_/_/     /_/   \\___/_/ /_/\\__/\\__,_/_/         "<<endl;
	cout<<"\t\t\t\t\t\t         _______  _______/ /____  ____ ___"<<endl;
	cout<<"\t\t\t\t\t\t        / ___/ / / / ___/ __/ _ \\/ __ `__ \\"<<endl;
	cout<<"\t\t\t\t\t\t       (__  / /_/ (__  / /_/  __/ / / / / /"<<endl;
	cout<<"\t\t\t\t\t\t      /____/\\__, /____/\\__/\\___/_/ /_/ /_/"<<endl;
	cout<<"\t\t\t\t\t\t            /____/"<<endl<<endl;
	cout<<"\t\t\t\t\t===================================================================="<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t\tPlese Enter The Car Data Below !"<<endl<<endl<<endl;
	
	// Input All Car Data Using Cin Function :
	cout<<"\t\t\t\t\t\t\tPlate Number: ";
	cin>>plate;
	
	// Checking the record is already store or not 	
	while(file >> plate2 >> brand >> model >> color >> capacity >> rate_per_hour >> trans){
		if(plate == plate2){
			cout<<"\n\t\t\t\t\t\tThis Car is Already Added!";
			for(int i=0;i<=6;i++)
       		{
           		fordelay(100000000);
           		printf(".");
       		}
       		system("cls");
			goto insert;
		}
	}

	// Close the Reading file
	file.close();
	
	cout<<"\t\t\t\t\t\t\tBrand: ";
	cin>>brand;
	cout<<"\t\t\t\t\t\t\tModel: ";
	cin>>model;
	cout<<"\t\t\t\t\t\t\tColor: ";
	cin>>color;
	cout<<"\t\t\t\t\t\t\tCapacity: ";
	cin>>capacity;
	cout<<"\t\t\t\t\t\t\tRate_Per_Hour: RS.";
	cin>>rate_per_hour;
	cout<<"\t\t\t\t\t\t\tTransmission(A/M): ";
	cin>>trans;
			
	// Add Record In to File :		
	MyFile<<plate<< " " ;
	MyFile<<brand<< " " ;
	MyFile<<model<< " " ;
	MyFile<<color<< " " ;
	MyFile<<capacity<< " " ;
	MyFile<<rate_per_hour<< " " ;
	MyFile<<trans<< " "<<endl;

	
	// Close the writing file
	MyFile.close();
	
	cout<<"\n\n\t\t\t\t\t\tYour Record Have been Added !\n";
	cout<<"\n\n\t\t\t\t\t\t==============================================\n";	
	cout<<"\t\t\t\t\t\tEnter 1 to go to the main menu and 0 to exit: ";
	cin>>main_exit;
	if(main_exit==1){
		system("cls");
		admin_menu();
	}
	else if (main_exit==0)
    {
        system("cls");
        close();
	}
	else
    {	
		cout<<"\n\t\t\t\t\t\tInvalid!";
        fordelay(1000000000);
        system("cls");
        admin_menu();
	}
	
} 

// 2. Function For Delete Data In Admin Panel !
void delete_data()
{
//	Declare Local Variables
	string plate_no;
	int test = 0;
	
	cout<<"\n\n\n\t\t\t\t\t===================================================================="<<endl<<endl;
	cout<<"\t\t\t\t\t\t                                       __        __    "<<endl;
	cout<<"\t\t\t\t\t\t   _________ ______   ________  ____  / /_____ _/ / "<<endl;
	cout<<"\t\t\t\t\t\t  / ___/ __ `/ ___/  / ___/ _ \\/ __ \\/ __/ __ `/ /          "<<endl;
	cout<<"\t\t\t\t\t\t / /__/ /_/ / /     / /  /  __/ / / / /_/ /_/ / / "<<endl;
	cout<<"\t\t\t\t\t\t \\___/\\__,_/_/     /_/   \\___/_/ /_/\\__/\\__,_/_/         "<<endl;
	cout<<"\t\t\t\t\t\t         _______  _______/ /____  ____ ___"<<endl;
	cout<<"\t\t\t\t\t\t        / ___/ / / / ___/ __/ _ \\/ __ `__ \\"<<endl;
	cout<<"\t\t\t\t\t\t       (__  / /_/ (__  / /_/  __/ / / / / /"<<endl;
	cout<<"\t\t\t\t\t\t      /____/\\__, /____/\\__/\\___/_/ /_/ /_/"<<endl;
	cout<<"\t\t\t\t\t\t            /____/"<<endl<<endl;
	cout<<"\t\t\t\t\t===================================================================="<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\tEnter Plate No You Want To Delete A Car: ";
	cin>>plate_no;
	
	// Read and open text file
	ifstream MyFile("record.txt");
	
	// Create and open a new text file 
	ofstream File("new.txt");
	
		MyFile>> plate;
		MyFile>> brand;
		MyFile>> model;
		MyFile>> color;
		MyFile>> capacity;
		MyFile>> rate_per_hour;
		MyFile>> trans;

	while(!MyFile.eof())
	{	
		if(plate != plate_no){
			File<<plate<< " " ;
			File<<brand<< " " ;
			File<<model<< " " ;
			File<<color<< " " ;
			File<<capacity<< " " ;
			File<<rate_per_hour<< " " ;
			File<<trans<< " "<<endl;
		}
		else{
			cout<<"\n\t\t\t\t\t\tRecord Deleted"<<endl;
			test++;
		}	
		MyFile>> plate;
		MyFile>> brand;
		MyFile>> model;
		MyFile>> color;
		MyFile>> capacity;
		MyFile>> rate_per_hour;
		MyFile>> trans;
	}
	
//	Files Close
	MyFile.close();
	File.close();	
	
	remove("record.txt");
	rename("new.txt","record.txt");
	
	if(test==0){
		cout<<"\n\t\t\t\t\t\tRecord not found!!\a\a\a"<<endl;
	}
	
	cout<<"\n\t\t\t\t\t\t==============================================\n";	
	cout<<"\t\t\t\t\t\tEnter 1 to go to the main menu and 0 to exit: ";
	cin>>main_exit;
	if(main_exit==1){
		system("cls");
		admin_menu();
	}
	else if (main_exit==0)
    {
       	system("cls");
       	close();
	}
	else
    {	
		cout<<"\n\t\t\t\t\t\tInvalid!";
   	    fordelay(1000000000);
        system("cls");
       	admin_menu();
	}
} 

// 3. Function For Show Data In Admin Panel !
void show_data()
{	
	// Declare Local Variable
	int test = 0;
	char plate2[20];
	cout<<"\n\n\n\t\t\t\t\t===================================================================="<<endl<<endl;
	cout<<"\t\t\t\t\t\t                                       __        __    "<<endl;
	cout<<"\t\t\t\t\t\t   _________ ______   ________  ____  / /_____ _/ / "<<endl;
	cout<<"\t\t\t\t\t\t  / ___/ __ `/ ___/  / ___/ _ \\/ __ \\/ __/ __ `/ /          "<<endl;
	cout<<"\t\t\t\t\t\t / /__/ /_/ / /     / /  /  __/ / / / /_/ /_/ / / "<<endl;
	cout<<"\t\t\t\t\t\t \\___/\\__,_/_/     /_/   \\___/_/ /_/\\__/\\__,_/_/         "<<endl;
	cout<<"\t\t\t\t\t\t         _______  _______/ /____  ____ ___"<<endl;
	cout<<"\t\t\t\t\t\t        / ___/ / / / ___/ __/ _ \\/ __ `__ \\"<<endl;
	cout<<"\t\t\t\t\t\t       (__  / /_/ (__  / /_/  __/ / / / / /"<<endl;
	cout<<"\t\t\t\t\t\t      /____/\\__, /____/\\__/\\___/_/ /_/ /_/"<<endl;
	cout<<"\t\t\t\t\t\t            /____/"<<endl<<endl;
	cout<<"\t\t\t\t\t===================================================================="<<endl<<endl<<endl;

	// Read from the text file
	ifstream Myfile("record.txt");
	
	cout<<"\t\t  Plate No:         Brand:         Model          Color:         Capacity:         Rate_Per_Hour:         Transition:"<<endl;
	cout<<"============================================================================================================================================================="<<endl;

	while (Myfile >> plate >> brand >> model >> color >> capacity >> rate_per_hour >> trans){
		cout<<"\t\t  "<<plate<<"           "<<brand<<"           "<<model<<"           "<<color<<"              "<<capacity<<"                RS."<<rate_per_hour<<"                   "<<trans<<endl;
		test++;
  	}
  	
	// Close the file
	Myfile.close();
	if(test == 0){
		cout<<"\n\t\t\t\t\t\t\t\t   NO RECORDS!"<<endl;
	}
	
  	cout<<"\n============================================================================================================================================================="<<endl;
	cout<<"\nEnter 1 to go to the main menu and 0 to exit: ";
	cin>>main_exit;
		if(main_exit==1){
			system("cls");
			admin_menu();
		}
		else if (main_exit==0)
        {
         	system("cls");
          	close();
		}
		else
    	{	
			cout<<"\nInvalid!";
        	fordelay(1000000000);
           	system("cls");
           	admin_menu();
		}
}

// Function For Admin Panel !
void admin_menu()
{	
	int choice;
	cout<<"\n\n\n\t\t\t\t\t===================================================================="<<endl<<endl;
	cout<<"\t\t\t\t\t\t                                       __        __    "<<endl;
	cout<<"\t\t\t\t\t\t   _________ ______   ________  ____  / /_____ _/ / "<<endl;
	cout<<"\t\t\t\t\t\t  / ___/ __ `/ ___/  / ___/ _ \\/ __ \\/ __/ __ `/ /          "<<endl;
	cout<<"\t\t\t\t\t\t / /__/ /_/ / /     / /  /  __/ / / / /_/ /_/ / / "<<endl;
	cout<<"\t\t\t\t\t\t \\___/\\__,_/_/     /_/   \\___/_/ /_/\\__/\\__,_/_/         "<<endl;
	cout<<"\t\t\t\t\t\t         _______  _______/ /____  ____ ___"<<endl;
	cout<<"\t\t\t\t\t\t        / ___/ / / / ___/ __/ _ \\/ __ `__ \\"<<endl;
	cout<<"\t\t\t\t\t\t       (__  / /_/ (__  / /_/  __/ / / / / /"<<endl;
	cout<<"\t\t\t\t\t\t      /____/\\__, /____/\\__/\\___/_/ /_/ /_/"<<endl;
	cout<<"\t\t\t\t\t\t            /____/"<<endl<<endl;
	cout<<"\t\t\t\t\t===================================================================="<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t 1. ADD CAR \n\t\t\t\t\t\t\t\t 2. DELETE CAR \n\t\t\t\t\t\t\t\t 3. SHOW DATA \n\t\t\t\t\t\t\t\t 4. LOG OFF"<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\tEnter Valid Choice: ";	
	cin>>choice;
	
	// Admin Panel Menu Option Using Switch case :
	switch (choice){
		case 1:
			system("cls");
			add_car();
		break;	
		case 2:
			system("cls");
			delete_data();
		break;	
		case 3:
			system("cls");
			show_data();
		break;	
		case 4:
			system("cls");
			cout<<"\n\nloading";
			for(int i=0;i<=6;i++)
       		{
           		fordelay(100000000);
           		cout<<".";
       		}
       		system("cls");
			menu();
		break;	
		default:
			cout<<"\n\n\t\t\t\t\t\tEnter Valid Option !";			
			cout<<"\n\n\t\t\t\t\t\t==============================================\n";	
			cout<<"\t\t\t\t\t\tEnter 1 to go to the main menu and 0 to exit: ";
			cin>>main_exit;
			if(main_exit==1){
				system("cls");
				admin_menu();
			}
			else if (main_exit==0)
        	{
           		system("cls");
           	 	close();
			}
			else
    		{	
				cout<<"\n\t\t\t\t\t\tInvalid!";
        		fordelay(1000000000);
            	system("cls");
            	admin_menu();
			}
		break;
	}
}


// ================================================= USER PANEL START =========================================================== 

// Function For Users Panel !
void users(string name)
{
	user:
	system("cls");
	int test = 0;
	cout<<"\n\n\n\t\t\t\t\t===================================================================="<<endl<<endl;
	cout<<"\t\t\t\t\t\t                                       __        __    "<<endl;
	cout<<"\t\t\t\t\t\t   _________ ______   ________  ____  / /_____ _/ / "<<endl;
	cout<<"\t\t\t\t\t\t  / ___/ __ `/ ___/  / ___/ _ \\/ __ \\/ __/ __ `/ /          "<<endl;
	cout<<"\t\t\t\t\t\t / /__/ /_/ / /     / /  /  __/ / / / /_/ /_/ / / "<<endl;
	cout<<"\t\t\t\t\t\t \\___/\\__,_/_/     /_/   \\___/_/ /_/\\__/\\__,_/_/         "<<endl;
	cout<<"\t\t\t\t\t\t         _______  _______/ /____  ____ ___"<<endl;
	cout<<"\t\t\t\t\t\t        / ___/ / / / ___/ __/ _ \\/ __ `__ \\"<<endl;
	cout<<"\t\t\t\t\t\t       (__  / /_/ (__  / /_/  __/ / / / / /"<<endl;
	cout<<"\t\t\t\t\t\t      /____/\\__, /____/\\__/\\___/_/ /_/ /_/"<<endl;
	cout<<"\t\t\t\t\t\t            /____/"<<endl<<endl;
	cout<<"\t\t\t\t\t===================================================================="<<endl<<endl<<endl;
	
	cout<<"\t\t\t\t\t\t\t\t WELCOME  "<<name<<" !"<<endl<<endl<<endl;
	
	// Read from the text file
	ifstream data("record.txt");
	
	cout<<"\t\t  Plate No:         Brand:         Model          Color:         Capacity:         Rate_Per_Hour:         Transition:"<<endl;
	cout<<"============================================================================================================================================================="<<endl;

	while (data >> plate >> brand >> model >> color >> capacity >> rate_per_hour >> trans){
		cout<<"\t\t  "<<plate<<"           "<<brand<<"           "<<model<<"           "<<color<<"              "<<capacity<<"                Rs."<<rate_per_hour<<"                   "<<trans<<endl;
		test++;
  	}
  	
  	if(test == 0){
		cout<<"\n\t\t\t\t\t\t\t\t   NO RECORDS!"<<endl;
	}
  	cout<<"============================================================================================================================================================="<<endl<<endl<<endl;
	
	string plate3;
	cout<<"\t\t\t\t\t\tPlease Select A Car: "<<endl<<endl;
	cout<<"\t\t\t\t\t\tPlate Number: ";
	cin>>plate3;
	cout<<"\n\t\t\t\t\t\tHours Per Rent: ";
	cin>>rent;
	
//	Declare local Variables
	int buy,rent2;
	char choice = 'Y';
		
	if(test!=0 && plate3 == plate){
		rent2 = rent * rate_per_hour;
		buy = 1;
	}
	
	if(buy == 1){
		cout<<"\n\t\t\t\t\t\tRent For "<<rent<<" hour: Rs."<<rent2<<endl<<endl;
		cout<<"\t\t\t\t\t\tWould You Like to Rent This Car? (Y or N): ";
		cin>>choice;
		if(choice == 'Y' || choice == 'y'){
			cout<<"\n\t\t\t\t\t\tThankyou.."<<endl;
			cout<<"\t\t\t\t\t\tYou Rent a Car for "<<rent<<" hours"<<endl;		
		}                      
		else if(choice == 'N' || choice == 'n')
		{
			cout<<"\n\t\t\t\t\t\tOkay No Problem..";	
		}                    
		else
		{
			cout<<"\n\t\t\t\t\t\tInvalid! Select (Y or N) Only ";	
			fordelay(1000000000);
			goto user;
		}
	}
	else{
		cout<<"\n\t\t\t\t\t\tWrong Plate No: \a\a\a";
	}
	cout<<"\n\n\t\t\t\t\t\t==============================================\n";	
	cout<<"\t\t\t\t\t\tEnter 1 to go to the main menu and 0 to exit: ";
	cin>>main_exit;
		if(main_exit==1){
			system("cls");
			menu();
		}
		else if (main_exit==0)
        {
         	system("cls");
          	close();
		}
		else
    	{	
			cout<<"\n\n\t\t\t\t\t\tInvalid!";
        	fordelay(1000000000);
           	system("cls");
           	menu();
		}
		
	// Close the file
	data.close();
}

// 1. Fuction For Create An User Account !
void create()
{
	cout<<"\n\n\n\t\t\t\t\t===================================================================="<<endl<<endl;
	cout<<"\t\t\t\t\t\t                                       __        __    "<<endl;
	cout<<"\t\t\t\t\t\t   _________ ______   ________  ____  / /_____ _/ / "<<endl;
	cout<<"\t\t\t\t\t\t  / ___/ __ `/ ___/  / ___/ _ \\/ __ \\/ __/ __ `/ /          "<<endl;
	cout<<"\t\t\t\t\t\t / /__/ /_/ / /     / /  /  __/ / / / /_/ /_/ / / "<<endl;
	cout<<"\t\t\t\t\t\t \\___/\\__,_/_/     /_/   \\___/_/ /_/\\__/\\__,_/_/         "<<endl;
	cout<<"\t\t\t\t\t\t         _______  _______/ /____  ____ ___"<<endl;
	cout<<"\t\t\t\t\t\t        / ___/ / / / ___/ __/ _ \\/ __ `__ \\"<<endl;
	cout<<"\t\t\t\t\t\t       (__  / /_/ (__  / /_/  __/ / / / / /"<<endl;
	cout<<"\t\t\t\t\t\t      /____/\\__, /____/\\__/\\___/_/ /_/ /_/"<<endl;
	cout<<"\t\t\t\t\t\t            /____/"<<endl<<endl;
	cout<<"\t\t\t\t\t===================================================================="<<endl<<endl<<endl;
	
//	Declare Local Variable
	char name[20];
	char pass[10];

	cout << "\t\t\t\t\t\t\tPlease Enter A Username: ";
   	cin >> name;
   	cout << "\n\t\t\t\t\t\t\tPlease Enter a Password: ";
   	cin >> pass;
   	
//  Create and open a file
   	ofstream createaccount("accounts.txt", ios::app); // Will store the users information.
   	
   	createaccount << name << " " << pass << endl;
   	
//  Close a file 	
   	createaccount.close();
   	cout << "\n\n\t\t\t\t\t\tAccount created!" << endl<< endl;
   	
   	cout<<"\t\t\t\t\t\tEnter 1 to go to the Login menu and 0 to exit: ";
   	cin>>main_exit;
   	if(main_exit == 1){
 		login();  		
   	}	
   	else if (main_exit==0)
    {
        system("cls");
        close();
	}
    else
    {	
		cout<<"\n\t\t\t\t\t\tInvalid!";
        fordelay(1000000000);
       	system("cls");
        menu();
	}
   	
}

// 2. Function for User Login !
void login()
{
	system("cls");
	login_try:
	cout<<"\n\n\n\t\t\t\t\t===================================================================="<<endl<<endl;
	cout<<"\t\t\t\t\t\t                                       __        __    "<<endl;
	cout<<"\t\t\t\t\t\t   _________ ______   ________  ____  / /_____ _/ / "<<endl;
	cout<<"\t\t\t\t\t\t  / ___/ __ `/ ___/  / ___/ _ \\/ __ \\/ __/ __ `/ /          "<<endl;
	cout<<"\t\t\t\t\t\t / /__/ /_/ / /     / /  /  __/ / / / /_/ /_/ / / "<<endl;
	cout<<"\t\t\t\t\t\t \\___/\\__,_/_/     /_/   \\___/_/ /_/\\__/\\__,_/_/         "<<endl;
	cout<<"\t\t\t\t\t\t         _______  _______/ /____  ____ ___"<<endl;
	cout<<"\t\t\t\t\t\t        / ___/ / / / ___/ __/ _ \\/ __ `__ \\"<<endl;
	cout<<"\t\t\t\t\t\t       (__  / /_/ (__  / /_/  __/ / / / / /"<<endl;
	cout<<"\t\t\t\t\t\t      /____/\\__, /____/\\__/\\___/_/ /_/ /_/"<<endl;
	cout<<"\t\t\t\t\t\t            /____/"<<endl<<endl;
	cout<<"\t\t\t\t\t===================================================================="<<endl<<endl<<endl;
	string username, password;
   	int log;
   	
//  Read a text file 	
   	ifstream savedaccount("accounts.txt"); // accounts.txt will verify user information.
   	
   	cout << "\t\t\t\t\t\t\tUSERNAME: " ;
   	cin >> username;
   	cout << "\n\t\t\t\t\t\t\tPASSWORD: " ;
   	cin >> password;
   	
//   Declare local Variables	
   	string username2, password2;
   	
   	while(savedaccount >> username2 >> password2){
		if (username == username2 && password == password2)
	   	{
   			log = 1;
    	}   
	}
   	
   	if (log ==1)
   	{
   		cout<<"\n\n\t\t\t\t\t\tAccess Granted!"<<endl;
		cout<<"\t\t\t\t\t\tloading";
		for(int i=0;i<=6;i++)
       	{
        	fordelay(100000000);
           	cout<<".";
       	}
        system("cls");
   		users(username);
    }
    else{
    	cout << "\n\n\t\t\t\t\t\tIncorrect Username & Password! OR Create new account.";
		cout<<"\n\n\t\t\t\t\t\t==============================================\n";	
		cout<<"\t\t\t\t\t\tEnter 1 to try again and 0 to main menu: ";
        cin>>main_exit;
        if (main_exit==1)
       	{
			system("cls");
        	goto login_try;
       	}	
		else if (main_exit==0)
        {
           	system("cls");
           	menu();
		}
        else
    	{	
			cout<<"\n\t\t\t\t\t\tInvalid!";
        	fordelay(1000000000);
            system("cls");
            menu();
		}
	}
	
//	File close
	savedaccount.close();
}


// ================================================= MAIN MENU START =========================================================== 

// Function For Main Menu !
void menu()
{	
	int choice;
	string pass =""; 	
	char ch;
	
	cout<<"\n\n\n\t\t\t\t\t===================================================================="<<endl<<endl;
	cout<<"\t\t\t\t\t\t                                       __        __    "<<endl;
	cout<<"\t\t\t\t\t\t   _________ ______   ________  ____  / /_____ _/ / "<<endl;
	cout<<"\t\t\t\t\t\t  / ___/ __ `/ ___/  / ___/ _ \\/ __ \\/ __/ __ `/ /          "<<endl;
	cout<<"\t\t\t\t\t\t / /__/ /_/ / /     / /  /  __/ / / / /_/ /_/ / / "<<endl;
	cout<<"\t\t\t\t\t\t \\___/\\__,_/_/     /_/   \\___/_/ /_/\\__/\\__,_/_/         "<<endl;
	cout<<"\t\t\t\t\t\t         _______  _______/ /____  ____ ___"<<endl;
	cout<<"\t\t\t\t\t\t        / ___/ / / / ___/ __/ _ \\/ __ `__ \\"<<endl;
	cout<<"\t\t\t\t\t\t       (__  / /_/ (__  / /_/  __/ / / / / /"<<endl;
	cout<<"\t\t\t\t\t\t      /____/\\__, /____/\\__/\\___/_/ /_/ /_/"<<endl;
	cout<<"\t\t\t\t\t\t            /____/"<<endl<<endl;
	cout<<"\t\t\t\t\t===================================================================="<<endl<<endl<<endl;
	cout<<"\t\t\t\t\t\t\t\t 1. ADMIN \n \t\t\t\t\t\t\t\t 2. USERS \n \t\t\t\t\t\t\t\t 3. EXIT"<<endl<<endl<<endl;
	
	cout<<"\t\t\t\t\t\tEnter Valid Choice: ";
	cin>>choice;
	
//	Menu Option Using Switch Case :
	switch (choice){
		case 1:
			system("cls");
			login_try:
			cout<<"\n\n\n\t\t\t\t\t===================================================================="<<endl<<endl;
			cout<<"\t\t\t\t\t\t                                       __        __    "<<endl;
			cout<<"\t\t\t\t\t\t   _________ ______   ________  ____  / /_____ _/ / "<<endl;
			cout<<"\t\t\t\t\t\t  / ___/ __ `/ ___/  / ___/ _ \\/ __ \\/ __/ __ `/ /          "<<endl;
			cout<<"\t\t\t\t\t\t / /__/ /_/ / /     / /  /  __/ / / / /_/ /_/ / / "<<endl;
			cout<<"\t\t\t\t\t\t \\___/\\__,_/_/     /_/   \\___/_/ /_/\\__/\\__,_/_/         "<<endl;
			cout<<"\t\t\t\t\t\t         _______  _______/ /____  ____ ___"<<endl;
			cout<<"\t\t\t\t\t\t        / ___/ / / / ___/ __/ _ \\/ __ `__ \\"<<endl;
			cout<<"\t\t\t\t\t\t       (__  / /_/ (__  / /_/  __/ / / / / /"<<endl;
			cout<<"\t\t\t\t\t\t      /____/\\__, /____/\\__/\\___/_/ /_/ /_/"<<endl;
			cout<<"\t\t\t\t\t\t            /____/"<<endl<<endl;
			cout<<"\t\t\t\t\t===================================================================="<<endl<<endl<<endl;
			cout<<"\n\t\t\t\t\t\t\tEnter Password: ";
   			ch = _getch();
   			while(ch != 13) //character 13 is enter
			{
      			pass.push_back(ch);
      			cout << '*';
      			ch = _getch();
   			}			
			//Chechking Password Using If statement !
			if(pass == "indus")  
			{	
				cout<<"\n\n\n\t\t\t\t\t\tAccess Granted!"<<endl;
				cout<<"\t\t\t\t\t\tloading";
				for(int i=0;i<=6;i++)
       			{
           			fordelay(100000000);
           			cout<<".";
       			}
        		system("cls");
				admin_menu();
			}
			else{
				cout <<"\n\n\n\t\t\t\t\t\tWrong Password ! Please try again.";
				cout<<"\n\n\t\t\t\t\t\t==============================================\n";	
				cout<<"\t\t\t\t\t\tEnter 1 to try again and 0 to exit: ";
        		cin>>main_exit;
        		if (main_exit==1)
        		{
					system("cls");
        	   		goto login_try;
       	 		}	
				else if (main_exit==0)
        		{
           	 		system("cls");
           	 		close();}
        		else
    			{	
					cout<<"\n\n\t\t\t\t\t\tInvalid!";
        			fordelay(1000000000);
            		system("cls");
            		menu();
				}
        	}
		break;
		case 2:
			system("cls");
			cout<<"\n\n\n\t\t\t\t\t===================================================================="<<endl<<endl;
			cout<<"\t\t\t\t\t\t                                       __        __    "<<endl;
			cout<<"\t\t\t\t\t\t   _________ ______   ________  ____  / /_____ _/ / "<<endl;
			cout<<"\t\t\t\t\t\t  / ___/ __ `/ ___/  / ___/ _ \\/ __ \\/ __/ __ `/ /          "<<endl;
			cout<<"\t\t\t\t\t\t / /__/ /_/ / /     / /  /  __/ / / / /_/ /_/ / / "<<endl;
			cout<<"\t\t\t\t\t\t \\___/\\__,_/_/     /_/   \\___/_/ /_/\\__/\\__,_/_/         "<<endl;
			cout<<"\t\t\t\t\t\t         _______  _______/ /____  ____ ___"<<endl;
			cout<<"\t\t\t\t\t\t        / ___/ / / / ___/ __/ _ \\/ __ `__ \\"<<endl;
			cout<<"\t\t\t\t\t\t       (__  / /_/ (__  / /_/  __/ / / / / /"<<endl;
			cout<<"\t\t\t\t\t\t      /____/\\__, /____/\\__/\\___/_/ /_/ /_/"<<endl;
			cout<<"\t\t\t\t\t\t            /____/"<<endl<<endl;
			cout<<"\t\t\t\t\t===================================================================="<<endl<<endl<<endl;
			cout<<"\t\t\t\t\t\t\t\t1. NEW  \n\t\t\t\t\t\t\t\t2. EXISTING  \n\t\t\t\t\t\t\t\t3. MAIN MENU"<<endl<<endl<<endl;
			cout<<"\t\t\t\t\t\tEnter Valid Choice: ";	
			cin>>choice;

			system("cls");			
			switch(choice){
				case 1:
					create();
				break;
				case 2:
					login();
				break;
				case 3:
					menu();
				break;
				default:
				break;
			}	
		break;
		case 3:
			system("cls");
			close();
		break;
		default:
			cout<<"\n\n\t\t\t\t\tEnter Valid Option !";			
			cout<<"\n\n\t\t\t\t\t==============================================\n";	
			cout<<"\t\t\t\t\tEnter 1 to go to the main menu and 0 to exit: ";
			cin>>main_exit;
			if(main_exit==1){
				system("cls");
				menu();
			}
			else if (main_exit==0)
        	{
           		system("cls");
           	 	close();}
        	else
    		{	
				cout<<"\n\t\t\t\t\tInvalid!";
        		fordelay(1000000000);
            	system("cls");
            	menu();
			}
		break;	
	}
}

// Function For Close Program !
void close(void)
{
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t*********************************************************\n";	
	cout<<"\t\t\t\t\t\t*\t\t\t\t\t\t\t*\n\t\t\t\t\t\t*\t\t\t\t\t\t\t*\n\t\t\t\t\t\t*\t\t\t\t\t\t\t*\n";
    cout<<"\t\t\t\t\t\t*\tThis Car Rental Project is developed by: \t*\n\t\t\t\t\t\t*\t\t\t\t\t\t\t*\n";
    cout<<"\t\t\t\t\t\t*\t Waqas Tariq (499-2021)\t\t\t\t*\n";
    cout<<"\t\t\t\t\t\t*\t Awais Jawad (121-2021)\t\t\t\t*\n";
    cout<<"\t\t\t\t\t\t*\t Abdul Moiz (48-2021)\t\t\t\t*\n";
    cout<<"\t\t\t\t\t\t*\t Talha Ansari (672-2021)\t\t\t*\n";
    cout<<"\t\t\t\t\t\t*\t\t\t\t\t\t\t*\n\t\t\t\t\t\t*\t\t\t\t\t\t\t*\n\t\t\t\t\t\t*\t\t\t\t\t\t\t*\n";
    cout<<"\t\t\t\t\t\t*********************************************************"<<endl<<endl;	
}

// Main Function Start Here !
int main(){
	menu();
	
	return 0;
}
