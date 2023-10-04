// *******************************************************
// Program Name: Order.h (Program 3)
// Author: Madeline Weber
// Description: This program simulates a simple product ordering system. This file is the header file containing the class declaration for the Order.cpp class implementation and serves as an interface to the class telling the program how the Order class can be used
// *******************************************************
#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <ctime>

class Order {
public:
  // Constructor
  Order(int orderNum, int custID, const std::vector<int>& productNums);


  // Setters
  void setOrderNum(int orderNum);
  void setCustID(int custID);
  void addProductNumber(int productNum);

  // Getters
  int getOrderNum() const;
  int getCustID() const;
  std::vector<int> getProductNumbers() const;
  static int getOrderCount();
  void getTime(int& year, int& month, int& day, int& hour, int& minute) const;

private:
  int orderNum;
  int custID;
  std::vector<int> productNums;
  time_t orderCreationTime; // Using time_t to store creation time
  static int orderCount; // Static member to keep track of the number of orders
};

#endif
