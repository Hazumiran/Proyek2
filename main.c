#include "editor.h"
#include "Puldown.h"
#include "FileHandl.h"


int main() {

   TCHAR szOldTitle[MAX_PATH];
   TCHAR szNewTitle[MAX_PATH];

   // Save current console title.

   if( GetConsoleTitle(szOldTitle, MAX_PATH) )
   {
      // Build new console title string.


      StringCchPrintf(szNewTitle, MAX_PATH, TEXT("Node Js V2.2"), szOldTitle);

      // Set console title to new title
      if( !SetConsoleTitle(szNewTitle) )
      {
         _tprintf(TEXT("failed (%d)\n"), GetLastError());
         return 1;
      }
      else
      {
         _tprintf(TEXT("Loading....\n"));
      }
   }

	
//	Pulldown();
	driver();

}
