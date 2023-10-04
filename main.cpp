// **********************************************************
// Program Name: main.cpp (Program 3)
// Author: Madeline Weber
// Description: This program simulates a simple product ordering system. I have provided the functionality to allow my user to create new customers, new products, and new orders. I then use a function to output a report with all customers, orders, and products, with their member data. 
//************************************************************

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <chrono>
#include <string>

// Include class declarations 
#include "Customer.h"
#include "Order.h"
#include "Product.h"

using namespace std;

// Function Prototype 
void outputReport(const vector<Customer>& customers, const vector<Order>& orders, const vector<Product>& products);

int main() {

  // Declare variables 
  int userChoice; // for user input of the menu 

  string name; 
  string address; 
  string productName; 
  string description; 
  int custID; 
  int productID;

  vector<Customer> customers;
  vector<Product> products;
  vector<Order> orders;
  vector<int> productNumbers;


  cout << "\nWelcome to Program 3!" << endl;

  // while 
  while (true) {
    cout << "\nPlease see the menu below." << endl;
    cout << "1. Create a new customer." << endl;
    cout << "2. Create a new product." << endl;
    cout << "3. Create a new order." << endl;
    cout << "4. Output Report." << endl;
    cout << "5. Exit program." << endl;

    cout << "\nPlease enter your choice here: ";

    cin >> userChoice;

    //switch 
    switch (userChoice) {
    case 1: {
      // ***********Case 1 to create a new customer*****************//

      cin.ignore(); // newline buffer
      cout << "Please enter the Customer Name: ";
      getline(cin, name);
      cout << "Enter Customer Address: ";
      getline(cin, address);

      // Create customer
      Customer newCustomer(customers.size() + 1, name, address);
      customers.push_back(newCustomer); // use vector member push_back to append new customer to the vector 

      // get customer ID from the static int and output it for the user
      cout << "Customer ID: " << newCustomer.getCustID() << endl;
      break; //**************END Case 1***********************
    }

    case 2: {
      //*******************Case 2 for Product Creation***************//
      cin.ignore(); // newline buffer
      cout << "Please enter the Product Name: ";
      getline(cin, productName);
      cout << "Please enter a description for the product: ";
      getline(cin, description);

      // Create product with a unique ID
      Product newProduct(products.size() + 1, productName, description);
      products.push_back(newProduct);

      // output product id for the user
      cout << "Product ID: " << newProduct.getProductNum() << endl;
      break;
    } //********************END Case 2**************************/

    case 3: {
      //*****************Case 3 for Order Creation*****************//
      // validate that at least one customer and one product has been made
      if (customers.empty() || products.empty()) {
        cout << "You need to create at least one customer and one product before creating an order." << endl;
      } 
      else {
        cout << "Enter the Customer ID for the order: ";
        cin >> custID;

        // create bool to validiate input and make sure that the custID actually exists
        bool customerExists = false;
        for (const Customer& customer : customers) {
          if (customer.getCustID() == custID) {
            customerExists = true;
            break;
          }
        } // end elif

        // check if the customer ID exists 
        if (!customerExists) {
          cout << "Customer with ID " << custID << " does not exist." << endl;
          break;
        } // end if 

        // Get Product ID from the user
        cout << "Enter the Product ID for the order: ";
        cin >> productID; 

        // validate that the proudct ID exists
        bool productExists = false;
        for (const Product& product : products) {
          if (product.getProductNum() == productID) {
            productExists = true;
            break;
          }
        }

        // check to make sure the product exists 
        if (!productExists) {
          cout << "Product with ID " << productID << " does not exist." << endl;
          break;
        } // end if

        productNumbers.push_back(productID); // add to the product numbers vector 

        Order newOrder(orders.size() + 1, custID, productNumbers);
        orders.push_back(newOrder);

        // output the order number from the static int
        cout << "Order Number: " << newOrder.getOrderNum() << endl;
      }
      break;
    } //**************************END Case 3*****************************/

    case 4: {
      //*********************Case 4 for Output Report******************/
    
      // Call outputReport() function and pass vectors as parameters
      outputReport(customers, orders, products);

      break;
    } //******************END Case 4*********************************/

    case 5: {
      //*************************Case 5 EXIT************************/ 

      cout << "Exiting program. Goodbye!" << endl;

      return 0; // add return 0
    }

    // if not one of the valid menu choices 
    default: {
      cout << "Invalid choice. Please enter a valid option." << endl;
      break;
    } // end default
    } // end switch
  } // end while 


  return 0;
}

//************************* outputReport() *****************************************/
void outputReport(const vector<Customer>& customers, const vector<Order>& orders, const vector<Product>& products) {
  // Output Customer Report 
  cout << "\n~Customer Report~" << endl;
  for (const Customer& customer : customers) {
    cout << "Customer ID: " << customer.getCustID() << endl;
    cout << "Name: " << customer.getName() << endl;
    cout << "Address: " << customer.getAddress() << endl;
    int year, month, day, hour, minute;
    customer.getTime(year, month, day, hour, minute);
    cout << "Customer Creation Time: " << year << "/" << month << "/" << day << " at " << setw(2) << hour << ":" << setw(2) << setfill('0') << minute << endl; // use set w to make sure that output is correct, setfill to 0 incase so the output is not 10: 1 but 10:01 

    cout << endl;
  } // end customer report

  // Output Product Report
  cout << "\n~Product Report~" << endl;
  for (const Product& product : products) {
    cout << "Product ID: " << product.getProductNum() << endl;
    cout << "Name: " << product.getProductName() << endl;
    cout << "Description: " << product.getProductDescription() << endl;

    int year, month, day, hour, minute;
    product.getTime(year, month, day, hour, minute);
    cout << "Product Creation Time: " << year << "/" << month << "/" << day << " at " << setw(2) << hour << ":" << setw(2) << setfill('0') << minute << endl; 

    cout << endl;
  } // end product report 

  // 
  cout << "\n~Order Report~" << endl;
  for (const Order& order : orders) {
    cout << "Order Number: " << order.getOrderNum() << endl;
    cout << "Customer ID: " << order.getCustID() << endl;
    cout << "Product Numbers: ";
    const vector<int>& productNums = order.getProductNumbers();
    for (int productNum : productNums) {
      cout << productNum << " ";
    }
    cout << endl;
    int year, month, day, hour, minute;
    order.getTime(year, month, day, hour, minute);
    cout << "Order Creation Time: " << year << "/" << month << "/" << day << " at " << setw(2) << hour << ":" << setw(2) << setfill('0') << minute << endl;

    cout << endl;
  } // end order report 
 } //******************END Function outputReport()**********************/