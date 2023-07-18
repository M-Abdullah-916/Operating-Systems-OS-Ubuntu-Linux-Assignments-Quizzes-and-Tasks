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

pthread_mutex_t Locker;
int temp = 480;
// INITIALIZATION ENDED !!!



// INITIALIZATION OF FUNCTIONS THAT ARE NEEDED THROUGOUT THE PROGRAM !!!

void SetCursorPos(int XPos, int YPos, int ram , int hard, int proc, int i)      // USED TO HAVE RAM ROM AND PROCESSOR ON SIDE OF TERMINAL
{
if(i==1)
 temp = 512;
if(i==2)
temp =  512;

if (i==0)
temp=ram;
 
 
 
 printf("\033[%d;%dH", YPos+1, XPos+1);
 cout << "RAM USAGE  : "<< temp << " MBs  / 2048 MBs" << endl;
 printf("\033[%d;%dH", YPos+2, XPos+1);
 cout << "HARD USAGE : "<< hard << " MBs / 15,360 MBs"<< endl;
 printf("\033[%d;%dH", YPos+3, XPos+1);
 cout << "PROCESSOR  : "<< proc << " % / 100 %"  << endl;
}

void* details(void* val)                                                                           // USED TO SHOW THE TEAM MEMBERS AND PROJECT DETAILS
{
    pthread_mutex_lock (&Locker);
    system("clear");
    SetCursorPos(100,1,512,2000,10,0);
    cout<<"\t-------------------------------------------------"<<endl;
    cout<< endl <<"\t\t\tℹ️  DETAILS ℹ️" << endl;
    cout<< endl <<"\t-------------------------------------------------"<<endl<< endl;
    sleep(1);
    cout << "\n\n\t\t🖥️  Operating Systems Project 🖥️"<<endl;
    sleep(1);
    cout << "\n\t  📽️  Project Name\t  🦁️ SPHINX"<<endl<<endl;
    sleep(1);
    cout << "\n\t  👨️ Members Name\t  🔢️ Members Roll Number"<<endl<<endl;
    sleep(1);
    cout << "\t    Jonathan Parveiz\t    19F-0910"<<endl;
    cout << "\t    M. Abdullah\t\t    19F-0916"<<endl<<endl;
    sleep(1);
    cout << "\t   🗞️  Degree\t\t  💻️ Software Engineering"<<endl<<endl;
    sleep(1);
    cout << "\t\tBatch\t\t    2K19"<<endl<<endl;
    sleep(1);
    cout << "\t\t  🇵🇰️  FAST-NUCES CFD CAMPUS"<<endl<<endl; 
    cin.get();
    pthread_mutex_unlock (&Locker);
    pthread_exit(NULL);
}

    



void splash_Screen()									//USED TO SHOW OPENING SCREEN FOR OS
{
    system("clear");
    string Message1;
    
    Message1 = "Booting UP Operating System, Please Wait ";  
    cout << "\n\n\n\t\t" << Message1;
    sleep (1);
    
    Message1 = "Starting OS Component  🖥️  / 4";
    cout << "\n\n\t\t" << Message1;
    sleep (1);
    
    Message1 = "Starting OS Component  🖥️  🖥️  / 4";
    cout << "\n\n\t\t" << Message1;
    sleep (1);
    
    Message1 = "Starting OS Component  🖥️  🖥️  🖥️  / 4";
    cout << "\n\n\t\t" << Message1;
    sleep (1);
    
    Message1 = "Starting OS Component  🖥️  🖥️  🖥️  🖥️   / 4";
    cout << "\n\n\t\t" << Message1;
    sleep (1);
    
    Message1 = "\n\n\t\tSystem Successfully Booted Up !! "; 
    cout << "\n\n\t\t" << Message1;
    sleep (2);
    cout << endl << endl;
    cin.get();
 
}

void exitt()										//USED TO SHOW EXITING TERMINAL FOR OS
{
    pthread_mutex_lock (&Locker);
    string Message1;
    
    Message1 = "Closing Operating System Files, Please Wait ";  
    cout << "\n\n\n\t\t" << Message1;
    sleep (1);
    
    Message1 = "Closing OS Component  📄️  / 4";
    cout << "\n\n\t\t" << Message1;
    sleep (1);
    
    Message1 = "Closing OS Component  📄️  📄️  / 4";
    cout << "\n\n\t\t" << Message1;
    sleep (1);
    
    Message1 = "Closing OS Component  📄️  📄️  📄️  / 4";
    cout << "\n\n\t\t" << Message1;
    sleep (1);
    
    Message1 = "Closing OS Component  📄️  📄️  📄️  📄️   / 4";
    cout << "\n\n\t\t" << Message1;
    sleep (1);
    
    Message1 = "\n\n\t\tNice Meeting You, Stay Blessed !! "; 
    cout << "\n\n\t\t" << Message1;
    Message1 = "\n\n\t\tSystem Successfully Closed Files !! "; 
    cout << "\n\n\t\t" << Message1;
    
    sleep (3);
    cout << endl << endl;
    pthread_mutex_unlock (&Locker);
}





void* sysdetails(void * val)                                                                         // USED TO SHOW SYSTEM DETAILS
{
   pthread_mutex_lock (&Locker);
   system("clear");
   SetCursorPos(100,1,480,2000,9,0);
   cout<<"\t-------------------------------------------------"<<endl;
   cout<< endl <<"\t\t\t   System Details " << endl;
   cout<< endl <<"\t-------------------------------------------------"<<endl<<endl;
   sleep(2);  
   system("lscpu");
   cout<<endl;
   cin.get();
   pthread_mutex_unlock (&Locker);
   pthread_exit(NULL);
}

void* installed(void * val)											//USED TO SHOW INSTALLED APPLICATIONS ON SYSTEM
{
   pthread_mutex_lock (&Locker);
   system("clear");
   SetCursorPos(100,1,680,2000,9,0);
   cout<<"\t-------------------------------------------------"<<endl;
   cout<< endl <<"\t\t    INSTALLED APPLICATIONS " << endl;
   cout<< endl <<"\t-------------------------------------------------"<<endl<<endl;
   sleep(2);  
   system("apt list --installed");
   cout<<endl;
   cin.get();
   pthread_mutex_unlock (&Locker);
   pthread_exit(NULL);
}

void Main_Menu()											// USED TO SHOW MAIN MENU AND RELATED OPTIONS
{
	int opt=0;
	pthread_t FThread;
	system("clear");
	SetCursorPos(100,1,temp,2000,9,0);
	cout<<"\t-------------------------------------------------"<<endl;
        cout<< endl <<"\t\t\t   MAIN MENU " << endl;
        cout<< endl <<"\t-------------------------------------------------"<<endl;
	cout << endl << "\tPress 1 to Enter Desktop        !" << endl;
	cout << "\tPress 2 to Enter Start Menu     !" << endl;
	cout << "\tPress 3 to Show System Details  !" << endl;
	cout << "\tPress 4 to View Installed Apps  !" << endl;
	cout << "\tPress 5 to Open Task Manager    !" << endl;
	cout << "\tPress 6 to Show Project Details !" << endl;
	cout << "\tPress 0 to Exit                 !" << endl;
	
	cout << endl << "\tSelected Option : ";
	cin >> opt;
        
	switch (opt)
	{
	    case 1:
	        system("x-terminal-emulator -e \"./desktop\"");
	        SetCursorPos(100,1,512,2000,10,1);
	        Main_Menu();
	        break;
	    case 2:
	        system("x-terminal-emulator -e \"./start\"");
	        SetCursorPos(100,1,512,2000,9,2);
	        Main_Menu();
	        break;
	    case 3:
	        system("clear");
	        pthread_create(&FThread,NULL,sysdetails,NULL);
	        pthread_join(FThread,NULL);
	        cin.get();
	        Main_Menu();
	        break;
	    case 4:
	        system("clear");
	        pthread_create(&FThread,NULL,installed,NULL);
	        pthread_join(FThread,NULL);
	        cin.get();
	        Main_Menu();
	        break;
	    case 5:
	        system("clear");
	        SetCursorPos(100,1,680,2000,12,0);
	        system("x-terminal-emulator -e \"gnome-system-monitor\"");
	        sleep(3);
	        cin.get();
	        Main_Menu();
	        break;
	    case 6:
	        system("clear");
	        pthread_create(&FThread,NULL,details,NULL);
	        pthread_join(FThread,NULL);
	        cin.get();
	        Main_Menu();
	        break;
	    case 0:
	        system("clear");
	        exitt();
	        break;
	    default:
	        cout << endl << "Unvalid Command, Try Again" << endl;
	        sleep(2);
	        Main_Menu();
	        break;
	    
	}
	
}






int main()									// MAIN PROGRAM CONSITING OF RELATED FUNCTIONS
{
   splash_Screen();
   Main_Menu();
   
   
   return 0;
   
}























