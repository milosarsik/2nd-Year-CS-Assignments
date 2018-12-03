#include <iostream>

using namespace std;
void swapElements(double *first, double *second)
{
	double temp = *first;
	*first = *second;
	*second = temp;
}

void bubbleSort(double values[], int sz)
{	
	bool swapped = true;

	while (swapped)
	{
		swapped = false;

		for (int e = 0; e < sz - 1; e++)
		{
			if (*(values + e) > *(values + (e + 1)))
			{
				swapElements(&(*(values + e)), &*(values + (e + 1)));
				swapped = true;
			}
		}
	}
}

double calcMedian(char *values[], int sz)
{
	cout << "Median" << endl;

	double *dynamicArray = new double[sz];
	double median = 0;

	for (int i = 0; i < sz; i++)
	{
		*(dynamicArray+ i) = atof(*(values + i));
	}

	double average = 0;

	bubbleSort(dynamicArray, sz);

	if (sz % 2 == 0)
	{
		double val = *(dynamicArray + (sz / 2)) + *(dynamicArray + ((sz / 2) - 1));
		
		median = double(val) / 2;
	}
	else
	{
		median = *(dynamicArray + (sz / 2));
	}

	delete[] dynamicArray;

	return median;
}

double calcAverage(char *values[], int sz)
{
	cout << "Average" << endl;

	double *dynamicArray = new double[sz];
	double average = 0;
	
	for (int i = 0; i < sz; i++)
	{
		dynamicArray[i] = atof(values[i]);
	}

	for (int i = 0; i < sz; i++)
	{
		average += dynamicArray[i];
	}

	average = average / double(sz);

	delete[] dynamicArray;
		
	return average;
}

double calcSum(char *values[])
{
	double staticArray[3] = { atof(values[0]), atof(values[1]), atof(values[2]) };
	double sum = 0;

	cout << "Sum" << endl;

	for (int i = 0; i < 3; i++)
	{
		sum += staticArray[i];
	}
	
	return sum;
}

int main(int argc, char *argv[])
{
	double outputValue;
	
	switch (*argv[1])
	{
		case 'A':										
			
			outputValue = calcAverage(&argv[2], argc - 2);
			
			for (int i = 2; i < (argc); i++)
			{
				cout << argv[i] << " ";
			}
			
			cout << endl << outputValue << endl;
					
			break;
		
		case 'M':	

			outputValue = calcMedian(&argv[2], argc - 2);

			for (int i = 2; i < (argc); i++)	
			{
				cout << argv[i] << " ";
			}

			cout << endl << outputValue << endl;

			break;
		
		case 'F':										
			
			outputValue = calcSum(&argv[2]);

			for (int i = 2; i < (argc); i++)	 
			{
				cout << argv[i] << " ";
			}

			cout << endl << outputValue << endl;

			break;
		
		default:										
			cout << "Wrong function code, you messed up!" << endl;
	}
	return 0;
}