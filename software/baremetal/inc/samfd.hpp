/**
 * \file   inc/samfd.hpp
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Contains a wrapper class around the programs main entrypoint.
 */

#pragma once

#include "mclk.hpp"
#include "port.hpp"

/**
 * Wrapper class around the programs main entrypoint.
 */
class samfd
{
private:

	/** Instance of the main clock controller. */
	mclk _mclk;
	/** Instance of the I/O pin controller port A. */
	port _port_pa;

	/** Pin the TX led is attached to. */
	const port::pin _tx_led_pin = port::pin::pin9;
	/** Pin the RX led is attached to. */
	const port::pin _rx_led_pin = port::pin::pin10;

public:

	samfd(void);

	/**
	 * Entrypoint of the actual program.
	 */
	void run(void);

};
