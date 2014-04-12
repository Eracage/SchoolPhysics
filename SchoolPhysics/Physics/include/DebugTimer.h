#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>


#define DebugTIMER sf::Clock debugTimer;
#define DebugCHECKPOINT(text) std::cout<<(text)<<"\t"<<debugTimer.restart().asSeconds()<<std::endl;
