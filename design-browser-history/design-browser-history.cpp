class BrowserHistory {
public:
    list<string> L;
    list<string>::iterator itr;
    BrowserHistory(string homepage) {
        L.push_back(homepage);
        itr = L.begin();
    }
    
    void visit(string url) {
        L.erase(++itr,L.end());
        L.push_back(url);
        itr = --(L.end());
    }
    
    string back(int steps) {
        if(L.size()>0){
        if(itr==L.begin()){
            return *itr;
        }
        while(steps > 0 && itr != L.begin()){
            advance(itr, -1);
            steps--;
        }
        return *itr;
        }
        return "";
    }
    
    string forward(int steps) {
        if(L.size()>0){
        if(itr==(--L.end())){
            return *itr;
        }
        while(steps > 0 && itr != --L.end()){
            advance(itr, 1);
            steps--;
        }
        return *itr;
        }
        return "";
    }
};
​
// itr = yt.com
// [leetcode.com, google.com,fb.com,yt.com]
// -> [leetcode.com, google.com,fb.com,link.com]
​
​
/**
["leetcode.com","linkedin.com","google.com"]
["linkedin.com","google.com","leetcode.com"]
​
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
