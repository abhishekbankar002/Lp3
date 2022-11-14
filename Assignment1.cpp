#include <iostream>
using namespace std;
int fib(int x) {
   if((x==1)||(x==0)) {
      cout << "\nif X value"<< x;
      return(x);
   }else {
       cout << "\nelse X value"<< x;
      return(fib(x-1)+fib(x-2));
   }
}
int main() {
   int x , i=0;
   cout << "Enter the number of terms of series : ";
   cin >> x;
   cout << "\nFibonnaci Series : ";
   while(i < x) {
      cout << "\n" << fib(i);
      i++;
   }
   return 0;
}
