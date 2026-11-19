#include "Logger.h"
#include "Logger.cpp"
#include <iostream>

int main(){

    std::ofstream log("log.txt");
    log << "";
    log.close();

    Logger logger(2);
    
    logger.log(0,"un message SILENT");
    logger.log(1,"un message INFO");
    logger.log(2,"un message WARNING");
    logger.log(3,"un message ERROR");

    logger.afficher();
    logger.setLevel(0);
    logger.afficher();

    return 0;
}