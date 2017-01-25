//For Controls
//See <Readme.txt>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<math.h>
using namespace std;
int calc(int y);
int chk_pp=1,chk_ws=0;
int score=0;
void wait(){
    Sleep(1000);cout<<".";Sleep(1000);cout<<".";Sleep(1000);cout<<".";cout<<endl;
}
char * str_low(char arr[]){
    for(int i=0;i<strlen(arr);i++)
        if(arr[i]>=65 && arr[i]<=91)
            arr[i]=arr[i]+32;
    return arr;
}
int str_game()
{
    fflush(stdin);
    unsigned int seedval;
	time_t t;
	seedval=(unsigned)time (&t);
	srand(seedval);
    char numInput, A;
        A=(rand()%61)+65;
    clock_t start = clock();
    cout<<"-----------------------------\n";cout<<"Type: ";
    cout<<A;cout<<endl<<endl<<"#";

    while ( ! _kbhit() ) //Check for keyboard hit
    {
        //Check if 2 sec timer expired or not
        if (((clock () - start)/ CLOCKS_PER_SEC ) >= 2)
        {
            cout << "\n Time Up!" << endl;
            return 0;
            //start = clock();                            //Set new timer
        }
    }

    //Get the input here
    cin>>numInput;
    if(A==numInput){
        cout << "Correct!" << numInput << endl;
        return 1;
    }
    else
        cout << "\n Wrong!" << endl;
    _getch();

    return 0;
    }
int chance(int num)
{
	unsigned int seedval;
	time_t t;
	seedval=(unsigned)time (&t);
	srand(seedval);
	return(rand()%num);
}
int hp=75,has_key=0;float money=80;
int inv[10]={1,2},inv_c=2;

void status(){
    cout<<"\n Your Status:\n------------------\n [Health] --> "<<hp<<"\n [Cash] --> $"<<money<<"\n";getch();
}
void chg_stat(unsigned int hpm,int mnm){
    if(mnm<0 && money<-mnm){
        cout<<"\n Insufficient Funds!\n";
        goto func_end;
        }
    else
        money+=mnm;
    if(hp==100){
	cout<<" My Health is Full! Can't buy anymore..."<<endl;
	goto func_end;
    }
    hp+=hpm;
    if(hp>=100){
	hp=100;
	cout<<"\n My Health is Full!"<<endl;
	getch();
    }
    func_end:
    status();
}
void chg_stat(int hpm,int mnm){
    if(mnm<0 && money<-mnm){
        cout<<"\n Insufficient Funds!\n";
        goto func_end;
    }
    else
        money+=mnm;
    if(hpm<0 && -hpm>hp){
        cout<<"\n You died of low health\n";getch();status();
        cout<<"\n You're now leaving Paheli District.\n Thanks for playing...";
    getch();exit(0);
    }
    else
        hp+=hpm;
    func_end:
    status();
}
void list_inv(){
    int i;
    cout<<"\n----------------------------\n Your inventory contains:\n----------------------------\n";
    for(i=0;i<inv_c;i++){
	    cout<<"> ";
	switch(inv[i]){
		case 1:cout<<"Map\n";
		       break;
		case 2:cout<<"Torch\n";
		       break;
        case 3:cout<<"Room Key\n";break;
        case 4:cout<<"Hammer\n";break;
        case 5:cout<<"Train Ticket\n";break;
        case 6:cout<<"AEC Coding Club Prize\n";break;
		default:cout<<"Unknown\n";
	    }
    }
    cout<<"----------------------------\n";
    getch();
}

int main(){
    inv[9]=0;
    char p_name[50],ch;

cout<<"-------------------------------------------------------------------\n";Sleep(200);
cout<<"        ***** **                 *                 ***             \n";Sleep(150);
cout<<"     ******  ****              **                   ***      *     \n";Sleep(150);
cout<<"    **   *  *  ***             **                    **     ***    \n";Sleep(150);
cout<<"   *    *  *    ***            **                    **      * \n";Sleep(150);
cout<<"       *  *      **            **                    **            \n";Sleep(150);
cout<<"      ** **      **    ****    **  ***      ***      **    ***     \n";Sleep(150);
cout<<"      ** **      **   * ***  * ** * ***    * ***     **     ***    \n";Sleep(150);
cout<<"    **** **      *   *   ****  ***   ***  *   ***    **      **    \n";Sleep(150);
cout<<"   * *** **     *   **    **   **     ** **    ***   **      **   \n";Sleep(150);
cout<<"      ** *******    **    **   **     ** ********    **      **    \n";Sleep(150);
cout<<"      ** ******     **    **   **     ** *******     **      **    \n";Sleep(150);
cout<<"      ** **         **    **   **     ** **          **      **   \n";Sleep(150);
cout<<"      ** **         **    **   **     ** ****    *   **      **   \n";Sleep(150);
cout<<" **   ** **           ***   **  **    **   *****      ***     *** \n";Sleep(150);
cout<<"***   *  *                            *\n";Sleep(150);
cout<<" ***    *                            * \n";Sleep(150);
cout<<"  ******                            *  \n";Sleep(150);
cout<<"    ***                            *\n";Sleep(150);
cout<<"-------------------------------------------------------------------";Sleep(200);
cout<<"\n For Instructions: See Readme.txt\n";
cout<<"\n\n\t Loading:\n";Sleep(200);
cout<<"\t #";Sleep(400);cout<<"#";Sleep(400);cout<<"#";Sleep(400);cout<<"#";Sleep(400);cout<<"#";Sleep(400);cout<<"#";Sleep(400);cout<<"#";Sleep(400);cout<<"#";Sleep(400);cout<<"#";Sleep(400);cout<<"#";Sleep(400);cout<<"#";Sleep(400);cout<<"#";cout<<endl<<"\t Done!\n";Sleep(150);


    cout<<"\n Welcome to the Paheli District!";cout<<"\n What is your name, Saheb?\n#";
    gets(p_name);

    cout<<"\n Mr. "<<p_name<<", you're currently standing at the gate of the Town of Ramnagar which is in the north.\n";
    getch();
    cout<<"\n From here, you can go west to the Panagarh forest, east to visit the Patel's Dhaba or go back to the Train Station.";
    getch();

    scene_1:
    cout<<"\n ----------------------------------------------------------------------";
    cout<<"\n 1) North - Panagarh Town\n 2) West - Ramnagar forest\n 3) East - Dhaba\n 4) South - Train Station\n\n#";
    fflush(stdin);
    cin>>ch;
    cout<<"\n";

    switch(ch){
	case '1':cout<<" I 'm kinda nervous!\n";
		 getch();
		 goto town;
	case '2':if(!(has_key==-1))
             cout<<" I think I should visit the town first rather than try to be Bear Grylls.\n";
             else{
                    cout<<"\n No more running...\n";getch();
cout<<"       ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^"<<endl;
cout<<"      /|\\/|\\/|\\ /|\\    /\\-_--\\    /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\"<<endl;
cout<<"      /|\\/|\\/|\\ /|\\   /  \\_-__\\   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\"<<endl;
cout<<"      /|\\/|\\/|\\ /|\\   |[]| [] |   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\"<<endl;}

		 getch();
		 goto scene_1;

	case '3':
		 goto dhaba;
	case '4':if(has_key==-1){
                goto train;
                }
            else{
                cout<<" I just arrived, don't wanna ride back again. I 'll probably vomit this time.\n";
                getch();
                goto scene_1;
            }
	case 'q':
	case 'Q':list_inv();
		 getch();
		 goto scene_1;
	case 'i':
	case 'I':status();
		 getch();
		 goto scene_1;
	case 'E':
	case 'e':goto end;
	default:cout<<" What! I can't understand myself now.\n";
		getch();
		goto scene_1;

    }

    //****************************
    dhaba:
        cout<<"\n ----------------------------------------------------------------------";
cout<<"\n                           )"<<endl;Sleep(150);
cout<<"                *-*       ("<<endl;Sleep(150);
cout<<"          _______|________%%__"<<endl;Sleep(150);
cout<<"         |%%%%%%%%%%%%%%%%%%%%%|"<<endl;Sleep(150);
cout<<"    _____|%%%/^\\%%%/^\\%%%/^\\%%%|_____"<<endl;Sleep(150);
cout<<"   /%/^\\%|%%%|-|%%%|-|%%%|-|%%%|%/^\\%\\"<<endl;Sleep(150);
cout<<"  /%%|-|%|%%%%%%%%%%%%%%%%%%%%%|%|-|¾¾\\"<<endl;Sleep(150);
cout<<" /%%%%%%%%| __  __ ___ __  __ |%%%%%%%%\\"<<endl;Sleep(150);
cout<<"  |_|-|-|_||__||__|.|.|__||__||_|-|-|_|"<<endl;Sleep(150);
cout<<"  IIIIIIII|       |_|_|       |IIIIIIII"<<endl;Sleep(150);
cout<<"  ~^    ^ @@@@@@@@|   |@@@@@@@@ ^    ^~"<<endl;Sleep(150);
cout<<"                  |   |"<<endl;Sleep(150);
	cout<<"\n You enter Patel's dhaba.\n";
	getch();
	cout<<"\n It is a dhaba located outside the Panagarh Town. It is owned by Motilal Patel and his family, you walk up to the counter to talk to him.\n";
	getch();
	scene_2:
	    cout<<"\n ----------------------------------------------------------------------";
	cout<<"\n Patel: What can i serve you, Saheb!";
	getch();
	cout<<"\n 1) Paratha - $30 -> +10HP\n 2) Lassi - $10 -> +8HP\n 3) Roti - $50 -> +20HP\n 4) Leave\n#";
	fflush(stdin);
	cin>>ch;
	switch(ch){
	case '1':
		 chg_stat((unsigned)10,-30);
		 goto scene_2;
	case '2':
		 chg_stat((unsigned)8,-10);
		 goto scene_2;
	case '3':
		 chg_stat((unsigned)20,-50);
		 goto scene_2;
	case '4':
		 goto scene_1;
	case 'q':
	case 'Q':list_inv();
		 goto scene_2;
	case 'i':
	case 'I':status();
		 getch();
		 goto scene_2;
	case 'E':
	case 'e':goto end;
	default:cout<<" What! I can't understand myself now.\n";
		getch();
		goto scene_2;

    }
    town:
cout<<"                                                    __________"<<endl;Sleep(80);
cout<<"             _,---.                          _..--'/          \\"<<endl;Sleep(80);
cout<<"          ,-'      )                    _,-,'     /            \\"<<endl;Sleep(80);
cout<<"         (          )               _,-'  /      /              \\"<<endl;Sleep(80);
cout<<"          `-.__, -'             _,-/     /     _/ ,------------. \\"<<endl;Sleep(80);
cout<<"     ,--._,---.             _,-'  /     /_,--'' | |            | |"<<endl;Sleep(80);
cout<<"   _(_,-'      )        _,-'/    /_, - '|       | |  Panagarh  | |"<<endl;Sleep(80);
cout<<" ,'  (        )      ,'/   /_, -'|      ||_  -  | |    Town    | |"<<endl;Sleep(80);
cout<<"(     `--._,-'    _,' /_,-'|     ||_  - |       | |            | |"<<endl;Sleep(80);
cout<<" `--.__,-'     _,'/,-'|  - ||_ - |      ||_  -  | |            | |"<<endl;Sleep(80);
cout<<"            _,'/,'|  - ___ |     ||_  - |       | `------------' |"<<endl;Sleep(80);
cout<<"        _ ,' |_' -|- _(   ) |_   |      ||_  -  |                |"<<endl;Sleep(80);
cout<<"       ( ): ((`) -| (. `-/ )   - ||_  - |       |                |"<<endl;Sleep(80);
cout<<"      ` | '(-.,') '( _\\`/-') _ - |      | _   - |                |"<<endl;Sleep(80);
cout<<"        `   (_.) -(_._ \\|,-_)    ||_  - |       |                |"<<endl;Sleep(80);
cout<<" .        `. || ` | (_\\||_)  _ - |      ||_  -  |                |"<<endl;Sleep(80);
cout<<"             `.    ` . ||  |   - ||_  - |       |                |"<<endl;Sleep(80);
cout<<"                `.     ||-.|  :  |  _   ||_   - |     __________ |"<<endl;Sleep(80);
cout<<"                   `.  ||    ` -.|   |  |   _   |    | _      _ |`'--.._"<<endl;Sleep(80);
cout<<"                      `.           ` - .|  | |  |    || ()._o  ||   __ |"<<endl;Sleep(80);
cout<<"            `            `.   `           ` -' .|____|`'---.|>_||  |. ||"<<endl;Sleep(80);
	fflush(stdin);
	cout<<"\n ----------------------------------------------------------------------";
	cout<<"\n You enter the town to find yourself in a calm and dry atmosphere... From here you can:\n 1) Go to the Inn\n 2) Go to Post office\n 3) Go to the Police Station\n 4) Go to Temple\n 5) Go Outside the Village\n#";
    cin>>ch;
    cout<<"\n";
    switch(ch){

	case '1':{if(has_key==0){
                cout<<" I hope a cozy bed waiting for me.";getch();
                goto inn;
		 }
		 else if(has_key==-1){cout<<"\n No more kidnappings!!!";goto town;}

		 else{cout<<" Back to the Room!";wait();}goto room;}
	case '2':cout<<" Maybe I 'll find my love letters there...\n";
		 getch();
		 goto post;
	case '3':if(has_key==-1)
                    goto police;
                else {
                    cout<<" No, That's isn't place to hang out right now."<<endl<<endl;getch();cout<<" I need to hit the bed!"<<endl;getch();
                    goto town;
                }
	case '4':goto temple;
	case '5':cout<<"You walked out of the village.";
		 getch();
		 goto scene_1;
	case 'q':
	case 'Q':list_inv();
		 getch();
		 goto town;
	case 'i':
	case 'I':status();
		 getch();
		 goto town;
	case 'E':
	case 'e':goto end;
	default:cout<<" What! I can't understand myself now.\n";
		getch();
		goto town;
    }
    temple:
cout<<"         ."<<endl;Sleep(150);
cout<<"      .                    |~~             ."<<endl;Sleep(150);
cout<<"                  .     ___|___      ."<<endl;Sleep(150);
cout<<"                       ((((())))"<<endl;Sleep(150);
cout<<"          .           (((((()))))         ."<<endl;Sleep(150);
cout<<"                    |-------------|"<<endl;Sleep(150);
cout<<"              +    I_I_I_I_I_I_I_I_I    +"<<endl;Sleep(150);
cout<<"             (()   |---------------|   (()"<<endl;Sleep(150);
cout<<"            |---|  ||-| |-| |-| |-||  |---|"<<endl;Sleep(150);
cout<<"  _________|-----|_|---------------|_|-----|_________"<<endl;Sleep(150);
cout<<"  I_I_I_I_I_I_I_I|I_I_I_I_I_I_I_I_I_I|I_I_I_I_I_I_I_|"<<endl;Sleep(150);
cout<<"  |-------|------|-------------------|------|-------|"<<endl;Sleep(150);
cout<<"  ||-| |-||  |-| ||-| |-| |-| |-| |-|| |-|  ||-| |-||"<<endl;Sleep(150);
cout<<"((|-------|------|-------------------|------|-------|))"<<endl;Sleep(150);
cout<<"()|  |_|  |  |_| |::::: ------- :::::| |_|  |  |_|  |()"<<endl;Sleep(150);
cout<<"))|  |_|  |  |_| | |_| |_.-'-._| |_| | |_|  |  |_|  |(("<<endl;Sleep(150);
cout<<"()|-------|------| |_| | | | | | |_| |------|-------|()"<<endl;Sleep(150);
cout<<"@@@@@@@@@@@@@@@@@|-----|_|_|_|_|-----|@@@@@@@@@@@@@@@@@"<<endl;Sleep(150);
cout<<"                @@@@/=============\@@@@"<<endl;Sleep(150);
        cout<<"\n ----------------------------------------------------------------------";
	cout<<"\n You walk some distance to reach the Sacred Temple.\n";
	getch();
	cout<<"\n There are not many devotees around but the priest is busy chanting the mantras in front of the Idol. You can:\n";
	getch();
	cout<<"\n 1) Pray to Devi and leave peacefully\n 2) Ring the Ghanta\n 3) Steal money from the Dan Patra\n 4) Dance at the Altar\n#";
	fflush(stdin);
	cin>>ch;
	cout<<"\n";

	switch(ch){
	case '1':cout<<" You pray to the Devi in the most devoted mood";
         wait();
		 cout<<"\n Your Devotion --> 100\n <Note: Devotion has no effect on game/>\n";getch();
		 goto town;
	case '2':cout<<" You rang the Ghanta.\n";getch();cout<<"\nHearing it, the priest woke up and persuaded you to make a donation of $10\n";getch();cout<<"\n<Caution: The Priest cannot remember faces so he may ask you for donation again/>\n";
		 getch();
		 if(money<10 && money!=0){
            chg_stat(0,-money);
		 }
		 else if(money<=0){
             cout<<"\n You don't have any money!";getch();
         }
		 else chg_stat(0,-10);
		 goto town;
	case '3':{cout<<"\n You try to steal money from the Dan Patra";wait();
             cout<<endl;
                int i=chance(3);
                if(!(!i)){
                        for(int i=0;i<150;i++)
                        cout<<" THE PRIEST NOTICES YOU!!!";
                        cout<<endl<<endl<<" He shouts for help!";getch();cout<<"\n Devotees come and BEAT you like HELL";wait();
                        chg_stat(-50,0);
                        cout<<"\n They take you to the Police Station\n";getch();
                        if(money<50){
                            cout<<"\n The Police demand bribe!\n";getch();
                            cout<<"\n You have less than $50\n";getch();
                            cout<<"\n You are left to rot in prison for theft!";getch();
                            goto over;
                        }
                        else{
                        chg_stat(0,-money);
                        cout<<"\n The Police takes all your money and lets you go\n";getch();
                        goto town;
                        }
                }
                else{
                    i=chance(100)+50;
                    cout<<"\n You found $"<<i<<"!\n";getch();
                    chg_stat(0,i);
                    cout<<"\n That's a whole lotta money!!";getch();cout<<"\n In an (very)elated mood, You leave the temple.\n";getch();
                    goto town;
                }}
	case '4':cout<<"\n You dance in a CRAZY WAY!\n";getch();cout<<"\n People have mistaken you for a escaped lunatic from Asylum\n";getch();cout<<"\n They admit you at the Asylum where you will spend the rest of your life";wait();goto over;
	case '5':cout<<"\n You walked out of the village.";
		 getch();
		 goto scene_1;
	case 'q':
	case 'Q':list_inv();
		 getch();
		 goto temple;
	case 'i':
	case 'I':status();
		 getch();
		 goto temple;
	case 'E':
	case 'e':goto end;
	default:cout<<" What! I can't understand myself now.\n";
		getch();
		goto town;

    }
    inn:
cout<<"\n            _H_              _H_               _H_                  o88o."<<endl;Sleep(150);
cout<<"          .=|_|===========v==|_|============v==|_|===========.    (8%8898),"<<endl;Sleep(150);
cout<<"         /                |                 |                 \ ,(8888%8688)"<<endl;Sleep(150);
cout<<"        /_________________|_________________|__________________(898%88688HJW)"<<endl;Sleep(150);
cout<<"        |=|_|_|_|  =|_|_|=|X|)^^^(|X|=|/ \\|=||_|_|_|=| ||_|_|=|`(86888%8%9b)"<<endl;Sleep(150);
cout<<"        |=|_|_|_|== |_|_|=|X|\\___/|X|=||_||=||_____|=|_||_|_|=|___(88%%8888)"<<endl;Sleep(150);
cout<<"        |=_________= ,-. =|''''''''''=''''= |=_________== == =|_______\\//`'"<<endl;Sleep(150);
cout<<"        |=|__|__|_| //O\\\= |X|'''''|X|=//'\\\\=|=|_|_|_|_| .---.=|.=====.||"<<endl;Sleep(150);
cout<<"        |=|__|__|_|=|| ||=|X|_____|X|=|| ||=|=|_______|=||'||=||=====|||"<<endl;Sleep(150);
cout<<"        |___d%8b____||_||_|=_________=||_||_|__d8%o%8b_=|j_j|=|j==o==j|\\---"<<endl;Sleep(150);
        chance(1);has_key=1;
    cout<<"\n ----------------------------------------------------------------------";
    cout<<"\n You walk towards the Inn\n";getch();
    cout<<"\n Receptionist: Welcome, Sir.\n";getch();
    cout<<"\n Receptionist: You must be Mr. "<<p_name<<".\n";getch();
    cout<<"\n You: Yes, I have a reservation here.\n";getch();
    cout<<"\n Receptionist: Yes, Sir Room #"<<(rand()%20)+2<<" is ready for you, Here is the key.\n";getch();
    {
        inv[inv_c]=3;
        inv_c++;
        cout<<"\n [ Key Acquired! ]\n"<<endl;getch();
        list_inv();
    }
    room:
cout<<"\n0================================================0"<<endl;Sleep(150);
cout<<"|'.                    (|)                     .'|"<<endl;Sleep(150);
cout<<"|  '.                   |                    .'  |"<<endl;Sleep(150);
cout<<"|    '.                |O|                 .'    |"<<endl;Sleep(150);
cout<<"|      '. ____________/===\\_____________ .'      |"<<endl;Sleep(150);
cout<<"|        :            `\\'/`  ______     :     .. |"<<endl;Sleep(150);
cout<<"|        :     mmmmmmm  V   |--%%--|    :   .'|| |"<<endl;Sleep(150);
cout<<"|        :     |  |  |      |-%%%%-|    :  |  || |"<<endl;Sleep(150);
cout<<"|        :     |--|--| @@@  |=_||_=|    :  I  || |"<<endl;Sleep(150);
cout<<"|        :     |__|__|@@@@@ |_\\__/_|    :  |  || |"<<endl;Sleep(150);
cout<<"|        :             \\|/   ____       :  |  || |"<<endl;Sleep(150);
cout<<"|        :;;       .'``(_)```\\__/````:  :  |  || |"<<endl;Sleep(150);
cout<<"|        :||___   :================:'|  :  | 0+| |"<<endl;Sleep(150);
cout<<"|        :||===)  | |              | |  :  |  || |"<<endl;Sleep(150);
cout<<"|        ://``\\\\__|_|______________|_|__:  I  || |"<<endl;Sleep(150);
cout<<"|      .'/'    \\' | '              | '   '.|  || |"<<endl;Sleep(150);
cout<<"|    .'           |                |       '. || |"<<endl;Sleep(150);
cout<<"|  .'                                        '|| |"<<endl;Sleep(150);
cout<<"|.'                                            '.|"<<endl;Sleep(150);
cout<<"0================================================0"<<endl;Sleep(150);
        cout<<"\n ----------------------------------------------------------------------";
	cout<<"\n You enter the room to:\n 1) Sleep on the Bed\n 2) Visit Bathroom\n 3) Visit Attic\n 4) Go Back to Town\n#";
   cin>>ch;
    cout<<"\n";
    switch(ch){
	case '1':cout<<" Good Night, Don't let the bedbugs bite!\n";
		 getch();
		 cout<<" One Sheep...";Sleep(500);cout<<" Two Sheep...";Sleep(500);cout<<" Three Sheep...";Sleep(500);
		 goto night;
	case '2':{
	    bath:
cout<<"                                                         |"<<endl;Sleep(150);
cout<<"                                            __________   |"<<endl;Sleep(150);
cout<<"                           _    __    _    |          |  |"<<endl;Sleep(150);
cout<<"                          /_\\  /  \\  /_\\   |          |  |"<<endl;Sleep(150);
cout<<"                          =|= | // | =|=   |          |  |"<<endl;Sleep(150);
cout<<"                           !   \\__/   !    |          |  |"<<endl;Sleep(150);
cout<<"                                 _         |          |  |"<<endl;Sleep(150);
cout<<" ___               ___          //'        |          |  |"<<endl;Sleep(150);
cout<<"[___]       _   :=|   |=:   __T_||_T__     |p=        |  |"<<endl;Sleep(150);
cout<<"|  ~|     =)_)=   |   |    [__________]    |          |  |"<<endl;Sleep(150);
cout<<"|   |      (_(    |xXx|     \_      _/     |          |  |"<<endl;Sleep(150);
cout<<"|   |      )_)    '''''       \\    /       |          |  |"<<endl;Sleep(150);
cout<<"\\___|                          |  |        |          |  |"<<endl;Sleep(150);
cout<<" |  `========,                 |  |        |          |  |"<<endl;Sleep(150);
cout<<"__`.        .'_________________|  |________|__________lc_|"<<endl;Sleep(150);
cout<<"    `.    .'                  (____)                      \\"<<endl;Sleep(150);
cout<<"    _|    |_...             .''''''''.                     \\"<<endl;Sleep(150);
cout<<"   (________)''''          :'''''''''':"<<endl;Sleep(150);
cout<<"        :::::::'            '::::::::'"<<endl;Sleep(150);
	        cout<<"\n ----------------------------------------------------------------------";
	    cout<<"\n You Wanna:\n 1) Pee \n 2) Wash hands\n 3) Back to Room\n#";
         cin>>ch;

            if(ch=='1')
            {
               if(chk_pp==1){
                    wait();
                    cout<<"\n My tank is empty now!\n";
                    chk_pp=0;chk_ws=1;
                    }
                else
                    cout<<"\n No more Pee left...\n";
                getch();
                goto bath;
            }
            else if(ch=='2')
            {
                cout<<"\n Swach Bharat Abhiyan has got me!\n";getch();
                chk_ws=0;
                goto bath;
            }
            else if(ch =='3')
            {
                if(chk_ws==1){
                    cout<<"\n I'm a dirty guy?\n\n Well, my hands are...\n";
                getch();}
                goto room;
            }}
	case '3':cout<<"\n You climb up to the Attic\n";getch();cout<<"\n It is dark and nothing is visible\n";getch();cout<<"\n Your head hits a beehive!\n";getch();cout<<"\n You realize that the attic isn't safe!\n";getch();chg_stat(15,0);
             goto room;

	case '4':goto town;
	case 'q':
	case 'Q':list_inv();
		 getch();
		 goto room;
	case 'i':
	case 'I':status();
		 getch();
		 goto room;
	case 'E':
	case 'e':goto end;
	default:cout<<" What! I can't understand myself now.\n";
		getch();
		goto room;

    }
    post:
        cout<<"\n ----------------------------------------------------------------------";
        cout<<"\n Postmaster: Hey! \n";getch();
        cout<<"\n You: Yes\n";getch();
        cout<<"\n Postmaster: I 'm in urgent need of help at the register, Wanna earn some extra cash? [y/n]\n#";
        cin>>ch;
        again:
        switch(ch)
            {
                case 'y':
                case 'Y':{score=0;
                            for(int i=0;i<10;i++){
                                int c=calc(15);
                                if(c==1)
                                    score++;}
                            cout<<endl<<"----------------------------------\n Your Total Score: "<<score<<endl;

                            cout<<endl<<" You earned $"<<score*10<<endl;
                            chg_stat(0,score*10);}
                            cout<<endl<<" Wanna go again? [y/n]\n#";
                                fflush(stdin);
                                cin>>ch;
                                    goto again;

                case 'n':
                case 'N':cout<<"\n Postmaster: No problem, come back if you change your mind.\n";getch();
                        goto town;
                default:cout<<"\n What are you saying, boy?";
                        goto again;
            }
    night:
        system("cls");
        getch();
        has_key=-1;
        cout<<" You wake up on hearing some noise..."<<endl;getch();
        cout<<" You look at the clock"<<endl;getch();
        cout<<"         ###  #      ### ###      #  # #"<<endl;Sleep(150);
        cout<<"         # # ##   #  # # #       # # ###"<<endl;Sleep(150);
        cout<<"         # #  #      # # ###     ### ###" <<endl;Sleep(150);
        cout<<"         # #  #   #  # #   #     # # # #" <<endl;Sleep(150);
        cout<<"         ### ###     ### ###     # # # #"<<endl;Sleep(150);getch();
        cout<<endl<<" The window to your room opens and two shadowy figures appear..."<<endl;getch();
        cout<<endl<<" There don't look too friendly";getch();cout<<" and probably aren't room service"<<endl;getch();
        cout<<endl<<" You try out your Youtube learnt taekwondo on them\n";getch();
        cout<<endl<<" YOU ARE KNOCKED OUT!!!";getch();cout<<"(WHAT DID YOU EXPECT?)";getch();
        cout<<endl<<"\n GAME OVER!!!\n";getch();
        cout<<endl<<"\n No, Not Now, Just messing";getch();
        system("cls");
    kidnap:
        getch();
        cout<<"\n ----------------------------------------------------------------------";
        char inv_name[20];
        cout<<"\n (Your head hurts!)";getch();cout<<"\n You wake up in a dark room...\n";getch();cout<<"\n You try to find your torch:";getch();
        list_inv();
        cout<<"\n Type Item name:\n#";
        fflush(stdin);
        gets(inv_name);
            while(strcmp(str_low(inv_name),"torch")){
                cout<<"\n It doesn't make sense!!! Re-enter!!!\n#";
                gets(inv_name);
            }
                cout<<"\n You turn on the torch.";getch();
                cout<<"\n The room illuminates!\n";getch();
                cout<<"\n You have been kidnapped and locked in a small room in an unknown place!\n";getch();
                if(money>0){
                cout<<"\n They took away your money!!!(Obviously)\n";getch();
                }
                cout<<"\n DISHOOM! ";Sleep(200);cout<<"\n DISHOOM! ";Sleep(200);
                chg_stat(-(hp/2),-money);
                exp1:
                cout<<"\n What are you going to do now?\n 1) Wait\n 2) Explore the place\n#";
                cin>>ch;

                switch(ch){
                    case '1':
                             {
                             exp2:

                             cout<<"\n You wait for some time";wait();cout<<"\n After some time, through a hole you watch the kidnappers go away into the forest.\n";getch();
                             cout<<"\n You have time to act now!";getch();
                             cout<<"\n You: \n 1) Wait longer\n 2) Explore the room\n 3) Suicide\n#";
                             char ch;
                             cin>>ch;
                                switch(ch){
                                    case '1':cout<<"\n You wait";wait();
                                             cout<<"\n After sometime, the kidnappers come back\n";getch();
                                             cout<<"\n They were nervous of getting caught and therefore decided to\n";getch();cout<<"SLIT YOUR THROAT!!!!SCARY!!!\n";getch();
                                             goto over;
                                    case '2':cout<<"\n You explore the room to find a Hammer\n";getch();cout<<" [Hammer Acquired!]";getch();inv[inv_c]=4;inv_c++;

                                             cout<<"\n You may be able to break the weak wall around the hole using it\n";getch();
                                             list_inv();
                                                cout<<"\n Type Item name:\n#";
                                                        fflush(stdin);
                                                        gets(inv_name);
                                                            while(strcmp(str_low(inv_name),"hammer")){
                                                                cout<<"\n It doesn't make sense!!! Re-enter!!!\n#";
                                                                gets(inv_name);
                                                            }
                                             cout<<"\n You begin hitting the wall!\n";getch();
                                             cout<<"\n -------------------------------------------------------------\n";
                                             cout<<" Type the displayed Character to break the wall:\n";getch();
                                             score=0;
                                             for(int i=0;i<10;i++){
                                                if(str_game()==1)
                                                    score++;
                                             }
                                             cout<<endl<<"Your Score: "<<score*10<<"/100";getch();
                                             if(score<5){
                                                cout<<"\n While hitting the wall, it fell on you and guess what!\n";getch();
                                                cout<<"\n You DIED!!!\n";
                                                goto over;
                                             }
                                             else goto the_run;
                                    case '3':cout<<"\n Anxiety and Horror feels your soul with Fear!\n";getch();
                                             cout<<"\n You decide to escape from life\n";getch();
                                             goto over;
                                     default:cout<<"\n What?!?!?!";getch();
                                             goto exp2;

                                }
                    }
                    case '2':cout<<"\n You try to explore the place";getch();cout<<"\n(You basically create lots of noises)\n\n";getch();
                             cout<<"\n The kidnapper's think you are trying to escape\n";getch();cout<<"\n They panic and BURN THE HOUSE!!!\n";getch();goto over;
                     default:cout<<"\n What?!?!?!";getch();
                             goto exp1;
                }
    the_run:
            cout<<"\n       ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^"<<endl;
            cout<<"      /|\\/|\\/|\\ /|\\    /\\-_--\\    /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\"<<endl;
            cout<<"      /|\\/|\\/|\\ /|\\   /  \\_-__\\   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\"<<endl;
            cout<<"      /|\\/|\\/|\\ /|\\   |[]| [] |   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\"<<endl;
            cout<<"\n ----------------------------------------------------------------------";
        cout<<"\n You are now trying to find your way through the forest\n";getch();cout<<"\n Unfortunately, the kidnappers have spotted you...\n";getch();cout<<"\n RUN FOR YOUR LIFE!!!\n";getch();
        for(int i=0;i<15;i++){if(calc(17)==0){
            if(hp<10)
                hp=0;
            else
                hp-=10;
            cout<<"\n You lost 10HP!\n HP : "<<hp<<endl;getch();
            if(hp<=0){
                    hp=0;
                    cout<<"\n You were killed!\n";getch();status();
                    goto over;
                }
            }
        }
        cout<<"\n You escaped and found your way to the town";getch();
        cout<<"\n The only thing on your mind is to escape from the town\n";getch();
        cout<<"\n You head to the Train Station";wait();
        goto train;
    police:
        cout<<"\n ----------------------------------------------------------------------";
        inv[9]=1;
        cout<<"\n You head over to the Police Station and report the case";wait();goto town;
    train:
        cout<<"\n ----------------------------------------------------------------------\n";
cout<<"                      (+++++++++++)"<<endl;Sleep(150);
cout<<"                  (++++)"<<endl;Sleep(150);
cout<<"               (+++)"<<endl;Sleep(150);
cout<<"             (+++)"<<endl;Sleep(150);
cout<<"            (++)"<<endl;Sleep(150);
cout<<"            [~]"<<endl;Sleep(150);
cout<<"            | | (~)  (~)  (~)    /~~~~~~~~~~~~"<<endl;Sleep(150);
cout<<"         /~~~~~~~~~~~~~~~~~~~~~~~  [~_~_] |    * * * /~~~~~~~~~~~|"<<endl;Sleep(150);
cout<<"       [|  %___________________           | |~~~~~~~~            |"<<endl;Sleep(150);
cout<<"         \[___] ___   ___   ___\  No. 4   | |   A.T. & S.F.      |"<<endl;Sleep(150);
cout<<"      /// [___+/-+-\-/-+-\-/-+ \\_________|=|____________________|="<<endl;Sleep(150);
cout<<"    //// @-=-@ \___/ \___/ \___/  @-==-@      @-==-@      @-==-@"<<endl;Sleep(150);
cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;Sleep(150);
        cout<<"\n You rush to the Ticket counter\n";getch();cout<<"\n Counter Guy: How can I help you?\n";getch();cout<<"\n You: I need a Ticket to Hoogli\n";getch();cout<<"\n Counter Guy: Ticket for Hoogli is for $150.\n";getch();if(money<150){cout<<"\n Counter Guy: You have insufficient funds!\n";getch();cout<<"\n You head back to the town";getch();goto town;}
        else{
            chg_stat(0,-150);
            cout<<"\n [Train Ticket Acquired!]";inv[inv_c]=5;inv_c++;list_inv();
            cout<<"\n Counter Guy: Your train will depart after "<<(rand()%3)+2<<" hrs\n";getch();system("cls");
            cout<<"Later";wait();
            cout<<"\n You get on your train and now are on your way home\n";
                if(inv[9]==1){
                    cout<<"\n Later, you hear the news that the kidnappers were caught by the Panagarh Police\n\n";getch();cout<<"\n You attained the Perfect Ending!\n";getch();
                    inv[inv_c]=6;inv_c++;
                }
                else
                    {cout<<"\n You missed the Perfect Ending!";getch();
                }
                cout<<"\n ----------------------------------------------------------------------";
                cout<<"___________.__             ___________           .___"<<endl;Sleep(150);
                cout<<"\\__    ___/|  |__   ____   \\_   _____/ ____    __| _/"<<endl;Sleep(150);
                cout<<"  |    |   |  |  \\_/ __ \\   |    __)_ /    \\  / __ | "<<endl;Sleep(150);
                cout<<"  |    |   |      \\  ___/   |        \\   |  \\/ /_/ | "<<endl;Sleep(150);
                cout<<"  |____|   |___|  /\\___  > /_______  /___|  /\\____ | "<<endl;Sleep(150);
                cout<<"                \\/     \\/          \\/     \\/      \\/ "<<endl;Sleep(150);
                last:
                    cout<<"\n ----------------------------------------------------------------------";
                    cout<<"\n Code: 67 72 69 67 75 49 78 86 69 78 84 79 82 89\n";
                cout<<"\n Type C to continue!\n#";
                cin>>ch;
                    switch(ch){
                        default: cout<<"\n C for Cat! Type C!\n";getch();
                                 goto last;
                        case 'q':
                        case 'Q':list_inv();has_key=99;
                        case 'c':
                        case 'C':if(has_key==99){cout<<"\n You discovered the Easter Egg!\n";getch();}
                                 else {cout<<"\n You failed to find the Easter Egg!\n";getch();}
                    }
                goto end;
        }
    over:
        cout<<"\n GAME OVER!!!\n";getch();cout<<"\n You LOSE!!!\n";getch();
cout<<"                           _,..__,"<<endl;Sleep(150);
cout<<"                       ,.'''      `'-,_"<<endl;Sleep(150);
cout<<"                     ,'                '."<<endl;Sleep(150);
cout<<"                   ,'                    '"<<endl;Sleep(150);
cout<<"                  /                       \_"<<endl;Sleep(150);
cout<<"                 ;     -.                   `\\"<<endl;Sleep(150);
cout<<"                 |       |     _         _    ."<<endl;Sleep(150);
cout<<"                ;       ,'  ,-' `.     /' `.  |"<<endl;Sleep(150);
cout<<"                |       '  /  o   |   t  o  \.'    .,-."<<endl;Sleep(150);
cout<<"                 |         |:    .'   |:    .|    /    \\"<<endl;Sleep(150);
cout<<"                 ;         \\:.._./    ':_..:/ `. |      L"<<endl;Sleep(150);
cout<<"                  \\  ,-'           |\\_         `\\-     '-."<<endl;Sleep(150);
cout<<"      ,-'``'-,    `f              '/`>                    `."<<endl;Sleep(150);
cout<<"    ,'        `L___.|              '  `     . _,/            \\"<<endl;Sleep(150);
cout<<"    |                \\_          _   _    .-.]____,,         |"<<endl;Sleep(150);
cout<<"    \\             ,. ___""----./` \\,' ',`\\'  \\      \\       .'"<<endl;Sleep(150);
cout<<"      `'-'|        '`         `|   |   |  |  |       `'--'`"<<endl;Sleep(150);
cout<<"          ,         |           L_.'.__:__.-'"<<endl;Sleep(150);
cout<<"           \\        /"<<endl;Sleep(150);
    end:
	cout<<"\n You're now leaving Paheli District.\n Thanks for playing...\n";
    getch();
}
int calc(int y)
{
    int x;
    unsigned int seedval;
	time_t t;
	seedval=(unsigned)time (&t);
	srand(seedval);
    char numInput[10];int A=(rand()%30)+y, B=(rand()%30)+y,bug_fix=0;
    clock_t start = clock();
    cout<<"\n Q: "<<A<<" + "<<B<<"?\n\n#";
    while ( ! _kbhit() ) {
        if (((clock () - start)/ CLOCKS_PER_SEC ) >= 5){
            cout<< "\n Time Up!!!" << endl;
            goto end;
            //start = clock();
            }
    }
    //Get the input here
    fflush(stdin);
    gets(numInput);
    x=strlen(numInput);
    for(int i=0;i<x;i++){
        bug_fix+=((int)(numInput[i])-48)*pow(10,x-i-1);
    }
    if(bug_fix==A+B){
        cout << "\n Correct: " << numInput << endl;
        return 1;
    }
    else
        cout << "\n Wrong!!!" << endl;
    end:
    return 0;
    }





