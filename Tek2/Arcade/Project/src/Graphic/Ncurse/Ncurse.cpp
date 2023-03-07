/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Ncurse
*/

#include "Ncurse.hpp"
#include "IGraphic.hpp"

/**
 * @brief linking the library with DLLoader
 *
 */

extern "C" arcade::graphic::IGraphic *entryPointGraphic(void)
{
    arcade::graphic::IGraphic *newGraphic = new arcade::graphic::Ncurse;

    return newGraphic;
}

/**
 * @brief Construct a new arcade::graphic::Ncurse::Ncurse object
 *
 */

// Initialise la structure WINDOW et autres paramètres
arcade::graphic::Ncurse::Ncurse()
{
	initWindow("ARCADE Ncurse");
	initKeypad();
    initColors();
	//cbreak(); 								// Attention
	noecho();
	curs_set(FALSE);
	refresh(); 								// Rafraîchit la fenêtre courante afin de voir le message apparaître
}

/**
 * @brief Destroy the arcade::graphic::Ncurse::Ncurse object
 *
 */

arcade::graphic::Ncurse::~Ncurse()
{
	arcade::graphic::Ncurse::closeWindow();
}

/**
 * @brief function clears the screen
 */
void arcade::graphic::Ncurse::clearScreen()
{
    if (_isOpen) {
	    clear();
	    noecho();
    }
}

void arcade::graphic::Ncurse::refreshScreen()
{
    if (_isOpen)
    	refresh();
}

/**
 * @brief function is used to close the window
 */
void arcade::graphic::Ncurse::closeWindow()
{
	_isOpen = false;
	endwin();
}

/**
 * @brief It returns the status of the window.
 *
 * @return The status of the window.
 */
bool arcade::graphic::Ncurse::getStatus() const
{
    return _isOpen;
}

/**
 * @brief Initialize the ncurses window
 *
 * @param name The name of the window.
 */
void arcade::graphic::Ncurse::initWindow(std::string const &name)
{
	_name = name;
	_isOpen = true;
	initscr();
}

/**
 * @brief Initializes the keypad
 */
void arcade::graphic::Ncurse::initKeypad()
{
	keypad(stdscr, TRUE);
}

/**
 * @brief It transforms a pixel_t with binary values color into a ncurses color
 * 
 * @param color The color to transform
 * 
 * @return The color of the pixel
 */
int arcade::graphic::Ncurse::transformBinarytoColor(arcade::graphic::pixel_t color)
{
    if (color.r == 0 && color.g == 0 && color.b == 0)
        return (0);
    if (color.r == 0 && color.g == 0 && color.b == 1)
        return (1);
    if (color.r == 0 && color.g == 1 && color.b == 0)
        return (2);
    if (color.r == 0 && color.g == 1 && color.b == 1)
        return (3);
    if (color.r == 1 && color.g == 0 && color.b == 0)
        return (4);
    if (color.r == 1 && color.g == 0 && color.b == 1)
        return (5);
    if (color.r == 1 && color.g == 1 && color.b == 0)
        return (6);
    if (color.r == 1 && color.g == 1 && color.b == 1)
        return (7);
    return (0);
}

/**
 * It transforms a color from RGB to binary
 * 
 * @param color The color to transform
 * 
 * @return The color in binary
 */
arcade::graphic::pixel_t arcade::graphic::Ncurse::transformRgbToBinary(arcade::graphic::pixel_t color)
{
    arcade::graphic::pixel_t colorNcurse;

    if (color.r < 128)
        colorNcurse.r = 0;
    else
        colorNcurse.r = 1;
    if (color.g < 128)
        colorNcurse.g = 0;
    else
        colorNcurse.g = 1;
    if (color.b < 128)
        colorNcurse.b = 0;
    else
        colorNcurse.b = 1;
    return (colorNcurse);
}

/**
 * @brief It converts a hexadecimal color to a pixel_t structure
 * 
 * @param color The color to transform
 * 
 * @return A pixel_t struct
 */
arcade::graphic::pixel_t arcade::graphic::Ncurse::transformHexaColorToPixel(const std::string &color) const
{
    arcade::graphic::pixel_t colors;

    sscanf(color.c_str(), "%02x%02x%02x", &(colors.r), &(colors.g), &(colors.b));
    return colors;
}

/**
 * @brief Initialize the color pairs for the game in Ncurse
 * @todo In progress
 */
void arcade::graphic::Ncurse::initColors()
{
	// The init_pair() routine changes the definition of a color-pair. It takes three arguments: the number of the color-pair to be changed, the foreground color number, and the background color number. The value of the first argument must be between 1 and COLOR_PAIRS−1. The value of the second and third arguments must be between 0 and COLORS. If the color-pair was previously initialized, the screen is refreshed and all occurrences of that color-pair is changed to the new definition.
	// init_pair(index, foreground, background);
	start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_BLUE, COLOR_BLUE);
	init_pair(2, COLOR_GREEN, COLOR_GREEN);
    init_pair(3, COLOR_CYAN, COLOR_CYAN);
    init_pair(4, COLOR_RED, COLOR_RED);
    init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(6, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(7, COLOR_WHITE, COLOR_WHITE);
    clear();
}


/**
 * @brief Display the game object on the screen
 *
 * @param item The game object to be displayed.
 */
void arcade::graphic::Ncurse::displayGameObject(const game_object_t &item)
{

	refresh();
	int color = transformBinarytoColor(transformRgbToBinary(transformHexaColorToPixel(item.color)));

	if (has_colors() == FALSE) { 						// check if your terminal support colors
		endwin();
		printf("Your terminal does not support color\n"); // THROW AN ERROR
		exit(1);
	}
    for (size_t y = 0; y != item.size.y; y++) {
        for (size_t x = 0; x != item.size.x; x++) {
	        attron(COLOR_PAIR(color));
	        mvwprintw(stdscr, item.pos.y + y, item.pos.x + x, "#");
            attroff(COLOR_PAIR(color));
        }
    }
	refresh();
}

/**
 * @brief Draws all the game objects that are pending to be drawn
 *
 * @param Items A vector of game objects to be drawn.
 */
void arcade::graphic::Ncurse::drawPendingGameObjects(const std::vector<arcade::game_object_t> &Items)
{
	int size = Items.size();

    if (_isOpen) {
    	for (int i = 0; i != size; i++) {
    	 	arcade::graphic::Ncurse::displayGameObject(Items[i]);
	    }
    }
}

/**
 * @brief This function displays the screen
 */
void arcade::graphic::Ncurse::displayScreen()
{
	if (_isOpen) {
        
    }
}

/**
 * @brief This function displays the background of the game
 */
void arcade::graphic::Ncurse::displayBackground(const arcade::game_object_t &game_object)
{
    (void) game_object;
    if (_isOpen) {

    }
}

/**
 * @brief Get the event from the keyboard (player input)
 *
 * @return A vector of event_t
 */
std::vector<arcade::event_t> arcade::graphic::Ncurse::getPendingEvent()
{
    timeout(100);
	int event_player = getch();
    std::vector<arcade::event_t> v_event;

        if (event_player != 0) {
            switch (event_player) {
                case 27:
                    arcade::graphic::Ncurse::closeWindow();
                    v_event.push_back(event_t::ESCAPE);
					break;
                case 122:
                    v_event.push_back(event_t::UP);
                    break;
                case 115:
                    v_event.push_back(event_t::DOWN);
                    break;
                case 113:
                    v_event.push_back(event_t::LEFT);
                    break;
                case 100:
                    v_event.push_back(event_t::RIGHT);
                    break;
                case KEY_UP:
                    v_event.push_back(event_t::NEXT_GRAPHIC);
                    break;
                case KEY_DOWN:
                    v_event.push_back(event_t::PREV_GRAPHIC);
                    break;
                case KEY_LEFT:
                    v_event.push_back(event_t::PREV_GAME);
                    break;
                case KEY_RIGHT:
                    v_event.push_back(event_t::NEXT_GAME);
                    break;
                case 97:
                    v_event.push_back(event_t::PAUSE);
                    break;
                case 114:
                    v_event.push_back(event_t::RESTART);
                    break;
                case 101:
                    v_event.push_back(event_t::MENU);
                    break;
                case 32:
                    v_event.push_back(event_t::ACTION);
                    break;
                default:
                    break;
            }
        }
    return v_event;
}

void arcade::graphic::Ncurse::displayTextObject(arcade::text_object_t item)
{
    refresh();
	int color = transformBinarytoColor(transformRgbToBinary(transformHexaColorToPixel(item.textColor)));
    int color_back = transformBinarytoColor(transformRgbToBinary(transformHexaColorToPixel(item.backgroundColor)));

	if (has_colors() == FALSE) { 						// check if your terminal support colors
		endwin();
		printf("Your terminal does not support color\n"); // THROW AN ERROR
		exit(1);
	}
    init_pair(0, color, color_back);
	attron(COLOR_PAIR(0));
    if (item.backgroundColor == "000000") {
        mvwprintw(stdscr, item.pos.y, item.pos.x, item.message.c_str());
    } else
        mvwprintw(stdscr, item.pos.y, item.pos.x, ("> " + item.message).c_str());
    attroff(COLOR_PAIR(0));
	refresh();
}

void arcade::graphic::Ncurse::drawPendingTexts(const std::vector<arcade::text_object_t> &text_object)
{
    int size = text_object.size();

    if (_isOpen) {
    	for (int i = 0; i != size; i++) {
            if (text_object[i].fontPath != "Score" && text_object[i].fontPath != "Pseudo" && text_object[i].fontPath != "Game" && text_object[i].fontPath != "Graphic")
    	 	    arcade::graphic::Ncurse::displayTextObject(text_object[i]);
	    }
    }
}