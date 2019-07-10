#include<Windows.h>
#include"resource.h"

HWND hEdit1;
CHAR s_text_1[] = { "Введите ваше имя:" };
CHAR s_text_2[] = { "Привет" };

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DLGPROC)DlgProc, 0);
	return 0;
}



BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		//SetDlgItemText(hwnd, IDC_EDIT1, s_text_1);
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{

		case IDOK:
		{
			GetDlgItemText(hwnd, IDC_EDIT1, s_text_2, 255);
			CHAR message[255] = "Привет";
			strcat(message, s_text_1);
			//SetDlgItemText(hwnd, IDC_EDIT1, s_text_2);
			MessageBox(hwnd, message, "Info", MB_OK | MB_ICONINFORMATION);
		}

		break;
		case IDCANCEL:
			EndDialog(hwnd, 0);
			return FALSE;
		}
	}
	break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		return FALSE;
	}
	return FALSE;
}