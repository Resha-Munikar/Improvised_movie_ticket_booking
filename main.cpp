#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<iomanip>
#include<cstdlib>
#include<sstream>
#include<string>
using namespace std;
//password verification part
class Password{
		public:
			string username,password;
			string newpw;
			string un,pw;
			char ch;
			void main_menu();
			void login_menu();
			void forgot();
			void login_details();
			void changepw();		
}obj;
//movie section
class Movie : public Password{
	public:
		string name,genre;
		int code;
		double price;
		void displayMenu();
		void displayuser_menu();
		void addmovie();
		void deletemovie();
		void showmovielist();
		void reserved();
		void view();
		void book();
		void cancel();
}Movie1;
class Oldrecord : public Movie
{
	public:
		string person_name;
		long long int mobile_number;
		int seat_reserved;
		int total_ticketprice;
		string movie_name;
		int price_per;
}test;
std::string intTostring(int num)
{
	std::stringstream ss;
	ss<<num;
	return ss.str();
}
int code_exists( int key)
{
	int code_found = 0;
	ifstream fp;
	fp.open("Try.txt",ios::in);
	fp.seekg(0, ios::beg);
	string line;
	while (getline(fp,line))
	{
		string name,genre;
		int code;
		double price;
		istringstream iss(line);
		if (getline(iss,name,','))
		{
			if (iss>>genre>>code>>price)
			{
				if (code == key)
				{
					code_found = 1;
					break;
				}
			}
		}
	}
	fp.close();
	return code_found;
}
//main function definition
void Movie::displayMenu()
{
	//object of movie class 
	Movie selection;
	int option;
	char ch;
	flag:
		system("cls"); //clears console
		//main menu 
		cout<<endl<<endl<<"\t\t\t-------------------------------MENU-----------------------------"<<endl;
		cout<<endl;
		cout<<endl<<"\t\t\t\t1. Add movie ";
		cout<<endl<<"\t\t\t\t2. Show movie list ";
		cout<<endl<<"\t\t\t\t3. Delete movie ";
		cout<<endl<<"\t\t\t\t4. View reserved movie list ";
		cout<<endl<<"\t\t\t\t5. Change password ";
		cout<<endl<<"\t\t\t\t6. Go back to main menu ";
		cout<<endl<<"\t\t\t\t7. Exit ";
		cout<<endl<<"\n\n\t\t\t   Enter your choice:  ";
		cin>>option;
		switch(option)
		{
			case 1:
				addmovie();
				break;
			case 2:
				showmovielist();
				break;
			case 3:
				deletemovie();
				break;
			case 4:
				reserved();
				break;
			case 5:
				changepw();
				break;
			case 6:
				main_menu();
				break;
			case 7:
				exit(0);
				break;
			default:
				cout<<endl<<"\t\t\t Invalid selection";
				cout<<endl<<endl<<"\t\t\t Do you want to try again?";
				fflush(stdin);
				cout<<endl<<endl<<"\t\t\t Press 'Y' to continue or 'N' to exit : ";
				cin>>ch;
				ch=tolower(ch);
				if(ch=='y')
				{
					goto flag;
				}
				else
				{
					exit(0);
				}
		}
}
void Movie::addmovie()
{
	char re_add;
	re_movie:
	ofstream fs;
	fs.open("Try.txt",ios::app);
	if (!fs)
	{
		cout<<endl<<"\t\t\t Error! File not found";
		exit(0);
	}
	cin.ignore();
	cout<<endl<<"\t\t\t Enter movie name: ";
	getline(cin,name);
	fflush(stdin);
	cout<<endl<<"\t\t\t Enter movie genre: ";
	getline(cin,genre);
re_code:
	cout<<endl<<"\t\t\t Enter movie code: ";
	cin>>code;
	if (code_exists(code))
	{
		cout<<endl<<"\t\t\t The movie with code"<<" "<<code<<" "<<"already exists. Try another code."<<endl;
		goto re_code;
	}
	cout<<endl<<"\t\t\t Enter movie ticket price: ";
	cin>>price;
	cout<<endl;
	fs<< name <<','<<" "<< genre <<" " << code <<" "<< price <<endl;
	if(fs.fail())
	{
		cout<<endl<<"\t\t\t Error writing to the file";
		exit(1);
	}
	fs.close();
	cout<<"\t\t\t Movie added successfully.";
	cout<<endl<<endl;
	cout<<"\t\t\t Do you want to add another movie?[Y/N] : ";
	cin>>re_add;
	re_add=tolower(re_add);
	if (re_add=='y')
	{
		goto re_movie;
	}
	system("cls");
	displayMenu();
}
void Movie::displayuser_menu()
{
	char ch,c;
	label:
		system("cls");
		cout<<endl<<"\t\t\t\t__________________USER OPTIONS__________________";
		cout<<endl;
		cout<<endl<<"\t\t\t\tPress A. to View Movie List";
		cout<<endl<<"\t\t\t\tPress B. to Book Ticket";
		cout<<endl<<"\t\t\t\tPress C. to Cancel Ticket";
		cout<<endl<<"\t\t\t\tPress D. to Go Back to Main Menu";
		cout<<endl<<"\t\t\t\tPress E. to Exit";
		fflush(stdin);
		cout<<endl<<endl<<"\t\t\tEnter your choice : ";
		cin>>ch;
		ch=toupper(ch);
		switch (ch)
		{
		case 'A':
			view();
			break;
		case 'B':
			book();
			break;
		case 'C':
			cancel();
			break;
		case'D':
			system("cls");
			obj.main_menu();
			break;
		case 'E':
			exit(0);
		default:
			printf("\n\t\t\t Wrong choice.");
			cout<<endl<<endl<<"\t\t\t Do you want to try again?";
			cout<<endl<<endl<<"\t\t\t Press 'Y' to continue or 'N' to exit : ";
			cin>>c;
			c=tolower(c);
			if(c=='y')
			{
				goto label;
			}
			else
			{
				exit(0);
			}
		}
}
void Movie :: showmovielist()
{
	ifstream my_file;
	my_file.open("Try.txt", ios::in);
	if (!my_file)
	{
		cout<<endl<<"\t\t\t Error! File not found";
		exit(0);
	}
	system("cls");
	cout<<endl;
	cout<<"\t\t__________________________________List of ongoing movies details__________________________________";
	cout<<endl<<endl<<endl;
	cout<<"\t\t"<<setw(55)<<left<<"Movie Name"<<setw(15)<<"Movie Genre"<<setw(15)<<"Movie Code"<<setw(15)<<"Ticket Price"<<endl<<endl;
	cout<<"\t\t_________________________________________________________________________________________________";
	printf("\n");
	string line;
	while (getline(my_file,line))
	{
		istringstream iss(line);
		if (getline(iss,name,','))
		{
			if (iss>>genre>>code>>price)
			{
				cout<<"\t\t"<<setw(55)<<name<<setw(15)<<genre<<setw(15)<<code<<setw(15)<<price;
				cout<<endl;
				cout<<"\t\t_________________________________________________________________________________________________";
				cout<<endl;
			}
		}
	}
	my_file.close();
	fflush(stdin);
	cout<<endl<<endl<<"\t\t\t Press enter to continue.....";
	getchar();
	system("cls");
	displayMenu();
}
void Movie :: view()
{
	ifstream my_file;
	my_file.open("Try.txt", ios::in);
	if (!my_file)
	{
		cout<<endl<<"\t\t\tError! File not found";
		exit(0);
	}
	system("cls");
	cout<<endl;
	cout<<"\t\t__________________________________List of ongoing movies details__________________________________";
	cout<<endl<<endl<<endl;
	cout<<"\t\t"<<setw(55)<<left<<"Movie Name"<<setw(15)<<"Movie Genre"<<setw(15)<<"Movie Code"<<setw(15)<<"Ticket Price"<<endl<<endl;
	cout<<"\t\t_________________________________________________________________________________________________";
	printf("\n");
	string line;
	while (getline(my_file,line))
	{
		istringstream iss(line);
		if (getline(iss,name,','))
		{
			if (iss>>genre>>code>>price)
			{
				cout<<"\t\t"<<setw(55)<<name<<setw(15)<<genre<<setw(15)<<code<<setw(15)<<price;
				cout<<endl;
				cout<<"\t\t_________________________________________________________________________________________________";
				cout<<endl;
			}
		}
	}
	my_file.close();
	fflush(stdin);
	cout<<endl<<endl<<"\t\t\t Press enter to continue.....";
	getchar();
	system("cls");
	displayuser_menu();
}
void Movie :: deletemovie()
{
	int found = 0, search =0;
	char re_add;
	ifstream fp;
	ofstream fs;
	system("cls");
	ifstream my_file;
	my_file.open("Try.txt", ios::in);
	if (!my_file)
	{
		cout<<endl<<"\t\t\t Error! File not found";
		exit(0);
	}
	system("cls");
	cout<<endl;
	cout<<"\t\t__________________________________List of ongoing movies details__________________________________";
	cout<<endl<<endl<<endl;
	cout<<"\t\t"<<setw(55)<<left<<"Movie Name"<<setw(15)<<"Movie Genre"<<setw(15)<<"Movie Code"<<setw(15)<<"Ticket Price"<<endl<<endl;
	cout<<"\t\t_________________________________________________________________________________________________";
	printf("\n");
	string line;
	while (getline(my_file,line))
	{
		istringstream iss(line);
		if (getline(iss,name,','))
		{
			if (iss>>genre>>code>>price)
			{
				cout<<"\t\t"<<setw(55)<<name<<setw(15)<<genre<<setw(15)<<code<<setw(15)<<price;
				cout<<endl;
				cout<<"\t\t_________________________________________________________________________________________________";
				cout<<endl;
			}
		}
	}
	my_file.close();
del_movie:
	cout<<endl;
	cout<<endl<<"\t\t\t Enter the code of movie you want to delete : ";
	cin>>search;
	fp.open("Try.txt", ios::in);
	if (!fp)
	{
		cout<<endl<<"\t\t\t File not found.";
		exit(0);
	}
	fs.open("Temp.txt", ios::out);
	if (!fs)
	{
		cout<<endl<<"\t\t\tFile not found.";
		exit(0);
	}
	while (getline(fp,line))
	{
		istringstream iss(line);
		if (getline(iss,name,','))
		{
			if (iss>>genre>>code>>price)
			{
				if (code != search)
				{
					fs<< name <<','<<" "<< genre << " " << code <<" "<< price <<endl;
				}
				else
				{
					found = 1;
				}
			}
		}
	}
	fp.close();
	fs.close();
	remove("Try.txt");
	rename("temp.txt", "Try.txt");
	if (found == 1)
	{
		cout<<endl<<"\t\t\t Movie with code"<<" "<<search<<" is deleted successfully.";
	}
	else
	{
		cout<<endl<<"\t\t\t Movie with code"<<" "<<search<<" not found.";
	}
	found=0;
	cout<<endl;
	cout<<endl<<"\t\t\t Do you want to delete another movie?[Y/N] : ";
	cin>>re_add;
	re_add=tolower(re_add);
	if (re_add=='y')
	{
		goto del_movie;
	}
	system("cls");
	displayMenu();
}
void Movie :: book()
{
	int movie_code; 
	string name,genre;
	int code,price,length;
	ifstream fs,fp;
	ofstream ufp;
	fs.open("Try.txt", ios::in);
	if (!fs)
	{
		cout<<endl<<"\t\t\tError! File not found";
		exit(0);
	}
	system("cls");
	cout<<endl;
	cout<<"\t\t_________________________________List of ongoing movies details__________________________________";
	cout<<endl<<endl;
	cout<<"\t\t"<<setw(55)<<left<<"Movie Name"<<setw(15)<<"Movie Genre"<<setw(15)<<"Movie Code"<<setw(15)<<"Ticket Price"<<endl<<endl;
	cout<<"\t\t_________________________________________________________________________________________________";
	printf("\n");
	string line;
	while (getline(fs,line))
	{
		istringstream iss(line);
		if (getline(iss,name,','))
		{
			if (iss>>genre>>code>>price)
			{
				cout<<"\t\t"<<setw(55)<<name<<setw(15)<<genre<<setw(15)<<code<<setw(15)<<price;
				cout<<endl;
				cout<<"\t\t_________________________________________________________________________________________________";
				cout<<endl;
			}
		}
	}
	fs.close();
	cout<<endl<<endl<<"\t\t\t Enter movie code you want to book ticket for :";
	cin>>movie_code;
	fp.open("Try.txt",ios::in);
	if(!fp)
	{
		cout<<endl<<"\t\t\tError! File not found !";
		exit(0);
	}
	else
	{	
		Oldrecord test; //instance of oldrecord
		bool movie_found=false;
		while (getline(fp,line))
		{
			istringstream iss(line);
			if (getline(iss,name,','))
			{
				if (iss>>genre>>code>>price)
				{
					if(code==movie_code)
					{	
						movie_found=true;
						cout<<endl<<"\t\t\tRecord Found";
						cout<<endl;
						cout<<endl<<"\t\t\tCode :"<<code;
						cout<<endl<<"\t\t\tMovie name :"<<name;
						cout<<endl<<"\t\t\tMovie genre :"<<genre;
						cout<<endl<<"\t\t\tPrice of ticket :"<<price;
						cout<<endl;
						cout<<endl<<endl<<"\t\t\t\t* _________________Fill Your Details_______________  *";
						cout<<endl;
						fflush(stdin);
						cout<<endl<<"\t\t\t Name :";
						getline(cin,test.person_name);
						fflush(stdin);
					again:
						cout<<endl<<"\t\t\t Mobile number :";
						cin>>test.mobile_number;
						string mobile_str=intTostring(test.mobile_number);
						length=mobile_str.length();
						if(length>10||length<10)
						{
							cout<<endl<<"\t\t\t  Invalid number. Please enter the correct number.";
							cout<<endl;
							goto again;
						}
					ticketrewind:
						cout<<endl<<"\t\t\t Total number of tickets :";
						cin>>test.seat_reserved;
						if(test.seat_reserved>10)
						{
							cout<<endl<<"\t\t\t Sorry! You can't reserve above 10 tickets at once. Try again.";
							cout<<endl;
							goto ticketrewind;
						}
						test.total_ticketprice = price * test.seat_reserved;
						cout<<endl<<"\t\t\t Your total expense for "<<test.seat_reserved<<" ticket is "<<test.total_ticketprice;
						test.movie_name=name; //converting string to const char*
						test.price_per=price;
						ufp.open("oldTransaction.txt",ios::app);
						if(!ufp)
						{
							cout<<endl<<"\t\t\tFile not found.";
						}
						ufp<<test.person_name<<','<<" "<<test.movie_name<<','<<" "<<test.mobile_number<<" "<<test.price_per<<" "<<test.seat_reserved<<" "<<test.total_ticketprice<<endl;
						ufp.close();
						cout<<endl<<endl;
						cout<<endl<<"\t\t\t ***YOUR SEATS ARE RESERVED! ENJOY YOUR MOVIE!!*** ";
						cout<<endl<<"\t\t\t\tRecord inserted sucessfully.";
						cout<<endl;
					}
				}
			}
		}
		if(!movie_found)
		{
			cout<<endl<<"\t\t\t Movie with code "<<movie_code<<" not found.";
			fflush(stdin);
			cout<<endl;
			cout<<endl<<"\t\t\t Press enter to continue.....";
			getchar();
			getchar();
			displayuser_menu();
		}
	}
	fp.close();
	fflush(stdin);
	cout<<endl<<"\t\t\t Press any key to continue.....";
	getchar();
	displayuser_menu();
}
void Movie :: cancel()
{
	system("cls");
	cout<<endl<<"\t\t\t________________________TICKET CANCELLATION________________________";
	int found=0;
	long long int cancel_code;
	ifstream fp;
	ofstream fs;
	fp.open("oldTransaction.txt",ios::in);
	if(!fp)
	{
		cout<<endl<<"\t\t\t File not found !";
		exit(0);
	}
	fs.open("Backup.txt", ios::out);
	if (!fs)
	{
		cout<<endl<<"\t\t\tFile not found.";
		exit(0);
	}
	cout<<endl<<endl<<endl<<"\t\t\tEnter your phone number: ";
	cin>>cancel_code;
	Oldrecord test;
	string line;
	while (getline(fp,line))
	{
		istringstream iss(line);
		if (getline(iss,test.person_name,','))
		{
			if(getline(iss,test.movie_name,','))
			{
				if (iss>>test.mobile_number>>test.price_per>>test.seat_reserved>>test.total_ticketprice)
				{
					if (test.mobile_number != cancel_code)
					{
						fs<<test.person_name<<','<<" "<<test.movie_name<<','<<" "<<test.mobile_number<<" "<<test.price_per<<" "<<test.seat_reserved<<" "<<test.total_ticketprice<<endl;
					}
					else
					{
						found = 1;
					}
				}
			}
		}
	}
	fp.close();
	fs.close();
	remove("oldTransaction.txt");
	rename("Backup.txt", "oldTransaction.txt");
	if (found == 1)
	{
		cout<<endl<<"\t\t\t Movie reservation has been cancelled successfully.";
	}
	else
	{
		cout<<endl<<"\t\t\t Movie reservation not found.";
		fflush(stdin);
		cout<<endl<<endl<<"\t\t\t Press enter to continue.....";
		getchar();
		displayuser_menu();
	}
	found=0;
	fflush(stdin);
	cout<<endl<<endl<<"\t\t\t Press enter to continue.....";
	getchar();
	system("cls");
	displayuser_menu();
}
void Movie :: reserved()
{
	ifstream fp;
	fp.open("oldTransaction.txt",ios::in);
	if(!fp)
	{
		cout<<endl<<"\t\t\t File does not found !";
		exit(0);
	}
	system("cls");
	cout<<endl;
	cout<<endl<<"\t\t\t\t_________________________________List of reserved movies details_________________________________";
	cout<<endl<<endl<<endl;
	cout<<"\t"<<setw(35)<<left<<"Customer Name"<<setw(40)<<"Movie Name"<<setw(20)<<"Phone Number"<<setw(20)<<"Price per Ticket"<<setw(20)<<"Seats Reserved"<<setw(20)<<"Total Price"<<endl;
	cout<<endl;
	cout<<"\t______________________________________________________________________________________________________________________________________________________";
	cout<<endl;
	Oldrecord record;
	string line;
	while (getline(fp,line))
	{
		istringstream iss(line);
		if (getline(iss,record.person_name,','))
		{
			if(getline(iss,record.movie_name,','))
			{
				if (iss>>record.mobile_number>>record.price_per>>record.seat_reserved>>record.total_ticketprice)
				{
					cout<<"\t"<<setw(35)<<left<<record.person_name<<setw(40)<<record.movie_name<<setw(20)<<record.mobile_number<<setw(20)<<record.price_per<<setw(20)<<record.seat_reserved<<setw(20)<<record.total_ticketprice;
					cout<<endl;
					cout<<"\t______________________________________________________________________________________________________________________________________________________";					cout<<endl;
				}
			}
		}
	}
	fp.close();
	fflush(stdin);
	cout<<endl<<endl<<"\t\t\t Press enter to continue.....";
	getchar();
	system("cls");
	displayMenu();
}
//login menu showing function
void Password::login_menu()
{
	int choice;
	char ch;
	flag:
	system("cls");
	cout<<endl<<"\t\t\t*****************************************************************";
	cout<<endl<<"\t\t\t\t\tMOVIE TICKET BOOKING SYSTEM";
	cout<<endl<<"\t\t\t*****************************************************************";
	cout<<endl;
	//cout<<endl<<endl<<"\t\t\t-------------------------------MENU-----------------------------"<<endl;
	cout<<endl<<"\t\t\t\t1. Login";
	cout<<endl<<"\t\t\t\t2. Forgot Password";
	cout<<endl<<"\t\t\t\t3. Exit";
	cout<<endl<<endl<<"\t\t\t  Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			login_details();
			break;
		case 2:
			forgot();
			break;
		case 3:
			exit(0);
		default:
			cout<<"\n\t\t\t\t Invalid Input!";
			cout<<endl<<endl<<"\t\t\t Do you want to try again?";
			cout<<endl<<endl<<"\t\t\t Press 'Y' to continue or 'N' to exit : ";
			cin>>ch;
			ch=tolower(ch);
			if(ch=='y')
			{
				goto flag;
			}
			else
			{
				exit(0);
			}
	}
}

//login details taking function
void Password::login_details()
{
	retry:
	system("cls");
	fstream login_file;
	cout<<endl<<"\t\t************WELCOME TO LOGIN PAGE************"<<endl;
	cout<<endl;
	fflush(stdin);
	cout<<endl<<"\t\t\t Enter your username: ";
	getline(cin,un);
	cout<<endl<<"\t\t\t Enter your password: ";
	getline(cin,pw);
	login_file.open("logindata.txt",ios::in);
	if(!login_file)
	{
		cout<<endl<<"\t\t\tNo such file";
	}
	
	while(login_file>>username>>password)
	{
		if(username==un && password==pw)
		{
			cout<<endl<<endl<<"\t\t\t    Logging in......";
			sleep(3);
			system("cls");
			Movie1.displayMenu();
		}
		else
		{
			cout<<endl<<"\t\t\t Invalid Username or Password! ";
			fflush(stdin);
			cout<<endl<<endl<<"\t\t\t Do you want to try again (Y/N)? ";
			cin>>ch;
			ch=tolower(ch);
			if(ch=='y')
			{
				system("cls");
				goto retry;
				login_file.close();
			}
			else if(ch=='n')
			{
				login_menu();
			}
			else
			{
				cout<<endl<<"\t\t\t\tInvalid Input!";
				exit(0);
			}
		}
	}
	login_file.close();
}
void Password :: forgot()
{
	again:
		string codeRetrieved,codeGiven;
		system("cls");
		cout<<endl<<"\t\t\t*****************************************************************";
		cout<<endl<<"\t\t\t\t\tMOVIE TICKET BOOKING SYSTEM";
		cout<<endl<<"\t\t\t*****************************************************************";
		cout<<endl;
		ifstream verify;
		ofstream file3;
		verify.open("securitykey.txt",ios::in);
		if(!verify)
		{
			cout<<endl<<"\t\t\tNo such file.";
		}
		verify>>codeRetrieved;
		cout<<endl<<"\t\t\t Enter the security key: ";
		cin>>codeGiven;
		if(codeRetrieved==codeGiven)
		{
			file3.open("logindata.txt",ios::out);
			if(!file3)
			{
				cout<<endl<<"\t\t\t File not found.";
			}
			cin.ignore();
			cout<<endl<<"\t\t\t Enter your username: ";
			cin>>username;
			cin.ignore();
			cout<<endl<<"\t\t\t Enter new password: ";
			cin>>newpw;
			file3<<username<<" "<<newpw;
			cout<<endl<<"\t\t\t Password changed successfully.";
			verify.close();
			file3.close();
			fflush(stdin);
			cout<<endl<<endl<<"\t\t\t Press enter to continue.....";
			getchar();
			login_details();
		}
		else
		{
			cout<<endl<<"\t\t\t Invalid security key.";
			cout<<endl<<endl<<"\t\t\t Do you want to try again?";
			cout<<endl<<endl<<"\t\t\t Press 'Y' to continue or 'N' to exit : ";
			cin>>ch;
			ch=tolower(ch);
			if(ch=='y')
			{
				goto again;
			}
			else
			{
				obj.main_menu();
			}
		}
}
void Password:: main_menu()
{
	int select;
	char ch;
	label:
		system("cls");
		cout<<endl<<"\t\t\t*****************************************************************";
		cout<<endl<<"\t\t\t\t\tMOVIE TICKET BOOKING SYSTEM";
		cout<<endl<<"\t\t\t*****************************************************************";
		cout<<endl;
		cout<<endl<<"\t\t\t\t1. Admin";
		cout<<endl<<"\t\t\t\t2. User";
		cout<<endl<<"\t\t\t\t3. Exit";
		cout<<endl<<endl<<"\t\t\t  Enter your choice:";
		cin>>select;
		switch(select)
		{
			case 1:
				obj.login_menu();
				break;
			case 2:
				Movie1.displayuser_menu();
				break;
			case 3:
				exit(0);
			default:
				cout<<endl<<"\t\t\t\t Invalid input.";
				cout<<endl<<endl<<"\t\t\t Do you want to try again?";
				fflush(stdin);
				cout<<endl<<endl<<"\t\t\t Press 'Y' to continue or 'N' to exit : ";
				cin>>ch;
				ch=tolower(ch);
				if(ch=='y')
				{
					goto label;
				}
				else
				{
					exit(0);
				}
				break;
		}
}
void Password::changepw()
{
	call:
		system("cls");
		cout<<endl<<"\t\t\t*****************************************************************";
		cout<<endl<<"\t\t\t\t\tMOVIE TICKET BOOKING SYSTEM";
		cout<<endl<<"\t\t\t*****************************************************************";
		cout<<endl;
		char ch;
		fstream file2,file3;
		cin.ignore();
		cout<<endl<<"\t\t\t Enter your username: ";
		cin>>un;
		cout<<endl<<"\t\t\t Enter your current password: ";
		cin>>pw;
		file2.open("logindata.txt",ios::in);
		if(!file2)
		{
			cout<<endl<<"\t\t\tNo such file.";
		}
		while(file2>>username>>password)
		{
			if(password==pw)
			{
				cin.ignore();
				cout<<endl<<"\t\t\t Enter new password: ";
				cin>>newpw;
				file3.open("logindata.txt",ios::out);
				if(!file3)
				{
					cout<<endl<<"\t\t\tNo such file.";
				}
				file3<<un<<" "<<newpw;
				cout<<endl<<"\t\t\t Password changed successfully."<<endl;
				fflush(stdin);
				cout<<endl<<"\t\t\t Press enter to continue.";
				getchar();
				file3.close();
				login_details();
			}
			else
			{
				cout<<endl<<"\t\t\t Username or password does not match.";
				cout<<endl<<endl<<"\t\t\t Do you want to try again?";
				cout<<endl<<endl<<"\t\t\tPress 'Y' to continue or 'N' to exit : ";
				cin>>ch;
				tolower(ch);
				if(ch=='y')
				{
					goto call;
				}
				else
				{
					main_menu();
				}
			}
 		}
		file2.close();
}
int main()
{
	obj.main_menu();	
	return 0;
}

