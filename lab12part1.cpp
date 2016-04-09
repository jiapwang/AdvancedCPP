/*
The IntArray class, described by a header file and an implementation file
dynamically creates an array of integers and performs bounds checking on
the array. Previously, if an invalid subscript was passed within the class,
it displayed an error message and aborted the program. Modify the class so
it throws an exception instead.
*/

#include <iostream>
#include <cstdlib>
using namespace std;


class IntArray
{
private:
	int *aptr;
	int arraySize;

public:
    class garbage {};                       //empty class declaration
	IntArray(int);
	IntArray(const IntArray &);
	~IntArray();
	int size() const { return arraySize; }
	int &operator[](int) const;
};

IntArray::IntArray(int s)
{
	arraySize = s;
	aptr = new int [s];
	for (int count = 0; count < arraySize; count++)
		*(aptr + count) = 0;
}

IntArray::IntArray(const IntArray &obj)
{
	arraySize = obj.arraySize;
	aptr = new int [arraySize];
	for(int count = 0; count < arraySize; count++)
		*(aptr + count) = *(obj.aptr + count);
}

IntArray::~IntArray()
{
	if (arraySize > 0) {
	   delete [] aptr;
	   arraySize = 0;
	   aptr = NULL;
	}
}

int &IntArray::operator[](int sub) const
{
	if (sub < 0 || sub >= arraySize)
		throw garbage();                    //throw garbage
	return aptr[sub];
}

int main()
{
   const int SIZE = 10;

   // Define an IntArray with 10 elements.
   IntArray table(SIZE);

   // Store values in the array.
   for (int x = 0; x  < SIZE; x++)
      table[x] = (x * 2);

   // Display the values in the array.
   for (int x = 0; x  < SIZE; x++)
      cout << table[x] << " ";
   cout << endl;

   try {                                       //try
        cout << table[-1] << endl;
   }

   catch (IntArray::garbage) {                 //catch
       cout << "The array element you've entered is not correct!";
   }


   return 0;
}
