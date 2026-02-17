class MyCalendar {
public:
    vector<pair<int,int>> mp;

    MyCalendar() {
    }
    
    bool book(int startTime, int endTime) {
        for(auto it:mp){
             if (startTime < it.second && endTime > it.first)
                return false;
        }
        mp.push_back({startTime, endTime});
  
  return true; }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */