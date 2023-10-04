// *******************************************************
// Program Name: Customer.h (Program 3)
// Author: Madeline Weber
// Description: This program simulates a simple product ordering system. This file is the header file containing the class declaration for the Customer.cpp class and serves as an interface to the class telling the program how the Customer class can be used
// *******************************************************
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <ctime>

class Customer {
public:
  // Constructor
  Customer(int id, const std::string& n, const std::string& addr);

  // Setters
  void setCustID(int id);
  void setName(const std::string& n);
  void setAddress(const std::string& addr);

  // Getters
  int getCustID() const;
  std::string getName() const;
  std::string getAddress() const;
  std::vector<int> getOrderNumbers() const;
  static int getCustomerCount();

  // Function to get the customer's creation time via reference parameters
  void getTime(int& year, int& month, int& day, int& hour, int& minute) const;

private:
  int custID;
  std::string name;
  std::string address;
  std::vector<int> orderNums;
  time_t customerCreationTime; // Using time_t to store creation time
  static int customerCount; // Static member to keep track of the number of customers

};

#endif
