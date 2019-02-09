/*
  Marcus Sauceda
  CISC 1600-L01
  Spring 2019
  Homework 02
  1-28-19
*/

#include <iostream>
using namespace std;

int main()
{

    /*
      variable declarations : presented in alphabetical order for easier readability
    */
    int compArch_bkCount, compiler_bkCount, data_bkCount;
    double changeDue, compArch_bkTotal, compiler_bkTotal, data_bkTotal, paymentRcvd, salesTax_Ny, subTotal, totalSalePrice, 
    compArch_bkPrice(95.49), compiler_bkPrice(89.99), data_bkPrice(78.87);
    string firstName, lastName;

    /*
      Greet customer and gather book purchase information
    */
    cout << "Welcome to the Very Small Computer Science Bookstore!\n";
    cout << "Please enter your first and last name: ";
    cin >> firstName;
    cin >> lastName;
    cout << firstName << ", how many of each textbook do you wish to purchase?\n";
    cout << "Enter number of Data Structures textbooks: \n";
    cin >> data_bkCount;
    cout << "Enter number of Computer Architectue textbooks: \n";
    cin >> compArch_bkCount;
    cout << "Enter number of Compilers textbooks: \n";
    cin >> compiler_bkCount;

  /*
    Calculate Total Sale Price
  */
    data_bkTotal = data_bkCount * data_bkPrice;
    compArch_bkTotal = compArch_bkCount * compArch_bkPrice;
    compiler_bkTotal = compiler_bkCount * compiler_bkPrice;

    /*
      We now begin to work with doubles, use the super duper double digit convert code
    */
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    subTotal = data_bkTotal + compArch_bkTotal + compiler_bkTotal;
    salesTax_Ny = .08875;
    salesTax_Ny = subTotal * salesTax_Ny;
    totalSalePrice = salesTax_Ny + subTotal;

    /*
      Order Total and Payment Received
    */
    cout << "Your order total is " << totalSalePrice << endl;
    cout << "How much money are you giving me? ";
    cin >> paymentRcvd;
    changeDue = paymentRcvd - totalSalePrice;
    cout << endl;

    /*
      Present Invoice to customer
    */
    cout << "Invoice for " << firstName << lastName << endl;
    cout << "_____________________________________________________________\n";
    cout << endl;
    cout << "Item \t \t \t Qty \t Unit Price \t Total Cost\n";
    cout << "Data Structures \t" << data_bkCount << " \t" << data_bkPrice << "  \t \t" << data_bkTotal << endl;
    cout << "Computer Architecture \t" << compArch_bkCount << " \t" << compArch_bkPrice << " \t \t" << compArch_bkTotal << endl;
    cout << "Compilers \t \t" << compiler_bkCount << " \t" << compiler_bkPrice << " \t \t" << compiler_bkTotal << endl;
    cout << "_____________________________________________________________\n";
    cout << endl;
    cout << "Subtotal: \t" << subTotal << endl;
    cout << "Sales Tax: \t" << salesTax_Ny << endl;
    cout << "Total Due: \t" << totalSalePrice << endl;
    cout << "_____________________________________________________________\n";
    cout << "Total Payment: \t" << paymentRcvd << endl;
    cout << "CHANGE DUE: \t" << changeDue << endl;
    cout << "_____________________________________________________________\n";
    cout << "Thank you for shopping locally " << firstName << ", comeback anytime!\n";

 return 0;

}
