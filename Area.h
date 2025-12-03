#include <string>
using namespace std;
#include "player.h"



class Area
{

    private:
    int destination;
    

    public:
    //void starting_location(Character& race);
    bool travel(Player &player);
    void current_area();
    std::string location ;  //will be changed to be a different starting location based on Race


    
};
