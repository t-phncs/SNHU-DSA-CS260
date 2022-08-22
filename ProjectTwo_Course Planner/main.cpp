//============================================================================
// Name        : Project Two - Course Planner
// Author      : Tam Phan
// Version     : 1.0
// Copyright   : Copyright © 2022
// Description : Course planner using binary search tree 
//============================================================================

#include "coursePlanner.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  BST *bst = new BST();

  Course course;

  string fileName = "courseInfo.csv";

  string courseTitle;
  // clock_t ticks;
  int userInput = 0;

  while (userInput != 9) {
    cout << "1. Load file" << endl;
    cout << "2. Print Course List" << endl;
    cout << "3. Print Course" << endl;
    cout << "4. Exit" << endl;

    cout << "What would you like to do? ";
    cin >> userInput;

    switch (userInput) {
    case 1:
      bst->loadCourses(fileName, bst);
      cout << "Loaded! " << endl;
      cout << endl;
      //  // Calculate elapsed time and display result
      // ticks = clock() - ticks; // current clock ticks minus starting clock
      // ticks cout << "time: " << ticks << " clock ticks" << endl; cout <<
      // "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;
      break;
    case 2:
      cout << "Here is a sample schedule: " << endl;
      cout << endl;
      bst->InOrder();
      break;
    case 3:
      cout << "What course do you want to know about? ";
      cin >> courseTitle;
      // convert input from lower to uppercase
      // reference to courseTitle, to modify the string value to convert to
      // uppercase directly
      for (auto &c : courseTitle)
        c = toupper(c);
      course = bst->search(courseTitle);

      // ticks = clock() - ticks; // current clock ticks minus starting clock
      // ticks
      if (!course.courseTitle.empty()) {
        bst->printCourse(course);
      }
      // cout << "time: " << ticks << " clock ticks" << endl;
      // cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

      break;
    case 4:
      cout << "Thank you for using the course planner!" << endl;
      exit(0);
    default:
      cout << userInput << " is not a valid option! Please try again!!!"
           << endl;
    }
  }

  return 0;
}
