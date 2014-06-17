#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main() {
	
	int count;
	for(count = 1; count <= 1000; count++){
	
		int random1 = rand() % 100000 + 1;
		int random2 = rand() % 100000 + 1;
		
		cout << random1 << " " << random2 << endl;
	}
}