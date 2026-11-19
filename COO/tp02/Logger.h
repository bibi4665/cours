#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger{
private:
    std::string message;
    short level;
    std::ofstream logFile;

public: 
    Logger(short level, const std::string& filename = "log.txt");
    ~Logger();

    void afficher();
    void setLevel(short level);
    void log(short level, const std::string& message);
    std::string levelToString(short level);

};


#endif
