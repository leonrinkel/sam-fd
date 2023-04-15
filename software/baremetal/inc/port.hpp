/**
 * \file   inc/port.hpp
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Declaration of stuff related to the I/O pin controller.
 */

#pragma once

#include "types.hpp"
#include "optional.hpp"

/**
 * Helper class to use the I/O pin controller.
 */
class port
{
public:

	/**
	 * Enum to specify I/O pin of port group.
	 */
	enum class pin
	{
		pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7,
		pin8, pin9, pin10, pin11, pin12, pin13, pin14, pin15,
		pin16, pin17, pin18, pin19, pin20, pin21, pin22, pin23,
		pin24, pin25, pin26, pin27, pin28, pin29, pin30, pin31,
	};

private:

	uint32_t _base_address; /**< Base address of the controller. */

	/** Address offset of DIR register relative to base address. */
	static const uint32_t _dir_register_offset = 0x00;
	/** Address offset of DIRCLR register relative to base address. */
	static const uint32_t _dirclr_register_offset = 0x04;
	/** Address offset of DIRSET register relative to base address. */
	static const uint32_t _dirset_register_offset = 0x08;
	/** Address offset of DIRTGL register relative to base address. */
	static const uint32_t _dirtgl_register_offset = 0x0c;
	/** Address offset of OUT register relative to base address. */
	static const uint32_t _out_register_offset = 0x10;
	/** Address offset of OUTCLR register relative to base address. */
	static const uint32_t _outclr_register_offset = 0x14;
	/** Address offset of OUTSET register relative to base address. */
	static const uint32_t _outset_register_offset = 0x18;
	/** Address offset of OUTTGL register relative to base address. */
	static const uint32_t _outtgl_register_offset = 0x1c;
	/** Address offset of IN register relative to base address. */
	static const uint32_t _in_register_offset = 0x20;
	/** Address offset of PINCFG register relative to base address. */
	static const uint32_t _pincfg_register_offset = 0x40;

	/**
	 * Packed struct representing the PINCFG register structure.
	 */
	struct _pincfg
	{
		uint8_t pmuxen:1; /**< Peripheral Multiplexer Enable */
		uint8_t inen:1;   /**< Input Buffer Enable*/
		uint8_t pullen:1; /**< Pull Enable */
		uint8_t:3;        /**< Reserved */
		uint8_t drvstr:1; /**< Output Driver Strength Selection */
		uint8_t:1;        /**< Reserved */
	} __attribute__((packed));
	static_assert(sizeof(struct port::_pincfg) == 1);

	/**
	 * Provides read-only access to the PINCFG register for a given pin.
	 * \param[in] pin The pin to get the PINCFG register for.
	 * \returns       Pointer to the PINCFG register.
	 */
	const volatile struct port::_pincfg* pincfg_ro(enum port::pin) const;

	/**
	 * Provides read-write access to the PINCFG register.
	 * \param[in] pin The pin to get the PINCFG register for.
	 * \returns       Pointer to the PINCFG register.
	 */
	volatile struct port::_pincfg* pincfg_rw(enum port::pin);

public:

	/**
	 * Struct to pass named constructor args.
	 */
	struct initializer
	{
		uint32_t base_address; /**< Base address of controller. */
	};

	/**
	 * Constructs an instance of this I/O controller helper.
	 * \param[in] init Parameters such as controller base address.
	 */
	port(struct port::initializer);

	/**
	 * Enum to specify direction (input/output) of an I/O pin.
	 */
	enum class direction
	{
		input,  /**< Pin configured in input direction. */
		output, /**< Pin configured in output direction. */
	};

	/**
	 * Retrieves direction (input/output) an I/O pin is configured as.
	 * \param[in] pin Which I/O pin to get direction of.
	 * \returns       The direction (input/output).
	 */
	enum port::direction get_direction(enum port::pin) const;

	/**
	 * Configures direction (input/output) of an I/O pin.
	 * \param[in] pin Which I/O pin to set direction of.
	 * \param[in] dir The direction (input/output) to set.
	 */
	void set_direction(enum port::pin, enum port::direction);

	/**
	 * Toggles direction (input/output) of an I/O pin.
	 * \param[in] pin Which I/O pin to toggle direction of.
	 */
	void toggle_direction(enum port::pin);

	/**
	 * Enum to specify output drive of an output pin.
	 */
	enum class output
	{
		low,  /**< Output pin is driven low. */
		high, /**< Output pin is driven high. */
	};

	/**
	 * Retrieves output drive (high/low) an output pin is configured as.
	 * \param[in] pin Which output pin to get output drive (high/low) of.
	 * \returns       The output drive (high/low).
	 */
	enum port::output get_output(enum port::pin) const;

	/**
	 * Configures output drive (high/low) of an output pin.
	 * \param[in] pin Which output pin to set output drive of.
	 * \param[in] out The output drive (high/low) to set.
	 */
	void set_output(enum port::pin, enum port::output);

	/**
	 * Toggles output drive (high/low) of an output pin.
	 * \param[in] pin Which output pin to toggle output drive of.
	 */
	void toggle_output(enum port::pin);

	/**
	 * Enum to specify sampled level of an input pin.
	 */
	enum class input
	{
		low,  /**< Input pin was sampled low. */
		high, /**< Input pin was sampled high. */
	};

	/**
	 * Retrieves input level (high/low) of an input pin.
	 * \param[in] pin Which input pin to get input level of.
	 */
	enum port::input get_input(enum port::pin) const;

	/**
	 * Enum to specify whether a pin uses the peripheral multiplexer.
	 */
	enum class mux_enable
	{
		/**
		 * The peripheral multiplexer selection is disabled, and the PORT
		 * registers control the direction and output drive value.
		 */
		disabled,

		/**
		 * The peripheral multiplexer selection is enabled, and the selected
		 * peripheral function controls the direction and output drive value.
		 */
		enabled,
	};

	/**
	 * Enum to specify whether the input buffer for an I/O pin is enabled.
	 */
	enum class buffer_enable
	{
		/**
		 * Input buffer for the I/O pin is disabled, and the input value will
		 * not be sampled.
		 */
		disabled,

		/**
		 * Input buffer for the I/O pin is enabled, and the input value will be
		 * sampled when required.
		 */
		enabled,
	};

	/**
	 * Enum to specify whether the internal pull for an I/O pin is enabled.
	 */
	enum class pull_enable
	{
		/**
		 * Internal pull resistor is disabled, and the input is in a
		 * high-impedance configuration. */
		disabled,

		/**
		 * Internal pull resistor is enabled, and the input is driven to a
		 * defined logic level in the absence of external input.
		 */
		enabled,
	};

	/**
	 * Enum to specify the drive strength of an I/O pin.
	 */
	enum class drive_strength
	{
		normal, /**< Pin drive strength is set to normal drive strength. */
		strong, /**< Pin drive strength is set to stronger drive strength. */
	};

	/**
	 * Struct with some pin configuration options.
	 *
	 * Fields are wrapped in the optional container, so that fields that have
	 * not been specified will not be configured and left as they are.
	 */
	struct pinconfig
	{
		/** Peripheral Multiplexer Enable */
		optional<enum port::mux_enable> pmuxen;
		/** Input Buffer Enable */
		optional<enum port::buffer_enable> inen;
		/** Pull Enable */
		optional<enum port::pull_enable> pullen;
		/** Output Driver Strength Selection */
		optional<enum port::drive_strength> drvstr;
	};

	/**
	 * Sets some configuration options for a given pin.
	 * \param[in] pin    Which pin to configure.
	 * \param[in] config The configuration to set.
	 */
	void set_pin_configuration(enum port::pin, struct port::pinconfig);

};
