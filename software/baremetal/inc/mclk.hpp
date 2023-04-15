/**
 * \file   inc/mclk.hpp
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Declaration of stuff related to the main clock controller.
 */

#pragma once

#include "types.hpp"

/**
 * Helper class to use the main clock controller.
 */
class mclk
{
private:

	uint32_t _base_address; /**< Base address of the controller. */

	/** Address offset of AHBMASK register relative to base address. */
	static const uint32_t _ahbmask_register_offset = 0x10;
	/** Address offset of APBAMASK register relative to base address. */
	static const uint32_t _apbamask_register_offset = 0x14;
	/** Address offset of APBBMASK register relative to base address. */
	static const uint32_t _apbbmask_register_offset = 0x18;
	/** Address offset of APBCMASK register relative to base address. */
	static const uint32_t _apbcmask_register_offset = 0x1c;

	/**
	 * Packed struct representing the AHBMASK register structure.
	 */
	struct ahbmask
	{
		uint8_t apba:1;      /**< APBA AHB Clock Enable */
		uint8_t apbb:1;      /**< APBB AHB Clock Enable */
		uint8_t apbc:1;      /**< APBC AHB Clock Enable */
		uint8_t dsu:1;       /**< DSU AHB Clock Enable */
		uint8_t hmatrixhs:1; /**< HMATRIXHS AHB Clock Enable */
		uint8_t nvmctrl:1;   /**< NVMCTRL AHB Clock Enable */
		uint8_t hsram:1;     /**< HSRAM AHB Clock Enable */
		uint8_t dmac:1;      /**< DMAC AHB Clock Enable */
		uint8_t can0:1;      /**< CAN0 AHB Clock Enable */
		uint8_t:1;           /**< Reserved */
		uint8_t pac:1;       /**< PAC AHB Clock Enable */
		uint8_t:1;           /**< Reserved */
		uint8_t divas:1;     /**< DIVAS AHB Clock Enable */
		uint32_t:18;         /**< Reserved */
	} __attribute__((packed));
	static_assert(sizeof(struct mclk::ahbmask) == 4);

	/**
	 * Provides read-only access to the AHBMASK register.
	 * \returns Pointer to the AHBMASK register.
	 */
	const volatile struct mclk::ahbmask* ahbmask_ro(void) const;

	/**
	 * Provides read-write access to the AHBMASK register.
	 * \returns Pointer to the AHBMASK register.
	 */
	volatile struct mclk::ahbmask* ahbmask_rw(void);

	/**
	 * Packed struct representing the APBAMASK register structure.
	 */
	struct apbamask
	{
		uint8_t pac:1;        /**< PAC APBA Clock Enable */
		uint8_t pm:1;         /**< PM APBA Clock Enable */
		uint8_t mclk:1;       /**< MCLK APBA Clock Enable */
		uint8_t rstc:1;       /**< RSTC APBA Clock Enable */
		uint8_t oscctrl:1;    /**< OSCCTRL APBA Clock Enable */
		uint8_t osc32kctrl:1; /**< OSC32KCTRL APBA Clock Enable */
		uint8_t supc:1;       /**< SUPC APBA Clock Enable */
		uint8_t gclk:1;       /**< GCLK APBA Clock Enable */
		uint8_t wdt:1;        /**< WDT APBA Clock Enable */
		uint8_t rtc:1;        /**< RTC APBA Clock Enable */
		uint8_t eic:1;        /**< EIC APBA Clock Enable */
		uint8_t freqm:1;      /**< FREQM APBA Clock Enable */
		uint8_t tsens:1;      /**< TSENS APBA Clock Enable */
		uint32_t:19;          /**< Reserved */
	} __attribute__((packed));
	static_assert(sizeof(struct mclk::apbamask) == 4);

	/**
	 * Provides read-only access to the APBAMASK register.
	 * \returns Pointer to the APBAMASK register.
	 */
	const volatile struct mclk::apbamask* apbamask_ro(void) const;

	/**
	 * Provides read-write access to the APBAMASK register.
	 * \returns Pointer to the APBAMASK register.
	 */
	volatile struct mclk::apbamask* apbamask_rw(void);

	/**
	 * Packed struct representing the APBBMASK register structure.
	 */
	struct apbbmask
	{
		uint8_t port:1;      /**< PORT APBB Clock Enable */
		uint8_t dsu:1;       /**< DSU APBB Clock Enable */
		uint8_t nvmctrl:1;   /**< NVMCTRL APBB Clock Enable */
		uint8_t:2;           /**< Reserved */
		uint8_t hmatrixhs:1; /**< HMATRIXHS APBB Clock Enable */
		uint32_t:26;         /**< Reserved */
	} __attribute__((packed));
	static_assert(sizeof(struct mclk::apbbmask) == 4);

	/**
	 * Provides read-only access to the APBBMASK register.
	 * \returns Pointer to the APBBMASK register.
	 */
	const volatile struct mclk::apbbmask* apbbmask_ro(void) const;

	/**
	 * Provides read-write access to the APBBMASK register.
	 * \returns Pointer to the APBBMASK register.
	 */
	volatile struct mclk::apbbmask* apbbmask_rw(void);

	/**
	 * Packed struct representing the APBCMASK register structure.
	 */
	struct apbcmask
	{
		uint8_t evsys:1;   /**< EVSYS APBC Clock Enable */
		uint8_t sercom0:1; /**< SERCOM0 APBC Mask Clock Enable */
		uint8_t sercom1:1; /**< SERCOM1 APBC Mask Clock Enable */
		uint8_t sercom2:1; /**< SERCOM2 APBC Mask Clock Enable */
		uint8_t sercom3:1; /**< SERCOM3 APBC Mask Clock Enable */
		uint8_t:4;         /**< Reserved */
		uint8_t tcc0:1;    /**< TCC0 APBC Mask Clock Enable */
		uint8_t tcc1:1;    /**< TCC1 APBC Mask Clock Enable */
		uint8_t tcc2:1;    /**< TCC2 APBC Mask Clock Enable */
		uint8_t tc0:1;     /**< TC0 APBC Mask Clock Enable */
		uint8_t tc1:1;     /**< TC1 APBC Mask Clock Enable */
		uint8_t tc2:1;     /**< TC2 APBC Mask Clock Enable */
		uint8_t tc3:1;     /**< TC3 APBC Mask Clock Enable */
		uint8_t tc4:1;     /**< TC4 APBC Mask Clock Enable */
		uint8_t adc0:1;    /**< ADC0 APBC Clock Enable */
		uint8_t adc1:1;    /**< ADC1 APBC Clock Enable */
		uint8_t sdadc:1;   /**< SDADC APBC Clock Enable */
		uint8_t ac:1;      /**< AC APBC Clock Enable */
		uint8_t dac:1;     /**< DAC APBC Mask Clock Enable */
		uint8_t ptc:1;     /**< PTC APBC Mask Clock Enable */
		uint8_t ccl:1;     /**< CCL APBC Clock Enable */
		uint8_t:8;         /**< Reserved */
	} __attribute__((packed));
	static_assert(sizeof(struct mclk::apbcmask) == 4);

	/**
	 * Provides read-only access to the APBCMASK register.
	 * \returns Pointer to the APBCMASK register.
	 */
	const volatile struct mclk::apbcmask* apbcmask_ro(void) const;

	/**
	 * Provides read-write access to the APBCMASK register.
	 * \returns Pointer to the APBCMASK register.
	 */
	volatile struct mclk::apbcmask* apbcmask_rw(void);

public:

	/**
	 * Struct to pass named constructor args.
	 */
	struct initializer
	{
		uint32_t base_address; /**< Base address of controller. */
	};

	/**
	 * Constructs an instance of this main clock controller helper.
	 * \param[in] init Parameters such as controller base address.
	 */
	mclk(struct mclk::initializer);

	/**
	 * Enum to specify peripherals to enable/disable the clock for.
	 */
	enum class peripheral
	{
		/* Peripherals of the AHB bus matrix. */
		ahb_apba,      /**< AHB-APB Bridge A */
		ahb_apbb,      /**< AHB-APB Bridge B */
		ahb_apbc,      /**< AHB-APB Bridge C */
		ahb_dsu,       /**< DSU - Device Service Unit */
		ahb_hmatrixhs, /**< HMATRIXHS - High-Speed Bus Matrix */
		ahb_nvmctrl,   /**< NVMCTRL – Non-Volatile Memory Controller */
		ahb_hsram,     /**< HSRAM - High-Speed SRAM Controller */
		ahb_dmac,      /**< DMAC - Direct Memory Access Controller */
		ahb_can0,      /**< CAN0 – Controller Area Network 0 */
		ahb_pac,       /**< PAC - Protection Access Controller */
		ahb_divas,     /**< DIVAS - Divide Accelerator */

		/* Peripherals of the AHB-APB bridge A. */
		apba_pac,        /**< PAC - Protection Access Controller */
		apba_pm,         /**< PM - Power Manager */
		apba_mclk,       /**< MCLK - Main Clock */
		apba_rstc,       /**< RSTC – Reset Controller */
		apba_oscctrl,    /**< OSCCTRL - Oscillators Controller */
		apba_osc32kctrl, /**< OSC32KCTRL - 32.768 kHz Oscillators Controller */
		apba_supc,       /**< SUPC - Supply Controller */
		apba_gclk,       /**< GCLK - Generic Clock Controller */
		apba_wdt,        /**< WDT – Watchdog Timer */
		apba_rtc,        /**< RTC – Real Time Clock */
		apba_eic,        /**< EIC – External Interrupt Controller */
		apba_freqm,      /**< FREQM – Frequency Meter */
		apba_tsens,      /**< TSENS – Temperature Sensor */

		/* Peripherals of the AHB-APB bridge B. */
		apbb_port,      /**< PORT - I/O Pin Controller */
		apbb_dsu,       /**< DSU - Device Service Unit */
		apbb_nvmctrl,   /**< NVMCTRL – Non-Volatile Memory Controller */
		apbb_hmatrixhs, /**< HMATRIXHS - High-Speed Bus Matrix */

		/* Peripherals of the AHB-APB bridge C. */
		apbc_evsys,   /**< EVSYS – Event System */
		apbc_sercom0, /**< SERCOM0 – Serial Communication Controller 0 */
		apbc_sercom1, /**< SERCOM1 – Serial Communication Controller 1 */
		apbc_sercom2, /**< SERCOM2 – Serial Communication Controller 2 */
		apbc_sercom3, /**< SERCOM3 – Serial Communication Controller 3 */
		apbc_tcc0,    /**< TCC0 – Timer Counter for Control 0 */
		apbc_tcc1,    /**< TCC1 – Timer Counter for Control 1 */
		apbc_tcc2,    /**< TCC2 – Timer Counter for Control 2 */
		apbc_tc0,     /**< TC0 – Timer Counter 0 */
		apbc_tc1,     /**< TC1 – Timer Counter 1 */
		apbc_tc2,     /**< TC2 – Timer Counter 2 */
		apbc_tc3,     /**< TC3 – Timer Counter 3 */
		apbc_tc4,     /**< TC4 – Timer Counter 4 */
		apbc_adc0,    /**< ADC0 – Analog-to-Digital Converter 0 */
		apbc_adc1,    /**< ADC1 – Analog-to-Digital Converter 1 */
		apbc_sdadc,   /**< SDADC – Sigma-Delta Analog-to-Digital Converter 1 */
		apbc_ac,      /**< AC – Analog Comparator */
		apbc_dac,     /**< DAC – Digital-to-Analog Converter */
		apbc_ptc,     /**< PTC – Peripheral Touch Controller */
		apbc_ccl,     /**< Custom Control Logic - CCL */
	};

	/**
	 * Enum to specify whether a peripheral clock is stopped/enabled.
	 */
	enum class clock_enable
	{
		stopped, /**< Clock for the peripheral is stopped. */
		enabled, /**< Clock for the peripheral is enabled. */
	};

	/**
	 * Checks whether clock for a peripheral is enabled/stopped.
	 * \param[in] p Which peripheral to get clock enable of.
	 * \returns     Whether clock for this peripheral is enabled/stopped.
	 */
	enum mclk::clock_enable get_peripheral_clock_enable(
		enum mclk::peripheral) const;

	/**
	 * Enables/stops clock for a peripheral.
	 * \param[in] p Which peripheral to enable/stop the clock for.
	 * \param[in] e Whether clock should be enabled/stopped.
	 */
	void set_peripheral_clock_enable(
		enum mclk::peripheral, enum mclk::clock_enable);

	/**
	 * Enables the clock for a peripheral.
	 * \param[in] p Which peripheral to enable the clock for.
	 */
	void enable_peripheral_clock(enum mclk::peripheral);

	/**
	 * Stops the clock for a peripheral.
	 * \param[in] p Which peripheral to stop the clock for.
	 */
	void stop_peripheral_clock(enum mclk::peripheral);

};
