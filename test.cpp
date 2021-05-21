#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    if (isalpha('1'))
        cout << (char)tolower('s') << endl;
    vector<int> nums{1, 2};
    int *arr = new int[2]{nums};
    cout << *arr << " " << *(arr + 1) << endl;
}



