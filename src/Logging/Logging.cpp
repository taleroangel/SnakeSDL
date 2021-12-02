#include "Logging.hpp"

Logging::Logging(std::string filename, bool append)
{
    // Open the log
    file.open(filename, std::fstream::out | (append ? std::ios::app : std::ios::trunc));

    if (file.is_open())
    {
        // Save the filename
        this->filename = filename;

        // Execution LOG
        file << "{ Execution began [" << getDateTime() << "] }" << std::endl;
        this->print("Logging", "Log file initialization succeeded");
    }

    else
        this->failure = true;
}

Logging::~Logging()
{
    // Execution LOG
    this->print("Logging", "Log file is being closed");
    file << "{ Execution finished [" << getDateTime() << "] }\n" << std::endl;
    file.close();
}

void Logging::print(std::string service, std::string message, InfoType type)
{
    // Get message time
    std::string typemsg;
    switch (type)
    {
    case InfoType::INFO:
        typemsg = "INFO";
        break;

    case InfoType::ERROR:
        typemsg = "ERROR";
        break;

    case InfoType::WARNING:
        typemsg = "WARNING";
        break;

    default:
        typemsg = "UNKNOWN";
        break;
    }

    // Print to the file
    file << "[" << service << ": " << getDateTime() << "] " << typemsg << ": " << message << std::endl;
}

bool Logging::isFailed()
{
    return this->failure;
}

std::string Logging::getDateTime()
{
    // Get time
    std::time_t time = std::time(nullptr);
    const int str_size = 25;
    char timedate[str_size];
    std::strftime(timedate, str_size, "%d/%m/%Y @ %H:%M:%S", std::localtime(&time));
    return std::string(timedate);
}
