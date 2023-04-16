/**
 * \file   src/gclk.cpp
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Implementation of stuff related to the generic clock controller.
 */

#include "gclk.hpp"

const volatile struct gclk::pchctrl* gclk::pchctrl_ro(
	enum gclk::peripheral p) const
{
	return ((const volatile struct gclk::pchctrl*) (
		_base_address + _pchctrl_register_offset + static_cast<int>(p) * 0x4));
}

volatile struct gclk::pchctrl* gclk::pchctrl_rw(enum gclk::peripheral p)
{
	return ((volatile struct gclk::pchctrl*) (
		_base_address + _pchctrl_register_offset + static_cast<int>(p) * 0x4));
}

gclk::gclk(
	struct gclk::initializer init
) : _base_address(init.base_address)
{
}

void gclk::set_peripheral_channel_control(
	enum gclk::peripheral p, struct gclk::peripheral_channel_control c)
{
	if (c.gen.has_value())
	{
		pchctrl_rw(p)->gen = static_cast<int>(c.gen.get_value());
	}

	if (c.chen.has_value())
	{
		pchctrl_rw(p)->chen = static_cast<int>(c.chen.get_value());
	}

	if (c.wrtlock.has_value())
	{
		pchctrl_rw(p)->wrtlock = static_cast<int>(c.wrtlock.get_value());
	}
}
