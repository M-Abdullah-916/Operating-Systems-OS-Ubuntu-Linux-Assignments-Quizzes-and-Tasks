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

void shut_down()										//USED TO SHUTDOWN THE SYSTEM
{   pthread_mutex_lock (&Locker);                             
    system("clear");  
    SetCursorPos(15,1,480,2000,9,0);
    cout<<"\t-------------------------------------------------"<<endl;
    cout<< endl <<"\t\t\t   ShutDown " << endl;
    cout<< endl <<"\t-------------------------------------------------"<<endl << endl;
    int opt;
    cout << endl << "\tConfirm System Shutdown by pressing 1 : ";
    cin >> opt;
    if (opt == 1)
    {
        //exitt();
        system("shutdown -P now");
    }
    pthread_mutex_unlock (&Locker);  
}

void restart()											//USED TO RESTART THE SYSTEM
{    
    pthread_mutex_lock (&Locker);      
    system("clear"); 
    SetCursorPos(15,1,480,2000,9,0);
    cout<<"\t-------------------------------------------------"<<endl;
    cout<< endl <<"\t\t\t   Restart " << endl;
    cout<< endl <<"\t-------------------------------------------------"<<endl << endl;                         
    int opt;
    cout << endl << "\tConfirm System Restart by pressing 1 : ";
    cin >> opt;
    if (opt == 1)
    {
        //exitt();
        system("shutdown -R now");
    }
    pthread_mutex_unlock (&Locker);  
}

void start_menu()										// USED TO SHOW START MENU AND RELATED OPTIONS
{
	int opt = 0;
	system("clear");
	SetCursorPos(15,1,512,2000,9,0);
	cout<<"\t-------------------------------------------------"<<endl;
        cout<< endl <<"\t\t\t   START MENU " << endl;
        cout<< endl <<"\t-------------------------------------------------"<<endl;
	cout << endl << "\tPress 1 to Open Disk Manager    !" << endl;
	cout << "\tPress 2 to Open Control Center  !" << endl;
	cout << "\tPress 3 to Open Terminal        !" << endl;
	cout << "\tPress 4 to Manage Files         !" << endl;
	cout << "\tPress 5 to Launch Minesweeper   !" << endl;
	cout << "\tPress 6 to Launch Sudoko        !" << endl;
	cout << "\tPress 7 to Help Center          !" << endl;
	cout << "\tPress 8 to Shut Down System     !" << endl;
	cout << "\tPress 9 to Restart System       !" << endl;
	cout << "\tPress 10 to Return to Main Menu !" << endl;
	
	cout << endl << "\tSelected Option : ";
	cin >> opt;
	
	switch (opt)
	{
	    case 1:
	        system("x-terminal-emulator -e \"gnome-disks\"");
	        SetCursorPos(15,1,700,2000,9,0);
	        sleep(4);
	        start_menu();
	        break;
	    case 2:
	        system("x-terminal-emulator -e \"gnome-control-center\"");
	        SetCursorPos(15,1,665,2000,9,0);
	        sleep(4);
	        start_menu();
	        break;
	    case 3:
	        system("x-terminal-emulator -e \"gnome-terminal\"");
	        SetCursorPos(15,1,1024,2000,9,0);
	        sleep(4);
	        start_menu();
	        break;
	    case 4:
	        system("x-terminal-emulator -e \"nautilus\"");
	        SetCursorPos(15,1,800,2000,9,0);
	        sleep(4);
	        start_menu();
	        break;
	    case 5:
	        system("x-terminal-emulator -e \"gnome-mines\"");
	        SetCursorPos(15,1,950,2000,9,0);
	        sleep(4);
	        start_menu();
	        break;
	    case 6:
	        system("x-terminal-emulator -e \"gnome-sudoku\"");
	        SetCursorPos(15,1,960,2000,9,0);
	        sleep(4);
	        start_menu();	        
	        break;
	    case 7:
	        system("x-terminal-emulator -e \"gnome-help\"");
	        SetCursorPos(15,1,660,2000,9,0);
	        sleep(4);
	        start_menu();	        
	        break;
	    case 8:
	        shut_down();
	        start_menu();
	        break;
	    case 9:
	        restart();
	        start_menu();
	        break;
	    case 10:
	        system("x-terminal-emulator -e \"Proj\"");
	        system("exit");
	        break;	
	    default:
	        cout << endl << "Unvalid Command, Try Again" << endl;
	        sleep(2);
	        start_menu();
	    break;
	    
	}			
}

int main()

{
   start_menu();
   
}

