#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Cria uma janela
    sf::RenderWindow window(sf::VideoMode(800, 600), "Coded + SFML = Carlos 2.0");

    // Carrega a textura e cria o sprite
    sf::Texture texture;
    if (!texture.loadFromFile("carlos.png")) {
        std::cout << "Erro ao carregar a textura" << std::endl;
        return 1;
    }
    sf::Sprite sprite(texture);

    // Escalona o sprite para um tamanho desejado
    sprite.setScale(1, 1);

    // Definir a posição inicial do sprite
    sf::Vector2f spritePosition(120, 0);
    sprite.setPosition(spritePosition);
    texture.loadFromFile("");

    // Define a velocidade do sprite
    float spriteSpeed = 5.0f;

    // Define icone
    sf::Image icon;
    if (icon.loadFromFile("carlos.png")) {
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
        icon.create(0, 0);
    } else {
        std::cout << "Erro ao carregar o ícone" << std::endl;
    }
    
    // Limita FPS para evitar alto consumo da GPU
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Executa o evento de fechar a janela
            if (event.type == sf::Event::Closed)
                window.close();

            // Corrige o tamanho da janela caso seja redimensionada
            if (event.type == sf::Event::Resized) {
                sf::View view = window.getView();
                view.setSize(static_cast<float>(event.size.width), static_cast<float>(event.size.height));
                window.setView(view);
            }

            // Evita uso de recursos se a janela estiver fora de foco pausando o loop
            if (event.type == sf::Event::LostFocus) {
                while (!window.hasFocus()) {
                    window.waitEvent(event);
                }
            }
        }

        // Verifica teclas pressionadas para mover o sprite
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            spritePosition.y -= spriteSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            spritePosition.x -= spriteSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            spritePosition.y += spriteSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            spritePosition.x += spriteSpeed;

        // Atualiza a posição do sprite
        sprite.setPosition(spritePosition);

        // Limpa a janela
        window.clear(sf::Color::White);

        // Desenha o sprite na janela
        window.draw(sprite);

        // Exibe o que foi desenhado
        window.display();
    }

    return 0;
}
