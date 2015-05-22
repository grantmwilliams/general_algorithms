#include <iostream>
#include <vector>

using namespace std;

vector<int> bubblesort(vector<int> a){
    int temp;
    bool run = true;
    while (run)    {
        run = true;
        for (int i = 0; i < a.size()-1; i++) {
            if (a[i] > a[i+1]) {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                run = false;
            }
        }
    }
    return a;
}

int main () {
/*    vector<int> sorted;
    int arr[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    
    vector<int> a (arr, arr + sizeof(arr)/ sizeof(arr[0]) );
 */ 

    vector<int> sorted;
    vector<int> a = {4,65,2,-31,0.99,2,83,782,1};  
    sorted = bubblesort(a);
    
    for (int i = 0; i<a.size()-1; i++){
        if (i == 0) cout << "Unsorted: ";
        cout << a[i] << " ";
        if (i == a.size()-2 ) cout << endl;
    }
    
    for (int j = 0; j<sorted.size()-1; j++){
        if (j == 0) cout << "Sorted: ";
        cout << sorted[j] << " ";
        if (j == sorted.size()-2 ) cout << endl;
    }
    return 0;
}
