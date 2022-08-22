#ifndef _COURSEPLANNER_H_
#define _COURSEPLANNER_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Course {
  string courseTitle;
  string courseName;
  vector<string> coursePrereq;
};
struct BstNode {
  Course course;
  BstNode *left;
  BstNode *right;

  // Default constructor
  BstNode() {
    this->left = nullptr;
    this->right = nullptr;
  }

  // initialize with a course
  BstNode(Course aCourse) : BstNode() { this->course = aCourse; }
};
class BST {
private:
  BstNode *root;
  void addNode(BstNode *bstNode, Course course);
  void inOrder(BstNode *bstNode);

public:
  BST();
  virtual ~BST();
  void insert(Course course);
  Course search(string courseTitle);
  void printCourse(Course course);
  void InOrder();
  void loadCourses(string fileName, BST *bst);
};

#endif