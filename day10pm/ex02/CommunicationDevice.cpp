#include <iostream>
#include <stdexcept>
#include "Errors.hpp"
#include "CommunicationDevice.hpp"

CommunicationDevice::CommunicationDevice(std::istream &input, std::ostream &output) try :
    _api(input, output)
{
}
catch (const std::exception &err) {
    throw CommunicationError("Error: " + (std::string)err.what());
}

CommunicationDevice::~CommunicationDevice()
{
}

void    CommunicationDevice::startMission(std::string const &missionName, std::string *users, size_t nbUsers)
{
    try {
    for (size_t i = 0; i < nbUsers; ++i)
        _api.addUser(users[i]);
    _api.startMission(missionName);
    }
    catch(const std::logic_error &err) {
        throw CommunicationError("LogicError: " + (std::string)err.what());
    }
    catch(const std::runtime_error &err) {
        throw CommunicationError("RuntimeError: " + (std::string)err.what());
    }
    catch(const std::exception &err) {
        throw CommunicationError("Error: " + (std::string)err.what());
    }
}

void    CommunicationDevice::send(std::string const &user, std::string const &message) const
{
    try {
        _api.sendMessage(user, message);
    }
    catch (const std::exception &err) {
        std::cerr << err.what() << std::endl;
        // throw CommunicationError(err.what());
    }
}

void    CommunicationDevice::receive(std::string const &user, std::string &message) const
{
    try {
        _api.receiveMessage(user, message);
    }
    catch (const std::exception &err) {
        std::cerr << err.what() << std::endl;
        message = "INVALID MESSAGE";
    }
}
