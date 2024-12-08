#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include "Rivertree.h"

void readTributaryData(const std::string& filename, RiverTree& tree);
void readDamData(const std::string& filename, RiverTree& tree);

#endif // DATA_LOADER_H
