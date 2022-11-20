#include <SFML/Window.hpp>
#include <SFML/Audio/SoundBufferRecorder.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics.hpp>
#include <unistd.h>

int main(){
    //check for audio capture support
    if(!sf::SoundBufferRecorder::isAvailable()){
        return 0;
    }
    sf::SoundBufferRecorder recorder;

    //fonts
    sf::Font font;
    font.loadFromFile("./Arialn.ttf");
    sf::Text text, text1;
    text.setFont(font);
    text.setString("recording ended");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    text.setOrigin(text.getLocalBounds().width/2. , text.getLocalBounds().height/2.);

    text1.setFont(font);
    text1.setString("recording started\nPress Q to end recording.");
    text1.setCharacterSize(50);
    text1.setFillColor(sf::Color::Black);
    text1.setOrigin(text.getLocalBounds().width/2. , text.getLocalBounds().height/2.);

    //create a window
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(1000, 500, desktopMode.bitsPerPixel), "Audio Recorder", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    window.setPosition(sf::Vector2i(960,545));

    recorder.start();
    
    //window
    while (window.isOpen())
    {
        sf::Event event, event1;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.clear(sf::Color(127, 127, 127));
                text.setPosition(window.getSize().x/2. , window.getSize().y/2.);
                window.draw(text);
                window.display();
                recorder.stop();
                const sf::SoundBuffer& buff = recorder.getBuffer();
                buff.saveToFile("audio.ogg");
                sleep(2);
                window.close();
            }
        }

        window.clear(sf::Color(127, 127, 127));
        text1.setPosition(window.getSize().x/2. , window.getSize().y/2.);
        window.draw(text1);
        
        window.display();
    }
    return 0;
}