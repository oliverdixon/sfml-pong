/**
 * @file
 * @author Oliver Dixon
 * @date 24 June 2024
 */

#ifndef PONG_IANIMATABLE_H
#define PONG_IANIMATABLE_H

#include "IUpdatable.h"
#include "IDrawable.h"

template<typename T>
concept IsVector = std::is_same_v<sf::Vector2f, T>;

template<typename T>
concept IsScalar = std::is_scalar_v<T>;

template<typename T>
concept IsValidVelocity = IsVector<T> || IsScalar<T>;

/**
 * The Animatable interface allows the instantiation, resetting, and storage of a velocity in addition to a basic
 * Updatable object.
 *
 * @tparam VelocityType The type of the stateful velocity: a scalar or two-dimensional vector.
 * @tparam StateType The type of the base stateful variable
 * @tparam ShapeType The type of shape to be animated
 */
template<typename VelocityType, typename StateType, GenericDrawable ShapeType>
        requires IsValidVelocity<VelocityType>
class IAnimatable:
        public IUpdatable<StateType>,
        public IDrawable<ShapeType> {
public:
    /**
     * Instantiates an Animatable object with a given initial velocity and initial basal state, where the latter refers
     * to the 'stateful variable' used by an Updatable object.
     *
     * @tparam Args The type of arguments passed to the SFML Drawable constructor
     * @param initial_velocity The initial velocity.
     * @param initial_state The initial basal state.
     * @param args Constructor arguments for the SFML Drawable constructor
     */
    template<typename... Args>
    explicit IAnimatable(VelocityType initial_velocity, StateType initial_state, Args&& ... args):
            IDrawable<ShapeType>(std::forward<Args>(args)...),
            IUpdatable<StateType>(initial_state),
            initial_velocity(initial_velocity) { }

    auto update(float delta) -> void override {
        animate(delta);
    }

    auto reset() -> void override {
        IUpdatable<StateType>::reset();
        velocity = initial_velocity;
    }

protected:
    VelocityType initial_velocity;
    VelocityType velocity;

private:
    /**
     * Updates the Animatable by updating the shape.
     *
     * @param delta The time difference from the previous render cycle.
     */
    auto animate(float delta) -> void requires IsScalar<VelocityType> {
        IDrawable<ShapeType>::shape.move(0, velocity * delta);
    }

    /**
     * Updates the Animatable in two dimensions by updating the shape.
     *
     * @param delta The time difference from the previous render cycle.
     */
    auto animate(float delta) -> void requires IsVector<VelocityType> {
        IDrawable<ShapeType>::shape.move(velocity * delta);
    }
};

#endif //PONG_IANIMATABLE_H
