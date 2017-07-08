#include <iostream>
#include<string>
#include<fstream>
using namespace std;

//inport function that inpots items there price and there taxcode from text file
int input_from_file(string name[20], double price[20], char tax_code[20]) {
	string userInput;
	ifstream info_File;
	info_File.open("Minimart.txt");
	if (info_File.is_open()) {
		//importing from the file until its the end of the file
		while (!info_File.eof()) {
			for (int i = 0; i <= 19; i++) {
				 //writing names of items from input file to array of names
				info_File >> name[i];
				//writing price of items  from input file to array of prices
				info_File >> price[i];
				//writing taxcode of items from input file to array of taxcode
				info_File >> tax_code[i];

			}
			

		}
		//closing sale_file
		info_File.close();

		//desplaying items
		for (int i = 0; i <= 19; i++) {
			cout << "(" << i + 1 << ")  " << name[i];
			if (i % 2 != 0) {
				cout << endl;
			}
			else cout << "						";
		}

		return -1;
	}

	
	else
	{
		cout << "input file not found" << endl;
		return 0;
	}

}


void main() {
	
	string name[20];
	double price[20];
	
	
	char tax_code[20];
	int choice;
	double sum=0;
	double tax=0;
	string newname;
	bool is_taxed = false;;
	string userInput;
	cout << "Grocery shopping program" << endl << endl<<"please enter the name of your grocery."<<endl;
	//creating a text file to write the file on 
	ofstream receipt;
	//opening the text file to write the items to be purchased 

	receipt.open("receipt.txt");
	//headers for the receipt
	receipt << "							Grocery order Receipt" << endl;
	//setting up the choice to the return value of the function input_from_file so that we will use it to chake if the file exist
	
	choice=input_from_file(name, price, tax_code);
	cout << "Please  place your order by entering the item number." << endl;
	while (choice==-1) {
		cout <<endl<< "you may choose the same item more then once."<<endl<<"please enter -1 when finished:  " << endl;
		cin >> choice;
		//if it is a valid input
		if (choice > 0 && choice < 20) {
			//display the order
			cout<< name[choice - 1] <<"			"<<price[choice - 1]<<"			";
			//cheak if it is a taxed item
			if (tax_code[choice - 1] == 'T') {
				//displaying taxable if the item is taxable
				cout << "taxable" << endl;
				tax = tax + (price[choice - 1] * 0.07);
				is_taxed = true;
			}
			//if it is not taxed item set tax to zero
			else { tax = 0;
			cout << "non-taxable" << endl;
			}
			//add the item price to total sum of purchase
			sum += price[choice - 1] + tax;
			//write the order and its price  to recepte 
			receipt <<"					"<< name[choice - 1] << "			$" << price[choice - 1]<< endl;


		}
		//if the person is done ordering print the the total tax and total price
		else if (choice == -1) {
			
			//cheaking if there is any taxed item in the list to show the tax on the receipt
			if (is_taxed) {
				//writing to recepit.txt
				receipt<<endl<<"					" << "The total amount of tax is $" <<sum*0.07 << endl;
				receipt << "					" << "The total amount due is $" <<sum+ (sum*0.07) << endl;
				//displaying to cmd
				cout<< endl << "					" << "The total amount of tax is $" << sum*0.07 << endl;
				cout << "					" << "The total amount due is $" << sum + (sum*0.07) << endl;

			}
			//if there is no any item thet is taxed in the list then show the tax is equal to 0 
			else{
				receipt << endl << "					" << "The total amount of tax is $" << 0.00 << endl;
				receipt << "					" << "The total amount due is $" << sum  << endl;
				cout<<  "The total amount of tax is $" << 0.00 << endl;
				cout << "The total amount due is $" << sum << endl;

			}
			//show the sum of the purchase
			receipt << "					thank you for your online order" << endl;
			break;
			//close the text file receipt


			receipt.close();

		}
		//if the user input is not a valid input the program will ask them to input a valid input.
		else if (choice > 20) {
			cout << "you have entered an invalid input!!";
		}
		choice = -1;

	}
	cout << "name of output  file where the recept is saved is receipt.txt" << endl;

	system("pause");
}