#include <iostream>
using namespace std;

void menu();
void viewcars();
void rent(int reserve[], string cars[], string modal[], int models[], int prices[],string name,long mblno,long cnic);
void driver();
void available(int reserve[], string cars[], string modal[], int models[], int prices[]);
void return_car(int reserve[], string cars[], string modal[], int models[], int prices[]);


int main() {
	system ("color 84");
	string name;
	long cnic,mblno;
	cout<<"Your good name: "<<endl;
	cin>>name;
	cout<<"your mobile number: "<<endl;
	cin>>mblno;
	cout<<"Enter your cninc number: "<<endl;
	cin>>cnic;
    char choice;
    int choice1;
    string cars[5] = { "honda", "toyota", "suzuki", "ford", "hyundai" };
    string modal[5] = { "civic", "grande", "Alto", "mustang", "elantra" };
    int models[5] = { 2017, 2019, 2022, 2018, 2020 };
    int prices[5] = { 5000, 4500, 2500, 7000, 4000 };
    int reserve[5] = {0}; // declare reserve array outside to maintain state

    do {
        cout << "Do you want to continue (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            cout << "Enter choice: ";
            cin >> choice1;

            if (choice1 == 1) {
                menu();
            }
            else if (choice1 == 2) {
                viewcars(); // pass reserve array to viewcars function
            }
            else if (choice1 == 3) {
                rent(reserve, cars, modal, models, prices,name,mblno,cnic); // pass car details to rent function
            }
            else if(choice1 == 4){
                driver();
            }
            else if(choice1 == 5){
                available(reserve, cars, modal, models, prices);
            }
            else if(choice1 == 6){
                return_car(reserve, cars, modal, models, prices);
            }
            
        }
    } while (choice != 'N' && choice != 'n');

    return 0;
}

void menu() {
    cout << "--------1.Menu--------" << endl;
    cout << "--------2.View cars------" << endl;
    cout << "--------3.Rent car------------" << endl;
    cout << "--------4.Hire a driver-------" << endl;
    cout << "--------5.Availability status---------" << endl;
    cout << "--------6.Return vehicle-------" << endl;
    cout << "--------7.Generate invoice-------" << endl; // Added option for generating an invoice
}

void viewcars() {
    string cars[5] = { "honda", "toyota", "suzuki", "ford", "hyundai" };
    string modal[5] = { "civic", "grande", "Alto", "mustang", "elantra" };
    int models[5] = { 2017, 2019, 2022, 2018, 2020 };
    int prices[5] = { 5000, 4500, 2500, 7000, 4000 };

    cout << "---------------------------------------------------" << endl;
    for (int i = 0; i < 5; i++) {
        cout << " " << cars[i] << " " << modal[i] << " " << models[i] << " " << prices[i]<<endl;
    }
}

void rent(int reserve[], string cars[], string modal[], int models[], int prices[],string name,long mblno,long cnic) {
    
	
	int index, days;

    cout << "Enter car number (0 to 4): ";
    cin >> index;
    cout << "Enter number of days you want to reserve the car: ";
    cin >> days;

    if (index >= 0 && index < 5) {
        if (reserve[index] == 0) {
            cout << "Car is reserved successfully." << endl;
            reserve[index] = 1;
        } else {
            cout << "Car has already been reserved." << endl;
        }
    } else {
        cout << "Invalid car number." << endl;
    }

    cout << "--------------RECEIPT------------" << endl;
    cout<<"Name: "<<name<<endl;
    cout<<"CNIC: "<<cnic<<endl;
    cout<<"Mobile Number: "<<mblno<<endl;
    cout << "Company: " << cars[index] << endl;
    cout << "Car:    " << modal[index] << endl;
    cout << "Model:  " << models[index] << endl;
    cout << "Price:  " << prices[index] * days << endl; 
	cout<<"Days: "<<days<<endl;
}
void driver() {
    char choice,days;
    cout<<"Enter no of days you want to hire a driver for: "<<endl;
    cin>>days;                                                    
    cout << "Do you want to hire a driver: (Y/N)" << endl;
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        cout << "Driver hired successfully"<<endl;
          }
    else{
        cout<<"your choice: "<<endl;
    }
}

void available(int reserve[], string cars[], string modal[], int models[], int prices[]){
    cout << "---------------------------------------------------" << endl;
    cout << "Available Cars:" << endl;
    cout << "Car       Model     Year   Price    Status" << endl;
    cout << "---------------------------------------------------" << endl;

    for (int i = 0; i < 5; i++) {
        if (reserve[i] == 0) {
            cout << cars[i] << "     " << modal[i] << "     " << models[i] << "     " << prices[i] << "     Available" << endl;
        } else if (reserve[i] == 1) {
            cout << cars[i] << "     " << modal[i] << "     " << models[i] << "     " << prices[i] << "     On Rent" << endl;
        }
    }

}

void return_car(int reserve[], string cars[], string modal[], int models[], int prices[]){
    char choice;
    int index;
    
    cout<<"Do you want to return a car: (Y/N)"<<endl;
    cin>>choice;
    cout<<"Enter the car number: "<<endl;
    cin>>index;
    
    if(choice=='y'||choice=='Y'){
        if (index >= 0 && index < 5) {
            if (reserve[index] == 1) { 
                reserve[index] = 0; 
                cout << "Car returned successfully." << endl;
            } else {
                cout << "The car is not on rent." << endl;
            }
        } else {
            cout << "Invalid car number." << endl;
        }
    } else {
        cout << "Invalid input." << endl;
    }
}