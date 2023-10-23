#pragma once

class PlayerT {
    public:

        PlayerT(){};

        int Score(void) const;
        void Score(int);


    private:
        int score {0};

};

int PlayerT::Score() const{
    return score;
}

void PlayerT::Score(int n) {
    score = n;
}

