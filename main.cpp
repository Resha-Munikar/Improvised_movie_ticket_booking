#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<iomanip>
#include<cstdlib>
#include<sstream>
using namespace std;
//password verification part
class Password{
		protected:
			string username,password;
			string newpw;
			string un,pw;
			char ch;
		public:
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
		int code,price;
		void displayMenu();
		void displayuser_menu();
		void addmovie();
		void deletemovie();
		void showmovielist();
		void reserved();
		void view();
		void book();
}Movie1;
class Oldrecord : public Movie
{
	public:
		char person_name[50];
		long long int mobile_number;
		int seat_reserved;
		int total_ticketprice;
		char movie_name[50];
		int price_per;
}test;
std::string intTostring(int num)
{
	std::stringstream ss;
	ss<<num;
	return ss.str();
}
int code_exists( int code)
{
	int code_found = 0;
	ifstream fp;
	fp.open("Try.txt",ios::in);
	Movie tempmovie;
	fp.seekg(0, ios::beg);
	while (fp>>tempmovie.name>>tempmovie.genre>>tempmovie.code>>tempmovie.price)
	{
		if (tempmovie.code == code)
		{
			code_found = 1;
			break;
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
		cout<<endl<<"\t\t\t\t1. Add movie list";
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
				cout<<endl<<"\t\t\t\tInvalid selection";
				cout<<endl<<endl<<"\t\t\tDo you want to try again?";
				cout<<endl<<"\t\t\tPress 'Y' to continue or 'N' to exit : ";
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
		cout<<"\nError! File not found";
		exit(0);
	}
	cin.ignore();
	cout<<endl<<"\t\t\tEnter movie name: ";
	getline(cin,name);
	fflush(stdin);
	cout<<endl<<"\t\t\tEnter movie genre: ";
	getline(cin,genre);
re_code:
	cout<<endl<<"\t\t\tEnter movie code: ";
	cin>>code;
	if (code_exists(code))
	{
		cout<<endl<<"\t\t\tThe movie with code"<<" "<<code<<" "<<"already exists. Try another code.";
		sleep(2);
		goto re_code;
	}
	cout<<endl<<"\t\t\tEnter movie ticket price: ";
	cin>>price;
	cout<<endl;
	fs<< name <<" "<< genre <<" " << code <<" "<< price <<endl;
	if(fs.fail())
	{
		cout<<endl<<"\t\t\tError writing to the file";
		exit(1);
	}
	fs.close();
	cout<<"\t\t\tMovie added successfully.";
	sleep(1);
	cout<<endl;
	cout<<"\t\t\tDo you want to add another movie?[Y/N] : ";
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
			break;
		case'D':
			system("cls");
			obj.main_menu();
			break;
		case 'E':
			exit(0);
		default:
			printf("\n\t\t\tWrong choice.");
			cout<<endl<<endl<<"\t\t\tDo you want to try again?";
			cout<<endl<<"\t\t\tPress 'Y' to continue or 'N' to exit : ";
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
		cout<<endl<<"\t\t\tError! File not found";
		exit(0);
	}
	system("cls");
	cout<<endl;
	cout<<"\t\t__________________________________List of ongoing movies details__________________________________";
	cout<<endl<<endl;
	cout<<"\t\t"<<setw(55)<<left<<"Movie Name"<<setw(15)<<"Movie Genre"<<setw(15)<<"Movie Code"<<setw(15)<<"Ticket Price"<<endl<<endl;
	cout<<"\t\t_________________________________________________________________________________________________";
	printf("\n");
	while (my_file>>name>>genre>>code>>price)
	{
		cout<<"\t\t"<<setw(55)<<name<<setw(15)<<genre<<setw(15)<<code<<setw(15)<<price;
		cout<<endl;
		cout<<"\t\t_________________________________________________________________________________________________";
		cout<<endl;
	}
	my_file.close();
	cin.ignore();
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
	cout<<endl<<endl;
	cout<<"\t\t"<<setw(55)<<left<<"Movie Name"<<setw(15)<<"Movie Genre"<<setw(15)<<"Movie Code"<<setw(15)<<"Ticket Price"<<endl<<endl;
	cout<<"\t\t_________________________________________________________________________________________________";
	printf("\n");
	while (my_file>>name>>genre>>code>>price)
	{
		cout<<"\t\t"<<setw(55)<<name<<setw(15)<<genre<<setw(15)<<code<<setw(15)<<price;
		cout<<endl;
		cout<<"\t\t_________________________________________________________________________________________________";
		cout<<endl;
	}
	my_file.close();
	cin.ignore();
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
		cout<<endl<<"\t\t\tError! File not found";
		exit(0);
	}
	system("cls");
	cout<<endl;
	cout<<"\t\t__________________________________List of ongoing movies details__________________________________";
	cout<<endl<<endl;
	cout<<"\t\t"<<setw(55)<<left<<"Movie Name"<<setw(15)<<"Movie Genre"<<setw(15)<<"Movie Code"<<setw(15)<<"Ticket Price"<<endl<<endl;
	cout<<"\t\t_________________________________________________________________________________________________";
	printf("\n");
	while (my_file>>name>>genre>>code>>price)
	{
		cout<<"\t\t"<<setw(55)<<name<<setw(15)<<genre<<setw(15)<<code<<setw(15)<<price;
		cout<<endl;
		cout<<"\t\t_________________________________________________________________________________________________";
		cout<<endl;
	}
	my_file.close();
del_movie:
	cout<<endl;
	cout<<endl<<"\t\t\tEnter the code of movie you want to delete : ";
	cin>>search;
	fp.open("Try.txt", ios::in);
	if (!fp)
	{
		cout<<endl<<"\t\t\tFile not found.";
		exit(0);
	}
	fs.open("Temp.txt", ios::out);
	if (!fs)
	{
		cout<<endl<<"\t\t\tFile not found.";
		exit(0);
	}
	while (fp>>name>>genre>>code>>price)
	{
		if (code != search)
		{
			fs<< name <<" "<< genre << " " << code <<" "<< price <<endl;
		}
		else
		{
			found = 1;
		}
	}
	fp.close();
	fs.close();
	remove("Try.txt");
	rename("temp.txt", "Try.txt");
	if (found == 1)
	{
		cout<<endl<<"\t\t\tMovie with code"<<" "<<search<<" is deleted successfully.";
	}
	else
	{
		cout<<endl<<"\t\t\tMovie with code"<<" "<<search<<" not found.";
	}
	found=0;
	sleep(1);
	cout<<endl<<"\t\t\tDo you want to delete another movie?[Y/N] : ";
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
	while (fs>>name>>genre>>code>>price)
	{
		cout<<"\t\t"<<setw(55)<<name<<setw(15)<<genre<<setw(15)<<code<<setw(15)<<price;
		cout<<endl;
		cout<<"\t\t_________________________________________________________________________________________________";
		cout<<endl;
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
		while (fp>>name>>genre>>code>>price)
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
				cin>>test.person_name;
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
					cout<<endl<<"\t\t\tSorry! You can't reserve above 10 tickets at once. Try again.";
					goto ticketrewind;
				}
				test.total_ticketprice = price * test.seat_reserved;
				cout<<endl<<"\t\t\tYour total expense for "<<test.seat_reserved<<" ticket is "<<test.total_ticketprice;
				strcpy(test.movie_name,name.c_str()); //converting string to const char*
				test.price_per=price;
				ufp.open("oldTransaction.txt",ios::app);
				if(!ufp)
				{
					cout<<endl<<"\t\t\tFile not found.";
				}
				ufp<<test.person_name<<" "<<test.mobile_number<<" "<<test.seat_reserved<<" "<<test.total_ticketprice<<" "<<test.movie_name<<" "<<test.price_per<<endl;
				ufp.close();
				cout<<endl<<endl;
				cout<<endl<<"\t\t\t ***YOUR SEATS ARE RESERVED! ENJOY YOUR MOVIE!!*** ";
				cout<<endl<<"\t\t\t\tRecord inserted sucessfully.";
				cout<<endl;
			}
		}
		if(!movie_found)
		{
			cout<<endl<<"\t\t\t Movie with code "<<movie_code<<" not found.";
			fflush(stdin);
			getchar();
			displayuser_menu();
		}
	}
	fp.close();
	cout<<endl;
	fflush(stdin);
	getchar();
	displayuser_menu();
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
			cout<<"\n\t\t\t\tInvalid Input!";
			cout<<endl<<endl<<"\t\t\tDo you want to try again?";
			cout<<endl<<"\t\t\tPress 'Y' to continue or 'N' to exit : ";
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
	fflush(stdin);
	cout<<endl<<"\t\t\tEnter your username: ";
	getline(cin,un);
	cout<<endl<<"\t\t\tEnter your password: ";
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
			cout<<endl<<"\t\t\t\tLogging in......";
			sleep(3);
			system("cls");
			Movie1.displayMenu();
		}
		else
		{
			cout<<endl<<"\t\t\tInvalid Username or Password! ";
			fflush(stdin);
			cout<<endl<<"\t\t\tDo you want to try again (Y/N)? ";
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
		system("cls");
		cout<<endl<<"\t\t\t*****************************************************************";
		cout<<endl<<"\t\t\t\t\tMOVIE TICKET BOOKING SYSTEM";
		cout<<endl<<"\t\t\t*****************************************************************";
		fstream file1;
		cin.ignore();
		cout<<endl<<"\t\t\tEnter your username: ";
		getline(cin,un);
		file1.open("logindata.txt",ios::in);
		if(!file1)
		{
			cout<<endl<<"\t\t\tNo such file.";
		}
		while(file1>>username>>password)
		{	
			if(username==un)
			{
				cout<<endl<<"\t\t\tAccount Found...";
				cout<<endl<<"\t\t\t Your password is: "<<password;
				cout<<endl<<endl<<"\t\t\t\tPlease wait....";
				sleep(2);
				login_details();
			}
			else
			{
				cout<<endl<<"\t\t\tAccount not found.";
				cout<<endl<<endl<<"\t\t\tDo you want to try again?";
				cout<<endl<<"\t\t\tPress 'Y' to continue or 'N' to exit : ";
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
			file1.close();
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
				cout<<endl<<"\t\t\t\tInvalid input.";
				cout<<endl<<endl<<"\t\t\tDo you want to try again?";
				cout<<endl<<"\t\t\tPress 'Y' to continue or 'N' to exit : ";
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
		cout<<endl<<"\t\t\tEnter your username: ";
		cin>>un;
		cout<<endl<<"\t\t\tEnter your current password: ";
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
				cout<<endl<<"\t\t\tEnter new password: ";
				cin>>newpw;
				file3.open("logindata.txt",ios::out);
				if(!file3)
				{
					cout<<endl<<"\t\t\tNo such file.";
				}
				file3<<un<<" "<<newpw;
				cout<<endl<<"\t\t\tPassword changed successfully."<<endl;
				cout<<endl<<endl<<"\t\t\t\tPlease wait....";
				sleep(2);
				file3.close();
				login_details();
			}
			else
			{
				cout<<endl<<"\t\t\tUsername or password does not match.";
				cout<<endl<<endl<<"\t\t\tDo you want to try again?";
				cout<<endl<<"\t\t\tPress 'Y' to continue or 'N' to exit : ";
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

