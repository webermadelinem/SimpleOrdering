// *******************************************************
// Program Name: Customer.cpp (Program 3)
// Author: Madeline Weber
// 
// Description: This program simulates a simple product ordering system. This file contains the implementation of the Customer class. It specifies what each function does and how it interacts with member variables. It uses the Scope Resolution Operator (::) from the textbook Section 9.2.5 and the this-> pointer
// *******************************************************

#include "Customer.h"
#include <ctime>

int Customer::customerCount = 0;

// Default Constructor 
Customer::Customer(int id, const std::string& n, const std::string& addr) {
  custID = id;
  name = n;
  address = addr;
  customerCreationTime = time(0); // Store the current time as the creation time
  customerCount++; // Increment the customer count
}


//******************Setters**************************

void Customer::setCustID(int id) {
  this->custID = id;
}

void Customer::setName(const std::string& n) {
  this->name = n;
}

void Customer::setAddress(const std::string& addr) {
  this->address = addr;
}


//*****************Getters**********************

int Customer::getCustID() const {
  return custID;
}

std::string Customer::getName() const {
  return name;
}

std::string Customer::getAddress() const {
  return address;
}

std::vector<int> Customer::getOrderNumbers() const {
  return orderNums;
}

int Customer::getCustomerCount() {
  return customerCount;
}

void Customer::getTime(int& year, int& month, int& day, int& hour, int& minute) const {
  tm creationTime;
  if (localtime_s(&creationTime, &customerCreationTime) == 0) {
    year = creationTime.tm_year + 1900; // the number of years since 1900
    month = creationTime.tm_mon + 1;
    day = creationTime.tm_mday;
    hour = creationTime.tm_hour;
    minute = creationTime.tm_min;
  }
}
