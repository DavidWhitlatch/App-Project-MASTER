/**********************
COP 1000 - Summer 2018
Last Updated 06/07/2018
Pizza App Project
David Whitlatch
Description: Design an online pizza ording app.
Currently, the program can ask user if it is for delivery or pickup, get the users address, go the menu and go into the pizza ordering menu, and lastly it can confirm the users address at the end as part of the confirmation page. I have set up a structure for payment details and plan to set up on a structure for the food order details as well.
***********************/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
using namespace std;
//Global Variables
int pickupOrDeliverySelection; // variable to determine if user wants deliver or pickup
bool deliverySelected; // user selected 2 for pickupOrDeliverySelectionvariable
bool pickupSelected; //  user selected 1 for pickupOrDeliverySelectionvariable

// structures
// Deliver and Pickup Address to locate closest store
struct userAddress {
  string userName;
  string userStreet;
  string userCity;
  string userState;
  int userZipCode;
};

// Payment details
struct paymentDetails {
  string cardType;
  int cardNumber;
  int cardExp;
  int cardCvv;
  string nameOnCard;
  string billingStreet;
  string billingCity;
  string billingState;
  int billingZipCode;
};

// Function to get address and check to see if address is in delivery zone
userAddress input(){
  userAddress newAddress;
  std::cout << '\n' << "DELIVERY AND PICKUP STORE LOCATOR DETAILS" << '\n';

  std::cout << "Enter your full name: ";
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Makes getline ignore the '\n' from the previous line
  std::getline(cin,newAddress.userName);

  std::cout << "Enter your street address: ";
  std::getline(cin,newAddress.userStreet);

  std::cout << "Enter your City: ";
  std::getline(cin,newAddress.userCity);

  std::cout << "Enter your State: ";
  std::getline(cin,newAddress.userState);

  std::cout << "Enter your Zip Code: ";
  std::cin >> newAddress.userZipCode;

  return newAddress;
}

// Input Function to get payment details at the end
paymentDetails input(){
  paymentDetails newPayment;
  std::cout << '\n' << "DELIVERY AND PICKUP STORE LOCATOR DETAILS" << '\n';

  std::cout << "Enter Credit Card Type - Master or Visa: ";
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Makes getline ignore the '\n' from the previous line
  std::getline(cin,newPayment.cardType);

  std::cout << "Enter Name on Credit Card: ";
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Makes getline ignore the '\n' from the previous line
  std::getline(cin,newPayment.nameOnCard);

  // std::cout << "Enter your street address: ";
  // std::getline(cin,newAddress.userStreet);
  //
  // std::cout << "Enter your City: ";
  // std::getline(cin,newAddress.userCity);
  //
  // std::cout << "Enter your State: ";
  // std::getline(cin,newAddress.userState);
  //
  // std::cout << "Enter your Zip Code: ";
  // std::cin >> newAddress.userZipCode;

  return newPayment;
}

// Pizza ordering menu - Case 1 in getOrder()
char getPizzaOrder() {
  int menuSelection;
  std::cout << "Please type the coorelating number from the following options: " << '\n';
  std::cout << "1 to make your own pizza " << '\n' << "2 for Specialty pizzas" << '\n' << "" << '\n' << "" << '\n' ;

 std::cin >> menuSelection;

 bool createPizza = true;

 //int pizzaToppings[];
 int pizzaToppingHolder;
 int pizzaToppings;

 switch (menuSelection) {
   // Make Your Own Pizza
   case 1:
   std::cout << "MAKE YOUR OWN PIZZA MENU" << '\n';

   while (createPizza == true) {
     std::cout << "Select Toppings" << '\n' << "Enter the coorelating number of the topping and then press enter." << '\n';

     std::cout << "MEATS & CHEESE:" << '\n' << "0. To Finish Making Your Own Pizza" << '\n' << "1. Extra Cheese" << '\n'<< "2. Pepperoni" << '\n'<< "3. Sausage" << '\n' << "4. Bacon" << '\n'<< "5. Canadian Bacon" << '\n';

     std::cout << "VEGETABLES & FRUITS" << '\n'<< "6. Bell Peppers" << '\n' << "7. Banana Peppers" << '\n' << "8. Onions" << '\n' << "9. Olives" << '\n' << "10. Pineapple" << '\n';

     std::cin >> pizzaToppingHolder;

     if (pizzaToppingHolder == 0) {
       createPizza = false;
     } else {
       pizzaToppingHolder = pizzaToppings;
     }
     std::cout << pizzaToppings << '\n';
     // Add toppings to array
     //std::cin >> pizzaToppings[];
   }
   break;

   //Specialty Pizzas
   case 2:
    bool orderSpecialtyPizza = true;
    int specialtyPizzaHolder;
    int specialtyPizza;

    while (orderSpecialtyPizza  == true) {
      std::cout << "SPECIALTY PIZZA MENU" << '\n';
      std::cout << "Enter the coorelating nuber of the specialty pizza you would like and then press enter:" << '\n';
      std::cout << "1. Ultimate Cheese" << '\n' << "2. Pepperoni Perfection" << '\n' << "3. The Meats" << '\n' << "4. The Hawiaan" << '\n';

      std::cin >> specialtyPizzaHolder;

      if (specialtyPizzaHolder == 0) {
        orderSpecialtyPizza = false;
      } else {
        specialtyPizzaHolder = specialtyPizza;

        std::cout << "You added " << specialtyPizza << " to your order." << '\n';
      }
    }
   break;
   return 0;
 }
  return 0;
}

// Breads and Sides ordering menu - Case 2 in getOrder()
char getBreadsAndSidesOrder() {
  int menuSelection;
  bool orderBreadsAndSides = true;

  while (orderBreadsAndSides == true){
    std::cout << "Please type the coorelating number from the following options: " << '\n';

    std::cout << "0. To Finish Ordering Breads & Sides" << '\n' << "1. Breadsticks " << '\n' << "2. Cheesy Sticks" << '\n' << "3. Cinna Sticks" << '\n' << "4. Bone In Chicken Wings" << '\n' << "5. Boneless Chicken Wings" << '\n' ;

    std::cin >> menuSelection;

   if (menuSelection == 0){
     orderBreadsAndSides = false;
   }

   std::cout << "You selected " << menuSelection << " from the Breaks and Sides Menu" << '\n';
   //return 0;
  }
return 0;
}

char getDrinkOrder(){
  int menuSelection;

  bool orderDrinks = true;

  while (orderDrinks == true){
    std::cout << "Please type the coorelating number from the following options: " << '\n';

    // FIX THESE ORDER ITEMS TO BE DRINKS
    std::cout << "0. To Finish Ordering Drinks" << '\n' << "1. Coke " << '\n' << "2. Diet Coke" << '\n' << "3. Sprite" << '\n' << "4. Mellow Yellow" << '\n' << "5. Dr. Pepper" << '\n' ;

    std::cin >> menuSelection;

   if (menuSelection == 0){
     orderDrinks = false;
   }
   std::cout << "You selected " << menuSelection << " from the Drinks Menu" << '\n';
   //return 0;
  }
  return 0;
}

char getDessertOrder(){
  int menuSelection;

  bool orderDessert = true;

  while (orderDessert == true){
    std::cout << "Please type the coorelating number from the following options: " << '\n';

    // FIX THESE ORDER ITEMS TO BE DRINKS
    std::cout << "0. To Finish Ordering Desserts" << '\n' << "1. Cinna Sticks " << '\n' << "2. Chocolate Lava Cake" << '\n' << "3. Brownie Bites" << '\n' << "4. Apple Turnover" << '\n';

    std::cin >> menuSelection;

   if (menuSelection == 0){
     orderDessert = false;
   }
   std::cout << "You selected " << menuSelection << " from the Drinks Menu" << '\n';
   //return 0;
  }
  return 0;
}

// ---------Function to get the order information--------
char getOrder(){
  std::cout << '\n'  << "MENU" << '\n';

  int menuSelection;
  std::cout << "Please type the coorelating number from the following options: " << '\n';
  std::cout << "1 for Pizza " << '\n' << "2 for Breads and Sides" << '\n' << "3 for drinks" << '\n' << "4 for Desserts" << '\n' << "5 to finish order and proceed to order confirmation and payment details" << '\n';

 std::cin >> menuSelection;

 switch (menuSelection) {
   case 1:
   std::cout << "PIZZA ORDERING MENU" << '\n';
   getPizzaOrder();
   getOrder();
   break;

   case 2:
   std::cout << "BREADS AND SIDES ORDERING MENU" << '\n';
   getBreadsAndSidesOrder();
   getOrder();
   break;

   case 3:
   std::cout << "DRINKS ORDERING MENU" << '\n';
   getDrinkOrder();
   getOrder();
   break;

   case 4:
   std::cout << "DESSERTS ORDERING MENU" <<'\n';
   getDessertOrder();
   getOrder();
   break;

   case 5: // The user selects case 5 to finish ordering and proceed to order confirmation and payment details
   std::cout << '\n';
   break;

   default:
   std::cout << "You did not enter a valid option. Please select from the MENU options." << '\n';
   getOrder();
   break;
 }
  return 0;
}

// Function to confirm order details
char confirmOrderDetails(string name, string address, string city, string state, int zip ){
  //THIS IS UNFINISHED
  // It will show the food order details as well.

  std::cout << '\n' <<"ORDER CONFIRMATION" << '\n';
  if (deliverySelected == true) {
    std::cout << "You have selected to have your pizza delivered." << '\n';
    std::cout << "Your order will be delivered to:" << '\n';
    std::cout << name << '\n';
    std::cout << address << '\n';
    std::cout << city << ", "<< state <<" "<< zip<< '\n';
  }
  else if (pickupSelected == true){
    std::cout << "You have selected to pick up your pizza at the closest store." << '\n';
    std::cout << "Pick Up Name: "<< '\n';
    std::cout << name << '\n';
    std::cout << "please use your Pick Up Name when claiming your order at the store" << '\n';
  }
  return 0;
}

// Function to get the payment
int getPayment(){
  std::cout << '\n' <<"Please Enter Your Payment Details Below:" << '\n';
  //THIS IS UNFINISHED.
  //Will take in details for payment
  return 0;
}

// --------------------MAIN PROGRAM-----------------
int main()
{
  std::cout << "Enter 1 for pickup or enter 2 for delivery" << '\n';
  std::cin >> pickupOrDeliverySelection;

  // Prevent user from selection a number other than 1 or 2.
  while ((pickupOrDeliverySelection < 1) || (pickupOrDeliverySelection > 2)) {
    std::cout << "Something went wrong. Please enter 1 for pickup or enter 2 for delivery." << '\n';
    std::cin >> pickupOrDeliverySelection;
  }
  if (pickupOrDeliverySelection == 1) {
     pickupSelected = true;
     deliverySelected = false;
  }
  else {
     deliverySelected = true;
     pickupSelected = false;
  }

 // gets the users address information and stores in the structure userAddress
  userAddress s;
  s = input();

 paymentDetails t;
 t = input();
  // Function to get food order details
  getOrder();

  // Function for confirming order details
  confirmOrderDetails(s.userName, s.userStreet, s.userCity, s.userState, s.userZipCode);

  // Function to get the payment details from user
  getPayment();

  std::cout << "Thank you for your order!" << '\n';

	return 0;
}
