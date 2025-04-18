#include "Logger.h"
#include "fun.h"

Logger logger({ DEBUG, INFO, WARNING, ERROR }); //выбор выводимых уровней

Logger :: Logger(vector<log_level> levels_to_write): _levels_to_write(levels_to_write) {
    const string dir_name = "logs";

    struct stat info;
    if (!((stat(dir_name.c_str(), &info) == 0 && (info.st_mode & S_IFDIR))))
        system(("mkdir " + dir_name).c_str());

    time_t now = time(0);
    const string file_name = "logfile" + to_string(now) + ".txt";

    _logFile.open(dir_name + "/" + file_name, ios::app);
    if (!_logFile.is_open()) {
        cerr << "Error opening log file." << endl;
    }
}

Logger :: ~Logger() {
    _logFile.close(); 
}

void Logger :: log(log_level level, string message) {
    for (int index=0; index<_levels_to_write.size(); index++){
        if (level == _levels_to_write[index]) break;
        else if (index == _levels_to_write.size() - 1) return;
    }

    struct tm time_info;
    time_t now = time(0);
    localtime_s(&time_info, &now);
    char time_stamp[20];
    strftime(time_stamp, sizeof(time_stamp), "%Y-%m-%d %H:%M:%S", &time_info);

    ostringstream log_entry;
    log_entry << "[" << time_stamp << "] " << levelToString(level) << ": " << message << endl;

    //cout << log_entry.str(); - при желании можно вывести всё на консоль

    if (_logFile.is_open()) {
        _logFile << log_entry.str();
        _logFile.flush(); 
    }
}
void Logger::log(log_level level, string message, Point point, string name_point) {
    string data = "";

    if (name_point != "") {
        data += " " + name_point + ": [";
    }
    else {
        data += " point: [";
    }

    for (int index = 0; index < point.point.size()-1; index++) {
        data+=to_string(point.point[index])+", ";
    }
    data += to_string(point.point[point.point.size() - 1]) + "]";

    log(level, message + data);
}

void Logger::log(log_level level, string message, vector<Point> symplex) {
    string data = "";
    int index_last_point = symplex[symplex.size() - 1].point.size() - 1;
    int index_last_str_symplex = symplex.size() - 1;

    data += " symplex: [";
    for (int index_symplex = 0; index_symplex <= index_last_str_symplex; index_symplex++) {
        for (int index_point = 0; index_point < index_last_point; index_point++) {
            data += to_string(symplex[index_symplex].point[index_point]) + ", ";
        }
    }
    data += to_string(symplex[index_last_str_symplex].point[index_last_point]) + "]";

    log(level, message + data);
}

void Logger :: log(log_level level, string message, int problem_size, vector<Point> symplex,
    float alpha, float beta, float gamma, int max_iter) {
    string data = "";
    int index_last_point = symplex[symplex.size() - 1].point.size() - 1;
    int index_last_str_symplex = symplex.size() - 1;

    data += "\nproblem_size: " + to_string(problem_size) + "\n";

    data += "start_symplex: [";
    for (int index_symplex = 0; index_symplex <= index_last_str_symplex; index_symplex++) {
        for (int index_point = 0; index_point < index_last_point; index_point++) {
            data += to_string(symplex[index_symplex].point[index_point]) + ", ";
        }
    }
    data += to_string(symplex[index_last_str_symplex].point[index_last_point]) + "]\n";

    data += "alpha: " + to_string(alpha) + "\n";
    data += "beta: " + to_string(beta) + "\n";
    data += "gamma: " + to_string(gamma) + "\n";
    data += "max_iter: " + to_string(max_iter);

    log(level, message + data);
}

string Logger :: levelToString(log_level level)
{
    switch (level) {
    case DEBUG:
        return "DEBUG";
    case INFO:
        return "INFO";
    case WARNING:
        return "WARNING";
    case ERROR:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}
