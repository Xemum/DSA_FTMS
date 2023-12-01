#ifndef game_hpp
#define game_hpp

#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include "DATE.hpp"
class Game {
public:
    Game(const std::string& homeTeam, const std::string& awayTeam, const Date& date,
         const std::string& startTime, const std::string& referee, int duration);

    ~Game();

    void endGame();

    void addGoal(const std::string& team, int playerNumber);

    void addYellowCard(const std::string& team, int playerNumber);

    void addRedCard(const std::string& team, int playerNumber);

    void makeSubstitution(const std::string& team, int inPlayerNumber, int outPlayerNumber, int substitutionTime);

    void recordPlayerDistance(const std::string& team, int playerNumber, float distance);
     
    bool operator > (const Game& other)const ;
    bool operator < (const Game& other)const;

    // Getters
     std::string getHomeTeam() const;
     std::string getAwayTeam() const;
     std::string getDate() const;
     std::string getStartTime() const;
     std::string getRefereeName() const;
     int getDuration() const;

     // Setters
     void setHomeTeam(const std::string& team);
     void setAwayTeam(const std::string& team);
     void setDate(const Date& date);
     void setStartTime(const std::string& startTime);
     void setRefereeName(const std::string& referee);
     void setDuration(int duration);

private:
    std::string homeTeam;
    std::string awayTeam;
    Date date;
    std::string startTime;
    std::string referee;
    int duration;

    std::unordered_map<std::string, int> score;
    std::unordered_map<std::string, std::vector<int>> goalScorers;
    std::unordered_map<std::string, std::vector<int>> yellowCards;
    std::unordered_map<std::string, std::vector<int>> redCards;
    std::unordered_map<std::string, std::vector<std::tuple<int, int, int>>> substitutions;
    std::unordered_map<std::string, std::unordered_map<int, float>> playerDistance;
};

#endif // game_hpp
