#include <SFML/Window.hpp>
#include <SFML/Audio/SoundBufferRecorder.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics.hpp>

int main(){
    //check for audio capture support
    if(!sf::SoundBufferRecorder::isAvailable()){
        return 0;
    }
    sf::SoundBufferRecorder recorder;

    //fonts
    sf::Font font;
    font.loadFromFile("./Arialn.ttf");
    sf::Text text;
    text.setFont(font);
    text.setString("hello");
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    text.setOrigin(text.getLocalBounds().width/2. , text.getLocalBounds().height/2.);

    //create a window
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(1000, 500, desktopMode.bitsPerPixel), "Audio Recorder", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
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

        window.clear(sf::Color(127, 127, 127));
        text.setPosition(window.getSize().x/2. , window.getSize().y/2.);
        window.draw(text);
        window.display();
    }
    return 0;
}