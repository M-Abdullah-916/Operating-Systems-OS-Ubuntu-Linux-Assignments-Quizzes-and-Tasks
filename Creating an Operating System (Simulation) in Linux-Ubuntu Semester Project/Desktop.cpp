#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <fstream>
#include <ctime>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

using namespace std;

// INITIALIZATION OF ATTRIBUTES THAT ARE NEEDED THROUGOUT THE PROGRAM !!!


int temp=2000;
int a = 12;                                                                  // To take file size for hard
int b = 12;

int c = 5;
int d = 5;

pthread_mutex_t Locker;

// INITIALIZATION ENDED !!!



// INITIALIZATION OF FUNCTIONS THAT ARE NEEDED THROUGOUT THE PROGRAM !!!

void SetCursorPos(int XPos, int YPos, int ram , int hard, int proc, int i)      // USED TO HAVE RAM ROM AND PROCESSOR ON SIDE OF TERMINAL
{
 if(temp >= hard && i == 0)
 {
   temp = temp;
 }
 else if (i==1)
 {
     temp = temp;
 }
 else
 {
    temp = hard;
 }
 
 printf("\033[%d;%dH", YPos+1, XPos+1);
 cout << "RAM USAGE  : "<< ram << " MBs  / 2048 MBs" << endl;
 printf("\033[%d;%dH", YPos+2, XPos+1);
 cout << "HARD USAGE : "<< temp << " MBs / 15,360 MBs"<< endl;
 printf("\033[%d;%dH", YPos+3, XPos+1);
 cout << "PROCESSOR  : "<< proc << " % / 100 %"  << endl;
}

int File_Create()                    								// USED TO CREATE EMPTY FILE OF ANY TYPE
{
    pthread_mutex_lock (&Locker);
    system("clear");
    int check=0;
    SetCursorPos(15,1,512,2000,10,0);
    cout<<"\t-------------------------------------------------"<<endl;
    cout<< endl <<"\t\t\t   File Creation " << endl;
    cout<< endl <<"\t-------------------------------------------------"<<endl<< endl;
    string file;
    int P[2];
    pipe(P);
    cout<< "\tEnter File name : ";
    getline(cin,file);
    write(P[1], &file, sizeof(string));
    ifstream opener;
    opener.open(file.c_str());
    if (opener.is_open())
    cout<<"\tFile Already Exist"<<endl;
    else
    {
        ofstream Open;
        Open.open(file.c_str());
        if(Open.is_open())
        cout<< endl << "\tFile has been Successfully Created !!!" << endl;
        read(P[0], &file, sizeof(string));
        string S = file;
        cout << endl << "\tCreated File Name Is : " << S << endl;
        Open.close();
        check = 1;
        
    }
    opener.close();
    cin.get();
    pthread_mutex_unlock (&Locker);
    if(check == 1)
    return 1;
    else 
    return 0;
}

int File_Delete()										// USED TO DELETE EMPTY FILE OF ANY TYPE
{
    pthread_mutex_lock (&Locker);
    system("clear");
    int check=0;
    SetCursorPos(15,1,512,2000,10,1);
    cout<<"\t-------------------------------------------------"<<endl;
    cout<< endl <<"\t\t\t   File Deletion " << endl;
    cout<< endl <<"\t-------------------------------------------------"<<endl << endl;
    string file;
    int P[2];
    pipe(P);
    cout<< "\tEnter File name : ";
    getline(cin,file);
    write(P[1],&file,sizeof(string));
    if (remove(file.c_str()) == 0)
    {
        check = 1;
        write(P[1],&file,sizeof(string));
        string S = file;
        cout << endl << "\tFile Removed, Named as : "<< file << endl;     
    }
    else
    {
        cout << endl << "\tNo File Exist" << endl;  
    }
    cin.get();
    pthread_mutex_unlock (&Locker);
    if(check == 1)
    return 1;
    else 
    return 0;
}

void* Game(void* val)											// USED TO START A GAME (TIC TAC TOE)
{
    system("x-terminal-emulator -e \"./obj2\"");
    system("clear");
    pthread_exit(NULL);
}

void* Calculator(void* val) 									      // USED TO OPEN AND USE CALCULATOR FOR 2 VALUES
{
        pthread_mutex_lock (&Locker);
        system("clear");
        SetCursorPos(15,1,756,2000,17,0);
        cout<<"\t-------------------------------------------------"<<endl;
        cout<< endl <<"\t\t\t   Calculator " << endl;
        cout<< endl <<"\t-------------------------------------------------"<<endl << endl;
        cout << endl;
        float val1=0 , val2=0; 
        int opt = 0;
	cout << "\tEnter First value  : ";
	cin >> val1;
	cout << "\tEnter Second value : ";
	cin >> val2;
	int P1[2],P2[2];
	pipe(P1);
	pipe(P2);
	write(P1[1],&val1,sizeof(int));
	write(P2[1],&val2,sizeof(int));
	cout << endl << "\tPress 1 For Addition         !" << endl ;
	cout << "\tPress 2 For Subtraction      !"<< endl ;
	cout << "\tPress 3 For Multiplication   !"<< endl ;
	cout << "\tPress 4 For Division         !"<< endl ;
	cout << endl << "\tSelect Option: ";
	cin >> opt;
	cout <<endl;
	switch (opt)
       {
           case 1:
               read(P1[0],&val1,sizeof(int));
               read(P2[0],&val2,sizeof(int));
               cout << "\tAddition Becomes : " << val1 + val2 << endl; 
               break;
           case 2:
               read(P1[0],&val1,sizeof(int));
               read(P2[0],&val2,sizeof(int));
               cout << "\tSubtraction Becomes : " << val1 - val2 << endl; 
               break;
           case 3:
               read(P1[0],&val1,sizeof(int));
               read(P2[0],&val2,sizeof(int));
               cout << "\tMultiplication Becomes : " << val1 * val2 << endl; 
               break;
           case 4:
               read(P1[0],&val1,sizeof(int));
               read(P2[0],&val2,sizeof(int));
               cout << "\tDivision Becomes : " << val1 / val2 << endl; 
               break;
           default:
               cout<< "\tWrong Entry !!!" << endl;
           break;
       }
       
       cout << endl << "\tIf You Want to Try Again, Press 1 : " ;
       cin>>opt;
       if(opt == 1)
       Calculator(NULL);
       else
       cout << "\tThank You " << endl;
       pthread_mutex_unlock (&Locker);
       pthread_exit(NULL);
}

void* Date_time(void* val)												// USED TO SHOW CURRENT DATE AND TIME OF SYSTEM
{ 
    pthread_mutex_lock (&Locker);
    system("clear");
    SetCursorPos(15,1,596,2000,11,0);
    cout<<"\t-------------------------------------------------"<<endl;
    cout<< endl <<"\t\t\t   Date & Time " << endl;
    cout<< endl <<"\t-------------------------------------------------"<<endl << endl;
    
    time_t ttime = time(0);
    
    char* dt = ctime(&ttime);
    cout << "\tCurrent Date and Time : " << dt << endl;
    pthread_mutex_unlock (&Locker);
    pthread_exit(NULL);
}


void* Open_and_read(void* val) 												// USED TO OPEN AND READ EXISTING FILE FROM SYSTEM
{
    pthread_mutex_lock (&Locker);
    system("clear");
    SetCursorPos(15,1,530,2000,13,0);
    cout<<"\t-------------------------------------------------"<<endl;
    cout<< endl <<"\t\t\t   Read File " << endl;
    cout<< endl <<"\t-------------------------------------------------"<<endl << endl;
    string file;
    cout<< "\tEnter File name to Read : ";
    getline(cin,file);
    ifstream opener;
    opener.open(file.c_str());
    if (!opener.is_open())
    cout<<"\tFile Dosen't Exist"<<endl;
    else
    {
        while (!opener.eof())
        {
            char a;
            getline(opener,file);
            cout << file << endl;
        }  
    }
    opener.close();
    cin.get();
    pthread_mutex_unlock (&Locker);
    pthread_exit(NULL);
}


int Make_Dir()											//USED TO MAKE A NEW FOLDER IN THE SYSTEM
{
    pthread_mutex_lock (&Locker);
    system("clear");
    int check=0;
    SetCursorPos(15,1,512,2000,10,1);
    cout<<"\t-------------------------------------------------"<<endl;
    cout<< endl <<"\t\t\t   Make Directory " << endl;
    cout<< endl <<"\t-------------------------------------------------"<<endl << endl;
    string filename;
    cout << "\tEnter Name of Directory to Create : ";
    getline (cin, filename);
    if (mkdir(filename.c_str(), 0777) == -1)
        cout << "\tError in Creating a Directory !! " <<endl;
    else
    {
        cout << "\tDirectory created" << endl;
        check = 1;
    }
    cin.get();
    pthread_mutex_unlock (&Locker);
    if(check == 1)
    return 1;
    else 
    return 0;
}

int Rem_Dir()											//USED TO REMOVE A FOLDER FROM THE SYSTEM
{
    pthread_mutex_lock (&Locker);
    system("clear");
    int check=0;
    SetCursorPos(15,1,512,2000,10,1);
    cout<<"\t-------------------------------------------------"<<endl;
    cout<< endl <<"\t\t\t   Delete Directory " << endl;
    cout<< endl <<"\t-------------------------------------------------"<<endl << endl;
    string filename;
    cout << "\tEnter Name of Directory to Remove : ";
    getline (cin, filename);
    if (remove(filename.c_str()) == 0)
    {
        cout << "\tDirectory Removed" << endl;
        check = 1;
    }
    
    else
    cout << "\tNo Directory Exist" << endl;
    cin.get();
    pthread_mutex_unlock (&Locker);
    if(check == 1)
    return 1;
    else 
    return 0;
}



void desktop()												// USED TO SHOW DESKTOP AND RELATED OPTIONS
{
        int opt=0,z=0;
        pthread_t Thread,SThread;
        system("clear");
        SetCursorPos(15,1,512,2000,9,0);
        cout<<"\t-------------------------------------------------"<<endl;
        cout<< endl <<"\t\t\t   DESKTOP " << endl;
        cout<< endl <<"\t-------------------------------------------------"<<endl;
	cout << endl << "\tPress 1 to Create a File          !"  << endl;
	cout << "\tPress 2 to Delete a File          !"  << endl;
	cout << "\tPress 3 to Open Calculator        !"  << endl;
	cout << "\tPress 4 to Show Date and time     !"  << endl;
	cout << "\tPress 5 to Open and Read File     !"  << endl;
	cout << "\tPress 6 to Make a Directory       !"  << endl;
	cout << "\tPress 7 to Delete a Directory     !"  << endl;
	cout << "\tPress 8 to Play Tic-Tac-Toe       !"  << endl;
	cout << "\tPress 9 to Open Firefox           !"  << endl;
	cout << "\tPress 10 to Open Music            !"  << endl;
	cout << "\tPress 11 to return to Main Menu   !"  << endl;


	cout << endl << "\tSelected Option : ";
	cin >> opt;
	cin.ignore();
	switch (opt)
	{
	    case 1:
	        z = File_Create();
	        if (z == 1)
	        {
	            SetCursorPos(15,1,512,2000+a,10,0);
                    a=a+12;
	        }
                system("clear");
	        desktop();
	        break;
	    case 2:
	        z = File_Delete();
	         if (z == 1)
	        {
	            temp = temp - b;
	            SetCursorPos(15,1,512,temp,10,1);
	        }
	        desktop();
	        break;
	    case 3:
	        pthread_create(&Thread,NULL,Calculator,NULL);
	        pthread_join(Thread,NULL);
	        desktop();
	        break;
	    case 4:
	        pthread_create(&Thread,NULL,Date_time,NULL);
	        pthread_join(Thread,NULL);
	        sleep(4);
	        desktop();
	        break;
	    case 5:
	        pthread_create(&Thread,NULL,Open_and_read,NULL);
	        pthread_join(Thread,NULL);
	        desktop();
	        break;
	    case 6:
	        z = Make_Dir();
	        if (z == 1)
	        {
	            SetCursorPos(15,1,512,2000+c,10,0);
                    c=c+5;
	        }
	        desktop();	        
	        break;
	    case 7:
	        z = Rem_Dir();
	        if (z == 1)
	        {
	            temp = temp - d;
	            SetCursorPos(15,1,512,temp,10,1);
	        }
	        desktop();	        
	        break;
	    case 8:
	        pthread_create(&SThread,NULL,Game,NULL);
	        pthread_join(SThread,NULL);
	        SetCursorPos(15,1,900,2000,10,0);
	        sleep(4);
	        desktop();
	        break;
	    case 9:
	        system("x-terminal-emulator -e \"firefox\"");
	        SetCursorPos(15,1,1024,2000,10,0);
	        sleep(4);
	        desktop();
	        break;
	    case 10:
	        system("x-terminal-emulator -e \"rhythmbox\"");
	        SetCursorPos(15,1,756,2000,10,0);
	        sleep(4);
	        desktop();
	        break;
	    case 11:
	        system("x-terminal-emulator -e \"Proj\"");
	        system("exit");
	        break;	
	    default:
	        cout << endl << "Unvalid Command, Try Again" << endl;
	        sleep(2);
	        desktop();
	    break;
	    
	}
}

int main()
{
    desktop();
}
