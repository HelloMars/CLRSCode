/*
 * =====================================================================================
 *
 *       Filename:  AbstractFactoryPolicy.cpp
 *
 *    Description:  This file implement a simple program which employ the
 *                  abstract factory pattern.
 *
 *        Version:  1.0
 *        Created:  2012/10/25 10:19:04
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Jiaxiang Zheng (NULL), jiaxiang.zheng135@gmail.com
 *   Organization:  State Key Lab of CAD&CG
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
class Button 
{
public:
    virtual void draw() = 0;
    virtual ~Button() {}
};
class Menu
{
public:
    virtual void draw() = 0;
    virtual ~Menu() {}
};
class WinButton : public Button
{
public:
    virtual void draw()
    {
        std::cout << "Win-Button" << std::endl;
    }
};
class UbuntuButton : public Button
{
public:
    virtual void draw()
    {
        std::cout << "Ubuntu-Button" << std::endl;
    }
};
class MacButton : public Button
{
public:
    virtual void draw()
    {
        std::cout << "Mac-Button" << std::endl;
    }
};

class WinMenu : public Menu
{
public:
    virtual void draw()
    {
        std::cout << "Win-Menu" << std::endl;
    }
};
class UbuntuMenu : public Menu
{
public:
    virtual void draw()
    {
        std::cout << "Ubuntu-Menu" << std::endl;
    }
};
class MacMenu : public Menu
{
public:
    virtual void draw()
    {
        std::cout << "Mac-Menu" << std::endl;
    }
};

class Factory
{
public:
    virtual Button* createButton() = 0;
    virtual Menu* createMenu() = 0;
};
class WinFactory : public Factory
{
public:
    virtual Button* createButton()
    {
        return new WinButton;
    }
    virtual Menu* createMenu()
    {
        return new WinMenu;
    }
};
class UbuntuFactory : public Factory
{
public:
    virtual Button* createButton()
    {
        return new UbuntuButton;
    }
    virtual Menu* createMenu()
    {
        return new UbuntuMenu;
    }
};
class MacFactory : public Factory
{
public:
    virtual Button* createButton()
    {
        return new MacButton;
    }
    virtual Menu* createMenu()
    {
        return new MacMenu;
    }
};

void createFactory(Factory*& factory)
{
    std::cout << "Enter platform : (Win | Ubuntu | Mac)" << std::endl;
    std::string platform_name;
    std::cin >> platform_name;
    if (platform_name == "Win")
        factory = new WinFactory;
    else if (platform_name == "Ubuntu")
        factory = new UbuntuFactory;
    else if (platform_name == "Mac")
        factory = new MacFactory;
    else factory = NULL;
    return;
}

int main()
{
    Factory* factory;
    createFactory(factory); //determined by the user
    if (!factory) return -1;
    Button* button = factory->createButton();
    button->draw();
    Menu* menu = factory->createMenu();
    menu->draw();

    delete factory;
    delete button;
    delete menu;
    return 0;
}
