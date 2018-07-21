//https://www.interviewbit.com/problems/min-stack/
std::vector<int>s;
std::vector<int>smin;
MinStack::MinStack() {
    s.clear();
    smin.clear();
}

void MinStack::push(int x) {
    if (smin.size() == 0)
        smin.push_back(x);
    else if (smin[smin.size()-1] > x)
        smin.push_back(x);
    s.push_back(x);
}

void MinStack::pop() {
    if (smin.size() > 0) {
        if(s[s.size()-1] == smin[smin.size()-1])
            smin.erase(smin.end()-1);
    }
    if (s.size() > 0)
        s.erase(s.end()-1);
}

int MinStack::top() {
    if (s.size() > 0)
        return s[s.size()-1];
    else
        return -1;
    
}

int MinStack::getMin() {
    if (smin.size() > 0)
        return smin[smin.size()-1];
    else
        return -1;
}