//
// Created by Noy Zini on 02/05/2022.
//

#ifndef MTMCHKIN_PLAYER_H
#define MTMCHKIN_PLAYER_H
#include <string>

const int MAX_LEVEL = 10;
using std::string; //can we do that???


//add public static and CONST!
class Player{

    string m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;

public:
    Player(const string& name, int maxHP = 100, int force = 5);
    Player(const Player&)=default;//ask on piazza if it's ok
    Player& operator=(const Player&)=default;
    ~Player()=default;

    /*
     * Prints the player info:
     *
     * @return
     *      void
    */
    void printInfo();

    /*
     * Levels up the player, to a maximum of level 10
     *
     * @return
     *          void
    */
    void levelUp();

    /*
     *  Returns the player level:
     *
     *  @return
     *          Player level
     */
    int getLevel();

    /*
     * Buffs the player
     *
     * @param boost - force to add to the player
     * @return
     *          void
    */
    void buff(int boost);

    /*
     * Heals the player, up to max hp
     *
     * @param hp - health points to add to the player
     * @return
     *          void
    */
    void heal(int hp);

    /*
     * Deals damage to the player
     *
     * @param damage - health points to deal to the player
     * @return
     *          void
    */
    void damage(int damage);

    /*
     *  Check if the player is knocked out
     *
     *  @return
     *          True if hp is 0
     *          False otherwise
     */
    bool isKnockedOut();

    /*
     * Add coins to the player
     *
     * @param coins - coins to add to the player
     * @return
     *          void
    */
    void addCoins(int coins);

    /*
     * Deduce coins from the player, given player have enough
     *
     * @param coins - coins to pay from player
     * @return
     *          True if paid and player had enough coins
     *          False otherwise
    */
    bool pay(int coins);

    /*
     * Returns the attack strength of the player
     * Player's attack strength is player force + player level
     *
     * @return
     *          Player's attack strength
    */
    int getAttackStrength();


};


#endif //MTMCHKIN_PLAYER_H
