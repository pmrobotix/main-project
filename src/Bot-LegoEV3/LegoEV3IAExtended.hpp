#ifndef LegoEV3_IAEXTENDED_HPP_
#define LegoEV3_IAEXTENDED_HPP_

#include <src/pmr_symmetrical_pg.h>
#include <string>

#include "../Common/IA/IAbyPath.hpp"
#include "../Common/IA/IAbyZone.hpp"

struct FoundPath;
struct Point;

class LegoEV3IAExtended //: public IA
{
private:

    IAbyZone iaz_;
    IAbyPath iap_;

    SymmetricalPlayground *p_;

    //Robot * robot_;

public:

    //Configuration per robot and strategy
    PlaygroundObjectID area_D3;
    PlaygroundObjectID area_A4;
    PlaygroundObjectID area_B4;
    PlaygroundObjectID area_C3;
    PlaygroundObjectID area_C4;
    PlaygroundObjectID area_D4;
    PlaygroundObjectID area_B3;
    PlaygroundObjectID area_A3;
/*
    PlaygroundObjectID area_start_violet;
    PlaygroundObjectID area_start_yellow;

    PlaygroundObjectID area_alea_violet;
    PlaygroundObjectID area_alea_yellow;

    PlaygroundObjectID area_3_start_violet;
    PlaygroundObjectID area_3_start_yellow;

    PlaygroundObjectID area_triangle_violet;
    PlaygroundObjectID area_triangle_yellow;

    PlaygroundObjectID area_distrib_violet;
    PlaygroundObjectID area_distrib_yellow;

    PlaygroundObjectID area_galerie_violet;
    PlaygroundObjectID area_galerie_yellow;
    */

    PlaygroundObjectID opponent_1;
    PlaygroundObjectID opponent_2;
    PlaygroundObjectID opponent_3;
    PlaygroundObjectID opponent_4;

    LegoEV3IAExtended(std::string botId, Robot *robot);

    ~LegoEV3IAExtended()
    {
    }

    IAbyZone& iAbyZone()
    {
        return iaz_;
    }

    IAbyPath& iAbyPath()
    {
        return iap_;
    }

    void initPlayground();

};

#endif
