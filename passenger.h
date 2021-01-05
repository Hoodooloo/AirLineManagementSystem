// #include <iostream>
// #include <string>
// #include <cstdio>
// #include <sstream>
// #include <vector>
// #include <fstream>
// using namespace std;
// class Passenger{
//    int flightNUmber;
//    std::string name;
//    std::string origin;
//    int pnr = 123;
//    public:
//    void getPassenger();
//    void deletePassenger();
//    void flightdetails();
// };

// // Getting flight details based on origin

// void Passenger::flightdetails(){ 
// 	fstream fin; 
// 	fin.open("flightdetails.csv", ios::in);
// 	string origin, origin1;
// 	cout <<"Origin: ";
// 	cin >> origin;
// 	vector<string> row;
// 	string line, word, temp;
// 	while (fin >> temp) {
// 		getline(fin, line);
// 		stringstream s(line);
// 		char comma = ','
// 		while (getline(s, word, comma)) {
// 			row.push_back(word); 
// 		} 
// 		origin1 = row[1];
// 		if (origin1 == origin && row[5] !=0) { 
// 			cout << "Details of Flight from " << row[1] << " : \n"; 
// 			cout << "Flight Number: " << row[0] << "\n"; 
// 			cout << "Flight Origin: " << row[1] << "\n"; 
// 			cout << "Flight Destination: " << row[2] << "\n";
// 			cout << "Departure Time: " << row[3] << "\t\t" << "Arrival Time: " << row[4];
// 			cout << "Total seats available: " << row[5] << "\n";
// 			cout << "Price(per person): " << row[6] << "\n"; 
// 		}
// 	} 
// 	if (origin1 != origin && row[5] ==0)
// 		cout << "Flight not available from that origin\n"; 
// }


// void Passenger::getPassenger(){

//     printf("\n\t\t\tEnter the Flight Number: ");
// 	int flightNumber;
//     std::cin >> flightNumber;

// 	printf("\t\t\tEnter your name: ");
// 	std::string name;
// 	std::cin >> name;

// 	printf("\t\t\tEnter your origin: ");
// 	std::string origin;
// 	std::cin >> origin;
// 	{
// 	    fstream fout; 
//          fout.open("passengerdetails.csv", ios::out | ios::app);
// 	    fout << flightNumber << ","
// 		<< name << ","
// 		<< origin << ","
// 		<< pnr++
// 		<< "\n";
// 	    fout.close();
// 		cout << "\t\t\tYour PNR No. is :" << pnr;
// 	    cout << "\t\t\t\nYour Flight has been booked successfully"<<endl;
// 	    std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
// 	    std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
// 	}
// }

// //DELETE

// void Passenger::deletePassenger(){
// 	fstream fin, fout;
// 	fin.open("passengerdetails.csv", ios::in);
// 	fout.open("newfile.csv", ios::out);
// 	int pnr, fl_n1, count = 0;
// 	string line, word;
// 	std::vector<string> row;

// 	cout << "\n\t\t\tEnter the pnr number to delete: ";
// 	cin >> pnr;

// 	while(!fin.eof()){
// 		row.clear();
// 		getline(fin,line);
// 		stringstream s(line);

// 		while(getline(s,word,',')){
// 			row.push_back(word);
// 		}

// 		int row_size = row.size();
// 		stringstream s1(row[3]);
// 		s1>>fl_n1;
// 		if(fl_n1 != pnr){
// 			if(!fin.eof()){
// 				for(int i=0;i<row_size-1;i++){
// 					fout << row[i] << ",";
// 				}
// 				fout << row[row_size-1] << "\n";
// 			}
// 		}
// 		else{
// 			count = 1;
// 		}
// 		if(fin.eof())
// 			break;
// 	}
// 	if(count == 1){
// 		cout << "\t\t\tRecord found and Deleted " << endl;
// 		std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
// 		std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
// 	}
// 	else{
// 		cout << "\t\t\tRecord not found  " << endl;
// 		std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
// 		std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
// 	}
// 	fin.close();
// 	fout.close();

// 	remove("passengerdetails.csv");
// 	rename("newfile.csv", "passengerdetails.csv");
// }

// void passenger(){

// 	Passenger p;
// 	int n;
	
// 	while(1){
// 		printf("\t\t\tEnter 1 to book flights.\n");
// 		printf("\t\t\tEnter 2 to delete tickets.\n");
// 		printf("\t\t\tEnter 3 to Exit.\n\t\t");
// 		std::cin >> n;
// 		std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
// 		std::cout << "_____________________________________________________________________________________________________________________________________________" <<std::endl;
// 		if (n == 1)
// 		{
// 			p.getPassenger();
// 		}
// 		else if(n == 2){
// 			p.deletePassenger();
// 		}
// 		// else if(n == 3){
// 		// 	break;
// 		// }
// 		else{
// 			printf("\tInvalid Input. Try again.\n");
// 		}
// 	}

// 	}