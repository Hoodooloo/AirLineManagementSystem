#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
class Flight{
	int fl_number[4];
	std::string fl_ori;
	std::string fl_des;
	int dtime;
	int atime;
	int total_seat;
	int sprice;
public:
	void getdata();
	void display();
	void deleteflight(){
		printf("Bye World\n");
	};
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