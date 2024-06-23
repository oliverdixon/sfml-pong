//
// Created by owd on 18/06/24.
//

#ifndef PONG_IMOVEABLE_H
#define PONG_IMOVEABLE_H

class IMoveable {
public:
    virtual void move(float delta) = 0;
};

#endif //PONG_IMOVEABLE_H
