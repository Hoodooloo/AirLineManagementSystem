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
};

void Flight::getdata(){
	printf("Enter the Flight Number: \n");
	int fl_number;
	std::cin >> fl_number;
	printf("Enter the flight origin: \n");
	std::string fl_ori;
	std::cin >> fl_ori;
	printf("Enter the flight destination: \n");
	std::string fl_des;
	std::cin >> fl_des;
	printf("Enter the flight departure time: \n");
	int dtime;
	std::cin >> dtime;
	printf("Enter the flight arrival time: \n");
	int atime;
	std::cin >> atime;
	printf("Enter the total seats: \n");
	int total_seat;
	std::cin >> total_seat;
	printf("Enter the price of each seat: \n");
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
	    cout << "Flight added successfully"<<endl;
	}
}

void Flight::deleteflight(){
	fstream fin, fout;
	fin.open("flightdetails.csv", ios::in);
	fout.open("newfile.csv", ios::out);
	int fl_n, fl_n1, count = 0;
	string line, word;
	std::vector<string> row;

	cout << "Enter the flight number to delete: ";
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
		cout << "Record not found " << endl;
	}
	else{
		cout << "Record found and Deleted " << endl;
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
	while(getline(fin,line))
		cout << line << endl;
}

void admin(){
	Flight fly;
	int n;
	std::cout << "_____________________________________" <<std::endl;
	printf("Enter 1 to add flights.\n");
	printf("Enter 2 to delete flights.\n");
	printf("Enter 3 to get flights details.\n");
	printf("Enter 4 to Exit.\n");
	while(std::cin >> n){
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
			break;
		}
		else{
			printf("Invalid Input. Try again.\n");
		}
	}
}