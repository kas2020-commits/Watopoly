#ifndef __UTIL_H__
#define __UTIL_H__
#include <string>
#include <random>

const int MAX_TILES = 40;

// get a random number between min and max
extern int getRand(int min, int max);

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

// Colors

const std::string RESET_All_COLORS = "\033[0m";

const std::string BOLD       = "\033[1m";
const std::string DIM        = "\033[2m";
const std::string UNDERLINED = "\033[4m";
const std::string BLINK      = "\033[5m";
const std::string REVERSE    = "\033[7m";
const std::string HIDDEN     = "\033[8m";

const std::string RESET_BOLD       = "\033[21m";
const std::string RESET_DIM        = "\033[22m";
const std::string RESET_UNDERLINED = "\033[24m";
const std::string RESET_BLINK      = "\033[25m";
const std::string RESET_REVERSE    = "\033[27m";
const std::string RESET_HIDDEN     = "\033[28m";

const std::string DEFAULT      = "\033[39m";
const std::string BLACK        = "\033[30m";
const std::string RED          = "\033[31m";
const std::string GREEN        = "\033[32m";
const std::string YELLOW       = "\033[33m";
const std::string BLUE         = "\033[34m";
const std::string MAGENTA      = "\033[35m";
const std::string CYAN         = "\033[36m";
const std::string LIGHT_GRAY    = "\033[37m";
const std::string DARKT_RAY     = "\033[90m";
const std::string LIGHT_RED     = "\033[91m";
const std::string LIGHT_GREEN   = "\033[92m";
const std::string LIGHT_YELLOW  = "\033[93m";
const std::string LIGHT_BLUE    = "\033[94m";
const std::string LIGHT_MAGENTA = "\033[95m";
const std::string LIGHT_CYAN    = "\033[96m";
const std::string WHITE        = "\033[97m";

const std::string BACKGROUND_DEFAULT      = "\033[49m";
const std::string BACKGROUND_BLACK        = "\033[40m";
const std::string BACKGROUND_RED          = "\033[41m";
const std::string BACKGROUND_GREEN        = "\033[42m";
const std::string BACKGROUND_YELLOW       = "\033[43m";
const std::string BACKGROUND_BLUE         = "\033[44m";
const std::string BACKGROUND_MAGENTA      = "\033[45m";
const std::string BACKGROUND_CYAN         = "\033[46m";
const std::string BACKGROUND_LIGHTGRAY    = "\033[47m";
const std::string BACKGROUND_DARKGRAY     = "\033[100m";
const std::string BACKGROUND_LIGHTRED     = "\033[101m";
const std::string BACKGROUND_LIGHTGREEN   = "\033[102m";
const std::string BACKGROUND_LIGHTYELLOW  = "\033[103m";
const std::string BACKGROUND_LIGHTBLUE    = "\033[104m";
const std::string BACKGROUND_LIGHTMAGENTA = "\033[105m";
const std::string BACKGROUND_LIGHTCYAN    = "\033[106m";
const std::string BACKGROUND_WHITE        = "\033[107m";

const std::string VIEW_TEMPLATE{
    "____________________________________________________________________________________________________\n"
    "|Goose   |        |NEEDLES |        |        |V1      |        |        |CIF     |        |GO TO   |\n"
    "|Nesting |--------|HALL    |--------|--------|        |--------|--------|        |--------|TIMS    |\n"
    "|        |EV1     |        |EV2     |EV3     |        |PHYS    |B1      |        |B2      |        |\n"
    "|        |        |        |        |        |        |        |        |        |        |        |\n"
    "|________|________|________|________|________|________|________|________|________|________|________|\n"
    "|        |                                                                                |        |\n"
    "|--------|                                                                                |--------|\n"
    "|OPT     |                                                                                |EIT     |\n"
    "|        |                                                                                |        |\n"
    "|________|                                                                                |________|\n"
    "|        |                                                                                |        |\n"
    "|--------|                                                                                |--------|\n"
    "|BMH     |                                                                                |ESC     |\n"
    "|        |                                                                                |        |\n"
    "|________|                                                                                |________|\n"
    "|SLC     |                                                                                |SLC     |\n"
    "|        |                                                                                |        |\n"
    "|        |                                                                                |        |\n"
    "|        |                                                                                |        |\n"
    "|________|                                                                                |________|\n"
    "|        |                                                                                |        |\n"
    "|--------|                                                                                |--------|\n"
    "|LHI     |                                                                                |C2      |\n"
    "|        |                 ______________________________________________                 |        |\n"
    "|________|                |                                              |                |________|\n"
    "|UWP     |                | #   # #### ##### ##### #### ##### #    #   # |                |REV     |\n"
    "|        |                | #   # #  #   #   #   # #  # #   # #    #   # |                |        |\n"
    "|        |                | # # # ####   #   #   # #### #   # #    ##### |                |        |\n"
    "|        |                | # # # #  #   #   #   # #    #   # #      #   |                |        |\n"
    "|________|                | ##### #  #   #   ##### #    ##### ####   #   |                |________|\n"
    "|        |                |______________________________________________|                |NEEDLES |\n"
    "|--------|                                                                                |HALL    |\n"
    "|CPH     |                                                                                |        |\n"
    "|        |                                                                                |        |\n"
    "|________|                                                                                |________|\n"
    "|        |                                                                                |        |\n"
    "|--------|                                                                                |--------|\n"
    "|DWE     |                                                                                |MC      |\n"
    "|        |                                                                                |        |\n"
    "|________|                                                                                |________|\n"
    "|PAC     |                                                                                |COOP    |\n"
    "|        |                                                                                |FEE     |\n"
    "|        |                                                                                |        |\n"
    "|        |                                                                                |        |\n"
    "|________|                                                                                |________|\n"
    "|        |                                                                                |        |\n"
    "|--------|                                                                                |--------|\n"
    "|RCH     |                                                                                |DC      |\n"
    "|        |                                                                                |        |\n"
    "|________|________________________________________________________________________________|________|\n"
    "|DC Tims |        |        |NEEDLES |        |MKV     |TUITION |        |SLC     |        |COLLECT |\n"
    "|Line    |--------|--------|HALL    |--------|        |        |--------|        |--------|OSAP    |\n"
    "|        |HH      |PAS     |        |ECH     |        |        |ML      |        |AL      |        |\n"
    "|        |        |        |        |        |        |        |        |        |        |        |\n"
    "|________|________|________|________|________|________|________|________|________|________|________|\n"
};


#endif