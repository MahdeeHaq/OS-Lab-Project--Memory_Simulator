#ifndef FRAMESIZE_H
#define FRAMESIZE_H

#include <string>
#include <vector>
#include "result.h"

// An Algorithm is any function shaped like runFIFO:
// it takes pages and a frame count, and returns a Result.
typedef Result (*Algorithm)(const std::vector<int>& pages, int frameCount);

void printFrameSizeTable(const std::string& name, Algorithm algo,
                         const std::vector<int>& pages, int maxFrames);

#endif
