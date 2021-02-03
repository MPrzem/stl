#include "AppendNewRecipe.hpp"

int main() {
    std::vector<std::string> steps{"Wsypać do miski 20 gram cukru",
                                   "Dorzucić 1 szklanke mąki",
                                   "Dokładnie wymieszać",
                                   "Nalać 40ml rumu do kieliszka",
                                   "Wypić kieliszek",
                                   "Wysypac zawartośc miski"};
    std::list<std::string> ingredients{"cukru", "mąki", "rumu"};
    std::deque<std::pair<size_t, char>> amount{
        {20, 'g'},
        {1, 's'},
        {40, 'm'}};

    AppendNewRecipe(steps, ingredients, amount);
    std::ifstream file("recipes.txt");
    std::string a(std::istreambuf_iterator<char>(file),{});
    std::cout<<a;
}