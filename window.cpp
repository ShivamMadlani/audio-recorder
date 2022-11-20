#include <SFML/Window.hpp>
#include <SFML/Audio/SoundBufferRecorder.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

int main(){
    //check for audio capture support
    if(!sf::SoundBufferRecorder::isAvailable()){
        return 0;
    }
    sf::SoundBufferRecorder recorder;

    //create a window
    sf::Window window(sf::VideoMode(1000, 500), "Audio Recorder", sf::Style::Default);
    window.setPosition(sf::Vector2i(960,545));

    //window
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