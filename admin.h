#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;
class Flight{
	int fl_number;
	std::string fl_ori;
	std::string fl_des;
	int dtime;
	int atime;
	int total_seat;
	int sprice;
public:
	void getdata();
	void display();
	void deleteflight();
	void p_display();
};

void Flight::getdata(){
	printf("\n\t\t\tEnter the Flight Number: ");
	int fl_number;
	std::cin >> fl_number;
	printf("\t\t\tEnter the flight origin: ");
	std::string fl_ori;
	std::cin >> fl_ori;
	printf("\t\t\tEnter the flight destination: ");
	std::string fl_des;
	std::cin >> fl_des;
	printf("\t\t\tEnter the flight departure time: ");
	int dtime;
	std::cin >> dtime;
	printf("\t\t\tEnter the flight arrival time: ");
	int atime;
	std::cin >> atime;
	printf("\t\t\tEnter the total seats: ");
	int total_seat;
	std::cin >> total_seat;
	printf("\t\t\tEnter the price of each seat: ");
	int sprice;
	std::cin >> sprice;
	{
	    fstream fout;
	    fout.open("flightdetails.csv", ios::out | ios::app);
	    fout << fl_number << ", "
	         << fl_ori << ", "
	         << fl_des << ", "
	         << dtime << ", "
	         << atime << ", "
	         << total_seat << ", "
	         << sprice
	         << "\n";
	    fout.close();
	    cout << "\t\t\tFlight added successfully"<<endl;
	    std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
	    std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
	}
}

void Flight::deleteflight(){
	fstream fin, fout;
	fin.open("flightdetails.csv", ios::in);
	fout.open("newfile.csv", ios::out);
	int fl_n, fl_n1, count = 0;
	string line, word;
	std::vector<string> row;

	cout << "\n\t\t\tEnter the flight number to delete: ";
	cin >> fl_n;

	while(!fin.eof()){
		row.clear();
		getline(fin,line);
		stringstream s(line);

		while(getline(s,word,',')){
			row.push_back(word);
		}

		int row_size = row.size();
		fl_n1 = stoi(row[0]);

		if(fl_n1 != fl_n){
			if(!fin.eof()){
				for(int i=0;i<row_size-1;i++){
					fout << row[i] << ",";
				}
				fout << row[row_size-1] << "\n";
			}
		}
		else{
			count = 1;
		}
		if(fin.eof())
			break;
	}
	if(count == 1){
		cout << "\t\t\tRecord found and Deleted " << endl;
		std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
		std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
	}
	else{
		cout << "\t\t\tRecord not found  " << endl;
		std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
		std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
	}
	fin.close();
	fout.close();

	remove("flightdetails.csv");
	rename("newfile.csv", "flightdetails.csv");
}

void Flight::display(){
	fstream fin;
	string data,line;
	fin.open("flightdetails.csv",ios::in);
	printf("\n");
	while(getline(fin,line))
		cout << "\t\t\t" << line << endl;
	fin.close();
	std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
	std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
}

void Flight::p_display(){
	fstream fin;
	string data,line;
	fin.open("passengerdetails.csv",ios::in);
	printf("\n");
	while(getline(fin,line))
		cout << "\t\t\t" << line << endl;
	fin.close();
	std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
	std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
}

void admin(){
	Flight fly;
	int n;
	std::cout << "_____________________________________________________________________________________________________________________________________________\n" <<std::endl;
	while(1){
		printf("\t\t\tEnter 1 to add flights.\n");
		printf("\t\t\tEnter 2 to delete flights.\n");
		printf("\t\t\tEnter 3 to get flights details.\n");
		printf("\t\t\tEnter 4 to get passengers details.\n");
		printf("\t\t\tEnter 5 to Exit.\n\t\t");
		std::cin >> n;
		std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
		std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
		if (n == 1)
		{
			fly.getdata();
		}
		else if(n == 2){
			fly.deleteflight();
		}
		else if(n == 3){
			fly.display();
		}
		else if(n == 4){
			fly.p_display();
		}
		else if(n == 5){
			break;
		}
		else{
			printf("\tInvalid Input. Try again.\n");
		}
	}
}
