

#include<iostream>
using namespace std;

/*

Car Fleet
There are n cars traveling to the same destination on a one-lane highway.

You are given two arrays of integers position and speed, both of length n.

position[i] is the position of the ith car (in miles)
speed[i] is the speed of the ith car (in miles per hour)
The destination is at position target miles.

A car can not pass another car ahead of it. It can only catch up to another car and then drive at the same speed as the car ahead of it.

A car fleet is a non-empty set of cars driving at the same position and same speed. A single car is also considered a car fleet.

If a car catches up to a car fleet the moment the fleet reaches the destination, then the car is considered to be part of the fleet.

Return the number of different car fleets that will arrive at the destination.



solution 

  in this problem we are creating a time pair vector and position vector 

1. time=(target-pos)/speed now we will sort the vector in decreasing order on the basis of position

2. we will create maxtime variable if any car has time greater than the maxtime then that car will form a new fleet





*/

   int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        // Step 1: Store (position, time)
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // Step 2: Sort cars by position descending
        sort(cars.rbegin(), cars.rend());

        // Step 3: Traverse and count fleets
        int fleets = 0;
        double maxTime = 0.0;

        for (auto& car : cars) {
            if (car.second > maxTime) {  // new fleet
                fleets++;
                maxTime = car.second;   // update leader time
            }
            // else merges into the existing fleet
        }

        return fleets;
    }

int main()
{



    return 0;
}