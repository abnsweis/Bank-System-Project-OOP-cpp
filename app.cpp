#include <iostream>
#include "./Screens/clsLoginScreen.h"

using namespace std;




int main() {
    system("cl");
    
    while(true) {
    
        if(!clsLoginScreen::ShowLoginScreen()){
            break;
        };
        
    }
    
    

    return 0;
}