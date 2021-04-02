#include <iostream>
#include <windows.h>
#include <ctime>
#include <mmsystem.h>
#include <conio.h>

using namespace std;

//========================================================================================================
//========================== COMPILAR COM A LIBRARY "Winmm" ==============================================
//                      -g "File" -o "File".exe -l Winmm -static
//========================================================================================================

int main()
{
    int n;
    cout << "Press 1 to start playing.\n";
    cin >> n;

    //play the audio file and specify start and end positions
    if (n == 1)
    {
        cout << "file playing....\n";
        time_t t1 = time(0);
        mciSendString((LPCTSTR) "play \"D:\\Documents\\GitHub\\cartridge\\musics\\01.mp3\" from 10000 to 30000 wait", NULL, 0, NULL);
        time_t t2 = time(0);
        cout << "Duration of the play :" << t2 - t1 << " seconds." << endl;
    }
    else
        cout << "You did not press 1." << endl;

    //close the audio file
    mciSendString((LPCTSTR) "close \"D:\\Documents\\GitHub\\cartridge\\musics\\01.mp3\"", (LPTSTR)NULL, (UINT)0, (HWND__ *)0);

    return 0;
}