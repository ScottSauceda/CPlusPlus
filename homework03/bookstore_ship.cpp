/*
    Marcus Sauceda
    CISC 1600-L01
    Spring 2019
    Homework03
    2-6-19
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
/*
    variable declarations: presented in alphabetical order for easier readibility
*/
    char complete_order, redo_ship, ship_method, expedited_service;
    
    int comparch_book_count, compiler_book_count, data_book_count;
    
    const double comparch_book_price(95.49),comparch_weight(1.75),
    compiler_book_price(89.99), compiler_weight(1.25),
    data_book_price(78.87), data_weight(2.50),
    ground_under_5(5.99), ground_5_10(7.99),ground_over_10(9.99),
    twoday_under_5(11.98), twoday_5_10(15.98), twoday_over_10(19.98),
    nextday_under_5(29.95), nextday_5_10(39.95), nextday_over_10(49.95);
    
    double change_due, comparch_totprice, comparch_totweight,
    compiler_totprice, compiler_totweight, customer_payment,
    data_totprice, data_totweight, salestax_ny(.08875),
    ship_cost(0.0), sub_total, total_sale_price, total_weight;
    
    string first_name, last_name;
    
    
/*
    Greet customer and gather book purchase information
*/
    cout << "Welcome to the Very Small Computer\n";
    cout << "Science BookStore - now with shipping!" << endl;
    cout << "Please enter your first and last name: ";
    cin >> first_name;
    cin >> last_name;
    cout << first_name << ", how many of each textbook \n"
                          "do you wish to purchase?" <<endl;
    cout << "Enter number of Computer Architecture textbooks \n";
    cin >> comparch_book_count;
    cout << "Enter number of Compilers textbooks: \n";
    cin >> compiler_book_count;
    cout << "Enter number of Data Structures textbooks \n";
    cin >> data_book_count;
        
/*
    We now begin to work with doubles,
    call on the special digit converter
*/
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
/*
    Calculate total price and weight for books
*/
    comparch_totprice = comparch_book_count * comparch_book_price;
    comparch_totweight = comparch_book_count * comparch_weight;
    compiler_totprice = compiler_book_count * compiler_book_price;
    compiler_totweight = compiler_book_count * compiler_weight;
    data_totprice = data_book_count * data_book_price;
    data_totweight = data_book_count * data_weight;
    
    sub_total = comparch_totprice + compiler_totprice + data_totprice;
    salestax_ny = sub_total * salestax_ny;
    total_sale_price = salestax_ny + sub_total;
    total_weight = comparch_totweight + compiler_totweight + data_totweight;
    
/*
    Shipping choice and calculations
*/
    cout << "Order Price w/out shipping cost: " << total_sale_price << endl;
    cout << "Order Weight: " << total_weight << " pounds." << endl;
    
    cout << "Our shipping options and prices include: " << endl;
    cout << "Ground - under 5 lbs: \t \t" << ground_under_5 << endl;
    cout << "Ground - between 5 - 10 lbs: \t" << ground_5_10 << endl;
    cout << "Ground - over 10 lbs: \t \t" << ground_over_10 << endl;
    cout << "Two-day - under 5 lbs: \t \t" << twoday_under_5 << endl;
    cout << "Two-day - between 5 - 10 lbs: \t" << twoday_5_10 << endl;
    cout << "Two-day - over 10 lbs: \t \t" << twoday_over_10 << endl;
    cout << "Next-day - under 5 lbs: \t" << nextday_under_5 << endl;
    cout << "Next-day - between 5 - 10 lbs: \t" << nextday_5_10 << endl;
    cout << "Next-day - over 10 lbs: \t" << nextday_over_10 << endl;
    
    
    
    do
    {
    cout << "Would you like ground or expedited shipping?\n";
    cout << "Type g for ground, type e for expedited: ";
    cin >> ship_method;
        if(ship_method == 'g' || ship_method == 'G')
        {
        cout << "Ship method: Ground" << endl;
            if(total_weight < 5)
            {
            ship_cost = ground_under_5;
            }
            if(total_weight >= 5 && total_weight <= 10){
            ship_cost = ground_5_10;
            }
            if(total_weight >= 10)
            {
            ship_cost = ground_over_10;
            }
        total_sale_price = total_sale_price + ship_cost;
        cout << "Shipping cost: " << ship_cost << endl;
        cout << "Your order total is : " << total_sale_price << endl;
        cout << "Would you like to redo shipping choice? \n";
        cout << "Type y for yes, or n for no. ";
        cin >> redo_ship;
            if(redo_ship == 'y' || redo_ship == 'Y')
            {
            total_sale_price = total_sale_price - ship_cost;
            ship_cost = 0.0;
            }
        }
        else
        {
            cout << "Ship method: Expedited" << endl;
            cout << "Would you like two-day or next-day shipping?\n";
            cout << "Type 2 for two day, or 1 for day: ";
            cin >> expedited_service;
            if(expedited_service == '2')
            {
            cout << "You chose two-day shipping." << endl;
                if(total_weight < 5)
                {
                ship_cost = twoday_under_5;
                }
                if(total_weight >= 5 && total_weight <= 10){
                ship_cost = twoday_5_10;
                }
                if(total_weight >= 10)
                {
                ship_cost = twoday_over_10;
                }
            }
            else
            {
            cout << "You chose next-day shipping." << endl;
                if(total_weight < 5)
                {
                ship_cost = nextday_under_5;
                }
                if(total_weight >= 5 && total_weight <= 10){
                ship_cost = nextday_5_10;
                }
                if(total_weight >= 10)
                {
                ship_cost = nextday_over_10;
                }
            }
        total_sale_price = total_sale_price + ship_cost;
        cout << "Shipping cost: " << ship_cost << endl;
        cout << "Your order total is : " << total_sale_price << endl;
        cout << "Would you like to redo shipping choice? \n";
        cout << "Type y for yes, or n for no. ";
        cin >> redo_ship;
            if(redo_ship == 'y' || redo_ship == 'Y')
            {
            total_sale_price = total_sale_price - ship_cost;
            ship_cost = 0.0;
            }
        }
    }while(redo_ship == 'y' || redo_ship == 'Y');
        
    do
    {
//    Payment option
    cout << "Your order total is " << total_sale_price << endl;
    cout << "How much money are you giving me? ";
    cin >> customer_payment;
        
    if(customer_payment < total_sale_price)
    {
    cout << "Sorry, this is not enough money." << endl;
    cout << "You can resubmit payment or cancel order \n";
    cout << "Would you like to resubmit payment? " 
            "Type y for yes, or n for no: ";
    cin >> complete_order;
        if(complete_order == 'n' || complete_order == 'N')
        {
            cout << "Please come back and try us again." << endl;
        }
    }
    elsen
    {
    change_due = customer_payment - total_sale_price;  
    /*
        Present Invoice to customer
    */
    cout << "Invoice for " << first_name << " " << last_name << endl;
    cout << "_____________________________________________________________\n";
    cout << endl;
    cout << "Item \t \t Qty \t Unit Price \t Total Cost \n";
    cout << "Comp. Archit. \t" << comparch_book_count << " \t"
         << comparch_book_price << " \t \t" << comparch_totprice << endl;
    cout << "Compilers \t" << compiler_book_count << " \t"
         << compiler_book_price << " \t \t" << compiler_totprice << endl;
    cout << "Data Struct. \t" << data_book_count << " \t"
         << data_book_price << " \t \t" << data_totprice << endl;
    cout << "_____________________________________________________________\n";
    cout << endl;
    cout << "Subtotal: \t" << sub_total << endl;
    cout << "Salestax: \t" << salestax_ny << endl;
    cout << "Shipping Cost: \t" << ship_cost << endl;
    cout << "Bill total: \t"<< total_sale_price << endl;
    cout << "_____________________________________________________________\n";
    cout << "Payment: \t" << customer_payment << endl;
    cout << "Change Due: \t" << change_due << endl;
    cout << "_____________________________________________________________\n";
    cout << "We appreciate your business, comeback anytime!" << endl;
    }
        
    }while(complete_order == 'y');
        
    return 0;
}