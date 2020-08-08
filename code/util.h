#ifndef __UTIL_H__
#define __UTIL_H__
#include <string>
#include <cstdlib>

const int MAX_TILES {40};

// rollDie will roll 1 die only, and return the value. If 2 dice need to be
// rolled make sure to call this method twice. The range of values is 1 through
// 6 inclusive.
extern int rollDie();

// Accademic buildings
const std::string AL {"AL"};
const std::string ML {"ML"};
const std::string ECH {"ECH"};
const std::string PAS {"PAS"};
const std::string HH {"HH"};
const std::string RCH {"RCH"};
const std::string DWE {"DWE"};
const std::string CPH {"CPH"};
const std::string LHI {"LHI"};
const std::string BMH {"BMH"};
const std::string OPT {"OPT"};
const std::string EV1 {"EV1"};
const std::string EV2 {"EV2"};
const std::string EV3 {"EV3"};
const std::string PHYS {"PHYS"};
const std::string B1 {"B1"};
const std::string B2 {"B2"};
const std::string EIT {"EIT"};
const std::string ESC {"ESC"};
const std::string C2 {"C2"};
const std::string MC {"MC"};
const std::string DC {"DC"};

// Gyms
const std::string PAC {"PAC"};
const std::string CIF {"CIF"};

// Residences
const std::string MKV {"MKV"};
const std::string UWP {"UWP"};
const std::string V1 {"V1"};
const std::string REV {"REV"};

// Non Property Squares
const std::string COLLECT_OSAP {"Collect OSAP"};
const std::string DC_TIMS_LINE {"DC Tims Line"};
const std::string GO_TO_TIMS {"Go to Tims"};
const std::string GOOSE_NESTING {"Goose Nesting"};
const std::string TUITION {"Tuition"};
const std::string COOP_FEE {"Coop Fee"};
const std::string SLC_S {"SLC"};
const std::string NEEDLES_HALL {"Needles Hall"};
const std::string ROLL_UP_THE_RIM_CUP {"Roll Up the Rim Cup"};

// Block names
const std::string ARTS1 {"Arts1"};
const std::string ARTS2 {"Arts2"};
const std::string ENG {"Eng"};
const std::string HEALTH {"Health"};
const std::string ENV {"Env"};
const std::string SCI1 {"Sci1"};
const std::string SCI2 {"Sci2"};
const std::string MATH {"Math"};

#endif
