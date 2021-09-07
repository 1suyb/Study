#include<iostream>
#include"MyVector.cpp"
#include"LinkedList.cpp"
#include<vector>
using namespace std;


 int main(void) {
	 cout << "LinkedList" << endl;
	 LinkedList<int> test1;
	 test1.push_back(1);
	 test1.push_back(2);
	 test1.push_back(3);
	 test1.print();
	 test1.reverse();
	 test1.print();
	 return 0;
	 
}