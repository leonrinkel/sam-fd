/**
 * \file   src/samfd.cpp
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Implementation of the actual program.
 */

#include "samfd.hpp"

#include "types.hpp"

samfd::samfd(
	void
) : _mclk   ({ .base_address = 0x40000800 }),
	_port_pa({ .base_address = 0x41000000 }),
	_gclk   ({ .base_address = 0x40001c00 })
{
}

void samfd::run(void)
{
	/* Enable PORT and SERCOM0 peripherals. */
	_mclk.enable_peripheral_clock(mclk::peripheral::apbb_port);
	_mclk.enable_peripheral_clock(mclk::peripheral::apbc_sercom0);

	/* Configure RX/TX LED pins. */
	_port_pa.set_direction(_tx_led_pin, port::direction::output);
	_port_pa.set_direction(_rx_led_pin, port::direction::output);

	/* Set SERCOM0 slow and core clock. */
	_gclk.set_peripheral_channel_control(
		gclk::peripheral::sercom01234_slow,
		{
			.gen = gclk::generator_selection::generator0,
			.chen = gclk::channel_enable::enabled,
		}
	);
	_gclk.set_peripheral_channel_control(
		gclk::peripheral::sercom0_core,
		{
			.gen = gclk::generator_selection::generator0,
			.chen = gclk::channel_enable::enabled,
		}
	);

	while(true)
	{
		/* Flash TX led very short. */
		_port_pa.set_output(_tx_led_pin, port::output::high);
		_port_pa.set_output(_rx_led_pin, port::output::low);
		for (uint32_t i = 0; i < 0xfff; i++);

		/* Turn off and delay a little longer. */
		_port_pa.set_output(_tx_led_pin, port::output::low);
		_port_pa.set_output(_rx_led_pin, port::output::low);
		for (uint32_t i = 0; i < 0xfffff; i++);

		/* Flash RX led very short. */
		_port_pa.set_output(_tx_led_pin, port::output::low);
		_port_pa.set_output(_rx_led_pin, port::output::high);
		for (uint32_t i = 0; i < 0xfff; i++);

		/* Turn off and delay a little longer. */
		_port_pa.set_output(_tx_led_pin, port::output::low);
		_port_pa.set_output(_rx_led_pin, port::output::low);
		for (uint32_t i = 0; i < 0xfffff; i++);
	}
}
