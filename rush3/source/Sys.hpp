/*
** EPITECH PROJECT, 2022
** rush3
** File description:
** sys
*/

#ifndef SYS_HPP_
#define SYS_HPP_

#include <iostream>
#include <string>
#include <unistd.h>

#include <algorithm>

#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <ctime>

class SystemProperties {
    public:
        SystemProperties();
        ~SystemProperties();

        void updateKernelProperties();
        std::string getSysName() const {return _sysname;};
        std::string getNodeName() const {return _nodeName;};
        std::string getRelease() const {return _release;};
        std::string getVersion() const {return _version;};
        std::string getMachine() const {return _machine;};
        std::string getHost() const {return _host;};
        std::string getUser() const {return _user;};
        std::string getDate() const {return _date;};

        void updateRamProperties();
        std::string getUptime() const {return _uptime;};
        std::string getTotalRam() const {return _totalRam;};
        std::string getFreeRam() const {return _freeRam;};
        std::string getSharedRam() const {return _sharedRam;};
        std::string getBufferRam() const {return _bufferRam;};
        std::string getSwapRam() const {return _swapRam;};
        std::string getFreeSwap() const {return _freeSwap;};
        std::string getProcesses() const {return _processes;};

        void updateCpuProperties();
        std::string getCpuModel() const {return _cpuModel;};
        std::string getCpuCores() const {return _cpuCores;};
    private:
        std::string _sysname; // Nom OS (Linux)
        std::string _nodeName; // Nom du noyau (MacBook-pro.local)
        std::string _release; // Release de l'OS (21.0.1)
        std::string _version; // Version du Kernel
        std::string _machine; // ID du materiel (arm64 ou x86_64 par exemple)
        std::string _host; // Hostname
        std::string _user; // Username
        std::string _date; // Date et Heure (Mon Jan 31 10:13:17 2022)

        std::string _uptime; // Uptime en secondes
        std::string _totalRam; // Ram utilisable totale
        std::string _freeRam; // Ram libre totale
        std::string _sharedRam; // quantite de ram partage
        std::string _bufferRam; // Ram utilise par les buffers
        std::string _swapRam; // Taille du swap
        std::string _freeSwap; // Taille du swap libre
        std::string _processes; // Nombre de process en cours

        std::string _cpuModel; // Modele du cpu (Intel i7-8700k @ 3.70GHz)
        std::string _cpuCores; // Nombre de coeurs
};

std::string parse(std::string, std::string);

#endif /* !SYS_HPP_ */