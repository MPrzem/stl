#include "AppendNewRecipe.hpp"


namespace labels{
    constexpr const char* const ingrdiens = "Skladniki:";
    constexpr const char* const steps = "Kroki:";
    std::map<char, std::string> units{ {'g',"gram"},{'s',"szklanki"},{'m',"ml"} };
}


std::stringstream FormatRecipit(std::vector<std::string> steps,const std::list<std::string>& ingredients,const std::deque<std::pair<size_t, char>>& amount) {
    std::stringstream ss;
    ss << labels::ingrdiens<<"\n";
    auto amount_it = amount.begin();
    for (const std::string& ingr : ingredients) {
        ss << amount_it->first <<" "<< labels::units[amount_it->second] <<" "<< ingr<<",\n";
        amount_it++;
    }
    ss << ss.str()<<"\n";
    ss << labels::steps<<"\n";
    short stepnum{ 1 };
    std::for_each(steps.cbegin(), steps.cend(), [&](auto step) {ss << stepnum++ << ") " << step<<".\n"; });
    return ss;

}

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount) {
    std::ofstream file("recipes.txt", file.app);
    if (!file.is_open())
        return false;

    file << FormatRecipit(steps, ingredients, amount).str();
    file.close();
    return true;
}