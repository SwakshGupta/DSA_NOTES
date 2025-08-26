/*
N meeting in a room 

so we are given with meeting starting time vector and ending time vector a1={0,3,1,5,5,8} a2={5,4,2,9,7,9}

so we can starting with a1 and end with a2 say start with 0 and end with 5 now in between i cannot attend any other meeting 

i have to return maximum number of meetings which i can attend 

intuition 

1. We will try to take those meeting which are starting early and ending early 

2. And then we will apply greedy algo in these so that we can attend maximum number of meetings

explanation in the notebook 
*/




#include <iostream>
using namespace std;

struct Meeting {
    int start;
    int end;
    int pos;  // this is the structure which we have created 
};

// Comparator to sort by end time
bool cmp(Meeting m1, Meeting m2) {
    if (m1.end == m2.end)
        return m1.pos < m2.pos;  
    return m1.end < m2.end;
}
// if cmp(x,y) is true then x comes before y



void maxMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();

    vector<Meeting> meetings(n); //  here we have created a vector which have the class of metting that is for 
    // each element it has three elements {start,end,pos}

    for (int i = 0; i < n; i++) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
        meetings[i].pos = i + 1; 
    }

    // Sort by meeting end time
    sort(meetings.begin(), meetings.end(), cmp);

    vector<int> selected; // store positions of chosen meetings
    int lastEnd = -1;

    for (int i = 0; i < n; i++) {
        if (meetings[i].start > lastEnd) {
            selected.push_back(meetings[i].pos);
            lastEnd = meetings[i].end;
        }
    }

    cout << "Maximum meetings: " << selected.size() << endl;
    cout << "Meetings selected (by position): ";
    for (int id : selected) cout << id << " ";
    cout << endl;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    maxMeetings(start, end);

    return 0;
}
