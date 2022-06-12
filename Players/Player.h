#ifndef MTMCHKIN_PLAYER_H
#define MTMCHKIN_PLAYER_H
#include <string>
#include "../HealthPoints.h"



using std::string;

class Player {

public:

    /*
     * C'tor of the game:
     *
     * @param name - The name of the player.
     * @result
     *      An instance of Mtmchkin
    */
    Player(const char* name);

    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Player(const Player&)=default;
    Player& operator=(const Player&)=default;
    virtual ~Player()=default;



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
    int getLevel() const;

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
    virtual void heal(int hp);

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
    bool isKnockedOut() const;

    /*
     * Add coins to the player
     *
     * @param coins - coins to add to the player
     * @return
     *          void
    */
    virtual void addCoins(int coins);

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
     * Returns the attack strength of the player.
     * Player's attack strength is player force + player level
     *
     * @return
     *          Player's attack strength
    */

    string  getName() const;

    int getCoins() const;

    virtual int getAttackStrength() const;



    static const int MAX_LEVEL = 10;

protected: // should be privet??
    string m_name;
    int m_level;
    int m_force;
    HealthPoints m_hp;
    int m_coins;

    friend std::ostream& operator<<(std::ostream& os, const Player& player) ;
    virtual void print(std::ostream& os) const =0;

    static const int MAX_HP_DEFAULT = 100;
    static const int PLAYER_FORCE_DEFAULT = 5;
    static const int DEFAULT_COINS = 10;
};


#endif //MTMCHKIN_PLAYER_H
