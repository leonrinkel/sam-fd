/**
 * \file   inc/optional.hpp
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Declaration of a container to manage optional values.
 */

#pragma once

/**
 * This template class contains an optional value, i.e. a value that may or may
 * not be set.
 */
template<class T>
class optional
{
private:

    T _value;        /**< The value (if it has been set). */
    bool _has_value; /**< Whether the value has been set. */

public:

    /**
     * Constructs an instance without initially setting a value.
     */
    optional(void);

    /**
     * Constructs an instance with an initially set value.
     * \param[in] value The value to set.
     */
    optional(T);

    /**
     * Retrieves the set value.
     * \returns The set value.
     */
    T get_value(void) const;

    /**
     * Sets a given value.
     * \param[in] value The value to set.
     */
    void set_value(T);

    /**
     * Checks whether a value has been set.
     * \returns True if a value has been set, false otherwise.
     */
    bool has_value(void) const;

};
