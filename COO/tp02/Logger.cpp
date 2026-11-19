#include <iostream>
#include "Logger.h"

Logger::Logger(short level, const std::string& filename)
    : level(level){
        logFile.open(filename, std::ios::app);
}

Logger::~Logger(){

};

void Logger::setLevel(short level){
    this->level = level;
}

void Logger::log(short level, const std::string& message){
    logFile << levelToString(level) << " : " << message << std::endl;
    logFile.flush();
}

std::string Logger::levelToString(short level){
    if (level == 0){
        return "SILENT";
    }
    else if (level == 1){
        return "INFO";
    }
    else if (level == 2){
        return "WARNING";
    }
    else if (level == 3){
        return "ERROR";
    }
    return "error";
}

void Logger::afficher(){
    std::ifstream fichier("log.txt");
    std::string line;
    while(std::getline(fichier, line)){
        short messageLevel;
        if(line.find("SILENT") != std::string::npos){
            messageLevel = 0;
        }
        else if(line.find("INFO") != std::string::npos){
            messageLevel = 1;
        }
        else if(line.find("WARNING") != std::string::npos){
            messageLevel = 2;
        }
        else if(line.find("ERROR") != std::string::npos){
            messageLevel = 3;
        }
        if (messageLevel >= level){
            std::cout << line << std::endl;
        }
    }
    std::cout << std::endl;
}

/*
void Logger::afficher(){
    std::cout << warning << " : " << message << std::endl;
}

void Logger::setMessage(std::string m, std::string error){
    message = m;
    warning = error;
}

void Logger::enregistrer(){
    std::ofstream log("log.txt");
    log << warning << "," << message << std::endl;
    log.close();
}

void Logger::recuperer(){
    std::ifstream log("log.txt");
    std::string line;
    warning = std::getline(log, line, ',');
    message = std::getline(log, line, ',');
    log.close();
}
    */