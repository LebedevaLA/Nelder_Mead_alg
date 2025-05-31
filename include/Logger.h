#pragma once
#include <iomanip>
#include <limits>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <sys/stat.h>
#include "fun.h"

enum log_level { DEBUG, INFO, WARNING, ERROR };

class Logger {
private:
    vector<log_level> _levels_to_write;
    ofstream _logFile;
    string levelToString(log_level);
    string doubleToString(double value);
    string symplexToString(vector<Point> symplex, string name_symplex);
public:
    Logger(vector<log_level>);
    ~Logger();
    void log(log_level, string);
    void log(log_level, string, Point, string);
    void log(log_level, string, vector<Point>);
    void log(log_level, string, int, vector<Point>, float, float, float, int);
};

extern Logger logger;


