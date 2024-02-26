#include <windows.h>
#include<cstdlib>
#include <string>

HWND textfield,PBT,MBT,MLBT,DBT,numbox1,numbox2;

char textSave1[50];

char textSave2[50];

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {

	switch(Message) {

		case WM_DESTROY: {

			PostQuitMessage(0);

			break;

		}

		default:

			return DefWindowProc(hwnd, Message, wParam, lParam);

        case WM_CREATE:



        textfield  = CreateWindow("STATIC",

                                    "Please input two numbers",

                                    WS_VISIBLE | WS_CHILD | WS_BORDER,

                                    30,5,180,20,

                                    hwnd,NULL,NULL,NULL);



        numbox1 = CreateWindow("EDIT",

                               "",

                               WS_BORDER|WS_CHILD|WS_VISIBLE,

                               30,45,180,20,

                               hwnd,NULL,NULL,NULL);



         numbox2 = CreateWindow("EDIT",

                               "",

                               WS_BORDER|WS_CHILD|WS_VISIBLE,

                               30,80,180,20,

                               hwnd,NULL,NULL,NULL);





        PBT  = CreateWindow("BUTTON",

                                  "+",

                                  WS_VISIBLE | WS_CHILD | WS_BORDER,

                                  50,130,20,20,

                                  hwnd,(HMENU) 1,NULL,NULL);



        MBT  = CreateWindow("BUTTON",

                                  "-",

                                  WS_VISIBLE | WS_CHILD | WS_BORDER,

                                  90,130,20,20,

                                  hwnd,(HMENU) 2,NULL,NULL);



        MLBT  = CreateWindow("BUTTON",

                                  "*",

                                  WS_VISIBLE | WS_CHILD | WS_BORDER,

                                  130,130,20,20,

                                  hwnd,(HMENU) 3,NULL,NULL);



        DBT  = CreateWindow("BUTTON",

                                  "/",

                                  WS_VISIBLE | WS_CHILD | WS_BORDER,

                                  170,130,20,20,

                                  hwnd,(HMENU) 4,NULL,NULL);



            case WM_COMMAND:

                switch (LOWORD(wParam)){

                {

                    case 1:

                        float getnum1 = 0;

                        float getnum2 = 0;

                        getnum1 = GetWindowText(numbox1, &textSave1[0], 20);

                        getnum2 = GetWindowText(numbox2, &textSave2[0], 20);

                        getnum1 = atof(textSave1);

                        getnum2 = atof(textSave2);

                        float answer = getnum1 + getnum2;

                        std::string answerStr = std::to_string(answer);

                        ::MessageBeep(MB_ICONERROR);

                        ::MessageBox(hwnd, answerStr.c_str(), "Result", MB_OK);

                        break;

                }



                {

                    case 2:

                        float getnum1 = 0;

                        float getnum2 = 0;

                        getnum1 = GetWindowText(numbox1, &textSave1[0], 20);

                        getnum2 = GetWindowText(numbox2, &textSave2[0], 20);

                        getnum1 = atof(textSave1);

                        getnum2 = atof(textSave2);

                        float answer = getnum1 - getnum2;

                        std::string answerStr = std::to_string(answer);

                        ::MessageBeep(MB_ICONERROR);

                        ::MessageBox(hwnd, answerStr.c_str(), "Result", MB_OK);

                        break;

                }



                {

                    case 3:

                        float getnum1 = 0;

                        float getnum2 = 0;

                        getnum1 = GetWindowText(numbox1, &textSave1[0], 20);

                        getnum2 = GetWindowText(numbox2, &textSave2[0], 20);

                        getnum1 = atof(textSave1);

                        getnum2 = atof(textSave2);

                        float answer = getnum1 * getnum2;

                        std::string answerStr = std::to_string(answer);

                        ::MessageBeep(MB_ICONERROR);

                        ::MessageBox(hwnd, answerStr.c_str(), "Result", MB_OK);

                        break;

                }



                {

                    case 4:

                        float getnum1 = 0;

                        float getnum2 = 0;

                        getnum1 = GetWindowText(numbox1, &textSave1[0], 20);

                        getnum2 = GetWindowText(numbox2, &textSave2[0], 20);

                        getnum1 = atof(textSave1);

                        getnum2 = atof(textSave2);

                        float answer = getnum1 / getnum2;

                        std::string answerStr = std::to_string(answer);

                        ::MessageBeep(MB_ICONERROR);

                        ::MessageBox(hwnd, answerStr.c_str(), "Result", MB_OK);

                        break;

                }





                }



	}

	return 0;

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	WNDCLASSEX wc; /* A properties struct of our window */

	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */

	MSG msg; /* A temporary location for all messages */

	memset(&wc,0,sizeof(wc));

	wc.cbSize	 = sizeof(WNDCLASSEX);

	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */

	wc.hInstance	 = hInstance;

	wc.hCursor	 = LoadCursor(NULL, IDC_ARROW);

	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW +9);

	wc.lpszClassName = "WindowClass";

	wc.hIcon	 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */

	wc.hIconSm	 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */



	if(!RegisterClassEx(&wc)) {

		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);

		return 0;

	}



	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","My Calculator",WS_VISIBLE|WS_SYSMENU,

		CW_USEDEFAULT, /* x */

		CW_USEDEFAULT, /* y */

		250, /* width */

		200, /* height */

		NULL,NULL,hInstance,NULL);



	if(hwnd == NULL) {

		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);

		return 0;

	}

	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */

		TranslateMessage(&msg); /* Translate key codes to chars if present */

		DispatchMessage(&msg); /* Send it to WndProc */

	}

	return msg.wParam;

}
