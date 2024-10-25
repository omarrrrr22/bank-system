#include <iostream>
using namespace std;
class Person {
protected:
	string name, password;
	int id;
public:
	Person() :
		name(name), password(password), id(0)
	{}
	Person(string name, string password, int id) :
		name(name), password(password), id(id)
	{}
	//setters
	  void set_name(string name) {
	    if (name.size() >= 5 && name.size() <= 20) {
		    for (char c : name) {
					if (!isalpha(c)) {
			    cout<<"Name must contain only alphabetic characters.";
					}
			}
				this->name = name;
		}
			else {
				cout<<"Name size must be between 5 and 20.";
	         }
		
	   }
	
	void set_password(string password) {
		if (password.size() >= 8 && password.size() <= 20) {
			this->password = password;
		}
		else {
		cout<<" size must be between 8 and 20";
		}
	}
	void set_id(int id) {
		Person::id = id;
	}
	//getter
	string get_name() {
		return name;
	}
	string get_password() {
		return password;
	}
	int get_id() {
		return id;
	}
	//methods
	void display() {
		cout << "name  " << name << endl <<
			"password  " << password << endl <<
			"id  " << id << endl;
	}
};
class Client :public Person {
private:
	double balance;
public:

	Client() :balance(0) {}
	Client(string name, string password, int id, double balance) :
		Person(name, password, id), balance(balance)
	{}
	//getter
	double get_balanece() {
		return balance;
	}
	//setters
	void set_balance(double balance) {
		if (balance >= 1500) {
			this->balance = balance;
		}
		else {
			cout << "invalid balance";
		}
	}
	//methods
	void deposit(double amount) {
		if (amount > 0) {
			balance += amount;
		}
	}
	void withdraw(double amount) {
		if (amount > 0) {
			balance -= amount;
		}
	}
	 void transferTo(double amount, Client& recipient) {
		if (amount <= 0 || amount > balance) {
			cout << "invalid amount";
		}
		else {
			balance -= amount;
			recipient.balance += amount;
		}
	}
	void checkBalance() {
		cout << "balance = " << balance;
	}
	
		 void display() {
			 cout << "ID: " << id << endl;
			 cout << "Name: " << name << endl;
			 cout << "Password: " << password << endl;
			 cout << "Balance: " << balance << endl;
		 }
};
class Employee :public Person {
private:
	double  salary;
public:
	Employee():salary(0){}
	Employee(string name, string password, int id, double salary):

		Person(name, password, id), salary(salary)
	{}
	//setter 
	void set_salary(double salary) {
		if (salary >= 5000) {
			Employee::salary = salary;

		}
		else {
			cout << "invalid salary";
		}
	}
	//getters 
	double get_salary() {
		return salary;
	}
	//methods
	void display() {
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Password: " << password << endl;
		cout << "Salary: " << salary;
	}
};


int main()
{
	Client e( "omar ashraf", "omarpassword",1, 5000.0);
	Client r(" mohamed ashraf", "mohamedpassword", 2, 3000.0);
	e.deposit(1000);
	e.checkBalance();
	cout << endl;
	e.withdraw(500);
	e.checkBalance();
	cout << endl;
	e.transferTo(450, r);
	e.checkBalance();
	cout << endl;
	r.checkBalance();
	cout << endl;
	e.display();
	cout << endl;
	r.display();
	Employee s("ahmedsaed", "paswordpassword", 45, 7000);
	cout << endl;
	s.Employee ::display();
}


