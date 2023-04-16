/**
 * \file   inc/gclk.hpp
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Declaration of stuff related to the generic clock controller.
 */

#pragma once

#include "types.hpp"
#include "optional.hpp"

/**
 * Helper class to use the generic clock controller.
 */
class gclk
{
public:

	/** Enum to specify peripherals to configure the clock for. */
	enum class peripheral
	{
		dpll             = 0, /**< FDPLL96M input clock source for reference */
		dpll_32k         = 1, /**< FDPLL96M 32.768 kHz clock for FDPLL96M internal clock timer */
		eic              = 2,
		freqm_msr        = 3, /**< FREQM Measure */
		freqm_ref        = 4, /**< FREQM Reference */
		tsens            = 5,
		evsys_channel_0  = 6,
		evsys_channel_1  = 7,
		evsys_channel_2  = 8,
		evsys_channel_3  = 9,
		evsys_channel_4  = 10,
		evsys_channel_5  = 11,
		evsys_channel_6  = 12,
		evsys_channel_7  = 13,
		evsys_channel_8  = 14,
		evsys_channel_9  = 15,
		evsys_channel_10 = 16,
		evsys_channel_11 = 17,
		sercom01234_slow = 18,
		sercom0_core     = 19,
		sercom1_core     = 20,
		sercom2_core     = 21,
		sercom3_core     = 22,
		sercom4_core     = 23,
		sercom5_slow     = 24,
		sercom5_core     = 25,
		can0             = 26,
		can1             = 27,
		tcc01            = 28,
		tcc2             = 29,
		tc01             = 30,
		tc23             = 31,
		tc4              = 32,
		adc0             = 33,
		adc1             = 34,
		sdadc            = 35,
		dac              = 36,
		ptc              = 37,
		ccl              = 38,
		ac               = 40,
		sercom6_core     = 41,
		sercom7_core     = 42,
		tc5              = 43,
		tc6              = 44,
		tc7              = 45,
	};

private:

	uint32_t _base_address; /**< Base address of the controller. */

	/** Address offset of PCHCTRL register relative to base address. */
	static const uint32_t _pchctrl_register_offset = 0x80;

	/**
	 * Packed struct representing the PCHCTRL register structure.
	 */
	struct pchctrl
	{
		uint8_t gen:4;     /**< Generator Selection */
		uint8_t:2;         /**< Reserved */
		uint8_t chen:1;    /**< Channel Enable */
		uint8_t wrtlock:1; /**< Write Lock */
		uint32_t:24;       /**< Reserved */
	} __attribute__((packed));
	static_assert(sizeof(struct gclk::pchctrl) == 4);

	/**
	 * Provides read-only access to the PCHCTRL register for a given peripheral.
	 * \param[in] p The peripheral to get the PCHCTRL register for.
	 * \returns     Pointer to the PCHCTRL register.
	 */
	const volatile struct gclk::pchctrl* pchctrl_ro(
		enum gclk::peripheral) const;

	/**
	 * Provides read-write access to the PCHCTRL register.
	 * \param[in] p The peripheral to get the PCHCTRL register for.
	 * \returns     Pointer to the PCHCTRL register.
	 */
	volatile struct gclk::pchctrl* pchctrl_rw(enum gclk::peripheral);

public:

	/**
	 * Struct to pass named constructor args.
	 */
	struct initializer
	{
		uint32_t base_address; /**< Base address of controller. */
	};

	/**
	 * Constructs an instance of this generic clock controller helper.
	 * \param[in] init Parameters such as controller base address.
	 */
	gclk(struct gclk::initializer);

	/**
	 * Enum to select generator of peripheral clock.
	 */
	enum class generator_selection
	{
		generator0, /**< Generic Clock Generator 0 */
		generator1, /**< Generic Clock Generator 1 */
		generator2, /**< Generic Clock Generator 2 */
		generator3, /**< Generic Clock Generator 3 */
		generator4, /**< Generic Clock Generator 4 */
		generator5, /**< Generic Clock Generator 5 */
		generator6, /**< Generic Clock Generator 6 */
		generator7, /**< Generic Clock Generator 7 */
		generator8, /**< Generic Clock Generator 8 */
	};

	/**
	 * Enum to specify enable state of a peripheral channel.
	 */
	enum class channel_enable
	{
		disabled, /**< The Peripheral Channel is disabled. */
		enabled,  /**< The Peripheral Channel is enabled. */
	};

	/**
	 * Enum to specify write lock status of a peripheral channel.
	 */
	enum class write_lock
	{
		/**
		 * The Peripheral Channel register and the associated Generator register
		 * are not locked. */
		not_locked,
		/**
		 * The Peripheral Channel register and the associated Generator register
		 * are locked. */
		locked,
	};

	/**
	 * Struct with peripheral channel control options.
	 *
	 * Fields are wrapped in the optional container, so that fields that have
	 * not been specified will not be configured and left as they are.
	*/
	struct peripheral_channel_control
	{
		/** Generator Selection */
		optional<enum gclk::generator_selection> gen;
		/** Channel Enable */
		optional<enum gclk::channel_enable> chen;
		/** Write Lock */
		optional<enum gclk::write_lock> wrtlock;
	};

	/**
	 * Sets some channel control options for a given peripherial.
	 * \param[in] p Which peripheral to configure.
	 * \param[in] c The control options to set.
	 */
	void set_peripheral_channel_control(
		enum gclk::peripheral, struct gclk::peripheral_channel_control);

};
