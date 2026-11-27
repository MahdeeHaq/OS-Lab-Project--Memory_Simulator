#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <vector>

// Each function returns true if it worked, false if the input was bad.
bool readPagesFromKeyboard(std::vector<int>& pages);
bool readPagesFromFile(const std::string& filename, std::vector<int>& pages);
bool readFrameCount(int& frames);

#endif
