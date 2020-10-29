#ifndef civilizacao
#define civilizacao

#include <string>
using std::string;

class Civilization {
    public:
        Civilization();
        virtual ~Civilization();
        void setDc(int dc);
        int getDc();
        void setPc(int pc);
        int getPc();
        void setPlanet(string name);
        string getPlanet();

    protected:
        string planet;
        int dc;
        int pc;

};

#endif 