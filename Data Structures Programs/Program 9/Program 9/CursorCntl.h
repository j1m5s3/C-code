#ifndef CURSORCNTL_H
#define CURSORCNTL_H
/*--------------- C u r s o r C n t l . h ---------------

by:   George Cheney
      16.322 Data Structures
      ECE Dept.
      UMASS Lowell

PURPOSE
This is the interface to CursorCntl.cpp.

CHANGES
03-23-2016 gpc - Distribute to 16.322 class.
03-24-2016 gpc - Corrections for non-windows environments
               - Correct conditional compile order
10-28-2016 gpc - Distribute to EECE322 class.
*/

// To simulate not running in Windows, include the following line.
//#define NoGraphics

// 03-24-2016 gpc - Correct conditional compile order
#ifndef _WIN32
#define NoGraphics
#endif 

#ifdef NoGraphics
void Sleep(unsigned ms);
#endif

//----- f u n c t i o n    p r o t o t y p e s

void getxy(int &x, int &y); // Return the column (x) and row (y) positions of the cursor.
void gotoxy(int x, int y);  // Move the cursor to column "x", row "y".
void clrscr ();             // Clear the entire screen.
void clreol ();             // Clear from the cursor to the end of line.
void SaveXY();              // Save the current cursor position.
void RestoreXY();           // Restore the current cursor position.
#endif

