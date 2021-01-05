#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;
class Passenger{
   int flightNUmber;
   std::string name;
   std::string origin;
   int pnr = 123;
   public:
   void getPassenger();
   void deletePassenger();
   void flightdetails();
};

// Getting flight details

void Passenger::flightdetails(){
	fstream fout;
	fout.open("flightdetails.csv", ios::in);
	string line;
	printf("\n");
	while(getline(fout,line))
		cout << "\t\t\t" << line << endl;
	fout.close();
}

void Passenger::getPassenger(){

    printf("\n\t\t\tEnter the Flight Number: ");
	int flightNumber;
    std::cin >> flightNumber;

	printf("\t\t\tFisrt name: ");
	std::string fname;
	std::cin >> fname;

  printf("\t\t\tLast name: ");
	std::string lname;
	std::cin >> lname;

	printf("\t\t\tEnter your Id: ");
	std::string id;
	std::cin >> id;
	{
	    fstream fout;
         fout.open("passengerdetails.csv", ios::out | ios::app);
	    fout << flightNumber << ","
		<< fname << ","
    << lname << ","
		<< id << ","
		<< pnr++
		<< "\n";
	    fout.close();
		cout << "\t\t Dear, "<< fname <<" " << lname<<  " your PNR No. is :" << pnr;
	    cout << "\t\t\t\nYour Flight has been booked successfully"<<endl;
	    std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
	    std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
	}
}

//DELETE

void Passenger::deletePassenger(){
	fstream fin, fout;
	fin.open("passengerdetails.csv", ios::in);
	fout.open("newfile.csv", ios::out);
	int pnr, fl_n1, count = 0;
	string line, word;
	std::vector<string> row;

	cout << "\n\t\t\tEnter the pnr number to delete: ";
	cin >> pnr;

	while(!fin.eof()){
		row.clear();
		getline(fin,line);
		stringstream s(line);

		while(getline(s,word,',')){
			row.push_back(word);
		}

		int row_size = row.size();
		stringstream s1(row[4]);
		s1>>fl_n1;
		if(fl_n1 != pnr){
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

	remove("passengerdetails.csv");
	rename("newfile.csv", "passengerdetails.csv");
}

void passenger(){

	Passenger p;
	int n;

	while(1){
		printf("\t\t\tEnter 1 to book flights.\n");
		printf("\t\t\tEnter 2 to delete tickets.\n");
		printf("\t\t\tEnter 3 to Exit.\n\t\t");
		std::cin >> n;
		std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
		std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
		if (n == 1)
		{
      p.flightdetails();
      printf("Press 1 to continue else 2 to exit");
      int k;
      cin >> k;
      if(k == 1)
        p.getPassenger();
		}
		else if(n == 2){
			p.deletePassenger();
		}
		else if(n == 3){
			break;
		}
		else{
			printf("\tInvalid Input. Try again.\n");
		}
	}

	}
