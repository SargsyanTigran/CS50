#include <iostream>
#include <time.h>

using namespace std;

int recursion_factorial(int n);
int loop_factorial(int n);

int main(){
	int n;
	cout << "Enter positive number: ";
	cin >> n;
	clock_t recursion_start = clock();
	cout << "Factorial of number " << n << " counting with recursion is " << recursion_factorial(n) << "\n";
	clock_t recursion_end = clock();
	double recursion_time = double(recursion_end - recursion_start)/CLOCKS_PER_SEC;
	printf("Time spent with recursion: %.6f seconds.\n", recursion_time);

	clock_t loop_start = clock();
	cout << "Factorial of number " << n << " counting with loop is " << loop_factorial(n) << "\n";
	clock_t loop_end = clock();
	double loop_time = double(loop_end - loop_start)/CLOCKS_PER_SEC;
	printf("Time spent with loop : %.6f seconds.\n", loop_time);
	return 0;
}

int recursion_factorial(int n){
	if(n > 1)
		return n * recursion_factorial(n - 1);
	else
		return 1;
}
int loop_factorial(int n){
	int factorial = 1;
	for (int i = 1; i <=n; i++)
		factorial *= i;
	return factorial;
}
