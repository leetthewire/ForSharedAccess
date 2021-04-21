#include <wrl.h>
#include <list>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <shellapi.h>
#include <windows.h>

using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

FILE* StartLoader(std::wstring fileName, std::wstring fileFormat)
{
    AllocConsole();
    std::fstream fin;
    std::fstream fout;
    char input;
    char const *stringCount = "1";
    int i = 1;
    std::string s;

    char numbers[] = {'1','2','3','4','5','6','7','8','9',};

    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int miliseconds = 0;

    int hours_plus = 0;
    int minutes_plus = 0;
    int seconds_plus = 3;
    int miliseconds_plus = 1;
    

	FILE* pStreamOut = nullptr;
	freopen_s(&pStreamOut, "CONOUT$", "w", stdout);
    fout.open(fileName + L"out" + fileFormat, fstream::in | fstream::out | fstream::trunc);

    if (fin.fail())
    {
        cout << "Open file error ";
        wcout << fileName << L"out" << fileFormat << endl;
        return 0;
    }
    else
    {
        cout << "File is open ";
        wcout << fileName << L"out" << fileFormat << endl;
    }

    fin.open(fileName + fileFormat);
    if (fin.fail())
    {
        cout << "Open file error ";
        wcout << fileName << fileFormat << endl;
        return 0;
    }
    else
    {
        cout << "File is open ";
        wcout << fileName << fileFormat << endl;
    }
    
    do
    {
        fin.get(input);
        fout << input;

        if (input == -65)
        {

            fin.get(input);
            fout << input;

            if (input == *stringCount)
            {
                i++;
                s = std::to_string(i);
                stringCount = s.c_str();
                fin.get(input);
                fout << input;

                if (input == '\n')
                {
                    fin.get(input);
                    hours = (input - '0') * 10;
                    fin.get(input);
                    hours += input - '0';
                    hours += hours_plus;
                    //skip ':'
                    fin.get(input);
                    fin.get(input);

                    minutes = (input - '0') * 10;
                    fin.get(input);
                    minutes += input - '0';
                    minutes += minutes_plus;

                    //skip ':'
                    fin.get(input);
                    fin.get(input);

                    seconds = (input - '0') * 10;
                    fin.get(input);
                    seconds += input - '0';
                    seconds += seconds_plus;
                    

                    //skip ','
                    fin.get(input);
                    fin.get(input);

                    miliseconds = input - '0';
                    miliseconds += miliseconds_plus;

                    if (miliseconds > 9)
                    {
                        seconds += 1;
                        miliseconds -= 10;
                    }

                    if (seconds > 59)
                    {
                        minutes += 1;
                        seconds -= 60;
                    }

                    if (minutes > 59)
                    {
                        hours += 1;
                        minutes -= 60;
                    }

                    if (hours < 10)
                    {
                        fout << '0' << hours << ':';
                        cout << '0' << hours << endl;
                    }
                    else
                    {
                        fout << hours << ':';
                        cout << hours << endl;
                    }

                    if (minutes < 10)
                    {
                        fout << '0' << minutes << ':';
                        cout << '0' << minutes << endl;
                    }
                    else
                    {
                        fout << minutes << ':';
                        cout << minutes << endl;
                    }
                    if (seconds < 10)
                    {
                        fout << '0' << seconds << ',';
                        cout << '0' << seconds << endl;
                    }
                    else
                    {
                        fout << seconds << ',';
                        cout << seconds << endl;
                    }
                    fout << miliseconds;
                    //skip last symbols
                    fin.get(input);
                    fout << input;
                    fin.get(input);
                    fout << input;
                    fin.get(input);
                    fout << input;
                }
            }
        }

        //second symbols

        else if (input == '\n')
        {

            fin.get(input);
            fout << input;

            if (input == '\n') 
            {
                fin.get(input);
                fout << input;

                if (input == *stringCount)
                {
                    i++;
                    s = std::to_string(i);
                    stringCount = s.c_str();
                    fin.get(input);
                    fout << input;

                    while (input != '\n')
                    {
                        fin.get(input);
                        fout << input;
                    }

                    if (input == '\n')
                    {
                        fin.get(input);
                        hours = (input - '0') * 10;
                        fin.get(input);
                        hours += input - '0';
                        hours += hours_plus;
                        //skip ':'
                        fin.get(input);
                        fin.get(input);

                        minutes = (input - '0') * 10;
                        fin.get(input);
                        minutes += input - '0';
                        minutes += minutes_plus;

                        //skip ':'
                        fin.get(input);
                        fin.get(input);

                        seconds = (input - '0') * 10;
                        fin.get(input);
                        seconds += input - '0';
                        seconds += seconds_plus;


                        //skip ','
                        fin.get(input);
                        fin.get(input);

                        miliseconds = input - '0';
                        miliseconds += miliseconds_plus;

                        if (miliseconds > 9)
                        {
                            seconds += 1;
                            miliseconds -= 10;
                        }

                        if (seconds > 59)
                        {
                            minutes += 1;
                            seconds -= 60;
                        }

                        if (minutes > 59)
                        {
                            hours += 1;
                            minutes -= 60;
                        }

                        if (hours < 10)
                        {
                            fout << '0' << hours << ':';
                            cout << '0' << hours << endl;
                        }
                        else
                        {
                            fout << hours << ':';
                            cout << hours << endl;
                        }

                        if (minutes < 10)
                        {
                            fout << '0' << minutes << ':';
                            cout << '0' << minutes << endl;
                        }
                        else
                        {
                            fout << minutes << ':';
                            cout << minutes << endl;
                        }
                        if (seconds < 10)
                        {
                            fout << '0' << seconds << ',';
                            cout << '0' << seconds << endl;
                        }
                        else
                        {
                            fout << seconds << ',';
                            cout << seconds << endl;
                        }
                        fout << miliseconds;
                        //skip last symbols
                        fin.get(input);
                        fout << input;
                        fin.get(input);
                        fout << input;
                        fin.get(input);
                        fout << input;
                    }
                }
            }
        }

        // after --> 

        else if (input == '-')
        {
            fin.get(input);
            fout << input;

            if (input == '-')
            {
                fin.get(input);
                fout << input;
                if (input == '>')
                {
                    fin.get(input);
                    fout << input;
                    
                    if (input == ' ')
                    {
                        fin.get(input);
                        hours = (input - '0') * 10;
                        fin.get(input);
                        hours += input - '0';
                        hours += hours_plus;
                        //skip ':'
                        fin.get(input);
                        fin.get(input);

                        minutes = (input - '0') * 10;
                        fin.get(input);
                        minutes += input - '0';
                        minutes += minutes_plus;

                        //skip ':'
                        fin.get(input);
                        fin.get(input);

                        seconds = (input - '0') * 10;
                        fin.get(input);
                        seconds += input - '0';
                        seconds += seconds_plus;


                        //skip ','
                        fin.get(input);
                        fin.get(input);

                        miliseconds = input - '0';
                        miliseconds += miliseconds_plus;

                        if (miliseconds > 9)
                        {
                            seconds += 1;
                            miliseconds -= 10;
                        }

                        if (seconds > 59)
                        {
                            minutes += 1;
                            seconds -= 60;
                        }

                        if (minutes > 59)
                        {
                            hours += 1;
                            minutes -= 60;
                        }

                        if (hours < 10)
                        {
                            fout << '0' << hours << ':';
                            cout << '0' << hours << endl;
                        }
                        else
                        {
                            fout << hours << ':';
                            cout << hours << endl;
                        }

                        if (minutes < 10)
                        {
                            fout << '0' << minutes << ':';
                            cout << '0' << minutes << endl;
                        }
                        else
                        {
                            fout << minutes << ':';
                            cout << minutes << endl;
                        }
                        if (seconds < 10)
                        {
                            fout << '0' << seconds << ',';
                            cout << '0' << seconds << endl;
                        }
                        else
                        {
                            fout << seconds << ',';
                            cout << seconds << endl;
                        }
                        fout << miliseconds;
                        //skip last symbols
                        fin.get(input);
                        fout << input;
                        fin.get(input);
                        fout << input;
                        fin.get(input);
                        fout << input;
                    }
                }
            }
        }


    } while (!fin.eof());



    fout.close();

	return pStreamOut;
}

void DestroyConsole(FILE* pStream)
{
    fclose(pStream);
    FreeConsole();
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{

    std::wstring fileName = L"the";
    std::wstring fileFormat = L".srt";

	FILE* pStreamOut = StartLoader(fileName, fileFormat);

        // Register class
        WNDCLASSEXW wcex = {};
        wcex.cbSize = sizeof(WNDCLASSEXW);
        wcex.style = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = WndProc;
        wcex.hInstance = hInstance;
        wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcex.lpszClassName = L"Direct3D_Win32_Game1WindowClass";
        if (!RegisterClassExW(&wcex))
            return 1;

        HWND hwnd = CreateWindow(L"Direct3D_Win32_Game1WindowClass", L"Direct3D Win32 Game1", WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, 500, 500, nullptr, nullptr, hInstance, nullptr);

        if (!hwnd)
            return 1;

        ShowWindow(hwnd, nCmdShow);

    // Main message loop
    MSG msg = {};
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    DestroyConsole(pStreamOut);

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;
}