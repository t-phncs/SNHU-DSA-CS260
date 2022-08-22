#include "coursePlanner.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// default constructor
BST::BST() { this->root = nullptr; }

BST::~BST() {}

void BST::InOrder() {
  // call inOrder function and pass root
  this->inOrder(root);
}

void BST::insert(Course course) {
  // if root equal to nullptr // nothing in tree
  if (this->root == nullptr) {
    // root is equal to new node course
    this->root = new BstNode(course);
  } else {
    // add node root and bid
    this->addNode(this->root, course);
  }
}

void BST::addNode(BstNode *bstNode, Course course) {
  // if bstNode is large ->
  if (bstNode->course.courseTitle > course.courseTitle) {
    // if no left node
    if (bstNode->left == nullptr) {
      // this node become left
      bstNode->left = new BstNode(course);
    } else {
      // else recurse down left node
      this->addNode(bstNode->left, course);
    }
  } else {
    // if no right node
    if (bstNode->right == nullptr) {
      // this bstNode becomes right
      bstNode->right = new BstNode(course);
    } else {
      // else recurse down right node
      this->addNode(bstNode->right, course);
    }
  }
}

Course BST::search(string courseTitle) {
  // set current BstNode equal to root
  BstNode *currBstNode = this->root;
  // keep looping downwards until bottom reached or matching courseTitle found
  while (currBstNode != nullptr) {
    // if match found, return current bstNode;
    if (currBstNode->course.courseTitle == courseTitle) {

      return currBstNode->course;
    }
    // if course is smaller than current node then traverse left
    if (currBstNode->course.courseTitle > courseTitle) {
      // visit left child
      currBstNode = currBstNode->left;
    } else {
      // else traverse right, and visit right child
      currBstNode = currBstNode->right;
    }
  }
  Course course;
  return course;
}

void BST::inOrder(BstNode *bstNode) {
  // check if bstNode is not null
  if (bstNode != nullptr) {
    // traverse left tree
    inOrder(bstNode->left);
    // print course title and course name
    cout << bstNode->course.courseTitle << ", " << bstNode->course.courseName
         << endl;
    // traverse right tree
    inOrder(bstNode->right);
  }
}

void BST::printCourse(Course course) {
  cout << course.courseTitle << ", " << course.courseName << endl;
  // check condition if there is any string values on the prerequisite list
  if (!course.coursePrereq.empty()) {
    cout << "Prerequisite: " << endl;
    // for every value in course prerequisite, loop is executed
    for (string c : course.coursePrereq) {
      // check condition if there are prequesite string values at the back of
      // vector course
      if (c == course.coursePrereq.back()) {
        // if there is only one value on the prerequiste list
        cout << c << endl;
      } else {
        // if there are two or more values on the prerequisite list
        cout << c << ", " << endl;
      }
    }
  }
}
void BST::loadCourses(string fileName, BST *bst) {
  cout << "Loading CSV file " << fileName << endl;
  ifstream inFile(fileName);
  // string token to hold courseTitle, courseName and coursePrereq
  string line, token;
  // this is for setting up the column in text file
  int count;
  if (inFile.is_open()) {
    // read the whole text file content
    while (!inFile.eof()) {
      getline(inFile, line);
      stringstream ss(line);

      count = 0;
      // make a new bst node
      BstNode *curBstNode = new BstNode();
      while (getline(ss, token, ',')) {
        // column 0
        if (count == 0) {
          curBstNode->course.courseTitle = token;
          // column 1
        } else if (count == 1) {
          curBstNode->course.courseName = token;
          // column 2 if they exist, it depends on column 0
        } else {
          curBstNode->course.coursePrereq.push_back(token);
        }
        count++;
      }
      // call insert function with current BstNode
      bst->insert(curBstNode->course);
      // clear the content of stringstream
      ss.str("");
    }
  } else {
    cout << "Failed!!!" << endl;
  }
  inFile.close();
}