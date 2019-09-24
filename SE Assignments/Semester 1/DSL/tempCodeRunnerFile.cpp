//============================================================================
// Name        : Assignment13.cpp
// Author      : Sanchit Raina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
Write C++ program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending
order using quick sort and display top five scores.
*/

#include <bits/stdc++.h>
using namespace std;

class SORT{
private:
	int i;
public:
	void display_mainmenu(int);
	void get_marks(float[], int);
	void partition(float[], int);
	void quick_sort(float[], int, int);	
	void display(float[], int);
	void display_top5(float[], int);
};

void SORT::display_mainmenu(int n){
	cout<<"*****MAIN MENU*****\n";
	cout<<"1. Get FE percentage of "<<n<<" students \n";
	cout<<"2. Get percentages of "<<n<<" students in ascending order (by quick sort) \n";
	cout<<"3. Display top 5 scores \n";
	cout<<"/*Option 3 implicilty sorts the array first*/ \n";
	cout<<"Enter your choice ";
}

void SORT::get_marks(float arr[], int n){
	cout<<"Enter marks of "<<n<<" students: \n";
		for(i=0;i<n;i++)
			cin>>arr[i];
}

void SORT::partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}

void SORT::quick_sort(float arr[], int low, int high){
	if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quick_sort(arr, low, pi - 1); 
        quick_sort(arr, pi + 1, high); 
    } 
}

void SORT::display(float arr[], int n){
	cout<<"The scores are: \n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<"  ";
	cout<<endl;
}

void SORT::display_top5(float arr[], int n){
	sort(arr,arr+n);
	cout<<"The top 5 scores are: \n";
	for(i=n-1;i>=n-5;i--)
		cout<<arr[i]<<"  ";
	cout<<endl;
}

int main() {
	int choice,n;
	char ch;
	SORT s;
	cout<<"Enter the number of students: \n";
	cin>>n;
	float arr[n];
	label:

	s.display_mainmenu(n);
	cin>>choice;
	switch(choice){
		case 1:{
			s.get_marks(arr,n);
			s.display(arr,n);
			break;}
		case 2:{
			s.quick_sort(arr,0,n-1);
			s.display(arr,n);
			break;}
		case 3:{
			s.display_top5(arr,n);
			break;}
		default:{
			cout<<"You have entered a wrong choice \n";}
	}

		cout<<"Do you want to continue (y/n) \n";
		cin>>ch;
		if((ch=='y')||(ch=='Y'))
			goto label;
		else
			cout<<"You have chose to exit !! \n";		
	return 0;
} 