/**
 * @file
 * @author Oliver Dixon
 * @date 24 June 2024
 */

#ifndef PONG_IANIMATABLE_H
#define PONG_IANIMATABLE_H

#include "IUpdatable.h"

/**
 * The Animatable interface allows the instantiation, resetting, and storage of a velocity in addition to a basic
 * Updatable object.
 *
 * @tparam VelocityType The type of the stateful velocity
 * @tparam StateType The type of the base stateful variable
 */
template<typename VelocityType, typename StateType>
class IAnimatable:
        public IUpdatable<StateType> {
public:
    /**
     * Instantiates an Animatable object with a given initial velocity and initial basal state, where the latter refers
     * to the 'stateful variable' used by an Updatable object.
     *
     * @param initial_velocity The initial velocity.
     * @param initial_state The initial basal state.
     */
    explicit IAnimatable(VelocityType initial_velocity, StateType initial_state):
            IUpdatable<StateType>(initial_state) {

        this->initial_velocity = initial_velocity;
    }

    void reset() final {
        IUpdatable<StateType>::reset();
        velocity = initial_velocity;
    }

protected:
    VelocityType initial_velocity;
    VelocityType velocity;
};

#endif //PONG_IANIMATABLE_H
