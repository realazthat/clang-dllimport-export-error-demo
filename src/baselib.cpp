
#include "baselib.hpp"

#include <iostream>

Exception::Exception(const std::string& message, const std::string& name,
                     const std::string& filename, int line) :
    d_message(message),
    d_filename(filename),
    d_name(name),
    d_line(line),
    d_what(name + " in file " + filename  +
           //"(" + PropertyHelper::intToString(line) +
           ") : " + message)
{
    // Log exception if possible
    //Logger* const logger = Logger::getSingletonPtr();
    //if (logger)
    //    logger->logEvent(d_what, Errors);

    // always output to stderr, since nobody seems to look in their log file!
    std::cerr << what() << std::endl;
}

//----------------------------------------------------------------------------//
Exception::~Exception(void) throw()
{
}

//----------------------------------------------------------------------------//
const char* Exception::what() const throw()
{
    return d_what.c_str();
}
