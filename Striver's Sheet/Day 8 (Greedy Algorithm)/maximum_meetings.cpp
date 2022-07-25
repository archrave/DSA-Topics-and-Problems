#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
class Meeting {
public:
    int startTime;
    int endTime;
    int pos;


    Meeting(int s, int e, int p) {
        startTime = s;
        endTime = e;
        pos = p;
    }
};

bool comparator(Meeting m1, Meeting m2) {
    if (m1.endTime < m2.endTime)    return true;
    else if (m1.endTime > m2.endTime)    return false;
    else if (m1.pos < m2.pos)    return true;
    return false;
}

vector<int> maximumMeetings(vector<int>& start, vector<int>& end) {

    int n = start.size(), lastTime = -1;
    vector<int> indexes;

    //      Meeting meetings[n];
    vector<Meeting> meetings;
    for (int i = 0; i < n; i++) {
        Meeting m(start[i], end[i], i + 1);
        meetings.push_back(m);
        //         meetings[i].startTime = start[i], meetings[i].endTime = end[i], meetings[i].pos = i+1;
    }

    sort(meetings.begin(), meetings.end(), comparator);
    //     sort(meetings, meetings + n, comparator);

    //     cout<<endl;
    for (int i = 0; i < n; i++) {
        //         cout<<"s: "<<meetings[i].startTime<<", e: "<<meetings[i].endTime<<", pos: "<<meetings[i].pos<<endl;
        if (meetings[i].startTime > lastTime && meetings[i].endTime > meetings[i].startTime) {
            indexes.push_back(meetings[i].pos);
            lastTime = meetings[i].endTime;
        }
        //     cout<<endl;

    }
    return indexes;
}
int main() {
    vector<int> start = { 1, 3, 0, 5, 8, 5 }, end = { 2, 4, 6, 7, 9, 9 };
    vector<int> ans = maximumMeetings(start, end);

    for (int i = 0;i < ans.size();i++) {
        cout << ans[i] << " ";
    }
    return 0;
}