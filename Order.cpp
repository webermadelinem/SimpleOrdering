// *******************************************************
// Program Name: Order.cpp (Program 3)
// Author: Madeline Weber
// Description: This program simulates a simple product ordering system. This file contains the implementation of the Order class. It specifies what each function does and how it interacts with member variables. It uses the Scope Resolution Operator (::) from the textbook Section 9.2.5 and the this-> pointer
// *******************************************************

#include "Order.h"
#include <ctime>


int Order::orderCount = 0;

Order::Order(int orderNum, int custID, const std::vector<int>& productNums) {
  this->orderNum = orderNum;
  this->custID = custID;
  this->productNums = productNums; // Copy the vector of product numbers
  orderCreationTime = time(0);     // Store the current time as the creation time
  orderCount++;                    // Increment the order count
}

//**************************Setters************************************
void Order::setOrderNum(int orderNum) {
  this->orderNum = orderNum;
}

void Order::setCustID(int custID) {
  this->custID = custID;
}

void Order::addProductNumber(int productNum) {
  this->productNums.push_back(productNum);
}

//****************************Getters**************************
int Order::getOrderNum() const {
  return orderNum;
}

int Order::getCustID() const {
  return custID;
}

std::vector<int> Order::getProductNumbers() const {
  return productNums;
}

int Order::getOrderCount() {
  return orderCount;
}

void Order::getTime(int& year, int& month, int& day, int& hour, int& minute) const {
  // Function to get the order's creation time via reference parameters
  tm creationTime; // creation time 
  // use localtime_s
  if (localtime_s(&creationTime, &orderCreationTime) == 0) {
    year = creationTime.tm_year + 1900; // the number of years since 1900
    month = creationTime.tm_mon + 1;
    day = creationTime.tm_mday;
    hour = creationTime.tm_hour;
    minute = creationTime.tm_min;
  }
}
