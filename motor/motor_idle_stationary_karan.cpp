//
//
// JUST COPIED TWO-STATE-TEST TEMPLATE CODE FOR NOW
//
//

#include <iostream>
//#include <windows.h>
//#include <conio.h>
using namespace std;

//State change detection while loop to be implemented at end of each function
int main_test() {
   char key;
   //cout << "TYPE SH!T!!!: ";
   while (1) {
      if (_kbhit()) {
         key = (char)_getch();
         //some key output conditionals
         cout << key; //sample debugging output for character output.
      }
   }
}

//prevent re-turn on via software reset? (something in hardware???)
int motor_idle_moving_fail() {
   cout << "Something went wrong" << endl << "Changing state to fail…" << endl;
   char key;
   while (1) {
      if (_kbhit()) {
         key = (char)_getch();
         if (key == 'd') cout << "Current state: -1 - MACHINE FAILURE" << endl;
         else if (key == 'x') return 7;
      }
   }
}

int motor_idle_moving() { //off state
   cout << "Changing state to off…" << endl << "Turning off light…" << endl;
   //and we turn on the light…
   int s;
   cout << "Enter test value for light sensor reading: ";
   cin >> s; //get some sensor output
   if (s == 0) cout << "Light successfully turned off!" << endl; //correct sensor reading
   //cases of failure
   else if (s < 0) {
      cout << "Oops, something went wrong with the lightbulb sensor!" << endl;
      return -1;
   }
   else if (s > 100) {
      cout << "MY EYES! THEY BURN!" << endl;
      return -1;
   }
   else if (s > 0) {
      cout << "Oops, the light's still on!" << endl;
      return -1;
   }
   //wait for more input
   char key;
   while (1) {
      if (_kbhit()) {
         key = (char)_getch();
         if (key == 'd') cout << "Current state: 0 - OFF" << endl;
         else if (key == 'x') return 7;
         else if (key == ' ') return 1;
      }
   }
}

/*
int main() {

}
*/