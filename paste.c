#include <windows.h>
#include <stdio.h>

int main(int argc,char **argv)
{
	if(OpenClipboard(NULL)){
		HANDLE hclip;
		char *text;
		hclip=GetClipboardData(CF_TEXT);
		text=GlobalLock(hclip);
		if(text){
			printf("%s\n",text);
			GlobalUnlock(hclip);
		}
		CloseClipboard();
	}
	return 0;
}