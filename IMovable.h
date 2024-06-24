/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2022
 */

#ifndef PONG_IMOVABLE_H
#define PONG_IMOVABLE_H

class IMovable {
public:
    /**
     * Update the position of the moveable object according to any internal state changes (e.g. standing velocities) to
     * be propagated on the next render cycle.
     *
     * @param delta The time difference from the previous render cycle, used to smooth animations.
     */
    virtual void move(float delta) = 0;
};

#endif //PONG_IMOVABLE_H
