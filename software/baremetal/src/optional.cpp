/**
 * \file   src/optional.cpp
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Implementation of a container to manage optional values and instantiation of
 * template classes.
 */

#include "optional.hpp"

#include "port.hpp"

template<class T>
optional<T>::optional(
	void
) : _has_value(false)
{
}

template<class T>
optional<T>::optional(
	T value
) : _value(value),
	_has_value(true)
{
}

template<class T>
T optional<T>::get_value(void) const
{
	return _value;
}

template<class T>
void optional<T>::set_value(T value)
{
	_value = value;
	_has_value = true;
}

template<class T>
bool optional<T>::has_value(void) const
{
	return _has_value;
}

/* Instantiate some template classes to be used with optional. */
template class optional<enum port::mux_enable>;
template class optional<enum port::buffer_enable>;
template class optional<enum port::pull_enable>;
template class optional<enum port::drive_strength>;
