#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {

}

ClapTrap::ClapTrap(std::string name) {
std::string()
}

ClapTrap::ClapTrap(ClapTrap &clapTrap) {

}

ClapTrap &ClapTrap::operator=(ClapTrap &clapTrap) {
    return <#initializer#>;
}

ClapTrap::~ClapTrap() {

}

void ClapTrap::attack(const std::string &target) {

}

void ClapTrap::takeDamage(unsigned int amount) {

}

void ClapTrap::beRepaired(unsigned int amount) {

}

unsigned int ClapTrap::getAttackDamage(void) {
    return 0;
}

const std::string &ClapTrap::getName() const {
    return _name;
}

void ClapTrap::setName(const std::string &name) {
    _name = name;
}

unsigned int ClapTrap::getHitPoints() const {
    return _hitPoints;
}

void ClapTrap::setHitPoints(unsigned int hitPoints) {
    _hitPoints = hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return _energyPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints) {
    _energyPoints = energyPoints;
}

unsigned int ClapTrap::getAttackDamage1() const {
    return _attackDamage;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage) {
    _attackDamage = attackDamage;
}
