#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <utility>
#include <vector>


bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount);