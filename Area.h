#include <string>
using namespace std;
#include "player.h"



class Area
{

    private:
    
    

    public:
    //void starting_location(Character& race);
    void travel();
    void current_area();
    string destination;
    string location = "FOREST";  //will be changed to be a different starting location based on Race


    
};
