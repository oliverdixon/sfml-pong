//
// Created by owd on 18/06/24.
//

#ifndef PONG_IMOVABLE_H
#define PONG_IMOVABLE_H

class IMovable {
public:
    virtual void move(float delta) = 0;
};

#endif //PONG_IMOVABLE_H
