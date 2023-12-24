#ifndef SPUTIFY_IDGENERATOR_H
#define SPUTIFY_IDGENERATOR_H


class IdGenerator {
public:
    IdGenerator();
    ~IdGenerator();

    int assign_id();
private:
    int last_id;
};


#endif //SPUTIFY_IDGENERATOR_H
