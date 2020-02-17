class TopVotedCandidate {
private:
    vector<int> times_;
    vector<int> toppicks_;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        multimap<int, int> vote_bst;
        unordered_map<int, multimap<int,int>::iterator> vote_hash;
        const int n = persons.size();
        for (int i = 0; i < n; ++i) {
            int p = persons[i], t = times[i];
            int vote = 1;
            if (vote_hash.count(p)) {
                auto iter = vote_hash[p];
                vote += iter->first;
                vote_bst.erase(iter);
            }
            vote_hash[p] = vote_bst.insert({vote, p});
            toppicks_.push_back(vote_bst.rbegin()->second);
        }
        times_ = times;
    }

    int q(int t) {
        auto idx = prev(upper_bound(times_.begin(), times_.end(), t)) - times_.begin();
        return toppicks_[idx];
    }
};

class TopVotedCandidate {
private:
    vector<int> times_;
    vector<int> toppicks_;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        unordered_map<int, int> votes;
        const int n = persons.size();
        int lead = -1;
        times_ = times;
        for (int i = 0; i < n; ++i) {
            const int p = persons[i];
            lead = ++votes[p] >= votes[lead] ? p : lead;
            toppicks_.push_back(lead);
        }
    }

    int q(int t) {
        auto idx = prev(upper_bound(times_.begin(), times_.end(), t)) - times_.begin();
        return toppicks_[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */