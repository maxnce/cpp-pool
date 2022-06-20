/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** sys
*/

#include "Sys.hpp"
#include <sstream>

SystemProperties::SystemProperties()
{
    updateKernelProperties();
    updateRamProperties();
    updateCpuProperties();
}

SystemProperties::~SystemProperties()
{}

void SystemProperties::updateKernelProperties()
{
    struct utsname unameData;
    uname(&unameData);

    time_t now = time(0);

    char hostname[255];
    char username[255];
    gethostname(hostname, 255);
    getlogin_r(username, 255);

    _sysname = std::string(unameData.sysname);
    _nodeName = std::string(unameData.nodename);
    _release = std::string(unameData.release);
    _version = std::string(unameData.version);
    _machine = std::string(unameData.machine);
    _host = std::string(hostname);
    _user = std::string(username);
    _date = std::string(ctime(&now));
}

void SystemProperties::updateRamProperties()
{
    struct sysinfo sysInfo;
    sysinfo(&sysInfo);

    _uptime = std::to_string(sysInfo.uptime);
    _totalRam = std::to_string(sysInfo.totalram);
    _freeRam = std::to_string(sysInfo.freeram);
    _sharedRam = std::to_string(sysInfo.sharedram);
    _bufferRam = std::to_string(sysInfo.bufferram);
    _swapRam = std::to_string(sysInfo.totalswap);
    _freeSwap = std::to_string(sysInfo.freeswap);
    _processes = std::to_string(sysInfo.procs);

    std::string totalLine = parse("MemTotal:", "/proc/meminfo");
    std::stringstream lineStream(totalLine);
    lineStream >> totalLine;
    long long totalRam;
    lineStream >> totalRam;
    _totalRam = std::to_string(totalRam);

    totalLine = parse("MemAvailable:", "/proc/meminfo");
    lineStream = std::stringstream(totalLine);
    lineStream >> totalLine;
    long long availableRam;
    lineStream >> availableRam;
    _freeRam = std::to_string(availableRam);
}

void SystemProperties::updateCpuProperties()
{
    std::string cpuLine = parse("model name", "/proc/cpuinfo");
    reverse(cpuLine.begin(), cpuLine.end());
    cpuLine = cpuLine.substr(0, cpuLine.find(":"));
    reverse(cpuLine.begin(), cpuLine.end());
    _cpuModel = cpuLine;

    std::string cpuCore = parse("cpu cores", "/proc/cpuinfo");
    reverse(cpuCore.begin(), cpuCore.end());
    cpuCore = cpuCore.substr(0, cpuCore.find(":"));
    _cpuCores = cpuCore;
}