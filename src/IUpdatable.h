/**
 * @file
 * @author Oliver Dixon
 * @date 23 June 2024
 */

#ifndef PONG_IUPDATABLE_H
#define PONG_IUPDATABLE_H

#include <optional>

/**
 * The Updatable interface allows the initialisation and resetting (but not storage) of a stateful value, such as an
 * onscreen position. Any implementors must provide a method of propagating the changed state, a method of resetting the
 * state to its initial value, and a method of updating the internal state as stored by the implementor.
 *
 * @tparam StateType The type of the stateful variable
 */
template<typename StateType>
class IUpdatable {
public:
    explicit IUpdatable(StateType initial_state):
        initial_state(initial_state) { }

    /**
     * Update the state of an updatable object according to any internal state changes (e.g. standing velocities) to
     * be propagated on the next render cycle.
     *
     * @param delta The time difference from the previous render cycle.
     */
    virtual auto update([[maybe_unused]] float delta) -> void = 0;

    /**
     * Reverts the updatable object back to its initial state.
     */
    virtual auto reset() -> void {
        set_state(initial_state);
    };

protected:
    StateType initial_state;

    /**
     * Directly manipulate the state of the updatable object.
     *
     * @param state The updated state
     */
    virtual auto set_state(const StateType& state) -> void = 0;
};

#endif //PONG_IUPDATABLE_H
