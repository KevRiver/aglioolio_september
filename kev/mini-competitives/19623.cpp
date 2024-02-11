#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define all(v) (v).begin(), (v).end()

struct Meeting
{
    int started;
    int finished;
    int participants;
};

int N;
vector<Meeting> meetings;
map<int, int> max_participants; // max_participants(t): t 이전까지의 회의 일정에서의 최대 참여 인원

void init()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int started, finished, participants;
        cin >> started >> finished >> participants;
        meetings.push_back({started, finished, participants});
    }
}

void solve()
{
    auto cmp = [](const Meeting &l, const Meeting &r)
    {
        return l.finished < r.finished;
    };

    sort(all(meetings), cmp);
    
    const Meeting &first_meeting = meetings[0];
    max_participants[first_meeting.finished] = first_meeting.participants;

    for (int i = 1; i < N; ++i)
    {
        const Meeting &meeting = meetings[i];
        int before_started = 0;

        auto it = max_participants.lower_bound(meeting.started);

        if(it == max_participants.end()){
            before_started = (--it)->second;
        }
        else if(it->first == meeting.started){
            before_started = it->second;
        }
        else if(it != max_participants.begin()){
            before_started = (--it)->second;
        }

        int new_value = before_started + meeting.participants;
        int cur_max = max_participants.rbegin()->second;

        max_participants[meeting.finished] = max(cur_max, new_value);
    }

    int answer = max_participants.rbegin()->second;
    cout << answer << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    solve();

    return 0;
}