#include "IdGenerator.h"

int IdGenerator::assign_id() {
    this->last_id++ ;
    return last_id;
}

IdGenerator::IdGenerator() {
    this->last_id = 0;
}

IdGenerator::~IdGenerator() = default;
