#include "game.hpp"

Game::Game(const std::string& homeTeam, const std::string& awayTeam, const Date& date,
           const std::string& startTime, const std::string& referee, int duration)
    : homeTeam(homeTeam), awayTeam(awayTeam), date(date), startTime(startTime), referee(referee),
      duration(std::max(duration, 90)), score{{"home", 0}, {"away", 0}} {}

Game::~Game() {
   //no need 
}

void Game::endGame() {
    std::cout << "The game between " << homeTeam<<" -"<<score[homeTeam]<<"-" << " and " << awayTeam<<" -"<<score[homeTeam]<<"-"  << " has ended." << std::endl;
}

void Game::addGoal(const std::string& team, int playerNumber) {
    score[team]++;
    goalScorers[team].push_back(playerNumber);
}

void Game::addYellowCard(const std::string& team, int playerNumber) {
    yellowCards[team].push_back(playerNumber);
}

void Game::addRedCard(const std::string& team, int playerNumber) {
    redCards[team].push_back(playerNumber);
}

void Game::makeSubstitution(const std::string& team, int inPlayerNumber, int outPlayerNumber, int substitutionTime) {
    substitutions[team].push_back(std::make_tuple(inPlayerNumber, outPlayerNumber, substitutionTime));
}

void Game::recordPlayerDistance(const std::string& team, int playerNumber, float distance) {
    playerDistance[team][playerNumber] += distance;
}


// Getters
std::string Game::getHomeTeam() const {
    return homeTeam;
}

std::string Game::getAwayTeam() const {
    return awayTeam;
}

std::string Game::getDate() const {
    std::string simple= std::to_string(date.GetYear());
    simple+=std::to_string(date.GetMonth());
    simple+=std::to_string(date.GetDay());
    return  simple;
}

std::string Game::getStartTime() const {
    return startTime;
}

std::string Game::getRefereeName() const {
    return referee;
}

int Game::getDuration() const {
    return duration;
}

// Setters
void Game::setHomeTeam(const std::string& team) {
    homeTeam = team;
}

void Game::setAwayTeam(const std::string& team) {
    awayTeam = team;
}

void Game::setDate(const Date& newDate) {
    date = newDate;
}

void Game::setStartTime(const std::string& newStartTime) {
    startTime = newStartTime;
}

void Game::setRefereeName(const std::string& newReferee) {
    referee = newReferee;
}

void Game::setDuration(int newDuration) {
    duration = std::max(newDuration, 90);
}



// Overloading the > operator to compare games based on date and start time
bool Game::operator > (const Game& other) const {
    // Convert date string to a comparable format (YYYYMMDD)
    int thisDate = std::stoi(this->getDate());
    int otherDate = std::stoi(other.getDate());

    if (thisDate > otherDate)
        return true;
    else if (thisDate < otherDate)
        return false;

    // If dates are equal, compare start times
    return startTime > other.startTime;
}
bool Game::operator < (const Game& other)const{
    return !(*this > other);
}

