#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
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
		string name;
		int code,price;
		void displayMenu();
		void displayuser_menu();
		void addmovie();
		void deletemovie();
		void showmovielist();
}Movie1;
int code_exists( int code)
{
	int code_found = 0;
	ifstream fp;
	fp.open("Try.txt",ios::in);
	Movie tempmovie;
	fp.seekg(0, ios::beg);
	while (fp>>tempmovie.name>>tempmovie.code>>tempmovie.price)
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
	//object of vehicle class 
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
		cout<<endl<<"\t\t\t\t4. Change password ";
		cout<<endl<<"\t\t\t\t5. Go back to main menu ";
		cout<<endl<<"\t\t\t\t6. Exit ";
		cout<<endl<<"\n\n\t\t\t\t   Enter your choice:  ";
		cin>>option;
		switch(option)
		{
			case 1:
				Movie1.addmovie();
				break;
			case 2:
				//selection.showmovielist();
				break;
			case 3:
				//selection.deletemovie();
				break;
			case 4:
				changepw();
				break;
			case 5:
				obj.main_menu();
				break;
			case 6:
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
	//fs.seekg(0, ios::end);
	fs<< name <<" "<< code <<" "<< price <<endl;
	if(fs.fail())
	{
		cout<<endl<<"\t\t\tError writing to the file";
		exit(1);
	}
	fs.close();
/*	if(!fs.is_open())
	{
		cout<<endl<<"\t\t\tError closing the file.";
		exit(1);
	}*/
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
	sleep(1);
	system("cls");
	displayMenu();
}
void Movie::displayuser_menu()
{
	char ch,c;
	label:
		system("cls");
		cout<<endl<<"\t\t\t\t\t______________USER OPTIONS______________";
		cout<<endl;
		cout<<endl<<"\t\t\t\tPress A. to View Movie List";
		cout<<endl<<"\t\t\t\tPress B. to Book Ticket";
		cout<<endl<<"\t\t\t\tPress C. to Cancel Ticket";
		cout<<endl<<"\t\t\t\tPress D. to Go Back to Main Menu";
		cout<<endl<<"\t\t\t\tPress E. to Exit";
		fflush(stdin);
		cout<<endl<<endl<<"\t\t\tEnter your choice : ";
		cin>>ch;
		c=toupper(ch);
		switch (ch)
		{
		case 'A':
			//view();
			//goto label;
			break;
		case 'B':
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
	cout<<endl<<endl<<"\t\t\tEnter your choice: ";
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
				sleep(3);
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
		cout<<endl<<endl<<"\t\t\t\tEnter your choice:";
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

