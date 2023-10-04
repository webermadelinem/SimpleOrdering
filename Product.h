// *******************************************************
// Program Name: Product.h (Program 3)
// Author: Madeline Weber
// Description: This project simulates a simple product ordering system. This file is the header file containing the class declaration for the Product.cpp class implementation and serves as an interface to the class telling the program how the Product class can be used.
// *******************************************************

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>


class Product {

public:
  // Constructor
  Product(int productNum, const std::string& productName, const std::string& productDescription);

  // Setters
  void setProductNum(int productNum);
  void setProductName(const std::string& productName);
  void setProductDescription(const std::string& productDescription);

  // Getters
  int getProductNum() const;
  std::string getProductName() const;
  std::string getProductDescription() const;
  static int getProductCount();
  void getTime(int& year, int& month, int& day, int& hour, int& minute) const;

private:
  int productNum;
  std::string productName;
  std::string productDescription;
  time_t productCreationTime; // Using time_t to store creation time
  static int productCount; // Static member to keep track of the number of products


};

#endif