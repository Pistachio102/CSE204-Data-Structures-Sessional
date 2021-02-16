#include <bits/stdc++.h>

using namespace std;

template <typename T1, typename T2>
class myPair
{
public:
    T1 first;
    T2 second;

    myPair() { first=second=0; }
    myPair(T1 first, T2 second) : first(first), second(second) {}
};


template <typename T>
void myQuickSort(T* arr, int low, int high)
{
    if(low >= high) return;

    int pivotIdx = low + rand() % (high-low+1);

    T temp = arr[pivotIdx];
    arr[pivotIdx] = arr[high];
    arr[high] = temp;

    T pivot = arr[high];

    int left = low;
    int right = high-1;

    while (left <= right) {
        //FIND item greater than pivot
        while (left <= right && arr[left].second<=pivot.second) left++;
        //FIND item smaller than or equal to pivot
        while (right >= left && arr[right].second>pivot.second) right--;
        if(left < right) {
            //SWAP(arr[left], arr[right]);
            T tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
        }
    }

    //SWAP(arr[left], arr[high]);
    temp = arr[left];
    arr[left] = arr[high];
    arr[high] = temp;

    myQuickSort(arr, low, left-1);

    myQuickSort(arr, left+1, high);
}

void intervalScheduling()
{
    cout << "********************** Interval Scheduling ************************" << endl;

    int n;
    cout << "Enter number of requests : ";
    cin >> n;

    myPair<int,int> *timeIntervals = new myPair<int,int>[n];

    cout << "Enter starting and ending times : \n\t";
    for (int i = 0; i < n; ++i) {
        cin >> timeIntervals[i].first >> timeIntervals[i].second;
    }

    myQuickSort(timeIntervals, 0, (n-1));

    int servedRequests = 0;
    myPair<int,int> *acceptedIntervals = new myPair<int,int>[n];
    for (int j = 0; j < n; ++j) {
        if(j==0) acceptedIntervals[servedRequests++] = timeIntervals[0];
        else {
            if(timeIntervals[j].first>=acceptedIntervals[(servedRequests-1)].second)
                acceptedIntervals[servedRequests++] = timeIntervals[j];
        }
    }

    cout << "\n\n" << servedRequests << endl;
    for (int k = 0; k < servedRequests; ++k) {
        cout << acceptedIntervals[k].first << " " << acceptedIntervals[k].second << endl;
    }

    delete[] timeIntervals;
    delete[] acceptedIntervals;
}
int main()
{

   intervalScheduling();

    return 0;
}
