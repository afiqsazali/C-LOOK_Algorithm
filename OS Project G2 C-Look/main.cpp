/*
 * main.cpp
 *
 *  Created on: 2 Nov 2021
 *      Author: afiqsazali
 */

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>

using namespace std;

int main(){

    int i,k,num_req,disk_size,sum = 0,head;

    cout << "Enter the size of disk\n";				//prompt the user to enter the disk size
    cin >> disk_size;

    cout << "Enter number of requests\n";			//prompt the user to enter the number of page requests
    cin >> num_req;

    cout << "Enter the requests\n";					//prompt the user to enter the values of those total page request given
    vector <int> a(num_req),l;							//then will create vector of array a and 1

    for(i=0;i<num_req;i++){								//for loop will enter the value of the requests into the array until the maximum given number of request

    	cin >> a[i];

    }

    for(i=0;i<num_req;i++) {

    	cout << a[i] << " \n";

    }

    for(i=0;i<num_req;i++){								//this loop will check if the given values of the request are valid, if the values are above the size of disk
    												//then it will prompt the user that is it an invalid value and exit the program
    	if(a[i]>disk_size || a[i]<0){

    		cout << "Error, " << a[i] << " is Out Of Bounds\n";
            return 0;

    	}

    }

    cout << "Enter the head position\n";			//the head position will be the beginning of the algorithm operation
    cin >> head;									//the user will be prompted to enter the value of the head

    while(1) {										//this is check to ensure the head position is inside the disk size

    	if (head > disk_size || head < 0) {

    		cout << "Head out of Bounds, Enter head again: ";
    		cin >> head;

    	}
    	else
    		break;

    }

    a.push_back(head);								//push_back function will push the head to the far end of the array vector
    sort(a.begin(),a.end());						//sort function will sort the values of the array into ascending order

    for (i=0;i<a.size();i++){						//for loop will count the number of jumps from the beginning of array a to the head

    	if (head==a[i])
            break;

    }

    k=i;											//
    if(k<num_req/2){

    	for (i=k;i<a.size();i++){

            l.push_back(a[i]);

        }

        for (i=0;i<k;i++){

            l.push_back(a[i]);

        }

    } else {

    	for (i=k;i>=0;i--){

            l.push_back(a[i]);

        }

        for (i=a.size()-1;i>k;i--){

            l.push_back(a[i]);

        }

    }

    int temp = l[0];

    cout << temp;

    for (i=1;i<l.size();i++){

    	cout << " -> " << l[i] << ' ';
        sum += abs(l[i]-temp);
        temp = a[i];

    }

    cout << '\n';
    cout << "Total head movements = " << sum << '\n';
    return 0;

}
