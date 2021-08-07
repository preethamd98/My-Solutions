class Logger {
public:
    unordered_map<string,int> log;
    /** Initialize your data structure here. */
    Logger() {}
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(log.find(message)==log.end()){
            log[message] = timestamp + 10;
        }
        else if(timestamp < log[message]){
            return false;
        }
        else{
            log[message] = timestamp + 10;
        }
        return true;
    }
};




