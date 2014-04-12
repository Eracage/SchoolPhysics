#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

// file making easier to debug time distribution with easy functions

#define DebugTIMER sf::Clock debugTimer;
#define DebugCHECKPOINT(text) std::cout<<(text)<<"\t"<<debugTimer.restart().asSeconds()<<std::endl;
