#include <iostream>
#include <string>
using namespace std;
// variables
int k, indexline; //Num of lines
bool check_loop = false;
float flex1 = 2, flex2 = 2, flex3 = 2;
float money1 = 0.5, money2 = 0.5, money3 = 0.5;
string password2, email2;
//structes 
struct line
{
	string phone_number;
	string package_type;
	float balance = 0;
};
struct User
{
	string name;
	string email;
	string password;
	string address;
	int num_of_lines = 3;
	line user_lines[3];
};
void password_checking(User user_1, string& password) //function to check password 
{
	cin >> user_1.password;
	password = user_1.password;
	while (true)
	{
		if (user_1.password.size() < 8)
		{
			cout << "Invalid Password ,Enter Your Password again :";
			cin >> user_1.password;
			password = user_1.password;
		}
		else
			break;
	}
}
void phone_number_checking(line user_lines)
{
	while (true)
	{
		if (user_lines.phone_number.size() != 11)
		{
			cout << "Invaild Phone Number,Enter Your Phone Number again :";
			cin >> user_lines.phone_number;
		}
		else
			break;
	}
}
void create_account(User user_1)
{
	cout << "\t\t\t\t\t\t\tYour Service" << endl;
	cout << "Now ,Create Yoyr Account" << endl;
	cout << " Enter your e-mail : ";
	cin >> user_1.email;
	email2 = user_1.email;
	cout << " Enter password (The password should be more than 8 charaters)";
	password_checking(user_1, password2);
	cout << " Enter your address : ";
	cin >> user_1.address;
	cout << " Enter your name : ";
	cin >> user_1.name;
	cout << " How many lines do you have (maximum 3 lines allowed )?  ";
	while (true)
	{
		cin >> user_1.num_of_lines;
		k = user_1.num_of_lines;
		if (user_1.num_of_lines == 1 || user_1.num_of_lines == 2 || user_1.num_of_lines == 3)
		{
			for (int i = 0; i < user_1.num_of_lines; i++)
			{
				indexline = i;
				cout << " Enter your mobile number for line " << i + 1 << " ? ";
				cin >> user_1.user_lines[i].phone_number;
				phone_number_checking(user_1.user_lines[i]);
			}
			check_loop = true;
		}
		else
			cout << "Maximum 3 lines allowed ,Please Try again" << endl;
		if (check_loop) // true
		{
			break;
		}
	}
	check_loop = false;
	cout << endl;
	cout << " ## Now ,You Should be sign in your account ##" << endl;
	cout << "Your Id is be Ready *(7122001)*,Please keep it save " << endl;
}
int  menu()
{
	cout << "1- Make a call " << endl << "2- Send a massage " << endl << "3-charage Your Balance" << endl << "4- Transfere balance to another Line" << endl << "5- Choose Your backage" << endl << "6- Change Your backage" << endl << "7-Exit" << endl;
	int service;
	cin >> service;
	return service;
}
void sign_in(User& user_1)
{
	while (true)
	{
		string email;
		string password;
		string id;
		cout << " ####### Sign In ######## " << endl;
		cout << "Enter your E-mail ,Please" << endl;
		cin >> email;
		cout << "Enter your Password ,Please " << endl;
		cin >> password;
		cout << "Enter Your Id" << endl;
		cin >> id;
		if (email == email2 && password == password2 && id == "7122001")
		{
			cout << "Asuccessful process " << endl;
			cout << "Telecom company offers you agift for using this app  " << endl;
			cout << "There is a (Flex) system for call and message " << endl;
			cout << "Now, you have 0.5 L.E and 2 flex for any line that exists" << endl;
			cout << " ** Menu of Services**" << endl;
			break;
		}
		else
			cout << "Invaild Information ,Please Try Again" << endl;
	}
}
float call(User b1, float& m1, float& m2, float& m3)
{
	int num_of_line;
	string call_number;
	cout << "Enter the number you want to call \n";
	while (true)
	{
		cin >> call_number;
		if (call_number.size() == 11)
			break;
		else
			cout << "Invalid Number, Try again\n";
	}
	if (k == 1) //has one line 
	{
		while (true)
		{
			cout << "You sign up in one line " << endl << endl << " 1- To Make a Call " << endl;
			cin >> num_of_line;
			if (num_of_line == 1)
				break;
			else
				cout << "Not available value ,Try again" << endl;
		}
		if (flex1 >= 2)
		{
			cout << "The Cost of  Call is 2 flexs\n";
			flex1 -= 2;
			cout << "Your flexs are " << flex1 << "Flex" << endl;
		}
		else if (money1 >= 0.25)
		{
			cout << "The cost of the call is a 0.25 L.E\n";
			money1 -= 0.25;
			cout << "your balance is " << money1 << "L.E" << endl;
		}
		else
			cout << "Sorry,Your balance is less than 0.25 L.E\n";
		return money1;
		return flex1;
	}
	else if (k == 2)
	{
		while (true)
		{
			cout << "which line do you want to make acall(1 or 2)" << endl;
			cin >> num_of_line;
			if (num_of_line == 1)
			{
				if (flex1 >= 2)
				{
					cout << "The cost of the call is 2 flexs\n";
					flex1 -= 2;
					cout << "Your flexs are " << flex1 << "Flex" << endl;
				}
				else if (money1 >= 0.25)
				{
					cout << "The cost of the call is a 0.25 L.E\n";
					money1 -= 0.25;
					cout << "Your balance is " << money1 << "L.E" << endl;
				}
				else
					cout << "Sorry,Your balance is less than 0.25 L.E\n";
				return flex1;
				return money1;
			}
			else if (num_of_line == 2)
			{
				if (flex2 >= 2)
				{
					cout << "The Cost of  Call is 2 Flexs\n";
					flex2 -= 2;
					cout << "Your flexs are " << flex2 << "Flex" << endl;
				}
				else if (money2 >= 0.25)
				{
					cout << "The cost of the call is a 0.25 L.E\n";
					money2 -= 0.25;
					cout << "your balance is " << money2 << "L.E" << endl;
				}
				else
					cout << "Sorry,Your balance is less than 0.25 L.E\n";
				return flex2;
				return money2;
			}
			else
				cout << "Unavailable ,You have only 2 Lines ,Please Try again" << endl;
		}
	}
	else if (k == 3) //has 3 lines
	{
		while (true)
		{
			cout << "which line do you want to make acall(1 , 2 or 3)" << endl;
			cin >> num_of_line;
			if (num_of_line == 1)
			{
				if (flex1 >= 2)
				{
					cout << "The cost of the call is 2 flexs\n";
					flex1 -= 2;
					cout << "Your flexs are " << flex1 << "Flex" << endl;
				}
				else if (money1 >= 0.25)
				{
					cout << "The cost of the call is a 0.25 L.E\n";
					money1 -= 0.25;
					cout << "your balance is " << money1 << "L.E" << endl;
				}
				else
					cout << "Sorry,Your balance is less than 0.25 L.E\n";
				return flex1;
				return money1;
			}
			else if (num_of_line == 2)
			{
				if (flex2 >= 2)
				{
					cout << "The cost of the call is 2 flexs\n";
					flex2 -= 2;
					cout << "Your flexs are " << flex2 << "Flex" << endl;
				}
				else if (money2 >= 0.25)
				{
					cout << "The cost of the call is a 0.25 L.E\n";
					money2 -= 0.25;
					cout << "your balance is " << money2 << "L.E" << endl;
				}
				else
					cout << "Sorry,Your balance is less than 0.25 L.E\n";
				return flex2;
				return money2;
			}
			else if (num_of_line == 3)
			{
				if (flex3 >= 2)
				{
					cout << "The cost of the call is 2 flexs\n";
					flex3 -= 2;
					cout << "Your flexs are " << flex3 << "Flex" << endl;
				}
				else if (money3 >= 0.25)
				{
					cout << "The cost of the call is a 0.25 L.E\n";
					money3 -= 0.25;
					cout << "your balance is " << money3 << "L.E" << endl;
				}
				else
					cout << "Sorry,Your balance is less than 0.25 L.E\n";
				return flex3;
				return money3;
			}
		}
	}
}
float message(User b1, float& m1, float& m2, float& m3)
{
	int num_of_line;
	string call_number;
	string message;
	cout << "Enter the message\n";
	cin >> message;
	cout << "Enter the number you want to send a message  \n";
	while (true)
	{
		cin >> call_number;
		if (call_number.size() == 11)
			break;
		else
			cout << "Invalid Number, Try again\n";
	}
	if (k == 1) //has 1 line
	{
		while (true)
		{
			cout << "You sign up in one line " << endl << " 1- To Send A Message " << endl;
			cin >> num_of_line;
			if (num_of_line == 1)
				break;
			else
				cout << "Not available value" << endl;
		}
		if (flex1 >= 2)
		{
			cout << "The Cost of  Message is 2 flexs\n";
			flex1 -= 2;
			cout << "Your flexs are " << flex1 << "Flex" << endl;
		}
		else if (money1 >= 0.25)
		{
			cout << "The cost of this Message is a 0.25 L.E\n";
			money1 -= 0.25;
			cout << "your balance is " << money1 << "L.E" << endl;
		}
		else
			cout << "Sorry,Your balance is less than 0.25 L.E\n";
		return flex1;
		return money1;
	}
	else if (k == 2) //has 2 lines
	{
		while (true)
		{
			cout << "which line do you want to send a message (1 or 2)" << endl;
			cin >> num_of_line;
			if (num_of_line == 1)
			{
				if (flex1 >= 2)
				{
					cout << "The cost of this Message is 2 flexs\n";
					flex1 -= 2;
					cout << "Your flexs are " << flex1 << "Flex" << endl;
				}
				else if (money1 >= 0.25)
				{
					cout << "The cost of this Message is a 0.25 L.E\n";
					money1 -= 0.25;
					cout << "Your balance is " << money1 << "L.E" << endl;
				}
				else
					cout << "Sorry,Your balance is less than 0.25 L.E\n";
				return 1;
				return money1;
			}
			else if (num_of_line == 2)
			{
				if (flex2 >= 2)
				{
					cout << "The Cost of  this Message is 2 flexs\n";
					flex2 -= 2;
					cout << "Your flexs are " << flex2 << "Flex" << endl;
				}
				else if (money2 >= 0.25)
				{
					cout << "The cost of this Message  is a 0.25 L.E\n";
					money2 -= 0.25;
					cout << "your balance is " << money2 << "L.E" << endl;
				}
				else
					cout << "Sorry,Your balance is less than 0.25 L.E\n";
				return flex2;
				return money2;
			}
			else
				cout << "Unavailable ,You have only 2 Lines ,Please Try again" << endl;
		}
	}
	else if (k == 3)
	{
		while (true)
		{
			cout << "which line do you want to send message(1 , 2 or 3)" << endl;
			cin >> num_of_line;
			if (num_of_line == 1)
			{
				if (flex1 >= 2)
				{
					cout << "The cost of this message is 2 flexs\n";
					flex1 -= 2;
					cout << "Your flexs are " << flex1 << "Flex" << endl;
				}
				else if (money1 >= 0.25)
				{
					cout << "The cost of this message is a 0.25 L.E\n";
					money1 -= 0.25;
					cout << "your balance is " << money1 << "L.E" << endl;
				}
				else
					cout << "Sorry,Your balance is less than 0.25 L.E\n";
				return flex1;
				return money1;
			}
			else if (num_of_line == 2)
			{
				if (flex2 >= 2)
				{
					cout << "The cost of this message is 2 flexs\n";
					flex2 -= 2;
					cout << "Your flexs are " << flex2 << "Flex" << endl;
				}
				else if (money2 >= 0.25)
				{
					cout << "The cost of this message is a 0.25 L.E\n";
					money2 -= 0.25;
					cout << "your balance is " << money2 << "L.E" << endl;
				}
				else
					cout << "Sorry,Your balance is less than 0.25 L.E\n";
				return flex2;
				return money2;
			}
			else if (num_of_line == 3)
			{
				if (flex3 >= 2)
				{
					cout << "The cost of this message is 2 flexs\n";
					flex3 -= 2;
					cout << "Your flexs are " << flex3 << "Flex" << endl;
				}
				else if (money3 >= 0.25)
				{
					cout << "The cost of this message is a 0.25 L.E\n";
					money3 -= 0.25;
					cout << "your balance is " << money3 << "L.E" << endl;
				}
				else
					cout << "Sorry,Your balance is less than 0.25 L.E\n";
				return flex3;
				return money3;
			}
		}
	}
	else
		cout << "Invaild Numder ,please Try again" << endl;
}
float  charging(User b1, float& m1, float& m2, float& m3)
{
	int cart20 = 13141516;
	int cart30 = 2324256;
	int cart50 = 2627289;
	int cart100 = 4459255;
	int Charging_card;
	int amount_of_card;
	int choose;
	if (k == 1)
	{
		cout << "Enter The Number of the Card\n";  //serial number
		cin >> Charging_card;
		cout << "Amount of the card that you requested to be charaged (20 , 30 , 50 or 100 )\n";
		cin >> amount_of_card;
		if (amount_of_card == 100 && Charging_card == 4459255)
		{
			cout << "The balance was successfully charged\n";
			b1.user_lines[0].balance = money1 = money1 + 100;
			money1 = b1.user_lines[0].balance;
			cout << " Now ,Your balance become " << money1 << endl;
			return money1;
		}
		else if (amount_of_card == 50 && Charging_card == 2627289)
		{
			cout << "The balance was successfully charged\n";
			b1.user_lines[0].balance = money1 = money1 + 50;
			money1 = b1.user_lines[0].balance;
			cout << " Now ,Your balance become" << money1 << endl;
			return money1;
		}
		else if (amount_of_card == 30 && Charging_card == 2324256)
		{
			cout << "The balance was successfully charged\n";
			b1.user_lines[0].balance = money1 = money1 + 30;
			money1 = b1.user_lines[0].balance;
			cout << "Now ,Your balance become " << money1 << endl;
			return money1;
		}
		else if (amount_of_card == 20 && Charging_card == 13141516)
		{
			cout << "The balance was successfully charged\n" << endl;
			b1.user_lines[0].balance = money1 = money1 + 20;
			money1 = b1.user_lines[0].balance;
			cout << "Now ,Your balance becomes " << money1 << endl;
			return money1;
		}
		else
			cout << "The Number or Amount is wrong" << endl;
	}
	else if (k == 2)
	{
		cout << "Which line do you want to charge? (1 or 2 )\n";
		while (true)
		{
			cin >> choose;
			if (choose == 1 || choose == 2)
			{
				break;
			}
			else
				cout << "Invalid choice , Try again\n";
		}
		if (choose == 1)
		{
			cout << "Enter The Number of the Card\n"; //serial number
			cin >> Charging_card;
			cout << "Amount of the card that you requested to be charaged (20 , 30 , 50 or 100 )\n";
			cin >> amount_of_card;
			if (amount_of_card == 100 && Charging_card == 4459255)
			{
				cout << "The balance was successfully charged\n";
				b1.user_lines[0].balance = money1 = money1 + 100;
				money1 = b1.user_lines[0].balance;
				cout << " Now ,Your balance become " << money1 << endl;
				return money1;
			}
			else if (amount_of_card == 50 && Charging_card == 2627289)
			{
				cout << "The balance was successfully charged\n";
				b1.user_lines[0].balance = money1 = money1 + 50;
				money1 = b1.user_lines[0].balance;
				cout << " Now ,Your balance become" << money1 << endl;
				return money1;
			}
			else if (amount_of_card == 30 && Charging_card == 2324256)
			{
				cout << "The balance was successfully charged\n";
				b1.user_lines[0].balance = money1 = money1 + 30;
				money1 = b1.user_lines[0].balance;
				cout << "Now ,Your balance becomes " << money1 << endl;
				return money1;
			}
			else if (amount_of_card == 20 && Charging_card == 13141516)
			{
				cout << "The balance was successfully charged\n" << endl;
				b1.user_lines[0].balance = money1 = money1 + 20;
				money1 = b1.user_lines[0].balance;
				cout << "Now ,Your balance becomes " << money1 << endl;
				return money1;
			}
			else
				cout << "the Number or Amount is wrong\n";
		}
		if (choose == 2)
		{
			cout << "Enter The Number of the Card\n";//serial number
			cin >> Charging_card;
			cout << "Amount of the card that you requested to be charaged (20 , 30 , 50 or 100 )\n";
			cin >> amount_of_card;
			if (amount_of_card == 100 && Charging_card == 4459255)
			{
				cout << "The balance was successfully charged\n";
				b1.user_lines[1].balance = money2 = money2 + 100;
				money2 = b1.user_lines[1].balance;
				cout << " Now ,Your balance becomes " << money2 << endl;
				return money2;
			}
			else if (amount_of_card == 50 && Charging_card == 2627289)
			{

				cout << "The balance was successfully charged\n";
				b1.user_lines[1].balance = money2 = money2 + 50;
				money2 = b1.user_lines[1].balance;
				cout << " Now ,Your balance becomes" << money2 << endl;
				return money2;
			}
			else if (amount_of_card == 30 && Charging_card == 2324256)
			{
				cout << "The balance was successfully charged\n";
				b1.user_lines[1].balance = money2 = money2 + 30;
				money2 = b1.user_lines[1].balance;
				cout << "Now ,Your balance becomes " << money2 << endl;
				return money2;
			}
			else if (amount_of_card == 20 && Charging_card == 13141516)
			{
				cout << "The balance was successfully charged\n" << endl;
				b1.user_lines[1].balance = money2 = money2 + 20;
				money2 = b1.user_lines[1].balance;
				cout << "Now ,Your balance becomes " << money2 << endl;
				return money2;
			}
			else
				cout << "the Number or Amount is wrong\n";
		}
	}
	else if (k == 3)
	{
		cout << "Which line do you want to charge? (1 , 2 or 3 )\n";
		while (true)
		{
			cin >> choose;
			if (choose == 1 || choose == 2 || choose == 3) //choose2 mean  num of lines 1 or 
			{
				break;
			}
			else
				cout << "invalid choice , try again\n";
		}
		if (choose == 1)
		{
			cout << "Enter The Number of the Card\n"; //serial number
			cin >> Charging_card;
			cout << "Amount of the card that you requested to be charaged (20 , 30 , 50 or 100 )\n";
			cin >> amount_of_card;
			if (amount_of_card == 100 && Charging_card == 4459255)
			{
				cout << "The balance was successfully charged\n";
				b1.user_lines[0].balance = money1 = money1 + 100;
				money1 = b1.user_lines[0].balance;
				cout << " Now ,Your balance becomes " << money1 << endl;
				return money1;
			}
			else if (amount_of_card == 50 && Charging_card == 2627289)
			{
				cout << "The balance was successfully charged\n";
				b1.user_lines[0].balance = money1 = money1 + 50;
				money1 = b1.user_lines[0].balance;
				cout << " Now ,Your balance becomes" << money1 << endl;
				return money1;
			}
			else if (amount_of_card == 30 && Charging_card == 2324256)
			{
				cout << "The balance was successfully charged\n";
				b1.user_lines[0].balance = money1 = money1 + 30;
				money1 = b1.user_lines[0].balance;
				cout << "Now ,Your balance becomes " << money1 << endl;
				return money1;
			}
			else if (amount_of_card == 20 && Charging_card == 13141516)
			{
				cout << "The balance was successfully charged\n" << endl;
				b1.user_lines[0].balance = money1 = money1 + 20;
				money1 = b1.user_lines[0].balance;
				cout << "Now ,Your balance becomes " << money1 << endl;
				return money1;
			}
			else
				cout << "the Number or Amount is wrong\n";
		}
		else if (choose == 2)
		{
			cout << "Enter The Number of the Card\n"; //serial number
			cin >> Charging_card;
			cout << "Amount of the card that you requested to be charaged (20 , 30 , 50 or 100 )\n";
			cin >> amount_of_card;
			if (amount_of_card == 100 && Charging_card == 4459255)
			{
				cout << "The balance was successfully charged\n";
				b1.user_lines[1].balance = money2 = money2 + 100;
				money2 = b1.user_lines[1].balance;
				cout << " Now ,Your balance becomes " << money2 << endl;
				return money2;
			}
			else if (amount_of_card == 50 && Charging_card == 2627289)
			{
				cout << "The balance was successfully charged\n";
				b1.user_lines[1].balance = money2 = money2 + 50;
				money2 = b1.user_lines[1].balance;
				cout << " Now ,Your balance becomes" << money2 << endl;
				return money2;
			}
			else if (amount_of_card == 30 && Charging_card == 2324256)
			{
				cout << "The balance was successfully charged\n";
				b1.user_lines[1].balance = money2 = money2 + 30;
				money2 = b1.user_lines[1].balance;
				cout << "Now ,Your balance becomes " << money2 << endl;
				return money2;
			}
			else if (amount_of_card == 20 && Charging_card == 13141516)
			{
				cout << "The balance was successfully charged\n" << endl;
				b1.user_lines[1].balance = money2 = money2 + 20;
				money2 = b1.user_lines[1].balance;
				cout << "Now ,Your balance becomes " << money2 << endl;
			}
			else
				cout << "the number or amount is wrong\n";
			return money2;
		}
		else if (choose == 3)
		{
			cout << "Enter The Number of the Card\n"; //serial number
			cin >> Charging_card;
			cout << "Amount of the card that you requested to be charaged (20 , 30 , 50 or 100 )\n";
			cin >> amount_of_card;
			if (amount_of_card == 100 && Charging_card == 4459255)
			{
				cout << "The balance was successfully charged\n";
				b1.user_lines[2].balance = money3 = money3 + 100;
				money3 = b1.user_lines[2].balance;
				cout << " Now ,Your balance becomes " << money3 << endl;
				return money3;
			}
			else if (amount_of_card == 50 && Charging_card == 2627289)
			{
				cout << "The balance was successfully charged\n";
				b1.user_lines[2].balance = money3 = money3 + 50;
				money3 = b1.user_lines[2].balance;
				cout << " Now ,Your balance becomes" << money3 << endl;
				return money3;
			}
			else if (amount_of_card == 30 && Charging_card == 2324256)
			{
				cout << "The balance was successfully charged\n";
				b1.user_lines[2].balance = money3 = money3 + 30;
				money3 = b1.user_lines[2].balance;
				cout << "Now ,Your balance becomes " << money3 << endl;
				return money3;
			}
			else if (amount_of_card == 20 && Charging_card == 13141516)
			{
				cout << "The balance was successfully charged\n" << endl;
				b1.user_lines[2].balance = money3 = money3 + 20;
				money3 = b1.user_lines[2].balance;
				cout << "Now ,Your balance becomes " << money3 << endl;
				return money3;
			}
			cout << "the number or amount is wrong\n";
			return money3;
		}
	}
}
float package(User b1, float& money1, float& money2, float& money3) //function to choose the package for any of the 3 lines
{
	int choose2, count;
	cout << " 1- Package (flex 50)  ---------> Package (50 L.E)\n";
	cout << " 2- Package (flex 100) ---------> Package (100 L.E)\n";
	cout << " 3- Package (flex 150) ---------> Package (150 L.E)\n";
	while (true)
	{
		cin >> count;
		if (count == 1 || count == 2 || count == 3)
		{
			break;
		}
		else
			cout << "Not available , Try again\n";
	}
	if (k == 1)  //has 1 line
	{
		if (count == 1 && money1 >= 50)
		{
			money1 -= 50;
			flex1 += 1000;
			cout << "You're now on The Flex System (50) !\n";
			cout << "you have " << flex1 << "Flex" << endl;
		}
		else if (count == 2 && money1 >= 100)
		{
			money1 -= 100;
			flex1 += 2000;
			cout << "You're now on The Flex System (100) !\n";
			cout << "you have " << flex1 << "Flex" << endl;
		}
		else if (count == 3 && money1 >= 150)
		{
			money1 -= 150;
			flex1 += 5000;
			cout << "You're now on The Flex System (150)!\n";
			cout << "you have " << flex1 << "Flex" << endl;
		}
		else
			cout << "Sorry your Balance  Not enough ,Charge and Try again\n";
		return money1;
	}
	else if (k == 2) //has 2 lines
	{
		cout << "Which line want to do aPackage on it ( 1 or 2) ??" << endl;
		while (true)
		{
			cin >> choose2;
			if (choose2 == 1 || choose2 == 2)   //choose2 mean  num of lines 1 or 2
				break;
			else
				cout << "line is not exist" << endl;
			cout << "please, try again" << endl;
		}
		if (choose2 == 1)
		{
			if (count == 1 && money1 >= 50)
			{
				money1 -= 50;
				flex1 += 1000;
				cout << "You're now on The Flex System (50) !\n";
				cout << "you have " << flex1 << "Flex" << endl;
			}
			else if (count == 2 && money1 >= 100)
			{
				money1 -= 100;
				flex1 += 2000;
				cout << "You're now on The Flex System (100) !\n";
				cout << "you have " << flex1 << "Flex" << endl;
			}
			else if (count == 3 && money1 >= 150)
			{
				money1 -= 150;
				flex1 += 5000;
				cout << "You're now on The Flex System (150)!\n";
				cout << "you have " << flex1 << "Flex" << endl;
			}
			else
				cout << "Sorry your Balance  Not enough ,Charge and Try again\n";
			return money1;
		}
		if (choose2 == 2)
		{
			if (count == 1 && money2 >= 50)
			{
				money2 -= 50;
				flex2 += 1000;
				cout << "You're now on The Flex System (50) !\n";
				cout << "you have " << flex2 << "Flex" << endl;
				cout << "Now ,You  ";
			}
			else if (count == 2 && money2 >= 100)
			{
				money2 -= 100;
				flex2 += 2000;
				cout << "You're now on The Flex System (100) !\n";
				cout << "you have " << flex2 << "Flex" << endl;
			}
			else if (count == 3 && money2 >= 150)
			{
				money2 -= 150;
				flex2 += 5000;
				cout << "You're now on The Flex System (150)!\n";
				cout << "you have " << flex2 << "Flex" << endl;;
			}
			else
				cout << "Sorry your Balance  Not enough ,Charge and Try again\n";
			return money2;
		}
	}
	else if (k == 3) // has a 3 lines 
	{
		cout << "Which line want to do aPackage on it ( 1 , 2 or 3) ??" << endl;
		while (true)
		{
			cin >> choose2;
			if (choose2 == 1 || choose2 == 2 || choose2 == 3)  //choose mean number of lines 1 ,2 or 3
				break;
			else
				cout << "line is not exist" << endl;
			cout << "please, try again" << endl;
		}
		if (choose2 == 1)
		{
			if (count == 1 && money1 >= 50)
			{
				money1 -= 50;
				flex1 += 1000;
				cout << "You're now on The Flex System (50) !\n";
				cout << "you have " << flex1 << "Flex" << endl;
			}
			else if (count == 2 && money1 >= 100)
			{
				money1 -= 100;
				flex1 += 2000;
				cout << "You're now on The Flex System (100) !\n";
				cout << "you have " << flex1 << "Flex" << endl;
			}
			else if (count == 3 && money1 >= 150)
			{
				money1 -= 150;
				flex1 += 5000;
				cout << "You're now on The Flex System (150)!\n";
				cout << "you have " << flex1 << "Flex" << endl;
			}
			else
				cout << "Sorry your Balance  Not enough ,Charge and Try again\n";
			return money1;
		}
		else if (choose2 == 2)
		{
			if (count == 1 && money2 >= 50)
			{
				money2 -= 50;
				flex2 += 1000;
				cout << "You're now on The Flex System (50) !\n";
				cout << "you have " << flex2 << "Flex" << endl;
			}
			else if (count == 2 && money2 >= 100)
			{
				money2 -= 100;
				flex2 += 2000;
				cout << "You're now on The Flex System (100) !\n";
				cout << "you have " << flex2 << endl;
			}
			else if (count == 3 && money2 >= 150)
			{
				money2 -= 150;
				flex2 += 5000;
				cout << "You're now on The Flex System (150)!\n";
				cout << "you have " << flex2 << "Flex" << endl;
			}
			else
				cout << "Sorry your Balance  Not enough ,Charge and Try again\n";
			return money2;
		}
		else if (choose2 == 3)
		{
			if (count == 1 && money3 >= 50)
			{
				money3 -= 50;
				flex3 += 1000;
				cout << "You're now on The Flex System (50) !\n";
				cout << "you have " << flex3 << "" << "Flex" << endl;
			}
			else if (count == 2 && money3 >= 100)
			{
				money3 -= 100;
				flex3 += 2000;
				cout << "You're now on The Flex System (100) !\n";
				cout << "you have " << flex3 << "" << "Flex" << endl;
			}
			else if (count == 3 && money3 >= 150)
			{
				money3 -= 150;
				flex3 += 5000;
				cout << "You're now on The Flex System (150)!\n";
				cout << "you have " << flex3 << "" << "Flex" << endl;
			}
			else
				cout << "Sorry your Balance  Not enough ,Charge and Try again\n";
			return money3;
		}
	}
}
void transfer(User tran1, float& m1, float& m2, float& m3)   //function to tranfer balance to another line 
{
	string numbertransfer;
	float money; //money belong to user 2
	int line_num; //num of line 
	cout << "what number do you want to transfer Your balance to" << endl;
	cin >> numbertransfer;
	while (true)
	{
		if (numbertransfer.size() != 11)
		{
			cout << "Invaid Phone Number,Enter Your Phone Number again :";
			cin >> numbertransfer;
		}
		else
			break;
	}
	cout << "what amount do you to want to transfer it" << endl;
	cin >> money;
	cout << "which line do you want to use to transfer from " << endl;
	cin >> line_num;
	if (line_num == 1)
	{
		if (money > money1)
		{
			cout << "Not enough balance ,please charge and try it" << endl;
		}
		else
		{
			tran1.user_lines[0].balance = money1 = money1 - money;
			money1 = tran1.user_lines[0].balance;
			cout << "Balance transfer has been Successful" << endl;
			cout << "Now ,Your balance after transfer is " << money1 << "L.E" << endl;
			cout << "The amount which you transfer it " << money << "L.E" << endl;
		}
	}
	else if (line_num == 2)
	{
		if (money > money2)
		{
			cout << "Not enough balance ,please charge and try it" << endl;
		}
		else
		{
			tran1.user_lines[1].balance = money2 = money2 - money;
			money2 = tran1.user_lines[1].balance;
			cout << "Balance transfer has been Successful" << endl;
			cout << "Now ,Your balance after transfer is " << money2 << "L.E" << endl;
			cout << "The amount which you transfer it " << money << "L.E" << endl;
		}
	}
	else if (line_num == 3)
	{
		if (money > money3)
		{
			cout << "Not enough balance ,please charge and try it" << endl;
		}
		else
		{
			tran1.user_lines[2].balance = money3 = money3 - money;
			money3 = tran1.user_lines[2].balance;
			cout << "Balance transfer has been Successful" << endl;
			cout << "Now ,Your balance after transfer is " << money3 << "L.E" << endl;
			cout << "The amount which you transfer it " << money << "L.E" << endl;
		}
	}
	else
		cout << "Invaild value , Back To Main Menu and Try again  " << endl;
}
int main()
{
	int services; // servies ==choose from menu
	int back;
	User user_2;
	User user_1;
	line lin[3];
	create_account(user_1);
	sign_in(user_1);
	do
	{
		services = menu();
		switch (services)
		{
		case 1:cout << "Now , You selected to call" << endl;
			call(user_1, money1, money2, money3);
			break;
		case 2:
			cout << "Now , You selected to Send a Massage " << endl;
			message(user_1, money1, money2, money3);
			break;
		case 3:cout << "Now, You selected to charge " << endl;
			charging(user_1, money1, money2, money3);
			break;
		case 4:cout << "Now, You selected to transfer balance  " << endl;
			transfer(user_1, money1, money2, money3);
			break;
		case 5:cout << "Now, You selected to choose your package " << endl;
			package(user_1, money1, money2, money3);
			break;
		case 6:cout << "Now, You selected to Renew your package or change it  " << endl;
			if (flex1 > 2)
			{
				cout << "Now ,you will change your (flex)system " << endl;
				cout << "Old flexes will be added to the value of the modern (flex) system" << endl;
				package(user_1, money1, money2, money3);
			}
			else if (flex2 > 2)
			{
				cout << "Now ,you will change your (flex)system " << endl;
				cout << "Old flexes will be added to the value of the modern (flex) system" << endl;
				package(user_1, money1, money2, money3);
			}
			else if (flex3 > 2)
			{

				cout << "Now ,you will change your (flex)system" << endl;
				cout << "Old flexes will be added to the value of the modern (flex) system" << endl;
				package(user_1, money1, money2, money3);
			}
			else
				cout << "You haven't added to (flex) system any thing t activate it, Choose Package and try again " << endl;
			break;
		case 7:
			cout << "You Selectet Exit" << endl;
			return 0;
			break;
		default:
			cout << "Unknown Application" << endl;
			break;
		}
		cout << "Do You Want to back to Main Menu? " << endl;
		cout << "Click 1- yes" << endl << "2- No" << endl;
		cin >> back;
	} while (back == 1);

}