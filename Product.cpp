// *******************************************************
// Program Name: Product.cpp (Program 3)
// Author: Madeline Weber
// Description: This program simulates a simple product ordering system. This file contains the implementation of the Product class. It specifies what each function does and how it interacts with member variables. It uses the Scope Resolution Operator (::) from the textbook Section 9.2.5 and the this-> pointer
// *******************************************************
#include "Product.h"
#include <ctime>; 

int Product::productCount = 0;

// Default constructor 
Product::Product(int productNum, const std::string& productName, const std::string& productDescription) {
  this->productNum = productNum;
  this->productName = productName;
  this->productDescription = productDescription;
  productCreationTime = time(0); // Store the current time as the creation time
  productCount++; // Increment the product count
}

// Setters implementations
void Product::setProductNum(int productNum) {
  this->productNum = productNum;
}

void Product::setProductName(const std::string& productName) {
  this->productName = productName;
}

void Product::setProductDescription(const std::string& productDescription) {
  this->productDescription = productDescription;
}

// Getters implementations
int Product::getProductNum() const {
  return productNum;
}

std::string Product::getProductName() const {
  return productName;
}

std::string Product::getProductDescription() const {
  return productDescription;
}

int Product::getProductCount() {
  return productCount;
}

void Product::getTime(int& year, int& month, int& day, int& hour, int& minute) const {
  tm creationTime;
  if (localtime_s(&creationTime, &productCreationTime) == 0) {
    year = creationTime.tm_year + 1900; // the number of years since 1900
    month = creationTime.tm_mon + 1;
    day = creationTime.tm_mday;
    hour = creationTime.tm_hour;
    minute = creationTime.tm_min;
  }
}
