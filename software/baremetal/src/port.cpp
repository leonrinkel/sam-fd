/**
 * \file   src/port.cpp
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Implementation of stuff related to the I/O pin controller.
 */

#include "port.hpp"

const volatile struct port::_pincfg* port::pincfg_ro(enum port::pin pin) const
{
	return ((const volatile struct port::_pincfg*)
		(_base_address + _pincfg_register_offset + static_cast<int>(pin)));
}

volatile struct port::_pincfg* port::pincfg_rw(enum port::pin pin)
{
	return ((volatile struct port::_pincfg*)
		(_base_address + _pincfg_register_offset + static_cast<int>(pin)));
}

port::port(struct initializer init)
	: _base_address(init.base_address)
{
}

enum port::direction port::get_direction(enum port::pin pin) const
{
	/* Determine direction by checking whether corresponding bit in DIR
	 * register is set (-> output) or cleared (-> input). */
	return (
		(
			*((volatile uint32_t*) (
				_base_address +
				_dir_register_offset
			)) & (1 << static_cast<int>(pin))
		) ?
			port::direction::output :
			port::direction::input
	);
}

void port::set_direction(enum port::pin pin, enum port::direction dir)
{
	/* While one could set direction by setting (-> output) or clearing
	 * (-> input) corresponding bit in DIR register, this uses DIRCLR and
	 * DIRSET registers so we only have to write DIRCLR/DIRSET once and not
	 * read + write the DIR register. */
	switch (dir)
	{
	case port::direction::input:
		/* Clear bit by setting in DIRCLR register. */
		*((uint32_t*) (
			_base_address +
			_dirclr_register_offset
		)) = 1 << static_cast<int>(pin);
		break;

	case port::direction::output:
		/* Set bit by setting in DIRSET register. */
		*((uint32_t*) (
			_base_address +
			_dirset_register_offset
		)) = 1 << static_cast<int>(pin);
		break;
	}
}

void port::toggle_direction(enum port::pin pin)
{
	/* Toggle direction by setting corresponding bit in DIRTGL register. */
	*((volatile uint32_t*) (
		_base_address +
		_dirtgl_register_offset
	)) = 1 << static_cast<int>(pin);
}

enum port::output port::get_output(enum port::pin pin) const
{
	/* Determine output drive by checking whether corresponding bit in OUT
	 * register is set (-> high) or cleared (-> low). */
	return (
		(
			*((volatile uint32_t*) (
				_base_address +
				_out_register_offset
			)) & (1 << static_cast<int>(pin))
		) ?
			port::output::high :
			port::output::low
	);
}

void port::set_output(enum port::pin pin, enum port::output out)
{
	/* While one could set output drive by setting (-> high) or clearing
	 * (-> low) corresponding bit in OUT register, this uses OUTCLR and
	 * OUTSET registers so we only have to write OUTCLR/OUTSET once and not
	 * read + write the OUT register. */
	switch (out)
	{
	case port::output::low:
		/* Clear bit by setting in OUTCLR register. */
		*((uint32_t*) (
			_base_address +
			_outclr_register_offset
		)) = 1 << static_cast<int>(pin);
		break;

	case port::output::high:
		/* Set bit by setting in OUTSET register. */
		*((uint32_t*) (
			_base_address +
			_outset_register_offset
		)) = 1 << static_cast<int>(pin);
		break;
	}
}

void port::toggle_output(enum port::pin pin)
{
	/* Toggle output drive by setting corresponding bit in OUTTGL register. */
	*((volatile uint32_t*) (
		_base_address +
		_outtgl_register_offset
	)) = 1 << static_cast<int>(pin);
}

enum port::input port::get_input(enum port::pin pin) const
{
	/* Determine input level by checking whether corresponding bit in IN
	 * register is set (-> high) or cleared (-> low). */
	return (
		(
			*((volatile uint32_t*) (
				_base_address +
				_in_register_offset
			)) & (1 << static_cast<int>(pin))
		) ?
			port::input::high :
			port::input::low
	);
}

void port::set_pin_configuration(
	enum port::pin pin, struct port::pinconfig config)
{
	if (config.pmuxen.has_value())
	{
		/* Set peripheral multiplexer enable. */
		switch (config.pmuxen.get_value())
		{
		case port::mux_enable::disabled:
		{
			pincfg_rw(pin)->pmuxen = 0;
			break;
		}

		case port::mux_enable::enabled:
		{
			pincfg_rw(pin)->pmuxen = 1;
			break;
		}
		}
	}

	if (config.inen.has_value())
	{
		/* Set input buffer enable. */
		switch (config.inen.get_value())
		{
		case port::buffer_enable::disabled:
		{
			pincfg_rw(pin)->inen = 0;
			break;
		}

		case port::buffer_enable::enabled:
		{
			pincfg_rw(pin)->inen = 1;
			break;
		}
		}
	}

	if (config.pullen.has_value())
	{
		/* Set pull enable. */
		switch (config.pullen.get_value())
		{
		case port::pull_enable::disabled:
		{
			pincfg_rw(pin)->pullen = 0;
			break;
		}

		case port::pull_enable::enabled:
		{
			pincfg_rw(pin)->pullen = 1;
			break;
		}
		}
	}

	if (config.drvstr.has_value())
	{
		/* Set output driver strength selection. */
		switch (config.drvstr.get_value())
		{
		case port::drive_strength::normal:
		{
			pincfg_rw(pin)->drvstr = 0;
			break;
		}

		case port::drive_strength::strong:
		{
			pincfg_rw(pin)->drvstr = 1;
			break;
		}
		}
	}
}
