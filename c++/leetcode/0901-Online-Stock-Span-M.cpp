class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int days = 0;
        int n = prices_.size();
        while (n - 1 - days >= 0 && prices_[n - 1 - days] <= price) {
            days += days_[n - 1 - days];
        }
        prices_.push_back(price);
        days_.push_back(days + 1);
        return days + 1;
    }

private:
    vector<int> prices_;
    vector<int> days_;
};

//

class StockSpanner {
public:
    StockSpanner() {

    }

    int next(int price) {
        int days = 0;
        while (!prices_.empty() && prices_.top() <= price) {
            prices_.pop();
            days += days_.top();
            days_.pop();
        }
        ++days;
        prices_.push(price);
        days_.push(days);
        return days;
    }

private:
    stack<int> prices_;
    stack<int> days_;
};

