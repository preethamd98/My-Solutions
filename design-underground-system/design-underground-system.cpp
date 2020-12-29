class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkIns;
    unordered_map<string, pair<double, int>> avgTimes;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkIns[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = checkIns[id].first;
        string journey = startStation + "|" + stationName;
        double duration = t - checkIns[id].second;
        if(avgTimes.find(journey) != avgTimes.end()) {
            int totalTime = avgTimes[journey].first;
            int journeyCount = avgTimes[journey].second;
            double newTotalTime = totalTime + duration;
            int newJourneyCount = journeyCount + 1;
            avgTimes[journey] = make_pair(newTotalTime, newJourneyCount);
        }
        else {
            avgTimes[journey] = make_pair(duration, 1);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        double res;
        string journey = startStation + "|" + endStation;
        res = avgTimes[journey].first/avgTimes[journey].second;
        return res;
    }
};
​
/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
