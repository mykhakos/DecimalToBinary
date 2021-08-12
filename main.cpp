#include <iostream>
#include <bits/stdc++.h>

using namespace std; 

void IntegerToBinaryManually(int integer_number){
	
	int i = 0; //counter i
	int j = 0; //counter j
	
	int integer_number_copy;
	int binary_number_size = 32; //number of bits (def. max possible int number) 
	int binary_number[binary_number_size]; 	//storage for a binary number
	for (int j = 0; j < binary_number_size; j++){ // zero values by default
		binary_number[j] = 0;
	}
	
	int number_of_ones = 0; //variable for parity evaluation
	char sign = '0'; //variable for sign evaluation
	
	int carry = 1; //+1 for 2's complement
	
	cout << "MANUAL CONVERSION: " << endl;
	
	if (integer_number > 0){ //convertion for positive integers
		integer_number_copy = integer_number;
		
		while  (integer_number_copy > 0 && i < binary_number_size){
			binary_number[binary_number_size-1-i] = integer_number_copy%2;
			integer_number_copy /= 2;
			i++;
		} 	
    	sign = '+';
	}	
	
	else if (integer_number < 0){ //convertion for negative integers - 2's comp.
		integer_number_copy = -integer_number;
	
		while  (integer_number_copy > 0 && i < binary_number_size){
			binary_number[binary_number_size-1-i] = integer_number_copy%2;
			integer_number_copy /= 2;
			i++;
		} 	
		
		for (j = 0; j < binary_number_size; j++) {
			if (binary_number[j] == 1){
				binary_number[j] = 0;
			}
			else{
				binary_number[j] = 1;
			}
    	}
    	
    	for (j = binary_number_size-1; j >= 0; j--) {
			if (binary_number[j] == 1 && carry == 1){
				binary_number[j] = 0;
			}
			else if (binary_number[j] == 0 && carry == 1){
				binary_number[j] = 1;
				carry == 0;
				break;
			}
    	}
    	sign = '-';
	}
	
	for (j = 0; j < binary_number_size; j++) { //parity evaluation
			if (binary_number[j] == 1){
				number_of_ones += 1;
			}
    	}
	
	if (integer_number_copy != 0){
			cout << "Integer number is too big." << endl;
		}
	else{	
   		if (number_of_ones%2 == 0){
			cout << "Bit-parity: even" << endl;
		}
  		else {
   		 	cout << "Bit-parity: odd" << endl;
   		}
    	
    	cout << "Sign: " << sign << endl;
		
		cout << "Binary representation: "; //print out the result
			for (j = 0; j < binary_number_size; j++) {
    			cout << binary_number[j];
			}
	}
    cout << "\n";
}
 
void IntegerToBinaryViaBitset(int integer_number){
	bitset<32> b(integer_number); //number of bits
	int number_of_ones = b.count(); //variable for parity evaluation
	char sign;
	
	cout << "CONVERSION VIA BITSET: " << endl;
	
	if (number_of_ones%2 == 0){ //parity evaluation
		cout << "Bit-parity: even" << endl;
	}
	else {
		cout << "Bit-parity: odd" << endl;
	}
	
	if (integer_number > 0){ //sign evaluation
		sign = '+';
	}
	else if (integer_number < 0){
		sign = '-';
	}
	else {
		sign = '0';
	}
	
	cout << "Sign: " << sign << endl;
	cout << "Binary representation: " << b << endl; //print out the resul
	cout << "\n";
}
 
int main() {

	int integer_number; //declare an integer variable
	cout << "This program converts positive and negative integers to binary." << endl;
	cout << "\n";
	cout << "Input examples: " << endl;
	cout << "123456:    valid input format" << endl;
	cout << "-123456:   valid input format" << endl;
	cout << "123456.0:  invalid input format" << endl;
	cout << "123456e3:  invalid input format" << endl;
	cout << "e3:        invalid input format" << endl;
	cout << "abc:       invalid input format" << endl;
	cout << "\n";
	cout << "Enter an integer: ";
	
	if (cin >> integer_number){ //prompt an input and check if it is an intege
    	char c;
			if (cin.get(c)) { 
     		cin.putback(c);
     			if (c != '\n') { 
       				cout << "Invalid input. Please input an integer without a dot.";
       				return 0;
				}
    			else if (c = '\n'){
    				cout << "\n";
					cout << "You entered: " << integer_number << endl;
					cout << "\n";
    			}
    	}	
			else {
    			cout << "\n";
				cout << "You entered: " << integer_number << endl;
				cout << "\n";
    		}
	}
	else {
    	cout << "Invalid input. Please input an integer without a dot.";
    	return 0;
	}

	IntegerToBinaryViaBitset(integer_number); //call conversion function (bitset - can be used for comparison)
	
	IntegerToBinaryManually(integer_number); //call conversion function
    
	return 0;
}
