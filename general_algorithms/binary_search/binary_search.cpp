#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int NOT_FOUND = -1;

template <typename Comparable> long binarySearch(const vector<Comparable> &a, const Comparable &x)
{
	long low = 0, high = a.size() -1, count = 1;
	while (low <= high)
	{
		long mid = (low + high) / 2;
		count++;

		if (a[mid] < x)
			low = mid + 1;
		else if (a[mid] > x)
			high = mid - 1;
		else
		{
			cout << "Iterations: " << count << endl;
			cout << "-------------------------\n";
			return mid; // found answer
		}
	}
	cout << "Iterations: " << count << endl;
	cout << "-------------------------\n";	
	return NOT_FOUND; // answer was not in vector
}



int main()
{

	// initialize random seed
  	srand (time(NULL));

  	long size = 1000000, min = 0, max = size + .1 * size, idx;
	long target = min + (rand() % (int) (max - min + 1)); // get random number in target range;
	vector<long> arr;

	for (long i = 0; i < size; ++i)
	{
		arr.push_back(min + (rand() % (int)(max - min + 1))); // random int in range of min <= int <= max.
	}

	sort(arr.begin(),arr.end());

	cout << "Binary Search | ";

	idx = binarySearch(arr, target);

	if (idx == -1)
		cout << "Target: " << target << " not found.\n";
	else
		cout << "Target: " << target << " at idx: " << idx << "  |  arr[" << idx << "]: " << arr[idx] << endl;


	return 0;

}




