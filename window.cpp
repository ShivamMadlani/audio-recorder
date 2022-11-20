#include <SFML/Window.hpp>
#include <SFML/Audio/SoundBufferRecorder.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

int main(){
    sf::Window window(sf::VideoMode(700, 700), "Audio Recorder", sf::Style::Default);
    
    if(!sf::SoundBufferRecorder::isAvailable()){
        return 0;
    }

    sf::SoundBufferRecorder recorder;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}